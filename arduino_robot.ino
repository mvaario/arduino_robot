#include <Servo.h>
#include "settings.h"
#include "sensors.h"
#include "parameters.h"
#include "switch.h"
#include "movement.h"

void setup() {
  // switch
  pinMode(switch_pin, INPUT);

  // leds
  // pinMode(green_led, OUTPUT);
  // pinMode(red_led, OUTPUT);
  // digitalWrite(red_led, LOW);
  // digitalWrite(green_led, LOW);

  // Sensor setups
  pinMode(left_trig, OUTPUT);
  pinMode(left_echo, INPUT);

  pinMode(right_trig, OUTPUT);
  pinMode(right_echo, INPUT);

  // IR sensor
  pinMode(ir_sensor, INPUT);

  // motor
  pinMode(left_enable, OUTPUT);
  pinMode(left_1, OUTPUT);
  pinMode(left_2, OUTPUT);

  pinMode(right_enable, OUTPUT);
  pinMode(right_1, OUTPUT);
  pinMode(right_2, OUTPUT);


  myServo.attach(servo_pin);
  Serial.begin(9600);
  Serial.println("");
  delay(1);
}

void loop() {
  // idle state - check switch
  button_check();
  
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
  // delay
  rest(rest_time);

  // forward x amount times
  move_times = 100;
  for (int i = 0; i < move_times; i++){
    interupts_check();
    fordward();
    movement();
  }

  // delay
  rest(rest_time);
  // turn right x amount
  move_times = 50;
  for (int i = 0; i < move_times; i++){
    interupts_check();
    right();
    movement();
  }
  

  // delay
  rest(rest_time);
  // forward x amount
  move_times = 100;
  for (int i = 0; i < move_times; i++){
    interupts_check();
    fordward();
    movement();
  }
}