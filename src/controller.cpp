#include "controller.h"
#include <stdio.h>

#include <iostream>

using namespace std;

#define THETA_ERROR 0.01
#define DIST_ERROR 0.01

#define FORWARD_PWM 200

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

int velocity (int pwm) {
    return 0;
}

void move_to_x(int x, struct location cur_loc, struct motor_data *motors) {
    if (cur_loc.x < x){
        motors->axis1 += FORWARD_PWM;
        motors->axis2 += FORWARD_PWM;
    }
}

//convert a translational distance for the robot into a pwm and time value, pass by reference
void for_distance (int dist, int *pwm, int *seconds) {
    
    return;
    
}

//when standing still
//convert a desired turn angle in radians to pwms for both motors in opposite directions for a given amount of time
//pass by reference
void for_rotation (int angle, int *pwm, int *seconds) {
    return;
}

//when moving
void for_rotation_in_motion (int angle, int cur_pwm0, int cur_pwm1) {
    return;
}