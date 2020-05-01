/******************************************************************************
 * Copyright (C) 2017 by EL KANTRI Youssef - ENSA of Fez, Morocco
 *
 *****************************************************************************/
/**
 * @file stats.h
 * @brief headr file for declarations and documentation for the functions from the stats.c
 * @author Youssef EL KANTRI
 * @date 16/04/2020
 *
 */
#ifndef __STATS_H__
#define __STATS_H__


/**
 * @brief returns the median value
 *
 * this function take as an input an unsigned char pointer to the array
 * and an unsigned int as the size of the array, this will calculate the
 * median value by sorting descendent a dynamic allocated array that
 * contains values of the test array in parameters, to not modify the
 * parameter of test array itself, and we will make conditions on the
 * array size because to calculate median we need to know the parity of
 * size (odd or even) , it will return an unsigned char as the median of
 * sorted array  
 *
 * @param test the unsigned char pointer to the array of values 
 * @param size_of_array the unsigned int variable containing length of array 
 *
 * @return the median value of the values of array 
 */
unsigned char find_median(unsigned char* test, unsigned int size_of_array);


/**
 * @brief returns the mean value
 *
 * this function take as an input an unsigned char pointer to the array
 * and an unsigned int as the length of the array, this will calculate the
 * mean value by calculating the sum of values of the array and divide its
 * by the length , it will return an unsigned char as the mean of
 * sorted array
 *
 * @param test the unsigned char pointer to the array of values 
 * @param size_of_array the unsigned int variable containing length of array 
 *
 * @return the mean value of the values of array 
 */
unsigned char find_mean(unsigned char* test, unsigned int size_of_array);


/**
 * @brief returns the maximum value
 *
 * this function take as an input an unsigned char pointer to the array
 * and an unsigned int as the length of the array, this will calculate the
 * maximum value of the array, it will return an unsigned char as the mean
 * of sorted array
 *
 * @param test the unsigned char pointer to the array of values 
 * @param size_of_array the unsigned int variable containing length of array 
 *
 * @return the maximum value of the values of array 
 */ 
unsigned char find_maximum(unsigned char* test, unsigned int size_of_array);


/**
 * @brief returns the minimum value
 *
 * this function take as an input an unsigned char pointer to the array
 * and an unsigned int as the length of the array, this will calculate the
 * minimum value of the array, it will returnan unsigned char as the mean 
 * of sorted array
 *
 * @param test the unsigned char pointer to the array of values 
 * @param size_of_array the unsigned int variable containing length of array 
 *
 * @return the minimum value of the values of array 
 */ 
unsigned char find_minimum(unsigned char* test, unsigned int size_of_array);


/**
 * @brief sorts the array from largest to smallest 
 *
 * this function take as an input an unsigned char pointer to the array
 * and an unsigned int as the length of the array, this will sort the 
 * given array from largest to smallest: (The zeroth Element is the 
 * largest value, and the last element (n-1) is the smallest value.)
 * using the bubble sort algorithm
 *
 * @param test the unsigned char pointer to the array of values 
 * @param size_of_array the unsigned int variable containing length of array 
 */
void sort_array(unsigned char* test, unsigned int size_of_array);


/**
 * @brief prints the statistics of an array including minimum, maximum, mean, and median
 *
 * this function take as an input an unsigned char pointer to the array
 * and an unsigned int as the length of the array, this will show the 
 * statistics of an array including minimum, maximum, mean, and median
 * by calling functions included in this header file .
 *
 * @param test the unsigned char pointer to the array of values 
 * @param size_of_array the unsigned int variable containing length of array 
 */
void print_statistics(unsigned char* test, unsigned int size_of_array);


/**
 * @brief prints the array to the screen
 *
 * this function take as an input an unsigned char pointer to the array
 * and an unsigned int as the length of the array, this will show the values 
 * of the given array for all indexes  
 *
 * @param test the unsigned char pointer to the array of values 
 * @param size_of_array the unsigned int variable containing length of array 
 */
void print_array(unsigned char* test, unsigned int size_of_array);


#endif /* __STATS_H__ */
