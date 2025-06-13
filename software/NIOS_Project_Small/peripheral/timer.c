#include "timer.h"


static uint8_t led_blink_register = 0;

// Led Toggle Function - used in timer16_isr
void led_blink(void){

	// Read from LED BASE
	alt_u32 value = IORD(LED_BASE, 0);

	// Toggle the relevant bit(s)
	value ^= (1 << 0);  // Toggle bit 0 (for example)

	// Write to the LED BASE
  	IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE, value);

  	//debug message
	#if DEBUG_TIMER == 1
		printf("led_blink - timer.c");
	#endif

}

void timer16_isr(void* context) {
	static int led_state = 0;

	    // Toggle LED state
	    led_state = !led_state;
	    IOWR_ALTERA_AVALON_PIO_DATA(LED_BASE, led_state);

	    // Clear the timer interrupt
	    IOWR_ALTERA_AVALON_TIMER_STATUS(TIM16_1MS_BASE, 0);

	    // Prints the message on Console (UART to Console is established through a USB Blaster)
	    // Such that the message appears in synchronous with the LED
	    if(led_state==0){
	    	alt_putstr("Hello from Nios II!\n");
	    }

}

void timer16_init(void) {
    // Disable timer before configuring
    IOWR(TIM16_1MS_BASE_ADDR, TIMER_CONTROL_OFFSET, 0);

    // Set period registers
    //IOWR(TIM16_1MS_BASE_ADDR, TIMER_PERIODL_OFFSET, TIMER_PERIOD_CYCLES & 0xFFFF);
    //IOWR(TIM16_1MS_BASE_ADDR, TIMER_PERIODH_OFFSET, (TIMER_PERIOD_CYCLES >> 16) & 0xFFFF);

    IOWR_ALTERA_AVALON_TIMER_CONTROL(TIM16_1MS_BASE,
    		ALTERA_AVALON_TIMER_CONTROL_CONT_MSK  |
			ALTERA_AVALON_TIMER_CONTROL_START_MSK |
			ALTERA_AVALON_TIMER_CONTROL_ITO_MSK );

    // Register ISR
    alt_ic_isr_register(
    		TIM16_1MS_IRQ_INTERRUPT_CONTROLLER_ID,
			TIM16_1MS_IRQ,
			timer16_isr,
        NULL,
        NULL
    );
}

// timer ISR - Triggers every period of the timer
/*
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
}*/
