/*
 * CRC16.c
 *
 *  Created on: Aug 25, 2024
 *      Author: Bania
 */

#include "CRC16.h"

uint16_t CRC16(uint8_t *frame, uint8_t length)
{
	uint16_t crc16 = 0xFFFF;

	for(uint8_t i = 0; i < length; i++)
	{
		crc16 = crc16 ^ frame[i];

		for(uint8_t j = 1; j <= 8; j++)
		{
			if((crc16 & 0x0001) != 0)
			{
				crc16 >>= 1;
				crc16 ^= 0xA001;
			}
			else
			{
				crc16 >>= 1;
			}
		}
	}

    return crc16;
}
