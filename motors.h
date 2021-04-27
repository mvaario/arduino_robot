class motor_setups {
public:
#include "settings.h"

void fordward(){
    // parametres for forward
    // Motors speed
    motor_speed = straight_speed;

    // left motor direction
    digitalWrite(left_1, HIGH);
    digitalWrite(left_2, LOW);

    // right motor direction
    digitalWrite(right_1, HIGH);
    digitalWrite(right_2, LOW);

    // servo angle
    angle = servo_straight;
}

void backward(){
    // parametres for backward
    motor_speed = straight_speed;

    // left motor
    digitalWrite(left_1, LOW);
    digitalWrite(left_2, HIGH);

    // right motor
    digitalWrite(right_1, LOW);
    digitalWrite(right_2, HIGH);

    // servo angle
    angle = servo_straight;
}

void right(){
    // parametres for right turn
    motor_speed = turning_speed;

    // left motor
    digitalWrite(left_1, HIGH);
    digitalWrite(left_2, LOW);

    // right motor
    digitalWrite(right_1, LOW);
    digitalWrite(right_2, HIGH);

    // servo angle
    angle = servo_right;
}

void left(){
    // parametres for left turn
    motor_speed = turning_speed;

    // left motor
    digitalWrite(left_1, LOW);
    digitalWrite(left_2, HIGH);

    // right motor
    digitalWrite(right_1, HIGH);
    digitalWrite(right_2, LOW);

    // servo angle
    angle = servo_left;
}

void stop(){
    // parametres for stop
    motor_speed = 0;

    // left motor
    digitalWrite(left_1, LOW);
    digitalWrite(left_2, LOW);

    // right motor
    digitalWrite(right_1, LOW);
    digitalWrite(right_2, LOW);

    // servo angle
    angle = myServo.read();
}
};