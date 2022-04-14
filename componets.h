// Arduino componets - sending and receiving data
// move motor
void movement_motor(){
    // motors
    analogWrite(left_enable, motor_speed-motor_calibration);
    analogWrite(right_enable, motor_speed+motor_calibration);  
}

// move servo
void movement_servo(){
    turning_servo.write(angle);
    delay(98);
}

// check switch
void button_check(){
    // reading on switch
    on_switch = digitalRead(switch_pin);
    delay(1);
    
    // starting / stopping the loop
    if (on_switch == 1 && old_switch == 0){
        old_switch = 1;
        // stop
        if (on == true){
            Serial.println("Stopping");
            on = false;
        }
        // start
        else{
            on = true;
        }
    }
    else if (on_switch == 0){
        old_switch = 0;
    }
}

// send sensor
long check_distance_sensor(int trig, int echo){
//   distance sensors
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long duration;
  duration = pulseIn(echo, HIGH);


  return duration;
}

// check ir sensor
int check_ir_sensor(){
    // check ir sensor
    ir_sensor = digitalRead(ir_sensor_pin);
}

// move giving servo
int movement_give_servo(int time){
    if (give_on == false){
        give_on = true;
        analogWrite(give_servo_pin, 1);
        delay(time);
    }
    // stop servo
    analogWrite(give_servo_pin, 0);
    delay(1000);
}