#include <iostream> //cout


#include "joystick.h"
#include "pserial.h"
#include "controller.h"

using namespace std;

//TODO: - normalize these values to PWMs more precisely
int normalize(int raw_js_value) {
    /*
    int32_t max = 32767;
    int32_t min = -32767;
    int32_t range = (max - min) + 1;
    // normalize between -512 and 511
    int32_t normalized = raw_js_value * 1024 / range;
    */
    int normalized = raw_js_value / 32;
    return normalized; //for now, makes everything a positive number so padding can be used properly
}




int main(int argc, char *argv[]) {

    //TODO - get current location input stream
        //then use that x and y, ask for a destination x and y
        
    struct motor_data *motors;
    int *pwm;
    int *seconds;

    serial_init();

    cout << "Starting controller input!!\n";
    string device("/dev/input/js1");
    Joystick j(device);

    //TODO: - run a sequence of commands to move the robot to a location
    //Controller::for_distance(pwm, seconds, motors);



    while (true){  
        
        motors->axis1 = normalize(j.axes[1]);
        motors->axis2 = normalize(j.axes[4]);

        write_serial(motors);
        

        cout << "sent axes: " << motors->axis1 << "\t" << motors->axis2 << "\n";
        
        //read_serial();
        usleep(50000);
    }


}



