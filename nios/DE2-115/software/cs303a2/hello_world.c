/*
 * "Hello World" example.
 *
 * This example prints 'Hello from Nios II' to the STDOUT stream. It runs on
 * the Nios II 'standard', 'full_featured', 'fast', and 'low_cost' example
 * designs. It runs with or without the MicroC/OS-II RTOS and requires a STDOUT
 * device in your system's hardware.
 * The memory footprint of this hosted application is ~69 kbytes by default
 * using the standard reference design.
 *
 * For a reduced footprint version of this template, and an explanation of how
 * to reduce the memory footprint for a given application, see the
 * "small_hello_world" template.
 *
 */

#include <stdio.h>
#include "sccharts.h"
#include <stddef.h>
#include "system.h"
#include <altera_avalon_pio_regs.h>
#include <alt_types.h>
#include <sys/alt_irq.h>
#include <io.h>
#include "sys/alt_alarm.h"
#include "timeouts.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

//Timer contexts
void *lri_context = &LRI_TO;
void *uri_context = &URI_TO;
void *avi_context = &AVI_TO;
void *aei_context = &AEI_TO;
void *pvarp_context = &PVARP_TO;
void *vrp_context = &VRP_TO;

//Register timers
static alt_alarm lri_timer;
static alt_alarm uri_timer;
static alt_alarm avi_timer;
static alt_alarm aei_timer;
static alt_alarm pvarp_timer;
static alt_alarm vrp_timer;

#define MAX_LED_TICKS 500

static int mode = 0;

/* DESCRIPTION:	Handles timers
 * PARAMETER: 	Context - opaque reference to timeout signal
 * RETURN:		0; stops the timer
 */
alt_u32 timer_isr_function(void* context) {
	char *signal = (char*)context;
	*signal = 1;
	return 0;
}

/* This function changes the mode depending on the value of the switches (only using sw0)
 * The value of the switches is polled for in the while loop
 */
void mode_set() {
	if ((IORD_ALTERA_AVALON_PIO_DATA(SWITCHES_BASE) & 0x01) == 1) {
		mode = 1; // mode 1
	}
	else {
		mode = 0; // start on mode 0
	}
}

int main(void) {
	// Initialise the counters which will dictate how many ticks the LEDs should be on for
	int VPace_led_ticks = 0;
	int APace_led_ticks = 0;
	int VSense_led_ticks = 0;
	int ASense_led_ticks = 0;

	// Initialise the value of the buttons to be 0
	int buttons = 0;

	// Initialise UART
	int fildes = open(UART_NAME,O_NONBLOCK | O_RDWR);
	char data;
	char *buffer;

	reset();

	while(1) {
		mode_set(); // check if mode has been changed
		if (mode == 1) { // mode 2; enable UART communication and read in VSense, ASense
			data = read(fildes, buffer, 1);
			if (*buffer == 'V') { // VSense high, as if actuating buttons KEY0
				buttons = 1;
			}
			else if (*buffer == 'A') { // ASense high, as if actuating buttons KEY1
				buttons = 2;
			}
			*buffer = 0;
		}
		else if (mode == 0) { // mode 1, buttons should be 'enabled' as hardware IO
			buttons = IORD_ALTERA_AVALON_PIO_EDGE_CAP(BUTTONS_BASE); // read the value of the buttons
			IOWR_ALTERA_AVALON_PIO_EDGE_CAP(BUTTONS_BASE, 0); // clear the edge cap register
		}

		if (buttons == 1) { // KEY0 pressed, VSense input
			VSense = 1; // assert VSense
			IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, 1); // turn on LED0
			VSense_led_ticks = MAX_LED_TICKS; // Start VSense LED ticks counter
			// Reset the other LED counters
			VPace_led_ticks = -1;
			APace_led_ticks = -1;
			ASense_led_ticks = -1;
		}
		else if (buttons == 2) { // KEY1 pressed, ASense input
			ASense = 1; // assert ASense
			IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, 2); // turn on LED1
			ASense_led_ticks = MAX_LED_TICKS; // start ASense LED tickers counter
			// Reset the other LED counters
			VSense_led_ticks = -1;
			VPace_led_ticks = -1;
			APace_led_ticks = -1;
		}


		//Call tick
		tick();

		// Send VPace and APace data via UART
		if (mode == 1) {
			if (APace == 1) {
				*buffer = 'A';
				write(fildes, buffer, 1);
			}
			if (VPace == 1) {
				*buffer = 'V';
				write(fildes, buffer, 1);
			}
		}


		// Reset inputs
		buttons = 0;
		VSense = 0;
		ASense = 0;

		/* Start the appropriate timers
		* Starts the alarm, passing in the context as the timeout signal
		* Timeout will be asserted high (to be passed into FSM) when the timer times out
		*/
		if(LRI_start == 1) {
			alt_alarm_start(&lri_timer, LRI_VALUE, timer_isr_function, lri_context);
			LRI_start = 0;
		}
		if(URI_start == 1) {
			alt_alarm_start(&uri_timer, URI_VALUE, timer_isr_function, uri_context);
			URI_start = 0;
		}
		if(AVI_start == 1) {
			alt_alarm_start(&avi_timer, AVI_VALUE, timer_isr_function, avi_context);
			AVI_start = 0;
		}
		if(AEI_start== 1) {
			alt_alarm_start(&aei_timer, AEI_VALUE, timer_isr_function, aei_context);
			AEI_start= 0;
		}
		if(VRP_start == 1) {
			alt_alarm_start(&vrp_timer, VRP_VALUE, timer_isr_function, vrp_context);
			VRP_start = 0;
		}
		if(PVARP_start == 1) {
			alt_alarm_start(&pvarp_timer, PVARP_VALUE, timer_isr_function, pvarp_context);
			PVARP_start = 0;
		}

		// Stop alarms and de-assert timeout
		if (LRI_ex == 1) {
			LRI_TO = 0; // de-assert timeout
			alt_alarm_stop(&lri_timer); // stop alarm
		}
		if (URI_ex == 1) {
			URI_TO = 0;
			alt_alarm_stop(&uri_timer);
		}
		if (AVI_ex == 1) {
			AVI_TO = 0;
			alt_alarm_stop(&avi_timer);
		}
		if (AEI_ex == 1) {
			AEI_TO = 0;
			alt_alarm_stop(&aei_timer);
		}
		if (VRP_ex == 1) {
			VRP_TO = 0;
			alt_alarm_stop(&vrp_timer);
		}
		if (PVARP_ex == 1) {
			PVARP_TO = 0;
			alt_alarm_stop(&pvarp_timer);
		}

		// Process pacing outputs
		if(VPace == 1) {
			IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, 4); // turn on LED2
			VPace_led_ticks = MAX_LED_TICKS; // start VPace LED ticks counter
			// Reset the other LED tick counters
			APace_led_ticks = -1;
			VSense_led_ticks = -1;
			ASense_led_ticks = -1;
		}
		if(APace == 1) {
			IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, 8); // turn on LED3
			APace_led_ticks = MAX_LED_TICKS; // start APace LED ticks counter
			// Reset the other LED tick counters
			VPace_led_ticks = -1;
			VSense_led_ticks = -1;
			ASense_led_ticks = -1;
		}

		/* Tick LEDs
		 * LEDs are kept on for MAX_LED_TICKS - 500 ticks.
		 * Each tick, the appropriate counter (x_led_ticks) is decremented
		 * Once the counter reaches 0, the LEDs are turned off
		 */
		if (APace_led_ticks > 0) {
			APace_led_ticks--; // decrement
		}
		else if (APace_led_ticks == 0){
			IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, 0); // turn off LED
		}

		if (VPace_led_ticks > 0) {
			VPace_led_ticks--;
		}
		else if (VPace_led_ticks == 0){
			IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, 0);
		}

		if (VSense_led_ticks > 0) {
			VSense_led_ticks--;
		}
		else if (VSense_led_ticks == 0) {
			IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, 0);
		}

		if (ASense_led_ticks > 0) {
			ASense_led_ticks--;
		}
		else if (ASense_led_ticks == 0) {
			IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, 0);
		}

	}

	return 0;
}
