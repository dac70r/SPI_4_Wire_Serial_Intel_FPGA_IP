/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'NIOS' in SOPC Builder design 'spi_platform_designer'
 * SOPC Builder design path: c:/Users/guan-ming.dennis-won/Documents/Code/SPI_4_Wire_Serial_Intel_FPGA_IP/spi_platform_designer.sopcinfo
 *
 * Generated: Wed Apr 30 12:45:06 SGT 2025
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_gen2"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x00040820
#define ALT_CPU_CPU_ARCH_NIOS2_R1
#define ALT_CPU_CPU_FREQ 50000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "tiny"
#define ALT_CPU_DATA_ADDR_WIDTH 0x13
#define ALT_CPU_DCACHE_LINE_SIZE 0
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_DCACHE_SIZE 0
#define ALT_CPU_EXCEPTION_ADDR 0x00020020
#define ALT_CPU_FLASH_ACCELERATOR_LINES 0
#define ALT_CPU_FLASH_ACCELERATOR_LINE_SIZE 0
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 50000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 0
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 0
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_ICACHE_SIZE 0
#define ALT_CPU_INST_ADDR_WIDTH 0x13
#define ALT_CPU_NAME "NIOS"
#define ALT_CPU_OCI_VERSION 1
#define ALT_CPU_RESET_ADDR 0x00020000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x00040820
#define NIOS2_CPU_ARCH_NIOS2_R1
#define NIOS2_CPU_FREQ 50000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "tiny"
#define NIOS2_DATA_ADDR_WIDTH 0x13
#define NIOS2_DCACHE_LINE_SIZE 0
#define NIOS2_DCACHE_LINE_SIZE_LOG2 0
#define NIOS2_DCACHE_SIZE 0
#define NIOS2_EXCEPTION_ADDR 0x00020020
#define NIOS2_FLASH_ACCELERATOR_LINES 0
#define NIOS2_FLASH_ACCELERATOR_LINE_SIZE 0
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 0
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 0
#define NIOS2_ICACHE_LINE_SIZE_LOG2 0
#define NIOS2_ICACHE_SIZE 0
#define NIOS2_INST_ADDR_WIDTH 0x13
#define NIOS2_OCI_VERSION 1
#define NIOS2_RESET_ADDR 0x00020000


/*
 * DEBUG configuration
 *
 */

#define ALT_MODULE_CLASS_DEBUG altera_avalon_jtag_uart
#define DEBUG_BASE 0x41058
#define DEBUG_IRQ 1
#define DEBUG_IRQ_INTERRUPT_CONTROLLER_ID 0
#define DEBUG_NAME "/dev/DEBUG"
#define DEBUG_READ_DEPTH 64
#define DEBUG_READ_THRESHOLD 8
#define DEBUG_SPAN 8
#define DEBUG_TYPE "altera_avalon_jtag_uart"
#define DEBUG_WRITE_DEPTH 64
#define DEBUG_WRITE_THRESHOLD 8


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_PIO
#define __ALTERA_AVALON_SPI
#define __ALTERA_AVALON_SYSID_QSYS
#define __ALTERA_NIOS2_GEN2


/*
 * ESC_EEPDONE_INPUT configuration
 *
 */

#define ALT_MODULE_CLASS_ESC_EEPDONE_INPUT altera_avalon_pio
#define ESC_EEPDONE_INPUT_BASE 0x41030
#define ESC_EEPDONE_INPUT_BIT_CLEARING_EDGE_REGISTER 0
#define ESC_EEPDONE_INPUT_BIT_MODIFYING_OUTPUT_REGISTER 0
#define ESC_EEPDONE_INPUT_CAPTURE 0
#define ESC_EEPDONE_INPUT_DATA_WIDTH 1
#define ESC_EEPDONE_INPUT_DO_TEST_BENCH_WIRING 0
#define ESC_EEPDONE_INPUT_DRIVEN_SIM_VALUE 0
#define ESC_EEPDONE_INPUT_EDGE_TYPE "NONE"
#define ESC_EEPDONE_INPUT_FREQ 50000000
#define ESC_EEPDONE_INPUT_HAS_IN 1
#define ESC_EEPDONE_INPUT_HAS_OUT 0
#define ESC_EEPDONE_INPUT_HAS_TRI 0
#define ESC_EEPDONE_INPUT_IRQ -1
#define ESC_EEPDONE_INPUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ESC_EEPDONE_INPUT_IRQ_TYPE "NONE"
#define ESC_EEPDONE_INPUT_NAME "/dev/ESC_EEPDONE_INPUT"
#define ESC_EEPDONE_INPUT_RESET_VALUE 0
#define ESC_EEPDONE_INPUT_SPAN 16
#define ESC_EEPDONE_INPUT_TYPE "altera_avalon_pio"


/*
 * ESC_SPI configuration
 *
 */

#define ALT_MODULE_CLASS_ESC_SPI altera_avalon_spi
#define ESC_SPI_BASE 0x41000
#define ESC_SPI_CLOCKMULT 1
#define ESC_SPI_CLOCKPHASE 1
#define ESC_SPI_CLOCKPOLARITY 1
#define ESC_SPI_CLOCKUNITS "Hz"
#define ESC_SPI_DATABITS 8
#define ESC_SPI_DATAWIDTH 16
#define ESC_SPI_DELAYMULT "1.0E-9"
#define ESC_SPI_DELAYUNITS "ns"
#define ESC_SPI_EXTRADELAY 0
#define ESC_SPI_INSERT_SYNC 0
#define ESC_SPI_IRQ 0
#define ESC_SPI_IRQ_INTERRUPT_CONTROLLER_ID 0
#define ESC_SPI_ISMASTER 1
#define ESC_SPI_LSBFIRST 0
#define ESC_SPI_NAME "/dev/ESC_SPI"
#define ESC_SPI_NUMSLAVES 1
#define ESC_SPI_PREFIX "spi_"
#define ESC_SPI_SPAN 32
#define ESC_SPI_SYNC_REG_DEPTH 2
#define ESC_SPI_TARGETCLOCK 5000000u
#define ESC_SPI_TARGETSSDELAY "0.0"
#define ESC_SPI_TYPE "altera_avalon_spi"


/*
 * ESC_SPI_CS configuration
 *
 */

#define ALT_MODULE_CLASS_ESC_SPI_CS altera_avalon_pio
#define ESC_SPI_CS_BASE 0x41040
#define ESC_SPI_CS_BIT_CLEARING_EDGE_REGISTER 0
#define ESC_SPI_CS_BIT_MODIFYING_OUTPUT_REGISTER 0
#define ESC_SPI_CS_CAPTURE 0
#define ESC_SPI_CS_DATA_WIDTH 1
#define ESC_SPI_CS_DO_TEST_BENCH_WIRING 0
#define ESC_SPI_CS_DRIVEN_SIM_VALUE 0
#define ESC_SPI_CS_EDGE_TYPE "NONE"
#define ESC_SPI_CS_FREQ 50000000
#define ESC_SPI_CS_HAS_IN 0
#define ESC_SPI_CS_HAS_OUT 1
#define ESC_SPI_CS_HAS_TRI 0
#define ESC_SPI_CS_IRQ -1
#define ESC_SPI_CS_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ESC_SPI_CS_IRQ_TYPE "NONE"
#define ESC_SPI_CS_NAME "/dev/ESC_SPI_CS"
#define ESC_SPI_CS_RESET_VALUE 1
#define ESC_SPI_CS_SPAN 16
#define ESC_SPI_CS_TYPE "altera_avalon_pio"


/*
 * LED configuration
 *
 */

#define ALT_MODULE_CLASS_LED altera_avalon_pio
#define LED_BASE 0x41020
#define LED_BIT_CLEARING_EDGE_REGISTER 0
#define LED_BIT_MODIFYING_OUTPUT_REGISTER 0
#define LED_CAPTURE 0
#define LED_DATA_WIDTH 1
#define LED_DO_TEST_BENCH_WIRING 0
#define LED_DRIVEN_SIM_VALUE 0
#define LED_EDGE_TYPE "NONE"
#define LED_FREQ 50000000
#define LED_HAS_IN 0
#define LED_HAS_OUT 1
#define LED_HAS_TRI 0
#define LED_IRQ -1
#define LED_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LED_IRQ_TYPE "NONE"
#define LED_NAME "/dev/LED"
#define LED_RESET_VALUE 0
#define LED_SPAN 16
#define LED_TYPE "altera_avalon_pio"


/*
 * RAM configuration
 *
 */

#define ALT_MODULE_CLASS_RAM altera_avalon_onchip_memory2
#define RAM_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define RAM_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define RAM_BASE 0x20000
#define RAM_CONTENTS_INFO ""
#define RAM_DUAL_PORT 0
#define RAM_GUI_RAM_BLOCK_TYPE "AUTO"
#define RAM_INIT_CONTENTS_FILE "spi_platform_designer_RAM"
#define RAM_INIT_MEM_CONTENT 1
#define RAM_INSTANCE_ID "NONE"
#define RAM_IRQ -1
#define RAM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define RAM_NAME "/dev/RAM"
#define RAM_NON_DEFAULT_INIT_FILE_ENABLED 1
#define RAM_RAM_BLOCK_TYPE "AUTO"
#define RAM_READ_DURING_WRITE_MODE "DONT_CARE"
#define RAM_SINGLE_CLOCK_OP 0
#define RAM_SIZE_MULTIPLE 1
#define RAM_SIZE_VALUE 81920
#define RAM_SPAN 81920
#define RAM_TYPE "altera_avalon_onchip_memory2"
#define RAM_WRITABLE 1


/*
 * SYSID configuration
 *
 */

#define ALT_MODULE_CLASS_SYSID altera_avalon_sysid_qsys
#define SYSID_BASE 0x41050
#define SYSID_ID 39011
#define SYSID_IRQ -1
#define SYSID_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SYSID_NAME "/dev/SYSID"
#define SYSID_SPAN 8
#define SYSID_TIMESTAMP 1745988059
#define SYSID_TYPE "altera_avalon_sysid_qsys"


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Cyclone 10 LP"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/DEBUG"
#define ALT_STDERR_BASE 0x41058
#define ALT_STDERR_DEV DEBUG
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/DEBUG"
#define ALT_STDIN_BASE 0x41058
#define ALT_STDIN_DEV DEBUG
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/DEBUG"
#define ALT_STDOUT_BASE 0x41058
#define ALT_STDOUT_DEV DEBUG
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "spi_platform_designer"
#define ALT_SYS_CLK_TICKS_PER_SEC NONE_TICKS_PER_SEC
#define ALT_TIMESTAMP_CLK_TIMER_DEVICE_TYPE NONE_TIMER_DEVICE_TYPE


/*
 * hal configuration
 *
 */

#define ALT_INCLUDE_INSTRUCTION_RELATED_EXCEPTION_API
#define ALT_MAX_FD 4
#define ALT_SYS_CLK none
#define ALT_TIMESTAMP_CLK none

#endif /* __SYSTEM_H_ */
