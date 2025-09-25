/*
 * encrypt_and_integrity.c
 *
 *  Created on: 12 sep. 2025
 *      Author: grtre
 */

 #include <string.h>
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

#include "aes.h"
#include <security.h>
#include "security_cfg.h"
/*FROM ENET EXAMPLE
 *

 *
 * */


#include "fsl_phy.h"
#if defined(FSL_FEATURE_MEMORY_HAS_ADDRESS_OFFSET) && FSL_FEATURE_MEMORY_HAS_ADDRESS_OFFSET
#include "fsl_memory.h"
#endif
#include "fsl_enet.h"
#include "fsl_enet_mdio.h"
#include "fsl_phyksz8081.h"
#include "fsl_common.h"
#include "fsl_sysmpu.h"
#include "fsl_enet_mdio.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* ENET base address */
#define EXAMPLE_ENET        ENET
#define EXAMPLE_PHY_ADDRESS 0x00U

/* MDIO operations. */
#define EXAMPLE_MDIO_OPS enet_ops
/* PHY operations. */
#define EXAMPLE_PHY_OPS phyksz8081_ops
/* ENET clock frequency. */
#define EXAMPLE_CLOCK_FREQ CLOCK_GetFreq(kCLOCK_CoreSysClk)
#define ENET_RXBD_NUM          (4)
#define ENET_TXBD_NUM          (4)
#define ENET_RXBUFF_SIZE       (ENET_FRAME_MAX_FRAMELEN)
#define ENET_TXBUFF_SIZE       (ENET_FRAME_MAX_FRAMELEN)
#define ENET_DATA_LENGTH       (1000)
#define ENET_TRANSMIT_DATA_NUM (20)
#ifndef APP_ENET_BUFF_ALIGNMENT
#define APP_ENET_BUFF_ALIGNMENT ENET_BUFF_ALIGNMENT
#endif
#ifndef PHY_AUTONEGO_TIMEOUT_COUNT
#define PHY_AUTONEGO_TIMEOUT_COUNT (100000)
#endif
#ifndef PHY_STABILITY_DELAY_US
#define PHY_STABILITY_DELAY_US (0U)
#endif

/* @TEST_ANCHOR */
//#define MAC_K64

#define MAX_MSG 1488
#define ENET_DATA_LENGTH       (1000)
#define MINIMUM_ENET_LEN 64


#define MAC_K64 {0xd4, 0xbe, 0xd9, 0x45, 0x22, 0x60}
#define MAC_PC  {0x40, 0xc2, 0xba, 0x39, 0xd0, 0xee}




//const uint8_t  key_cfg[] = { 0x60, 0x3d, 0xeb, 0x10, 0x15, 0xca, 0x71, 0xbe, 0x2b, 0x73, 0xae, 0xf0, 0x85, 0x7d, 0x77,
//				 0x81, 0x1f, 0x35, 0x2c, 0x07, 0x3b, 0x61, 0x08, 0xd7, 0x2d, 0x98, 0x10, 0xa3, 0x09, 0x14,
//				 0xdf, 0xf4};

//const uint8_t iv_cfg[]  = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e,
//				  0x0f };



/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! @brief Buffer descriptors should be in non-cacheable region and should be align to "ENET_BUFF_ALIGNMENT". */
AT_NONCACHEABLE_SECTION_ALIGN(enet_rx_bd_struct_t g_rxBuffDescrip[ENET_RXBD_NUM], ENET_BUFF_ALIGNMENT);
AT_NONCACHEABLE_SECTION_ALIGN(enet_tx_bd_struct_t g_txBuffDescrip[ENET_TXBD_NUM], ENET_BUFF_ALIGNMENT);
/*! @brief The data buffers can be in cacheable region or in non-cacheable region.
 * If use cacheable region, the alignment size should be the maximum size of "CACHE LINE SIZE" and "ENET_BUFF_ALIGNMENT"
 * If use non-cache region, the alignment size is the "ENET_BUFF_ALIGNMENT".
 */
SDK_ALIGN(uint8_t g_rxDataBuff[ENET_RXBD_NUM][SDK_SIZEALIGN(ENET_RXBUFF_SIZE, APP_ENET_BUFF_ALIGNMENT)],
          APP_ENET_BUFF_ALIGNMENT);
SDK_ALIGN(uint8_t g_txDataBuff[ENET_TXBD_NUM][SDK_SIZEALIGN(ENET_TXBUFF_SIZE, APP_ENET_BUFF_ALIGNMENT)],
          APP_ENET_BUFF_ALIGNMENT);

enet_handle_t g_handle;


/*! @brief The MAC address for ENET device. */
uint8_t g_macAddr[6] = MAC_K64;

/*! @brief Enet PHY and MDIO interface handler. */
static mdio_handle_t mdioHandle = {.ops = &EXAMPLE_MDIO_OPS};
static phy_handle_t phyHandle   = {.phyAddr = EXAMPLE_PHY_ADDRESS, .mdioHandle = &mdioHandle, .ops = &EXAMPLE_PHY_OPS};


//GLOBAL Variables for the project
bool link = false;
bool autonego = false;
phy_speed_t speed;
phy_duplex_t duplex;



/*
 *encrypt_and_integryt_init() API designed to start all services that are needed for the practice
 * for example the initialization for Ethernet.
 *
 * */

/*void encrypt_and_integrity_init(struct AES_ctx* ctx)
{
}
*/
status_t security_ENET_INIT()
{
    enet_config_t config;
    phy_config_t phyConfig = {0};
    volatile uint32_t count = 0;
    status_t status;

    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
  //  BOARD_InitBootPeripherals();
    BOARD_InitDebugConsole();
    /* Disable SYSMPU. */
    SYSMPU_Enable(SYSMPU, false);

    PRINTF("\r\nENET example Start");

    /* Prepare the buffer configuration. */
    enet_buffer_config_t buffConfig[] = {{
        ENET_RXBD_NUM,
        ENET_TXBD_NUM,
        SDK_SIZEALIGN(ENET_RXBUFF_SIZE, APP_ENET_BUFF_ALIGNMENT),
        SDK_SIZEALIGN(ENET_TXBUFF_SIZE, APP_ENET_BUFF_ALIGNMENT),
        &g_rxBuffDescrip[0],
        &g_txBuffDescrip[0],
        &g_rxDataBuff[0][0],
        &g_txDataBuff[0][0],
        true,
        true,
        NULL,
    }};

    ENET_GetDefaultConfig(&config);


#ifdef EXAMPLE_PHY_INTERFACE_RGMII
    config.miiMode = kENET_RgmiiMode;
#else
    config.miiMode = kENET_RmiiMode;
#endif

    phyConfig.phyAddr               = EXAMPLE_PHY_ADDRESS;
    phyConfig.autoNeg               = true;
    mdioHandle.resource.base        = EXAMPLE_ENET;
    mdioHandle.resource.csrClock_Hz = EXAMPLE_CLOCK_FREQ;

       /* Initialize PHY and wait auto-negotiation over. */
    PRINTF("Wait for PHY init...\r\n");
    do
    {
        status = PHY_Init(&phyHandle, &phyConfig);
        if (status == kStatus_Success)
        {
            PRINTF("Wait for PHY link up...\r\n");
            /* Wait for auto-negotiation success and link up */
            count = PHY_AUTONEGO_TIMEOUT_COUNT;
            do
            {
                PHY_GetAutoNegotiationStatus(&phyHandle, &autonego);
                PHY_GetLinkStatus(&phyHandle, &link);
                if (autonego && link)
                {
                    break;
                }
            } while (--count);
            if (!autonego)
            {
                PRINTF("PHY Auto-negotiation failed. Please check the cable connection and link partner setting.\r\n");
            }
        }
    } while (!(link && autonego));

#if PHY_STABILITY_DELAY_US
    /* Wait a moment for PHY status to be stable. */
    SDK_DelayAtLeastUs(PHY_STABILITY_DELAY_US, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
#endif


    PHY_GetLinkSpeedDuplex(&phyHandle, &speed, &duplex);
    /* Change the MII speed and duplex for actual link status. */
    config.miiSpeed  = (enet_mii_speed_t)speed;
    config.miiDuplex = (enet_mii_duplex_t)duplex;

    ENET_Init(EXAMPLE_ENET, &g_handle, &config, &buffConfig[0], &g_macAddr[0], EXAMPLE_CLOCK_FREQ);
    ENET_ActiveRead(EXAMPLE_ENET);

return status;
}







/*
 * encript_and_integrity_send() API designed to
 *  1) Receive the String from Main APP
 *  2) Encrypt it packaging it  using aes 128.
 *  3) Send it over enet
 * */
void security_send(const uint8_t* message, uint32_t len )
{
	uint8_t package [ ENET_DATA_LENGTH -14 ] = {0}  ;
	uint8_t mac_origen[6] = MAC_K64 ;
	uint8_t  mac_dest[6] = MAC_PC;
	uint32_t payload_len;
	struct AES_ctx ctx;

	//// determine padding and adding it to encrypt
	uint8_t  bytes_needed = (16 - (len % 16));
	payload_len = len + bytes_needed;
	uint8_t* encrypted_vector = (uint8_t*)malloc(payload_len);
	memcpy(encrypted_vector, message, len);
 	for (uint8_t i = 0; i < bytes_needed; i++)
	 {
	   encrypted_vector[len + i] = bytes_needed;
	 }

	//*  using AES128 *//

 	PRINTF("%s", message);
	AES_init_ctx_iv(&ctx, KEY_AES, IV_AES);
//	 PRINTF("vector b4 encrypt: %u\r\n", strlen(encrypted_vector));
	AES_CBC_encrypt_buffer(&ctx, encrypted_vector, payload_len);
//	PRINTF("vector justafter encrypt: %u\r\n", strlen(encrypted_vector));

	 /*Creating Package to be sent */
	memcpy(&package,mac_dest, MAC_SIZE);
	memcpy(&package[MAC_SIZE],mac_origen, MAC_SIZE);

	payload_len +14 ;
	package[12] = (payload_len >> 8) & 0xFFU;
	package[13] = payload_len & 0xFFU;
	// package[12] = 0x88;
	// package[13] = 0xB5;

	memcpy(&package[14], encrypted_vector, payload_len );

/*
	 PRINTF("len encrypted vector: %u\r\n", payload_len);
	 PRINTF("len payload full %u\r\n", payload_len);

	 PRINTF("ENET_BuildFrame: payload_len=%u header[12]=0x%02X header[13]=0x%02X\r\n",
	 		   payload_len, package[12], package[13]);
*/
	security_ENET_TX(package, payload_len+14);
	free(encrypted_vector);
}



void security_ENET_TX(uint8_t* payload, uint32_t payload_len)
{
	bool link = false;
	/* Send a multicast frame when the PHY is link up. */
	if (kStatus_Success == PHY_GetLinkStatus(&phyHandle, &link))
	{
		if (link)
		{
			if(( ENET_SendFrame(EXAMPLE_ENET, &g_handle, &payload[0], payload_len, 0, false, NULL)))
			    // PRINTF("Transmitted: \r\n");
			    PRINTF(" \r\nTransmit frame failed!\r\n");
		}
	}

}





/*
 * encrypt_and_integrity_receive() API designed to
 *
 *
 * */

status_t security_receive()
{


	status_t status;
	uint32_t length;
	uint8_t dest[MAC_SIZE] = MAC_K64;
	uint8_t origen[MAC_SIZE] = MAC_PC ;
	enet_data_error_stats_t eErrStatic;
    /* Get the Frame size */
	status = ENET_GetRxFrameSize(&g_handle, &length, 0);
    /* Call ENET_ReadFrame when there is a received frame. */
	if (length != 0)
	{
           // /* Received valid frame. Deliver the rx buffer with the size equal to length.
		uint8_t *data = (uint8_t *)malloc(length);

        status  = ENET_ReadFrame(EXAMPLE_ENET, &g_handle, data, length, 0, NULL);
        if (status == kStatus_Success)
        {

        	if(data[0] == dest[0] && data[1] == dest[1] && data[2] == dest[2] && data[3] == dest[3] &&
        		data[4] == dest[4] && data[5] == dest[5]  )
        		security_decrypt(data, length);
        	else
        	{
        		//PRINTF("NOT MY PACKAGE \n\r");
        		free(data);
        		return kStatus_Fail;
        	}
        }else if (status == kStatus_ENET_RxFrameError)
        {
        	/* Update the received buffer when error happened. */
        	/* Get the error information of the received g_frame.*/
        	ENET_GetRxErrBeforeReadFrame(&g_handle, &eErrStatic, 0);
        	/* update the receive buffer. */
        	ENET_ReadFrame(EXAMPLE_ENET, &g_handle, NULL, 0, 0, NULL);
        	return status = kStatus_Fail;
        }
	}else
		status = kStatus_Fail;

  return status;

}



void security_decrypt(const uint8_t *data, uint32_t length )
{

	uint8_t payload_message =0;
	uint8_t frame_confirmed = 0;
	payload_message += data[12];
	payload_message += data[13];

	uint8_t *load_pckg = (uint8_t *)malloc(payload_message);
	if(!load_pckg)
	{
		PRINTF("FAILED TO INTIALIZE PAY LOAD \r\n");
		free(load_pckg);
	}

	//strcpy(load_pckg, &data[14]);
	/*
	 * commenting strcpy since in response to message 5 there is a 0x00 in 14th which makes
	 * the message does not copy the buffer.
	 * memcpy does not allow to copy from a specific address of source buffer
	 *
	 * */
	for(uint8_t i = 0; i < payload_message  ; i++)
	{
		load_pckg[i] = data[14 + i];
	}

		 // Decrypt in-place
	struct AES_ctx ctx;
	AES_init_ctx_iv(&ctx, KEY_AES, IV_AES);
	AES_CBC_decrypt_buffer(&ctx, load_pckg, payload_message);

		//removing padding PCK#7
	uint8_t padding = load_pckg[payload_message-1];


	load_pckg[payload_message - padding]= '\0';

	PRINTF("  %s\r\n", load_pckg);


}
