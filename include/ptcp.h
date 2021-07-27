#include <iostream> //cout

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <arpa/inet.h>

#include "controller.h"

#define PORT 3000
#define IP_ADDR "192.168.137.42"

int tcp_connect();

int send_values( struct motor_data *md);

int print_rcv_buffer();