//
// Created by german on 11/21/19.
//

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <stdint.h> //allows int32 


struct motor_data {
    int32_t axis1;
    int32_t axis2;
};

struct location {
    int x;
    int y;
    int theta;
};

struct Controller{
    
public:

    void run_instruction();

    int velocity (int pwm);
    
    //convert a translational distance for the robot into a pwm and time value
    //pass by reference
    void for_distance (int dist, int *pwm, int *seconds);

    //when standing stil
    //convert a desired turn angle in radians to pwms for both motors in opposite directions for a given amount of time
    //pass by reference
    int for_rotation (int angle, int *pwm, int *seconds);

    //when moving
    int for_rotation_in_motion (int angle, int cur_pwm0, int cur_pwm1, int total_time);

    //send pwm commands for a given amount of time appropriately and then stop
    int run_instruction (int pwm1, int pwm2, int seconds);

private:
    bool isRunning = true;
    //int acceleration_to_pwm(int a)?
};

#endif //CONTROLLER_H
