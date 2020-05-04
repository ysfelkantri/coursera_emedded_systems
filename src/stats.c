/******************************************************************************
 * Copyright (C) 2020 by EL KANTRI Youssef - ENSA of Fez
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. EL KANTRI Youssef is not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief analyze an array and report analytics on the maximum, minimum, mean, and median of the data set
 * @author Youssef EL KANTRI
 * @date 16/04/2020
 *
 */

#include <stdio.h>
#include "stats.h"
#include <stdlib.h>
#include "platform.h"

/* Size of the Data Set */
#define SIZE (40)

void print_statistics(unsigned char* test, unsigned int size_of_array){
  PRINTF("*****************************************\n");
  PRINTF("*\tmedian  \t : %d \t\t*\n", find_median(test,size_of_array));
  PRINTF("*\tmean    \t : %d \t\t*\n", find_mean(test,size_of_array));
  PRINTF("*\tmaximum \t : %d \t\t*\n", find_maximum(test,size_of_array));
  PRINTF("*\tminimum \t : %d \t\t*\n", find_minimum(test,size_of_array));
  PRINTF("*****************************************\n");
}


void print_array(unsigned char* test, unsigned int size_of_array){
#ifdef VERBOSE
  PRINTF("\tvalues of my array are : \n*****************************************\n");
  for (int i = 0;i<size_of_array;i++)
    PRINTF("*\tvalue at index %d : %d\t\t*\n",i,test[i]);
  PRINTF("*****************************************\n");
#endif
}


unsigned char find_median(unsigned char* test, unsigned int size_of_array){
  unsigned char* sorted_array = (unsigned char*) malloc(sizeof(unsigned char)*size_of_array);
  for (int i = 0; i<size_of_array; i++)
    sorted_array[i] = test[i] ;
  sort_array(sorted_array, size_of_array);
  if (!(size_of_array%2)) //if even 
	return (sorted_array[size_of_array>>1]+sorted_array[(size_of_array+1)>>1])>>1 ;
  else //if odd 
	return (unsigned char) (sorted_array[(size_of_array+1)>>1])>>1 ;
}



unsigned char find_mean(unsigned char* test, unsigned int size_of_array) {
  short int sum =0 ;
  for ( int i = 0; i<size_of_array; i++)
    sum += test[i];
  return (unsigned char)(sum/size_of_array) ;
}


unsigned char find_maximum(unsigned char* test, unsigned int size_of_array) {
  unsigned char max = 0 ;
  for (int j = 0; j<size_of_array; j++)
    if(max < test[j]) 
	  max = test[j] ;
  return (unsigned char) max ;
}


unsigned char find_minimum(unsigned char* test, unsigned int size_of_array) {
  unsigned char min = 255 ;
  for (int j = 0; j<size_of_array; j++)
    if(min > test[j]) 
	  min = test[j] ;
  return (unsigned char) min ;
}


void sort_array(unsigned char* test, unsigned int size_of_array) {
  unsigned char temp = 0 ;
  for (int i = 0; i<size_of_array; i++){
    for (int j = 0; j<size_of_array; j++){
	  if (test[j]<=test[j+1]){
	    temp = test[j];
 		test[j]=test[j+1];
		test[j+1]=temp;
	  }
    }
  }
}

