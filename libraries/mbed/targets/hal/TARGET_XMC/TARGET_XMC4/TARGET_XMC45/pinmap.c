/* mbed Microcontroller Library
 * Copyright (c) 2006-2013 ARM Limited
 * Modifications for XMC4500 Copyright (c) 2015, Michael N. Lipp
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "mbed_assert.h"
#include "pinmap.h"
#include "mbed_error.h"

static inline void reg_and_shift (PinName pin, __IO uint32_t** reg, uint8_t* shift) {
    // Fill GPIO object structure for future use
    int port_set_offset = (pin >> 4) << 8; // port * 0x100
    // The register set this pin's port belongs to
    PORT0_Type* reg_set = (PORT0_Type*)(PORT0_BASE + port_set_offset);
    // The IOCR field to be used for this pin
    *reg = &reg_set->IOCR0 + ((pin & 0xc) >> 2);
    // The shift for the IOCR subfield for this pin
    *shift = (pin & 0x3) * 8 + 3;
}

/**
 * Selects an alternate function for an output pin.
 * Parameter function is usually used to select
 * an input of the output multiplexer.
 */
void pin_function(PinName pin, int function) {
    MBED_ASSERT(pin != (PinName)NC);

    __IO uint32_t* iocr;
    uint8_t shift;
    reg_and_shift(pin, &iocr, &shift);

    if (function == -1) {
    	// to be used as GPIO input, set to free floating input,
    	// will be adjusted by pin_mode later
    	*iocr &= ~(0x1f << shift);
    } else {
    	// function != -1 implies output. To be on the safe side, start as open-drain
    	// will be adjusted by pin_mode later
    	*iocr = (*iocr & ~(0x1f << shift)) | ((0x18 | (function & 7)) << shift);
    }
}

void pin_mode(PinName pin, PinMode mode) {
    MBED_ASSERT(pin != (PinName)NC);
    
    __IO uint32_t* iocr;
    uint8_t shift;
    reg_and_shift(pin, &iocr, &shift);

    if (*iocr & (0x10 << shift)) {
    	// Configured as output, only open-drain can be turned on or off
    	if (mode == OpenDrain) {
    		*iocr |= (0x8 << shift);
    	} else {
    		*iocr &= ~(0x8 << shift);
    	}
    } else {
    	// Configured as input, adjust
    	if (mode < OpenDrain) {
    		*iocr = (*iocr & (0x1f << shift)) | ((mode & 0x7) << shift);
    	}
    }
}
