/******************************************************************************
 * Copyright (C) 2020 by EL KANTRI Youssef - ENSA of Fez
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. EL KANTRI Youssef is not liable for any
 * misuse of this material. 
 * *****************************************************************************/
/**
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author EL KANTRI Youssef
 * @date May 5, 2020
 *
 */
#include "memory.h"

/***********************************************************
 Function Definitions
***********************************************************/

int32_t * reserve_words(size_t length){
	return (int32_t *) malloc(sizeof(uint32_t)*length) ;
}

void free_words(uint32_t* src){
	free(src);
}

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length){
	uint8_t * temp = (uint8_t *) malloc (sizeof(uint8_t)*length) ;
	// Copy data from temp[] to dst[] 
	for (int i=0; i<length; i++) 
       	*(temp+i) = *(src+i); 
  
    // Copy data from temp[] to dst[] 
   	for (int i=0; i<length; i++) 
       	*(dst+i) = *(temp+i); 
	return dst ;
}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length){
  for (int i = 0; i< length; i++){
		*(dst + i) = *(src + i);
	}
	return dst ;
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value){
	for(int i =0 ;i <length ; i++){
		*(src + i) = value ;
	}
	return src ;
}

uint8_t * my_memzero(uint8_t * src, size_t length){
	for(int i =0 ;i <length ; i++){
		*(src + i) = 0 ;
	}
	return src ;
}

uint8_t * my_reverse(uint8_t * src, size_t length){
	uint8_t temp = 0;
	for(int i = 0; i <length/2; i++){
		temp = *(src + i);
		*(src+i) = *(src + length -1-i) ;
		*(src + length -1-i) = temp ;
	}
	return src ;
}

