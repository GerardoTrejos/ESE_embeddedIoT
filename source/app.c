/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdlib.h>
#include "pin_mux.h"
#include "board.h"
#include "fsl_debug_console.h"
#include "fsl_enet.h"
#include "fsl_phy.h"
#if defined(FSL_FEATURE_MEMORY_HAS_ADDRESS_OFFSET) && FSL_FEATURE_MEMORY_HAS_ADDRESS_OFFSET
#include "fsl_memory.h"
#endif
#include "fsl_enet_mdio.h"
#include "fsl_phyksz8081.h"
#include "fsl_common.h"
#include "fsl_sysmpu.h"

#include <security.h>
#include <security_cfg.h>

#include <string.h>
/* @TEST_ANCHOR */

#ifndef MAC_ADDRESS
#define MAC_ADDRESS {0xd4, 0xbe, 0xd9, 0x45, 0x22, 0x60}
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*! @brief Build ENET broadcast frame. */
static void ENET_BuildBroadCastFrame(void);


/*******************************************************************************
 * Code
 ******************************************************************************/
/*! @brief Build Frame for transmit. */

/*
static void ENET_BuildBroadCastFrame(void)
{

}*/

/*!
 * @brief Main function
 */
int main(void)
{
	const uint8_t *message = (uint8_t*)malloc(MAX_MSG);
 	const uint8_t *received = (uint8_t*)(sizeof(uint8_t)*MAX_PCKG_SIZE);
	status_t status_phy = encrypt_and_integrity_INIT();
	status_t status;
		if(status_phy != kStatus_Success)
		{
			PRINTF("Phy failed to initialize");
		}



#if PHY_STABILITY_DELAY_US
    /* Wait a moment for PHY status to be stable. */
    SDK_DelayAtLeastUs(PHY_STABILITY_DELAY_US, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
#endif


  	uint32_t len= 0;
	uint8_t repetir = 1;
	PRINTF("Application started");
    do
    {

     //   if(encrypt_and_integrity_receive())
        // {
           //     	PRINTF("Received Message");
       //  }else
        // {
    	PRINTF("\n=== Main Menu Select a Message to Send===\r\n");

    	PRINTF("1: %s\r\n", M1);
    	PRINTF("2: %s\r\n", M2);
    	PRINTF("3: %s\r\n", M3);
    	PRINTF("4: %s\r\n", M4);
    	PRINTF("5: %s\r\n", M5);
    	PRINTF("6: %s\r\n", M6);
    	PRINTF("7: %s\r\n", M7);
    	PRINTF("8: %s\r\n", M8);
       	PRINTF("9: %s\r\n", M9);
       	PRINTF("a: %s\r\n", M10);
        PRINTF("b: %s\r\n", M11);
        PRINTF("c: %s\r\n", M12);
        PRINTF("d: %s\r\n", M13);
        PRINTF("e: %s\r\n", M14);
        PRINTF("f: %s\r\n", M15);
        PRINTF("g: %s\r\n", M16);
        char choice = GETCHAR();

        if (choice == '1') {
            message =  M1;
        } else if (choice == '2') {
           message = M2;
        } else if (choice == '3') {

            message = M3;
        } else if (choice == '4') {

            message= M4;
        } else if (choice == '5') {

        	 message= M5;
        } else if (choice == '6') {

        	 message= M6;
        } else if (choice == '7') {

        	 message= M7;
        } else if (choice == '8') {

        	 message= M8;
        } else if (choice == '9') {

        	 message= M9;
        } else if (choice == 'a') {

        	 message= M10;
        } else if (choice == 'b') {
        	 message= M11;
        } else if (choice == 'c') {
        	 message= M12;
        } else if (choice == 'd') {
        	 message= M13;
        } else if (choice == 'e') {
        	 message= M14;
        } else if (choice == 'f') {
        	 message= M15;
        } else if (choice == 'g') {
        	 message= M16;
        } else {
            PRINTF("Invalid choice. Please enter.\n");
        }

        choice = '\0';


    //  }
        if(message != NULL)
        	encrypt_and_integrity_send(message, strlen(message));
      do{
        status = encrypt_and_integrity_receive();
      }while(status);





        PRINTF("Deseas mandar otro mensaje 1)si 0)no \r\n ");
        repetir = GETCHAR();
        	if(repetir == '0')
        		repetir &=~0xFF;
    }while(repetir);
    PRINTF("Application end \r\n");

}
