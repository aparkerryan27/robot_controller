#include <iostream> //cout

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <arpa/inet.h>

#include "controller.h"

#define PORT 3000
#define IP_ADDR "192.168.137.41" //TODO: make this an input variable when the program starts up OR have a list of IPs and robot names to match up

int tcp_connect();

int send_values(bot_data bd);

int print_rcv_buffer();