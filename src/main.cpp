#include "joystick.h"
#include "ptcp.h"
#include "controller.h"

using namespace std;


int main(int argc, char *argv[]) {

    struct location *robot_loc;
    struct location *mouse_loc;
    struct motor_data *motors;
 
    cout << "Starting controller input!!\n";
    string device("/dev/input/js1");
    Joystick j(device);

    int connected = tcp_connect();
    if (connected < 0) {
        cout << "Error connecting over TCP. Terminating program.";
        return -1;
    }
    cout << "Remote Device connected over TCP\n";
    

    cout << "starting controller input\n";
    while (true){  
        
        //TODO: convert this pipeline into Location Struct objects for mouse and robot
        //handle if no robot detected elif no mouse detected

        //TODO: currently still pulling joysticks values

        motors->axis1 = 4000; //normalize(j.axes[1]);
        motors->axis2 = 4000; //normalize(j.axes[4]);

        cout << motors->axis1 << ", " << motors->axis2 << endl;

        //TODO: use this to compute the next PWM value to send based on the current location to send 
        //set_pwm_for_dest(mouse_loc, robot_loc, motors);

        int ssent = send_values(motors);
        if (ssent < 0) {
            printf("Failure sending a value. Terminating program");
            return -1;
        }

       usleep(50000);
    }

        


}
//To time a function
    //auto start = chrono::high_resolution_clock::now();
    //auto stop = chrono::high_resolution_clock::now();
    //auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    //cout << "this took " << duration.count() << " microseconds"<< endl;
