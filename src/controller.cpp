#include "controller.h"
#include <stdio.h>

#include <iostream>

using namespace std;

#define THETA_ERROR 0.01
#define DIST_ERROR 0.01

#define FORWARD_PWM 200

int velocity (int pwm) {
    return 0;
}

void move_to_x(int x, struct location cur_loc, struct motor_data *motors) {
    if (current.x < x){
        motors->axis1 += FORWARD_PWM;
        motors->axis2 += FORWARD_SPEED;
    }
}

//convert a translational distance for the robot into a pwm and time value, pass by reference
void for_distance (int dist, int *pwm, int *seconds) {
    
    return;
    
}

//when standing stil
//convert a desired turn angle in radians to pwms for both motors in opposite directions for a given amount of time
//pass by reference
void for_rotation (int angle, int *pwm, int *seconds) {
    return;
}

//when moving
void for_rotation_in_motion (int angle, int cur_pwm0, int cur_pwm1) {
    return;
}

//send pwm commands for a given amount of time appropriately and then stop
int run_instruction (int pwm1, int pwm2, int seconds) {
    
    return 0; //success

    
}