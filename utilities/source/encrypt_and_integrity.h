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

#define MAX_MSG 1488
#define MAC_SIZE 6

#define  MAX_PCKG_SIZE  MAC_SIZE + MAC_SIZE + MAX_MSG

/*
 * Init functions declaration
 * */
//void encrypt_and_integrity_init(struct AES_ctx* ctx);



/*
 * Sender Functions and related
 * */

void encrypt_and_integrity_send(const uint8_t* message, uint32_t len);
void encrypt_and_integrity_ENET_TX(uint8_t* payload, uint32_t payload_len);
/*
 * Receiver Functions and related
 *
 * */
status_t encrypt_and_integrity_receive();
status_t encrypt_and_integrity_INIT();
void encrypt_and_integrity_decrypt(const uint8_t *data, uint32_t length);

#endif /* ENCRYPT_AND_INTEGRITY_H_ */
