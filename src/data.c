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

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h> 
#include "data.h"
#include "memory.h"

// Implementation of itoa() 
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{ 
	//ptr = (uint8_t *) malloc(sizeof(char)*32);
    uint8_t i = 0; 
    bool isNegative = false; 
  
    // Handle 0 explicitely, otherwise empty ptring is printed for 0 
    if (data == 0) 
    { 
        *(ptr + i++) = '0'; 
        *(ptr + i) = '\0'; 
        return i+1; 
    } 
  
    // In standard itoa(), negative numbers are handled only with  
    // base 10. Otherwise numbers are considered unsigned. 
    if (data < 0 && base == 10) 
    { 
        isNegative = true; 
        data = -data; 
    } 
  
    // Process individual digits 
    while (data != 0) 
    { 
        int rem = data % base; 
        *(ptr + i++) = (rem > 9)? (rem-10) + 'A' : rem + '0'; 
        data = data/base; 
    } 
  
    // If number is negative, append '-' 
    if (isNegative) 
        *(ptr + i++) = '-'; 
  
    *(ptr + i) = '\0'; // Append null terminator 
  
    // Reverse the pointering
    ptr = my_reverse(ptr, i);
  
	// return the length of data converted + signe + null terminator  
    return (i<=34)? i+1 : -1	; 
} 

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){ 
   
	int32_t res = 0; // Initialize result 
  
    // Iterate through all characters of input string and 
    // update result 
	
    for (int i = 0; *(ptr + i) != '\0'; ++i){ 
        res = (res * base) + *(ptr + i) - ((*(ptr + i)>'9')? '7' : '0'); 
	} 
    // return result. 
    return res; 
} 
