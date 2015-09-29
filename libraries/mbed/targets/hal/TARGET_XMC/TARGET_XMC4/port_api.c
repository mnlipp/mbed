/* mbed Microcontroller Library
 * Copyright (c) 2006-2015 ARM Limited
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
#include "port_api.h"
#include "pinmap.h"
#include "gpio_api.h"

// high nibble = port number
// low nibble  = pin number
PinName port_pin(PortName port, int pin_n) {
    return (PinName)(pin_n + (port << 4));
}

void port_init(port_t *obj, PortName port, int mask, PinDirection dir) {
    obj->port = port;
    obj->mask = mask;
    
    // Fill GPIO object structure for future use
    int port_set_offset = port << 8; // port * 0x100
    // The register set this pin's port belongs to
    PORT0_Type* reg_set = (PORT0_Type*)(PORT0_BASE + port_set_offset);

    obj->reg_in  = &reg_set->IN;
    obj->reg_out = &reg_set->OUT;
 
    uint32_t i;
    // The function is set per pin: reuse gpio logic
    for (i=0; i<16; i++) {
        if (obj->mask & (1<<i)) {
            gpio_set(port_pin(obj->port, i));
        }
    }
    
    port_dir(obj, dir);
}

void port_mode(port_t *obj, PinMode mode) {
    uint32_t i;
    // The mode is set per pin: reuse pinmap logic
    for (i=0; i<32; i++) {
        if (obj->mask & (1<<i)) {
            pin_mode(port_pin(obj->port, i), mode);
        }
    }
}

void port_dir(port_t *obj, PinDirection dir) {
	int i;
    // The direction is set per pin: reuse gpio logic
    for (i=0; i<16; i++) {
        if (obj->mask & (1<<i)) {
            gpio_set(port_pin(obj->port, i));
        }
    }
}

void port_write(port_t *obj, int value) {
    *obj->reg_out = value;
}

int port_read(port_t *obj) {
    return (*obj->reg_in);
}
