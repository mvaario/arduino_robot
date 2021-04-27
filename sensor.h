class sensor_setups {
public:
#include "settings.h"

// Left sensor
void left_sensor(){
    digitalWrite(left_trig, LOW);
    delayMicroseconds(2);

    digitalWrite(left_trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(left_trig, LOW);

    duration = pulseIn(left_echo, HIGH);
    left_distance = duration * 0.034 / 2;
}

// Right sensor
void right_sensor(){
    digitalWrite(right_trig, LOW);
    delayMicroseconds(2);

    digitalWrite(right_trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(right_trig, LOW);

    duration = pulseIn(right_echo, HIGH);
    right_distance = duration * 0.034 / 2;


}

// center sensor
// void center_sensor(){
//     digitalWrite(center_trig, LOW);
//     delayMicroseconds(2);

//     digitalWrite(center_trig, HIGH);
//     delayMicroseconds(10);
//     digitalWrite(center_trig, LOW);

//     duration = pulseIn(center_echo, HIGH);
//     center_distance = duration * 0.034 / 2;

// }
};
