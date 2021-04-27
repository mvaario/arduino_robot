#include <Servo.h>
#include "motors.h"
#include "movement.h"
#include "switch.h"
#include "settings.h"

motor_setups motor;
movement_setups move;
switch_setups button;

void setup() {
  //Switch and leds
  pinMode(switch_pin, INPUT);
  // pinMode(green_led, OUTPUT);
  // pinMode(red_led, OUTPUT);
  // digitalWrite(red_led, LOW);
  // digitalWrite(green_led, LOW);

  //Sensor setups
  pinMode(left_trig, OUTPUT);
  pinMode(left_echo, INPUT);

  pinMode(right_trig, OUTPUT);
  pinMode(right_echo, INPUT);

  // pinMode(center_trig, OUTPUT);
  // pinMode(center_echo, INPUT);

  // motor
  pinMode(left_enable, OUTPUT);
  pinMode(left_1, OUTPUT);
  pinMode(left_2, OUTPUT);

  pinMode(right_enable, OUTPUT);
  pinMode(right_1, OUTPUT);
  pinMode(right_2, OUTPUT);


  myServo.attach(servo_pin);
  Serial.begin(9600);
  delay(1);
}

void loop () {
    // idle state - check switch
    button.start_button();
    
    if (on){
      move_state();
      on = false;
    }
    else{
      delayMicroseconds(100);
    }
}

void move_state(){
    // forward
    move.rest();
    motor.fordward();
    // while arguments
    move.movement();


    // // turn right
    // move.rest();
    // motor.right();
    // // while arguments
    // move.movement();

    // // forward
    // move.rest();
    // motor.fordward();
    // // while arguments
    // move.movement();


}