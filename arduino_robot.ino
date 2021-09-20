#include <Servo.h>
#include "settings.h"
#include "sensors.h"
#include "motors.h"
#include "switch.h"
#include "movement.h"


void setup() {
  // Switch and leds
  // pinMode(switch_pin, INPUT);
  // pinMode(green_led, OUTPUT);
  // pinMode(red_led, OUTPUT);
  // digitalWrite(red_led, LOW);
  // digitalWrite(green_led, LOW);

  // Sensor setups
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
    start_button();
    
    // start 
    if (on){
      move_state();
      // on = false when done
      on = false;
      delay(100);
    }
    else{
      delayMicroseconds(100);
    }
}

void move_state(){
  // forward x amount times
  rest();

  for (int i = 0; i < 500; i++){
    fordward();
    movement();
  }

  rest();
  // turn right
  for (int i = 0; i < 500; i++){
    right();
    movement();
  }

  rest();
  // turn right x2 (180 degree)
  for (int i = 0; i < 500; i++){
    right();
    movement();
  }

  rest();
  // forward 2x
  for (int i = 0; i < 500; i++){
    fordward();
    movement();
  }
    
}