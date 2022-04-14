// Mechatronics projekts - arduino robot
// 18i190
// main setup and scripts
#include <Servo.h>
#include "settings.h"
#include "parameters.h"
#include "componets.h"

// route lists lens, len(direction) == len(distance)
int direction_len = sizeof(users_direction) / sizeof(String);
int distance_len = sizeof(users_distances) / sizeof(int);

// define pin modes
void setup() {
  // switch
  pinMode(switch_pin, INPUT);

  // IR sensor
  pinMode(ir_sensor_pin, INPUT);

  // giving servo
  pinMode(give_servo_pin, OUTPUT);

  // distance sersors
  pinMode(left_trig, OUTPUT);
  pinMode(left_echo, INPUT);

  pinMode(right_trig, OUTPUT);
  pinMode(right_echo, INPUT);

  // turning servo
  turning_servo.attach(turning_servo_pin);

  // motors
  pinMode(left_enable, OUTPUT);
  pinMode(left_1, OUTPUT);
  pinMode(left_2, OUTPUT);

  pinMode(right_enable, OUTPUT);
  pinMode(right_1, OUTPUT);
  pinMode(right_2, OUTPUT);

  Serial.begin(9600);
  delay(1);
}

// idle state
void loop() {
  // quit if lengths don't match
  if (direction_len != distance_len){
    Serial.println("Routes don't match!");
    Serial.println("Check settings.h file");
    delay(100);
    exit(0);
  }

  // check switch
  button_check();

  // start
  if (on){
    delay(100);
    Serial.println("Running");
    // scripted route
    for (int i = 0; i < direction_len; i++){
      if (on == false){
        // stop
        stop();
        // move servo
        movement_servo();
        // move motor
        movement_motor();
        break;
      }

      // get move direction
      direction = users_direction[i];

      // get move amount
      move_times = users_distances[i];

      // send move arguments
      move_state(move_times, direction);
    }
    // stop
    rest(rest_time);
    Serial.println("Done");
    on = false;
    delay(500);
  }
  else{
    delay(50);
  }
}

// move state
void move_state(int move_time, String direction){
  Serial.println("Resting");
  // rest
  rest(rest_time);

  Serial.println(direction);
  // move users_distance amounts to users_direction
  for (int i = 0; i < move_times; i++){
    // check sensors and switch
    check_interupts();
    if (on == false){
      break;
    }

    // direction parameters
    if (direction == "forward"){
      forward();
    }
    else if(direction == "left"){
      left();
    }
    else if (direction == "right"){
      right();
    }
    else if (direction == "backward"){
      backward();
    }
    else{
      Serial.println("Error: Route error");
      Serial.println("Check settings.h file");
      delay(100);
      exit(0);
    }

    // move servo
    movement_servo();
    // move motor
    movement_motor();
  }
}

// checking sensors
void check_interupts(){
  // check button
  button_check();
  
  // check ir-sensor
  check_ir_sensor();
  check_give(ir_sensor);

  // check left distance
  trig = left_trig;
  echo = left_echo;
  left_duration = check_distance_sensor(trig, echo);

  // check right distance
  trig = right_trig;
  echo = right_echo;
  right_duration = check_distance_sensor(trig, echo);

  // Calculate shortest distance
  if (left_duration < right_duration){
      distance = left_duration * 0.034 / 2;
  }
  else{
      distance = right_duration * 0.034 / 2;
  }

  // stop if needed
  check_obstacle(distance);
}

// giving arguments
void check_give(int ir_sensor){
  // stop if ir sensor
  if (ir_sensor == 0){
      Serial.println("ir sensor");
      // stop parameters
      stop();
      // move servo
      movement_servo();
      // move motor
      movement_motor();

      delay(800);

      // giving servo
      movement_give_servo(give_servo_time);
      
      // check again
      check_interupts();    
  }
  // allow to give more
  give_on = false;
}

// stop if distance sensors
void check_obstacle(int distance){
  // Stop if necessary and check again
  if (distance <= min_distance and distance != 0){
    Serial.println("distance sensor");
    // stop
    stop();
    // move servo
    movement_servo();
    // move motor
    movement_motor();

    delay(10);

    // check again
    check_interupts();
  }
}

// resting
void rest(int time){
    // stop for a while
    stop();
    for (int i = 0; i < time; i++){
      if (on == false){
        break;
      }
      // servo movement
      movement_servo();
      // motor movements
      movement_motor();
      // check sensors
      check_interupts();
      delay(98);
    }
}
