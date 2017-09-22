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
#include <system.h>
#include <altera_avalon_pio_regs.h>
#include <alt_types.h>
#include <sys/alt_irq.h>
#include <io.h>
#include "sys/alt_alarm.h"
#include "timeouts.h"

alt_u32 timer_isr_function(void *context) {
	char *signal = (char*)context;
	*signal = 1;
	return 0;
}

alt_u32 led_off_isr_function(void *context) {
	IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, 0);
	return 0;
}

void button_isr_function(void *context, alt_u32 id) {
	//int *buttonState = (int*)context;

	//Store button state in context
	//*buttonState = IORD_ALTERA_AVALON_PIO_EDGE_CAP(BUTTONS_BASE);
	int temp = IORD_ALTERA_AVALON_PIO_EDGE_CAP(BUTTONS_BASE);
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(BUTTONS_BASE, 0);

	//Check if any heart events have occurred
//	for(i = 0; i < 2; i ++) {
//		//mask = 1 << i;
//		if(*buttonState & i) {
//			if(i == 0) {
//				VSense = 1;
//			} else if(i == 1) {
//				ASense = 1;
//			}
//		} else {
//			VSense = 0;
//			ASense = 0;
//		}
//	}

	if (temp == 1) { // key0 pressed
		VSense = 1;

		//IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, 1);
	}
	else if (temp == 2) { // key1 pressed
		ASense = 1;
		//IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, 2);
	}




}

int main(void) {
	//Initialisation here

	//IO Signals
	int mode = 0;
	int switchState = 0;

	//Mode 1 button context
	int *buttonState;
	void *buttonContext = (void*)buttonState;

	//Mode 1 led timer to keep led on
	static alt_alarm led_timer;

	//Bitwise processing
	int i;
	int mask;

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

	//Register button isr
	IOWR_ALTERA_AVALON_PIO_EDGE_CAP(BUTTONS_BASE, 0);
	IOWR_ALTERA_AVALON_PIO_IRQ_MASK(BUTTONS_BASE, 0x3);
	alt_irq_register(BUTTONS_IRQ, buttonContext, button_isr_function);
	IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, 0);

	//Output binary vector
	int output = 0;

	reset();
	while(1) {
		//Read IO
		//Check the current mode
		switchState = IORD_ALTERA_AVALON_PIO_DATA(SWITCHES_BASE);
		for(i = 0; i < 2; i++) {
			mask = 1 << i;
			if(switchState & mask) {
				mode = i;
			}
		}




		//Call tick
		tick();

		//Process Outputs

		//Check if we need to start timers
		if(_DDDPacemaker_local_LRI_start == 1) {
			//printf("LRI timer started");
			alt_alarm_start(&lri_timer, LRI_VALUE, timer_isr_function, lri_context);
			_DDDPacemaker_local_LRI_start = 0;
		}
		if(_DDDPacemaker_local_URI_start == 1) {
			//printf("URI timer started");
			alt_alarm_start(&uri_timer, URI_VALUE, timer_isr_function, uri_context);
			_DDDPacemaker_local_URI_start = 0;
		}
		if(_DDDPacemaker_local_AVI_start == 1) {
			//printf("AVI timer started");
			alt_alarm_start(&avi_timer, AVI_VALUE, timer_isr_function, avi_context);
			_DDDPacemaker_local_AVI_start = 0;
		}
		if(_DDDPacemaker_local_AEI_start== 1) {
			//printf("AEI timer started");
			alt_alarm_start(&aei_timer, AEI_VALUE, timer_isr_function, aei_context);
			_DDDPacemaker_local_AEI_start= 0;
		}
		if(_DDDPacemaker_local_VRP_start == 1) {
			//printf("VRP timer started");
			alt_alarm_start(&vrp_timer, VRP_VALUE, timer_isr_function, vrp_context);
			_DDDPacemaker_local_VRP_start = 0;
		}
		if(_DDDPacemaker_local_PVARP_start == 1) {
			//printf("PVARP timer started");
			alt_alarm_start(&pvarp_timer, PVARP_VALUE, timer_isr_function, pvarp_context);
			_DDDPacemaker_local_PVARP_start = 0;
		}
//		printf("LRI:%d, URI:%d, AVI:%d, AEI:%d, VRP:%d, PVARP:%d\n", \
//				_DDDPacemaker_local_LRI_start, _DDDPacemaker_local_URI_start,_DDDPacemaker_local_AVI_start,_DDDPacemaker_local_AEI_start, _DDDPacemaker_local_VRP_start,_DDDPacemaker_local_PVARP_start);

		//Process pace output
		if(VPace) {
			output = 1;
			printf("Vpace = 1");
			IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, 1);
			alt_alarm_start(&led_timer, 500, led_off_isr_function, NULL);
		}
		if(APace) {
			output = 2;
			printf("Apace = 1");
			IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, 2);
			alt_alarm_start(&led_timer, 500, led_off_isr_function, NULL);
		}

//		//Actuate based on processed output
//		if((mode == 0) && (output)) {
//			//IOWR_ALTERA_AVALON_PIO_DATA(LEDS_GREEN_BASE, output);
//			alt_alarm_start(&led_timer, 500, led_off_isr_function, NULL);
//		}

		//Reset IO
		VSense = 0;
		ASense = 0;
		output = 0;
		VPace = 0;
		APace = 0;

	}

	return 0;
}
