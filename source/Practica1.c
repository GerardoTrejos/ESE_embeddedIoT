/*
 * Copyright 2016-2025 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file    Practica1.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "fsl_debug_console.h"

//* Define Messages Macros **//
#define  M1 "No todo lo que es oro reluce..."
#define  M2 "Aún en la oscuridad..."
#define  M3 "¿Qué es la vida?"
#define  M4 "No temas a la oscuridad..."
#define  M5 "Hasta los más pequeños..."
#define  M6 "No digas que el sol se ha puesto..."
#define  M7 "El coraje se encuentra..."
#define  M8 "No todos los tesoros..."

#define  M9  "Es peligroso..."
#define  M10 "Un mago nunca llega tarde..."
#define  M11 "Aún hay esperanza..."
#define  M12 "El mundo está cambiando..."
#define  M13 "Las raíces profundas..."
#define  M14 "No se puede..."
#define  M15 "Y sobre todo..."
#define  M18 "De las cenizas, un fuego..."

#define R1 "...Ni todos los que vagan están perdidos."
#define R2 "...brilla una luz."
#define R3 "Nada más que un breve caminar a la luz del sol."
#define R4 "...pues en ella se esconden las estrellas."
#define R5 "...pueden cambiar el curso del futuro."
#define R6 "...si aún te queda la luna."
#define R7 "...en los lugares más inesperados."
#define R8 "...son oro y plata."

#define R9 "...cruzar tu puerta."
#define R10 "...ni pronto, Frodo Bolsón. Llega precisamente cuando se lo propone."
#define R11 "...mientras la Compañía permanezca fiel."
#define R12 "...Siento que algo se avecina."
#define R13 "...no alcanzan las heladas."
#define R14 "...pasar."
#define R15 "...cuidado con el Anillo."
#define R16 "...se despertará."

/*   END of Messages*/






/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */

/*
 * @brief   Application entry point.
 */
int main(void) {

    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif






    PRINTF("Hello World\r\n");

    /* Force the counter to be placed into memory. */
    volatile static int i = 0 ;
    /* Enter an infinite loop, just incrementing a counter. */
    while(1) {
        i++ ;
        /* 'Dummy' NOP to allow source level single stepping of
            tight while() loop */
        __asm volatile ("nop");
    }
    return 0 ;
}
