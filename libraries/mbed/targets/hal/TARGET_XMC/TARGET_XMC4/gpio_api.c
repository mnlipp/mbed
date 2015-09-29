/* mbed Microcontroller Library
 *******************************************************************************
 * Copyright (c) 2014, STMicroelectronics
 * Modifications for XMC4500 Copyright (c) 2015, Michael N. Lipp
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. Neither the name of STMicroelectronics nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *******************************************************************************
 */
#include "mbed_assert.h"
#include "gpio_api.h"
#include "pinmap.h"
#include "mbed_error.h"

uint32_t gpio_set(PinName pin)
{
    MBED_ASSERT(pin != (PinName)NC);

    pin_function(pin, 0);
    return (uint32_t)(1 << ((uint32_t)pin & 0xF)); // Return the pin mask
}

void gpio_init(gpio_t *obj, PinName pin)
{
    obj->pin = pin;
    if (pin == (PinName)NC)
        return;

    obj->mask = gpio_set(pin);

    // Fill GPIO object structure for future use
    int port_set_offset = (pin >> 4) << 8; // port * 0x100
    // The register set this pin's port belongs to
    obj->reg_set = (PORT0_Type*)(PORT0_BASE + port_set_offset);
}

void gpio_mode(gpio_t *obj, PinMode mode)
{
    pin_mode(obj->pin, mode);
}

void gpio_dir(gpio_t *obj, PinDirection direction)
{
    MBED_ASSERT(obj->pin != (PinName)NC);
    if (direction == PIN_OUTPUT) {
        pin_function(obj->pin, 0);
    } else { // PIN_INPUT
        pin_function(obj->pin, -1);
    }
}
