//Allows a user to initialize and push data to a usb serial device and use as input

#include "pserial.h"

using namespace std;

int port{-1}; 

void serial_init(){
    port = open( "/dev/ttyUSB0", O_RDWR | O_NOCTTY);
    struct termios tty;
    struct termios tty_old;
    memset (&tty, 0, sizeof tty);

    /* Error Handling */
    if ( tcgetattr ( port, &tty ) != 0 ) {
        cout << "Error " << errno << " from tcgetattr: " << strerror(errno) << std::endl;
    }

    cout << "Port " << port << " opened\n";
    /* Save old tty parameters */
    tty_old = tty;

    /* Set Baud Rate */
    cfsetospeed (&tty, (speed_t)B115200);
    cfsetispeed (&tty, (speed_t)B115200);

    /* Setting other Port Stuff */
    tty.c_cflag     &=  ~PARENB;            // Make 8n1
    tty.c_cflag     &=  ~CSTOPB;
    tty.c_cflag     &=  ~CSIZE;
    tty.c_cflag     |=  CS8;

    tty.c_cflag     &=  ~CRTSCTS;           //  flow control

    tty.c_cc[VMIN]   =  1;                  // read doesn't block
    tty.c_cc[VTIME]  =  5;                  // 0.5 seconds read timeout
    tty.c_cflag     |=  CREAD | CLOCAL;     // turn on READ & ignore ctrl lines

    /* Make raw */
    cfmakeraw(&tty);
    /* Flush Port, then applies attributes */
    tcflush( port, TCIFLUSH );
    
    if ( tcsetattr ( port, TCSANOW, &tty ) != 0) {
        cout << "Error " << errno << " from tcsetattr" << std::endl;
    }

}

void write_serial(struct bot_data *motors) {
    int n_bytes = write( port, motors, sizeof(struct bot_data));
}

void read_serial(){

    int n_bytes = 0, i = 0;
    char buf = '\0';
   
    //Whole response
    char response[512];
    memset(response, '\0', sizeof response);

    do {
        n_bytes = read( port, &buf, 1 );
        sprintf( &response[i], "%c", buf );
        i += n_bytes;
    } while( buf != '\r' && n_bytes > 0);
 
    if (n_bytes < 0) {
        std::cout << "Error reading: " << strerror(errno) << std::endl;
    }
    else if (n_bytes == 0) {
        std::cout << "Read nothing!" << std::endl;
    }
    else {
        std::cout << "Response: " << response << std::endl;
    }
    
}
