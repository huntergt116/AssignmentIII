// MAIN.C

// ========================================================================//
// NOTES
// ========================================================================//

// LPM: Sections 2.3/2.4 in slau144j
// UART: Chapter 15 in slau144j

/*
0. Read temp every 5 minutes
1. Read UART command: up to 16 chars (t, s, o, or l)
2. Execute command: (store at least 32 temps, set time, read time, read temp, read all temps)
3. Enter LPM (LPM3) and wait for next command
*/

// Use ACLK for RT clock and 9600 8N1 for UART

// enable_LPM3
  BIS   #GIE+CPUOFF+SCG1+SCG0,  SR

// ========================================================================//
// STORE EVERY 5 MINUTES - Qeue structure
// ========================================================================//




// ========================================================================//
// UART MODES: t, s, o, l
// ========================================================================//


/*
t: Show the current time of the system.
Output to the serial terminal the current time of the system using the form hhmmss, where
hh is the two digit hour in 24-hour format, mm is the two digit minute in the hour, and ss is
the two digit second within the minute.
*/




/*s: Set the current time of the system.
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



/*l: Show all the temperature readings and their timestamps.
Output to the serial terminal all the temperature readings and their timestamps. The output
should be in chronological order, oldest first. The output must have the form hhmmss: T,
where hh is the two digit hour in 24-hour format, mm is the two digit minute in the hour, ss is
the two digit second within the minute, and T is the measured temperature. All entries must
be removed from the list. If no readings have been performed, the message “No temperatures
recorded.” must be displayed. */
