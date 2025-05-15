#ifndef PERIPHERAL_LINKER_H
#define PERIPHERAL_LINKER_H

#include "system.h"							// must include otherwise will not work
#include "sys/alt_stdio.h"
#include "alt_types.h"
#include "altera_avalon_pio_regs.h"
//#include "altera_avalon_timer_regs.h"
//#include "altera_avalon_timer.h"
#include "sys/alt_irq.h"
#include "altera_avalon_spi.h"
#include "altera_avalon_spi_regs.h"
#include "stdint.h"
//#include "../imported_source/ax58100_hw.h"

#define SPI_TIMEOUT_MAX 1000000UL  // Adjust depending on expected speed and system clock

// function declaration
void timer_isr(void *context);
void delay_ms(int milliseconds);											// Simple Delay
void adc_init(alt_u32 base, alt_u32 spi_manual_cs);							// Initializes the ADC using Half-Duplex SPI
int spi_transmit_receive(alt_u32 base, alt_u32 slave,						// Self Defined SPI TransmitReceive function
						 const alt_u8 *tx_buf, alt_u8 *rx_buf,
						 alt_u32 length, alt_u32 flags);

void adc_init_spi_transmit_receive(alt_u32 base, alt_u32 spi_manual_cs);	// Initializes the ADC using Full-Duplex SPI
void HAL_TIM_Base_Start_IT(void);											// Initializes Tim16 and Starts
void HAL_TIM_Base_Start(void);												// Initializes Tim6 and Starts
void init_timer_one_sec (void);

#endif // LINKER_H


// Deprecated functions
/*
int spi_command (const alt_u8 * write_data, alt_u32 write_length, alt_u32 read_length, 	// SPI Command
		alt_u8 * read_data );

*/
