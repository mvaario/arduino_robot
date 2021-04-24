#include <Servo.h>
#include "settings.h"
#include "switch.h"
#include "route.h"
#include "sensor.h"


switch_setups button;
route_setups route;
sensor_setups sensor;

void setup() {
  //Switch and leds
  pinMode(switch_pin, INPUT);
  // pinMode(green_led, OUTPUT);
  // pinMode(red_led, OUTPUT);


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

  delay(1);
  Serial.begin(9600);
}

void loop () {
    // Start
    button.start_button();

    while (on){
      route.start();

    }
}