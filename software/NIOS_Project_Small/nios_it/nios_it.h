/*
 *  This file contains nios interrupt headers and function/ variable declarations
 *
 *  Author: Dennis Wong Guan Ming
 *
 * */
#ifndef NIOS_IT_H
#define NIOS_IT_H

#include "system.h"
#include "sys\alt_irq.h"
#include "altera_avalon_pio_regs.h"

//ISR declaration
void exti0_isr (void * context);			// Low Level ISR
void init_exti0_it (void);					// Initialize PDI_ISR


//void init_readback_it (void);
//void readback_isr (void * context);

#endif // LINKER_H
