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

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

TARGET = c1m2

# Platform Overrides -DMSP432 or -DHOST
ifeq ($(PLATFORM),HOST)
	# Compile Defines
	CC = gcc
	DUMP = objdump
	SIZE = size
	LDFLAGS = -Wl,-Map=$(TARGET).map 
	CFLAGS = -Wall -Werror -g -O0  -std=c99
else	
	# Architecture Specific Flags //done
	CPU = cortex-m4
	ARCH = -mthumb -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16
	SPECS = nosys.specs 

	# Compile Defines
	CC = arm-none-eabi-gcc
	DUMP = arm-none-eabi-objdump
	SIZE = arm-none-eabi-size
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
	CFLAGS = -mcpu=$(CPU) $(ARCH) --specs=$(SPECS) -Wall -Werror -g -O0 -std=c99
	# Platform Specific Flags //done but the path 
	LINKER_FILE = ../msp432p401r.lds
endif
#arm-none-eabi-gcc -I../include/common -I../include/msp432 -I../include/CMSIS -c sys* -mcpu=cortex-m4 -mthumb -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=nosys.specs -Wall -Werror -g -O0 -std=c99 -o sys.o -DMSP432



# obj file generation
OBJS = $(SOURCES:.c=.o)

%.i : %.c 
	$(CC) $(INCLUDES) -E $< $(CFLAGS) -o $@ -D$(PLATFORM)

%.s : %.c
	$(CC) $(INCLUDES) -S $< $(CFLAGS) -D$(PLATFORM)

%.asm : %.o
	$(DUMP) -S $< > $@

.PHONY: compile-all
compile-all: $(OBJS)

%.o : %.c 
	$(CC) $(INCLUDES) -MM $< > $(patsubst %.c,%.dep,$<) -D$(PLATFORM) 
	$(CC) $(INCLUDES) -c $< $(CFLAGS) -o $@ -D$(PLATFORM) 
	
	
.PHONY: build
build: all
	$(SIZE) -Btd $(TARGET).out 
	$(SIZE) -Bx $(TARGET).out 
	$(SIZE) -Ad $(TARGET).out 

.PHONY: all
all: $(TARGET).out

$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET).out $(TARGET).map *.s *.i *.asm *.dep

