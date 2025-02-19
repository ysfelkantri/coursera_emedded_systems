#******************************************************************************
# Copyright (C) 2020 by EL KANTRI Youssef - ENSA of Fez
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. EL KANTRI Youssef is not liable for any
# misuse of this material. 
#
#*****************************************************************************

# Add your Source files to this variable
INCLUDES =
SOURCES = 

ifeq ($(PLATFORM),HOST)
SOURCES = src/main.c src/memory.c src/data.c src/stats.c src/course1.c
INCLUDES = -Iinclude/common
#$(info $$var is [${INCLUDES}])
else
SOURCES = $(wildcard src/*)
# Add your include paths to this variable
INC = $(wildcard include/*)
INCLUDES = $(addprefix -I,$(INC))
$(info $$var is [${INCLUDES}])
endif

