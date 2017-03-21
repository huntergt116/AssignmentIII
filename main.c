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
#define PRINT_ERR “No temperatures recorded.”

// GLOBALS
  char *cmd[17];        // Command String
  char cmd_ind = 0;     // To cycle through the Command String
  char *temps[64];      // Temperature Storage (is 64 enough?)
  char temp_T, temp_H;  // Tail and Header pointers for 'char *temps'
  char time[3];         // Stores our time in {hr,min,sec} format
  char **hr;            // Pointer to time[0]
  char **min;           // Pointer to time[1]
  char **sec;           // Pointer to time[2]
  char current_temp;    // Used for storing the current temperature


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
// adc.c/main.c - edit: declare i before the for loop
// Makefile
// Makefile.in

/* -----------7------------- */

/*
Need interrupts for:

UART_R
UART_T
timer_A
Push Button 
Temp
*/

/* -----------*------------- */


int main(void)
{
  // Initialize vectors, etc.
 temp_H = temp_T = -1;
 hr  = time[0];
 min = time[1];
 sec = time[2];
  __bit_set(GIE | CPUOFF);
}

// ========================================================================//
// STORE EVERY 5 MINUTES - Queue structure
// ========================================================================//

storeTemp
{
  if(temp_H == -1)
    temp_H = 0;
  temps[++temp_T] = current_temp;
}

timeCount
{
  sec++;
  
  if(sec == 60)
  {  
    min++;
    sec = 0;
  }
  if(min == 60)
  {
    hr++;
    min = 0;
  }
  if((min % 5 == 0) && (sec == 00))
  {
    transTemp;
    storeTemp;
  }
  
  if((hr == 23) && (min == 59) && (sec == 60))  // If counter is 23:59:59,
    hr = min = sec = 0;                         // reset time counter to zero.
}

// ========================================================================//
// UART MODES: t, s, o, l
// ========================================================================//


/* t: Show the current time of the system.
Output to the serial terminal the current time of the system using the form hhmmss, where
hh is the two digit hour in 24-hour format, mm is the two digit minute in the hour, and ss is
the two digit second within the minute.*/

  currentTime
  {
    transTime((hr/10)  % 3  + '\0');
    transTime( hr      % 10 + '\0');
    transTime((min/10) % 6  + '\0');
    transTime( min     % 10 + '\0');
    transTime((sec/10) % 6  + '\0');
    transTime( sec     % 10 + '\0');
  }
  
  transTime
  {
    // Transmit time in hhmmss format using UART
  }
  


/* s: Set the current time of the system.
Set the current time of the system to the provided argument. There will be no space between
the command and its argument. The argument will be on the form hhmmss, where hh is the
two digit hour in 24-hour format, mm is the two digit minute in the hour, and ss is the two
digit second within the minute.*/

// setTime
// {
//   volatile int i;
//   for(i = 0; i < 3; i++, cmd_int++)
//     time[i] = cmd[cmd_int] * 10 + cmd[++cmd_int];
// }


/* o: Show the oldest temperature reading and its timestamp.
Output to the serial terminal the oldest temperature reading and its timestamp. The output
must have the form hhmmss: T, where hh is the two digit hour in 24-hour format, mm is
the two digit minute in the hour, ss is the two digit second within the minute, and T is the
measured temperature. The displayed entry must be removed from the list. If no readings
have been performed, the message “No temperatures recorded.” must be displayed.*/

oldestTemp
{
  if (temp_H != -1)
    transTemp(temps[temp_H++]);
  else
    PRINT_ERR;
}

transTemp
{
  transTime();
  // Additionally, transmit: <'\t'temps[temp_H]>
}

/* l: Show all the temperature readings and their timestamps.
Output to the serial terminal all the temperature readings and their timestamps. The output
should be in chronological order, oldest first. The output must have the form hhmmss: T,
where hh is the two digit hour in 24-hour format, mm is the two digit minute in the hour, ss is
the two digit second within the minute, and T is the measured temperature. All entries must
be removed from the list. If no readings have been performed, the message “No temperatures
recorded.” must be displayed. */

transAll
{
  if(temp_H == -1)
    PRINT_ERR;
  else
    do{
      tansTemp(temps[temp_H++]);
    } while ((temp_H - 1) != temp_T);
  
  temp_T = temp_H = -1;
}
