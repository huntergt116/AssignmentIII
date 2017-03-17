// MAIN.C

// ========================================================================//
// OBJECTIVES:
// 0. Read temp every 5 minutes
// 1. Read UART command: up to 16 chars (t, s, o, or l)
// 2. Execute command: (store at least 32 temps, set time, read time, read temp, read all temps)
// 3. Enter LPM (LPM3) and wait for next command
// ========================================================================//

// LIBRARIES
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


// GLOBALS
  char *buffer[]; // Buffer for temp readings (size?)
  


// ========================================================================//
// NOTES - [ LPM: Sections 2.3/2.4 in slau144j ]
//         [ UART: Chapter 15 in slau144j ]
// ========================================================================//

/* -----------1------------- */

// *Use ACLK (ADC10CTL1 = ADC10SSEL_1)

/* -----------2------------- */

/*
"You might be wondering why a real time clock is based on 32.768kHz; 32768 is exactly 2^15. 
This number can be divided down using binary values to give you a frequency of 1Hz, or a 
period of 1 second. This is why 32kHz is the standard frequency used in real-time clocks."

http://www.msp430launchpad.com/2012/03/using-aclk-and-32khz-crystal.html
 (also contains test code for crystal)
*/

/* -----------3------------- */

/*
to enable_LPM3:
__bis_SR_register(GIE + CPUOFF + SCG1 + SCG0);
*/

/* -----------4------------- */

// Article on ADC: https://www.embeddedrelated.com/showarticle/199.php

/* -----------5------------- */

  /* For a 1MHz clock:
 
    1    32768
   --- x ----- = 32 clock ticks
   1e6     1
  */


/* -----------6------------- */

// Files in Orlando's example project:
// dco.c
// dco.h
// uart.c
// uart.h
// bitmanip.h
// main.c - edit: declare i before the for loop
// Makefile
// Makefile.in

/* -----------*------------- */


int main(void)
{
 

// ========================================================================//
// STORE EVERY 5 MINUTES - Queue structure
// ========================================================================//

/* 
!!! NOTES FOR QUEUES FROM COP3502 HAVE BEEN INCLUDED IN A SECOND BRANCH
*/

  
// ========================================================================//
// UART MODES: t, s, o, l
// ========================================================================//


/* t: Show the current time of the system.
Output to the serial terminal the current time of the system using the form hhmmss, where
hh is the two digit hour in 24-hour format, mm is the two digit minute in the hour, and ss is
the two digit second within the minute.*/



/* s: Set the current time of the system.
Set the current time of the system to the provided argument. There will be no space between
the command and its argument. The argument will be on the form hhmmss, where hh is the
two digit hour in 24-hour format, mm is the two digit minute in the hour, and ss is the two
digit second within the minute.*/



/* o: Show the oldest temperature reading and its timestamp.
Output to the serial terminal the oldest temperature reading and its timestamp. The output
must have the form hhmmss: T, where hh is the two digit hour in 24-hour format, mm is
the two digit minute in the hour, ss is the two digit second within the minute, and T is the
measured temperature. The displayed entry must be removed from the list. If no readings
have been performed, the message “No temperatures recorded.” must be displayed.*/



/* l: Show all the temperature readings and their timestamps.
Output to the serial terminal all the temperature readings and their timestamps. The output
should be in chronological order, oldest first. The output must have the form hhmmss: T,
where hh is the two digit hour in 24-hour format, mm is the two digit minute in the hour, ss is
the two digit second within the minute, and T is the measured temperature. All entries must
be removed from the list. If no readings have been performed, the message “No temperatures
recorded.” must be displayed. */

  
  
}
