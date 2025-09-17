/*
 * encrypt_and_integrity.h
 *
 *  Created on: 12 sep. 2025
 *      Author: grtre
 */


#ifndef ENCRYPT_AND_INTEGRITY_H_
#define ENCRYPT_AND_INTEGRITY_H_

#include <stdint.h>
#include <stddef.h>
#include "encrypt_and_integrity_cfg.h"
#define CHONKS_SIZE 64



/*
 * Init functions declaration
 * */
//void encrypt_and_integrity_init(struct AES_ctx* ctx);



/*
 * Sender Functions and related
 * */

void encrypt_and_integrity_send(void* message, uint32_t len);
void encrypt_and_integrity_ENET_TX(uint8_t* payload, uint32_t payload_len);
/*
 * Receiver Functions and related
 *
 * */

bool encrypt_and_integrity_receive();
void encrypt_and_integrity_PHY_INIT();


#endif /* ENCRYPT_AND_INTEGRITY_H_ */
