/*
 * encrypt_and_integrity.c
 *
 *  Created on: 12 sep. 2025
 *      Author: grtre
 */


#include "encrypt_and_integrity.h"
#include "encrypt_and_integrity_cfg.h"


/*
 *encrypt_and_integiryt_init() API designed to start all services that are needed for the practice
 * for example the initialization for Ethernet.
 *
 * */

void encrypt_and_integrity_init()
{


}


/*
 * encript_and_integrity_send() API designed to
 *  1) Receive the String from Main APP
 *  2) Encrypt it packaging it  using aes 128.
 *  3) Send it over enet
 * */
void encrypt_and_integrity_send()
{
}


/*
 * encrypt_and_integrity_receive() API designed to
 *  1)Receive over enet.
 *  2)Decrypt using aes128
 *  3)Verify integrity using crc
 *  4)Expose to main APP the package.
 *
 *
 *
 * */

void encrypt_and_integrity_receive()
{


}
