#include "joystick.h"
#include "ptcp.h"
#include "controller.h"

using namespace std;

struct motor_data *motors;
string pipeLine;

int main(int argc, char *argv[]) {

 
    cout << "Starting controller input!!\n";
    string device("/dev/input/js1");
    Joystick j(device);

    int connected = tcp_connect();
    if (connected < 0) {
        cout << "Error connecting over TCP. Terminating program.";
        return -1;
    }
    cout << "Remote Device connected over TCP";
    

    cout << "Opening tracker input stream\n";

    while (getline(cin,pipeLine)){  
        
        cout << pipeLine;

        //TODO: currently still pulling js values
        motors->axis1 = normalize(j.axes[1]);
        motors->axis2 = -1 * normalize(j.axes[4]);

        //TODO: actually compute the next PWM value to send based on the current location to send 

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


