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
 * @file main.c
 * @brief Main entry point to the C1M2 Assessment
 *
 * This file contains the main code for the C1M2 assesment. Students
 * are not to change any of the code, they are instead supposed to compile
 * these files with their makefile.
 *
 * @author EL KANTRI Youssef
 * @date May 5, 2020
 * 
 */
#include "platform.h"
#include "memory.h"
#include "course1.h"


int main(void) {
#ifdef COURSE1
  course1();
#endif
  return 0;
}

