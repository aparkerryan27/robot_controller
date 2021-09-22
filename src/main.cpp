#include "joystick.h"
#include "ptcp.h"
#include "controller.h"

using namespace std;

int main(int argc, char *argv[]) {

    struct location robot_loc;
    struct location mouse_loc;
    
    //Initialize Motor Struct
    bot_data botd;
    botd.light_trigger = false;
    botd.stimulus_trigger = false;
    string lineInput;
    int x = 0;

    //cout << "Starting controller input!!\n";
    //string device("/dev/input/js1");
    //Joystick j(device);

    cout << "Opening TCP connection...\n";

    int connected = tcp_connect();
    if (connected < 0) {
        cout << "Error connecting over TCP. Terminating program.";
        return -1;
    }
    cout << "Remote Device connected over TCP\n";
    

    cout << "starting controller input\n";
    while (true){  
        
        /*
        getline(cin,lineInput);
        if (lineInput.length() != 0) {
            cout << "recieved: " << lineInput;
            x = stoi(lineInput);            
        }
        */
        botd.axis1 = 0; //-normalize(j.axes[4]); 
        botd.axis2 = 0; //normalize(j.axes[1]);
        
        botd.light_trigger ? botd.light_trigger = false : botd.light_trigger = true;
        
        cout << "is the light on?: " <<  botd.light_trigger << endl;

        int ssent = send_values(botd);
        if (ssent < 0) {
            printf("Failure sending a value. Terminating program");
            return -1;
        }

       usleep(5000000); //added 2 0s...
    }

        


}
//To time a function
    //auto start = chrono::high_resolution_clock::now();
    //auto stop = chrono::high_resolution_clock::now();
    //auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    //cout << "this took " << duration.count() << " microseconds"<< endl;
