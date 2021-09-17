#include "joystick.h"
#include "ptcp.h"
#include "controller.h"

using namespace std;


int main(int argc, char *argv[]) {

    struct location *robot_loc;
    struct location *mouse_loc;
    //Initialize Motor Struct
    motor_data motors;

    motors.axis1 = 0;
    motors.axis2 = 0;

    string lineInput;
    int x = 0;

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
        
        getline(cin,lineInput);
        if (lineInput.length() != 0) {
            cout << "recieved: " << lineInput;
            x = stoi(lineInput);            
        }

        if (x < 4) {
            motors.axis1 = 1000; //-normalize(j.axes[4]); 
            motors.axis2 = 1000; //normalize(j.axes[1]);
        } else {
            motors.axis1 = 0;
            motors.axis2 = 0; 
        }

        cout << "values: " << motors.axis1 << ", " << motors.axis2 << endl;

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
