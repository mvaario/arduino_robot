class route_setups {
public:
#include "motors.h"
#include "servos.h"

servo_setups servo;
motor_setups motor;

void start(){
    // forward
    rest();
    motor.fordward();
    movement();


    // turn right
    rest();
    motor.right();
    movement();


    // forward
    rest();
    motor.fordward();
    movement();

}
void movement(){
    // switch check
    button.start_button();

    // sensor info
    sensor.left_sensor();
    sensor.right_sensor();
    sensor.center_sensor();

    // vika sensori
    // sensor.up_sensor();

    if (on){
        // motors
        analogWrite(left_enable, motor_speed);
        analogWrite(right_enable, motor_speed);

        // servo
        myServo.write(angle);
    }
    else{
        motor.stop();
        analogWrite(left_enable, motor_speed);
        analogWrite(right_enable, motor_speed);
    }
}

void rest(){
    motor_speed = 0;
    for (int i = 0; i < rest_time; i++){
        delay(5);
    }
}
};