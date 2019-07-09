
/* mbed Microcontroller Library

 * Copyright (c) 2018 ARM Limited

 * SPDX-License-Identifier: Apache-2.0

   Change for the sake of change
 */


#include "mbed.h"
#include "stats_report.h"

DigitalOut led3(LED3);
DigitalOut led1(LED1);
DigitalOut led2(LED2);


#define SLEEP_TIME                  1000 // (msec)

#define PRINT_AFTER_N_LOOPS         20



// main() runs in its own thread in the OS

int main()

{

    SystemReport sys_state( SLEEP_TIME * PRINT_AFTER_N_LOOPS /* Loop delay time in ms */);



    int count = 0;
    led1 = true;
    while (true) {

        // Blink LED and wait 0.5 seconds
	led2 = !led2;
	led3 = !led2;
        led1 = led1;
        wait_ms(SLEEP_TIME);
        /*to checck if shit gets indentified */

        wait_ms(SLEEP_TIME);
        /*to checck if shit gets indentified */
        if ((0 == count) || (PRINT_AFTER_N_LOOPS == count)) {
            // Following the main thread wait, report on the current system status
            sys_state.report_state();
            count = 0;
        }
        ++count;

    }

}
