class movement_setups {
public:
#include "settings.h"
#include "sensor.h"
#include "motors.h"
#include "switch.h"

switch_setups button;
sensor_setups sensor;
motor_setups motor;

void movement(){
    // INTERUPTS
    // switch check
    button.start_button();

    // sensor info
    sensor.left_sensor();
    sensor.right_sensor();
    // sensor.center_sensor();

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
    // stop motors
    motor_speed = 0;
    angle = myServo.read();
    for (int i = 0; i < rest_time; i++){
        if (on){
            // movement();
            delay(10);
        }
        else{
            loop();
        }
    }
}
};