#include "peripheral_linker.h"  // Include the linker header file with peripheral definitions
#include "system.h"
#include "stdint.h"

// Delay function
// No Parameters
void delay_ms(int milliseconds) {
    usleep(milliseconds * 1000);  // Convert to microseconds
}

// ADC Initialization Using Half-Duplex SPI
// Parameter 1: Base address for SPI Base
// Parameter 2: Base address for SPI Chip Select Manual
void adc_init(alt_u32 base, alt_u32 spi_manual_cs){

	int spi_check = -1;
	alt_u8 opcode_null[4] = {0x00,0x00,0x00,0x00};
	alt_u8 opcode_null_receive[4] = {0x01, 0x01, 0x03, 0x04};
	alt_u8 opcode_ready[4] = {0x06, 0x55, 0x00, 0x00};
	alt_u8 opcode_ready_receive[4] = {0x05, 0x06, 0x07, 0x08};
	uint8_t opcode_lock[4] = {0x05, 0x55, 0x00, 0x00};
	uint8_t opcode_lock_receive[4] = {0x00, 0x00, 0x00, 0x00};

	IOWR_ALTERA_AVALON_PIO_DATA(spi_manual_cs, 0b00000000);
	delay_ms(5);
	IOWR_ALTERA_AVALON_PIO_DATA(spi_manual_cs, 0b00000001);
	delay_ms(20);

	spi_check = alt_avalon_spi_command(base,
										0,								// number of slaves
										4,		// number of bytes to send to SPI Slave, '0' if only reading
										opcode_null,				// A pointer to the data buffer that contains the data to be written, 'NULL' if N/A
										0,							// The number of bytes to read from the SPI slave, '0' if only writing
										0,		// A pointer to the buffer where the received (read) data will be stored, 'NULL' if N/A
										0							// Special control flags for the SPI command
										);

	 delay_ms(50);
	 spi_check = alt_avalon_spi_command(base,
										0,							// number of slaves
										0,							// number of bytes to send to SPI Slave, '0' if only reading
										0,							// A pointer to the data buffer that contains the data to be written, 'NULL' if N/A
										4,							// The number of bytes to read from the SPI slave, '0' if only writing
										opcode_null_receive,		// A pointer to the buffer where the received (read) data will be stored, 'NULL' if N/A
										0							// Special control flags for the SPI command
										);

	 spi_check = alt_avalon_spi_command(base,
										0,							// number of slaves
										4,		// number of bytes to send to SPI Slave, '0' if only reading
										opcode_ready,				// A pointer to the data buffer that contains the data to be written, 'NULL' if N/A
										0,							// The number of bytes to read from the SPI slave, '0' if only writing
										0,		// A pointer to the buffer where the received (read) data will be stored, 'NULL' if N/A
										0							// Special control flags for the SPI command
										);

	 delay_ms(50);
	 spi_check = alt_avalon_spi_command(base,
										0,							// number of slaves
										0,							// number of bytes to send to SPI Slave, '0' if only reading
										0,							// A pointer to the data buffer that contains the data to be written, 'NULL' if N/A
										4,							// The number of bytes to read from the SPI slave, '0' if only writing
										opcode_ready_receive,		// A pointer to the buffer where the received (read) data will be stored, 'NULL' if N/A
										0							// Special control flags for the SPI command
										);

	 spi_check = alt_avalon_spi_command(base,
										0,							// number of slaves
										4,		// number of bytes to send to SPI Slave, '0' if only reading
										opcode_lock,				// A pointer to the data buffer that contains the data to be written, 'NULL' if N/A
										0,							// The number of bytes to read from the SPI slave, '0' if only writing
										0,		// A pointer to the buffer where the received (read) data will be stored, 'NULL' if N/A
										0							// Special control flags for the SPI command
										);

	 delay_ms(50);
	 spi_check = alt_avalon_spi_command(base,
										0,							// number of slaves
										0,							// number of bytes to send to SPI Slave, '0' if only reading
										0,							// A pointer to the data buffer that contains the data to be written, 'NULL' if N/A
										4,							// The number of bytes to read from the SPI slave, '0' if only writing
										opcode_lock_receive,		// A pointer to the buffer where the received (read) data will be stored, 'NULL' if N/A
										0							// Special control flags for the SPI command
										);
	 delay_ms(50);
}

// Self-defined SPI TransmitReceive Function (Same as HAL_SPI_TransmitReceive())
// Parameter 1: SPI Base Address
// Parameter 2: The slave that master is communicating to
// Parameter 3: transmit buffer
// Parameter 4: receive buffer
// Parameter 5: Number of bytes to send and receive
// Parameter 6: Flags
int spi_transmit_receive(alt_u32 base, alt_u32 slave,
                                    const alt_u8 *tx_buf, alt_u8 *rx_buf,
                                    alt_u32 length, alt_u32 flags)
{
    alt_u32 status;
    alt_32 credits = 1;
    const alt_u8 *tx_ptr = tx_buf;
    alt_u8 *rx_ptr = rx_buf;
    const alt_u8 *tx_end = tx_buf ? (tx_buf + length) : NULL;
    alt_u8 dummy_tx = 0xFF;

    // 1. Select slave
    IOWR_ALTERA_AVALON_SPI_SLAVE_SEL(base, 1 << slave);

    // 2. Assert CS unless toggle flag is set
    if ((flags & ALT_AVALON_SPI_COMMAND_TOGGLE_SS_N) == 0) {
        IOWR_ALTERA_AVALON_SPI_CONTROL(base, ALTERA_AVALON_SPI_CONTROL_SSO_MSK);
    }

    // 3. Clear stale RX
    IORD_ALTERA_AVALON_SPI_RXDATA(base);

    while ((rx_ptr - rx_buf) < length)
    {
        // Wait for either TX ready or RX ready
        do {
            status = IORD_ALTERA_AVALON_SPI_STATUS(base);
        } while (((status & ALTERA_AVALON_SPI_STATUS_TRDY_MSK) == 0 || credits == 0) &&
                 (status & ALTERA_AVALON_SPI_STATUS_RRDY_MSK) == 0);

        // Transmit if ready
        if ((status & ALTERA_AVALON_SPI_STATUS_TRDY_MSK) && credits > 0) {
            alt_u8 tx_data = tx_ptr ? *tx_ptr++ : dummy_tx;
            IOWR_ALTERA_AVALON_SPI_TXDATA(base, tx_data);
            credits--;
        }

        // Receive if data available
        if ((status & ALTERA_AVALON_SPI_STATUS_RRDY_MSK)) {
            *rx_ptr++ = (alt_u8)IORD_ALTERA_AVALON_SPI_RXDATA(base);
            credits++;
        }
    }

    // Wait until TX FIFO is empty (transmit complete)
    do {
        status = IORD_ALTERA_AVALON_SPI_STATUS(base);
    } while ((status & ALTERA_AVALON_SPI_STATUS_TMT_MSK) == 0);

    // Release chip select unless merging
    if ((flags & ALT_AVALON_SPI_COMMAND_MERGE) == 0) {
        IOWR_ALTERA_AVALON_SPI_CONTROL(base, 0);
    }

    return length;
}

// ADC Initialization Using Full-Duplex SPI
void adc_init_spi_transmit_receive(alt_u32 base, alt_u32 spi_manual_cs){
	int spi_check = -1;
		alt_u8 opcode_null[4] = {0x00,0x00,0x00,0x00};
		alt_u8 opcode_null_receive[4] = {0x01, 0x02, 0x03, 0x04};
		alt_u8 opcode_ready[4] = {0x06, 0x55, 0x00, 0x00};
		alt_u8 opcode_ready_receive[4] = {0x05, 0x06, 0x07, 0x08};
		uint8_t opcode_lock[4] = {0x05, 0x55, 0x00, 0x00};
		uint8_t opcode_lock_receive[4] = {0x07, 0x08, 0x09, 0x09};

		IOWR_ALTERA_AVALON_PIO_DATA(spi_manual_cs, 0b00000000);
		delay_ms(5);
		IOWR_ALTERA_AVALON_PIO_DATA(spi_manual_cs, 0b00000001);
		delay_ms(20);

		spi_check = spi_transmit_receive(	base,
											0,							// number of slaves
											opcode_null,				// A pointer to the data buffer that contains the data to be written, 'NULL' if N/A
											opcode_null_receive,		// A pointer to the buffer where the received (read) data will be stored, 'NULL' if N/A
											4,
											0							// Special control flags for the SPI command
											);

				delay_ms(1);
		spi_check = spi_transmit_receive(	base,
											0,							// number of slaves
											opcode_ready,				// A pointer to the data buffer that contains the data to be written, 'NULL' if N/A
											opcode_ready_receive,		// A pointer to the buffer where the received (read) data will be stored, 'NULL' if N/A
											4,
											0							// Special control flags for the SPI command
											);
				delay_ms(1);
		spi_check = spi_transmit_receive(	base,
											0,							// number of slaves
											opcode_lock,				// A pointer to the data buffer that contains the data to be written, 'NULL' if N/A
											opcode_lock_receive,		// A pointer to the buffer where the received (read) data will be stored, 'NULL' if N/A
											4,
											0							// Special control flags for the SPI command
											);
				delay_ms(1);
		spi_check = alt_avalon_spi_command(base,
											0,							// number of slaves
											0,		// number of bytes to send to SPI Slave, '0' if only reading
											0,				// A pointer to the data buffer that contains the data to be written, 'NULL' if N/A
											4,							// The number of bytes to read from the SPI slave, '0' if only writing
											opcode_lock_receive,		// A pointer to the buffer where the received (read) data will be stored, 'NULL' if N/A
											0							// Special control flags for the SPI command
											);
				delay_ms(1);
}
/*
// timer ISR - Triggers every period of the timer
void timer_isr(void *context) {
    static int led_state = 0;

    // Toggle LED state
    led_state = !led_state;
    IOWR_ALTERA_AVALON_PIO_DATA(PIO_BASE, led_state);

    // Clear the timer interrupt
    IOWR_ALTERA_AVALON_TIMER_STATUS(ONE_SEC_CLK_BASE, 0);

    // Prints the message on Console (UART to Console is established through a USB Blaster)
    // Such that the message appears in synchronous with the LED
    if(led_state==0){
    	alt_putstr("Hello from Nios II!\n");
    }
}

// Initializes and Starts the Timer
void init_timer_one_sec (void) {
	IOWR_ALTERA_AVALON_TIMER_CONTROL(ONE_SEC_CLK_BASE,
									 ALTERA_AVALON_TIMER_CONTROL_START_MSK |	//starts the timer
									 ALTERA_AVALON_TIMER_CONTROL_CONT_MSK |		//timer will restart after reaching the period value
									 ALTERA_AVALON_TIMER_CONTROL_ITO_MSK);		//timer generates an interrupt when reaching timeout value

	// Register the ISR
	alt_ic_isr_register(ONE_SEC_CLK_IRQ_INTERRUPT_CONTROLLER_ID,
						ONE_SEC_CLK_IRQ,
						timer_isr,
						NULL,
						NULL);
}

// Initializes Tim16 and Starts
void HAL_TIM16_Base_Start_IT(void){

	// Register the ISR
	alt_ic_isr_register(TIM16_BASE,						// Timer Name
						TIM16_IRQ,						// IRQ Name
						HW_TIMETASK_IRQHandler,			// ISR Function name
						NULL,							// No context for IST
						0);								// Highest Priority

	// Set control register: continuous mode, interrupt  but DO NOT start
	IOWR_ALTERA_AVALON_TIMER_CONTROL(TIM16_BASE,
					ALTERA_AVALON_TIMER_CONTROL_START_MSK |
					 ALTERA_AVALON_TIMER_CONTROL_CONT_MSK |		//timer will restart after reaching the period value
					 ALTERA_AVALON_TIMER_CONTROL_ITO_MSK);		//timer generates an interrupt when reaching timeout value
}

// Initializes Tim6 and Starts
void HAL_TIM6_Base_Start(void)
{
	// Set control register: continuous mode, and start timer
	IOWR_ALTERA_AVALON_TIMER_CONTROL(TIM6_BASE,
		ALTERA_AVALON_TIMER_CONTROL_START_MSK |
		ALTERA_AVALON_TIMER_CONTROL_CONT_MSK );		//timer generates an interrupt when reaching timeout value
};
*/

