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

static int mode;

alt_u32 timer_isr_function(void* context) {
	char *signal = (char*)context;
	*signal = 1;
	printf("timer stopped, Apace:%d\n", APace);
	return 0;
}

//// AVI timer
//alt_u32 avi_timer_isr(void* context) {
//	volatile int* trigger = (volatile int*) context;
//	*trigger = 1;
//	AVI_TO = 1;
//	printf("AVI timeout");
//	return 0;
//}
//
//alt_u32 aei_timer_isr(void* context) {
//	volatile int* trigger = (volatile int*) context;
//	*trigger = 1;
//	AEI_TO = 1;
//	printf("AEI timeout");
//	return 0;
//}
//
//alt_u32 vrp_timer_isr(void* context) {
//	volatile int* trigger = (volatile int*) context;
//	*trigger = 1;
//	VRP_TO = 1;
//	printf("VRP timeout");
//	return 0;
//}
//
//alt_u32 pvarp_timer_isr(void* context) {
//	volatile int* trigger = (volatile int*) context;
//	*trigger = 1;
//	PVARP_TO = 1;
//	printf("PVARP timeout");
//	return 0;
//}
//
//alt_u32 lri_timer_isr(void* context) {
//	volatile int* trigger = (volatile int*) context;
//	*trigger = 1;
//	LRI_TO = 1;
//	printf("LRI timeout");
//	return 0;
//}
//
//alt_u32 uri_timer_isr(void* context) {
//	volatile int* trigger = (volatile int*) context;
//	*trigger = 1;
//	PVARP_TO = 1;
//	printf("URI timeout");
//	return 0;
//}

alt_u32 led_off_isr_function(void *context) {
	IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, 0);

	return 0;
}

void button_isr_function(void *context, alt_u32 id) {

	//Store button state in context
	//*buttonState = IORD_ALTERA_AVALON_PIO_EDGE_CAP(BUTTONS_BASE);
	int temp = IORD_ALTERA_AVALON_PIO_EDGE_CAP(BUTTONS_BASE);
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(BUTTONS_BASE, 0);

	if (temp == 1) { // key0 pressed
		VSense = 1;

		//IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, 1);
	}
	else if (temp == 2) { // key1 pressed
		ASense = 1;
		//IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, 2);
	}
}

void mode_set() {
	if ((IORD_ALTERA_AVALON_PIO_DATA(SWITCHES_BASE) & 0x01) == 1) {
		mode = 1; // mode 1
	}
	else {
		mode = 0; // start on mode 0
	}
}

int main(void) {
	//Initialisation here

	//IO Signals
	mode = 0;
	//int switchState = 0;

	int VPace_led_ticks = 0;
	int APace_led_ticks = 0;
	int VSense_led_ticks = 0;
	int ASense_led_ticks = 0;

	IOWR_ALTERA_AVALON_PIO_IRQ_MASK(BUTTONS_BASE, 0x3);
	int buttons = 0;

	int fildes = open(UART_NAME,O_NONBLOCK | O_RDWR);
	char data;
	char *buffer;

	reset();
	while(1) {
		mode_set(); // check if mode has been changed
		if (mode == 1) {
			data = read(fildes, buffer, 1);
			if (*buffer == 'V') {
				buttons = 1;
			}
			else if (*buffer == 'A') {
				buttons = 2;
			}
			*buffer = 0;
		}
		else if (mode == 0) {
			buttons = IORD_ALTERA_AVALON_PIO_EDGE_CAP(BUTTONS_BASE);
			IOWR_ALTERA_AVALON_PIO_EDGE_CAP(BUTTONS_BASE, 0);
		}

		if (buttons == 1) {
			VSense = 1;
			IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, 1); // LED0
			VSense_led_ticks = MAX_LED_TICKS;
			VPace_led_ticks = -1;
			APace_led_ticks = -1;
			ASense_led_ticks = -1;
			printf("VSense detected ");
		}
		else if (buttons == 2) {
			ASense = 1;
			IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, 2); // LED1
			ASense_led_ticks = MAX_LED_TICKS;
			VSense_led_ticks = -1;
			VPace_led_ticks = -1;
			APace_led_ticks = -1;
			printf("ASense detected ");
		}


		//Call tick
		tick();

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


		// Reset input
		buttons = 0;
		VSense = 0;
		ASense = 0;

		// Check if timers need to be started, start them
		if(LRI_start == 1) {
			printf("LRI timer started, Apace:%d ", APace);
			alt_alarm_start(&lri_timer, LRI_VALUE, timer_isr_function, lri_context);
			LRI_start = 0;
		}
		if(URI_start == 1) {
			printf("URI timer started, Apace:%d ", APace);
			alt_alarm_start(&uri_timer, URI_VALUE, timer_isr_function, uri_context);
			URI_start = 0;
		}
		if(AVI_start == 1) {
			printf("AVI timer started, Apace:%d ", APace);
			alt_alarm_start(&avi_timer, AVI_VALUE, timer_isr_function, avi_context);
			AVI_start = 0;
		}
		if(AEI_start== 1) {
			printf("AEI timer started, Apace:%d ", APace);
			alt_alarm_start(&aei_timer, AEI_VALUE, timer_isr_function, aei_context);
			AEI_start= 0;
			//printf("AEI timer stopped");
		}
		if(VRP_start == 1) {
			printf("VRP timer started, Apace:%d ", APace);
			alt_alarm_start(&vrp_timer, VRP_VALUE, timer_isr_function, vrp_context);
			VRP_start = 0;
		}
		if(PVARP_start == 1) {
			printf("PVARP timer started, Apace:%d ", APace);
			alt_alarm_start(&pvarp_timer, PVARP_VALUE, timer_isr_function, pvarp_context);
			PVARP_start = 0;
		}

		// Stop alarms and reset timeout
		if (LRI_ex == 1) {
			LRI_TO = 0;
			alt_alarm_stop(&lri_timer);
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
			printf("Vpace = 1\n");
			IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, 4); // LED2
			VPace_led_ticks = MAX_LED_TICKS;
			APace_led_ticks = -1;
			VSense_led_ticks = -1;
			ASense_led_ticks = -1;
			//VPace = 0;
		}
		if(APace == 1) {
			//output = 2;
			printf("Apace = 1\n");
			IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, 8); // LED3
			APace_led_ticks = MAX_LED_TICKS;
			VPace_led_ticks = -1;
			VSense_led_ticks = -1;
			ASense_led_ticks = -1;
		}

		// Tick LEDs
		if (APace_led_ticks > 0) {
			APace_led_ticks--;
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
