/******************************************************************************
 * Copyright (C) 2020 EL KANTRI Youssef ENSA of Fez 
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. EL KANTRI Youssef is not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file data.h
 * @brief conversion from standard integer type to ASCII string and vice versa 
 *
 * This header file provides an abstraction of conversion from standard integer type to ASCII string and vice versa . 
 *
 * @author EL KANTRI Youssef 
 * @date may 2020
 *
 */

#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h>

#define BASE_10	(10)
#define BASE_16	(16)

/**
 * @brief convert data from a standard integer type into an ASCII string
 **/
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief convert data back from an ASCII represented string into an 
 **/
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */
