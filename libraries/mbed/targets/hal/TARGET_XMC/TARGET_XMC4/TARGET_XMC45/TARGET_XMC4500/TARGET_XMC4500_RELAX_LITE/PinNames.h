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
#ifndef MBED_PINNAMES_H
#define MBED_PINNAMES_H

#include "cmsis.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    PIN_INPUT,
    PIN_OUTPUT
} PinDirection;

typedef enum {
    P0_0  = 0x00,
    P0_1  = 0x01,
    P0_2  = 0x02,
    P0_3  = 0x03,
    P0_4  = 0x04,
    P0_5  = 0x05,
    P0_6  = 0x06,
    P0_7  = 0x07,
    P0_8  = 0x08,
    P0_9  = 0x09,
    P0_10 = 0x0A,
    P0_11 = 0x0B,
    P0_12 = 0x0C,
    P0_13 = 0x0D,
    P0_14 = 0x0E,
    P0_15 = 0x0F,

    P1_0  = 0x10,
    P1_1  = 0x11,
    P1_2  = 0x12,
    P1_3  = 0x13,
    P1_4  = 0x14,
    P1_5  = 0x15,
    P1_6  = 0x16,
    P1_7  = 0x17,
    P1_8  = 0x18,
    P1_9  = 0x19,
    P1_10 = 0x1A,
    P1_11 = 0x1B,
    P1_12 = 0x1C,
    P1_13 = 0x1D,
    P1_14 = 0x1E,
    P1_15 = 0x1F,

    P2_0  = 0x20,
    P2_1  = 0x21,
    P2_2  = 0x22,
    P2_3  = 0x23,
    P2_4  = 0x24,
    P2_5  = 0x25,
    P2_6  = 0x26,
    P2_7  = 0x27,
    P2_8  = 0x28,
    P2_9  = 0x29,
    P2_10 = 0x2A,
    P2_11 = 0x2B,
    P2_12 = 0x2C,
    P2_13 = 0x2D,
    P2_14 = 0x2E,
    P2_15 = 0x2F,

    P3_0  = 0x30,
    P3_1  = 0x31,
    P3_2  = 0x32,
    P3_3  = 0x33,
    P3_4  = 0x34,
    P3_5  = 0x35,
    P3_6  = 0x36,
    P3_7  = 0x37,
    P3_8  = 0x38,
    P3_9  = 0x39,
    P3_10 = 0x3A,
    P3_11 = 0x3B,
    P3_12 = 0x3C,
    P3_13 = 0x3D,
    P3_14 = 0x3E,
    P3_15 = 0x3F,

    P4_0  = 0x40,
    P4_1  = 0x41,
    P4_2  = 0x42,
    P4_3  = 0x43,
    P4_4  = 0x44,
    P4_5  = 0x45,
    P4_6  = 0x46,
    P4_7  = 0x47,


    P5_0  = 0x50,
    P5_1  = 0x51,
    P5_2  = 0x52,
    P5_3  = 0x53,
    P5_4  = 0x54,
    P5_5  = 0x55,
    P5_6  = 0x56,
    P5_7  = 0x57,
    P5_8  = 0x58,
    P5_9  = 0x59,
    P5_10 = 0x5A,
    P5_11 = 0x5B,


    P6_0  = 0x60,
    P6_1  = 0x61,
    P6_2  = 0x62,
    P6_3  = 0x63,
    P6_4  = 0x64,
    P6_5  = 0x65,
    P6_6  = 0x66,


    // Generic signals namings
    LED1        = P1_1,
    LED2        = P1_0,
    BUTTON1     = P1_14,
    BUTTON2     = P1_15,
//    SERIAL_TX   = PA_9,
//    SERIAL_RX   = PA_10,
//    USBTX       = PA_9,
//    USBRX       = PA_10,
//    I2C_SCL     = PB_8,
//    I2C_SDA     = PB_9,
//    SPI_MOSI    = PA_7,
//    SPI_MISO    = PA_6,
//    SPI_SCK     = PA_5,
//    SPI_CS      = PA_4,
//    PWM_OUT     = PB_3,

    // Not connected
    NC = (int)0xFFFFFFFF
} PinName;

typedef enum {
    PullNone = 0,
    PullDown = 1,
    PullUp = 2,
    OpenDrain = 8,
    PullDefault = PullNone
} PinMode;

#ifdef __cplusplus
}
#endif

#endif
