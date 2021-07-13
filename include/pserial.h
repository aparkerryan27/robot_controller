
#ifndef PSERIAL_H
#define PSERIAL_H

#include <fcntl.h> // Contains file controls like O_RDWR
#include <errno.h> // Error integer and strerror() function
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h> // write(), read(), close()
#include <string.h>
#include <stdio.h> 
#include <iostream> //cout

//TODO: - is there a cleaner/sharper way to import motor struct into this file? 
#include "controller.h"

//opens up a serial port to the ESP32 on /dev/ttyUSB0
void serial_init();

//writes the motor struct into serial for the ESP32
void write_serial(struct motor_data *motors);

//reads a single line from the serial input
void read_serial();

#endif //PSERIAL_H