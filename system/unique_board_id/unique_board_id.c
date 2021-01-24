/**
 * Copyright (c) 2021 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>

#include "pico/stdlib.h"
#include "hardware/flash.h"

// RP2040 does not have a unique on-board ID, but this is a standard feature
// on the NOR flash it boots from. There is a 1:1 association between RP2040
// and the flash, so this can be used to get a 64 bit globally unique board ID
// for an RP2040-based board, including Pico.

int main() {
    stdio_init_all();

    uint8_t unique_id_bytes[FLASH_UNIQUE_ID_SIZE_BYTES];
    flash_get_unique_id(unique_id_bytes);

    printf("Unique identifier:");
    for (int i = 0; i < FLASH_UNIQUE_ID_SIZE_BYTES; ++i) {
        printf(" %02x", unique_id_bytes[i]);
    }
    printf("\n");
}
