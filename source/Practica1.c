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
#include "encrypt_and_integrity.h"
#include "encrypt_and_integrity_cfg.h"
#include "aes.h"
//#define CHONKS_SIZE 148

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



#ifndef MAC_ADDRESS
#define MAC_ADDRESS {0xd4, 0xbe, 0xd9, 0x45, 0x22, 0x60}
#define MAC_DEST  {0x40, 0xc2. 0xba, 0x39, 0xd0, 0xee}
#endif



/*
 * @brief   Application entry point.
 */
int main(void) {

    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
    BOARD_InitDebugConsole();

    encrypt_and_integrity_PHY_INIT();

    /* Get default configuration. */
    /*
     * config.miiMode = kENET_RmiiMode;
     * config.miiSpeed = kENET_MiiSpeed100M;
     * config.miiDuplex = kENET_MiiFullDuplex;
     * config.rxMaxFrameLen = ENET_FRAME_MAX_FRAMELEN;
     */



   /* uint8_t choice;

        while (1) {
            printf("\n=== Main Menu Select a Message to Send===\n");
            printf("1: %s\n", M1);
            printf("2: %s\n", M2);
            printf("3: %s\n", M3);
            printf("4: %s\n", M4);


            printf("Enter your choice (): ");
            scanf("%d", &choice);

            switch (choice) {
                       case 1:
                    	   printf("Adding record...\n");
                       	   break;
                       case 2:
                    	   printf("Deleting record...\n"); break;
                       case 3:  printf("Updating record...\n"); break;
                       case 4:  printf("Viewing record...\n"); break;
                       case 5:  printf("Searching record...\n"); break;
                       case 6:  printf("Sorting records...\n"); break;
                       case 7:  printf("Exporting to CSV...\n"); break;
                       case 8:  printf("Importing from CSV...\n"); break;
                       case 9:  printf("Backing up database...\n"); break;
                       case 10: printf("Restoring database...\n"); break;
                       case 11: printf("Generating report...\n"); break;
                       case 12: printf("Emailing report...\n"); break;
                       case 13: printf("Printing report...\n"); break;
                       case 14: printf("Changing settings...\n"); break;
                       case 15: printf("Viewing logs...\n"); break;
                       case 16: printf("Displaying help...\n"); break;
                       default:
                    	   printf("Invalid choice. Please enter a number between 1 and 10.\n");
            }
        }*/



     //if(encrypt_and_integrity_receive())
      /// si no recibo puedo mandar ////


    uint8_t* message  = M1;
    encrypt_and_integrity_send(message, (uint32_t)strlen(message));





    return 0 ;
}
