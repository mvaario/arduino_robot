void movement(){
    // servo
    myServo.write(angle);
    // needs delay?

    // motors
    analogWrite(left_enable, motor_speed);
    analogWrite(right_enable, motor_speed);

}

void interupts_check(){
    // check start/stop button
    button_check();

    // left sensor check
    int trig = left_trig;
    int echo = left_echo;
    left_distance = sensor_check(trig, echo);

    // right sensor check
    trig = right_trig;
    echo = right_echo;
    right_distance = sensor_check(trig, echo);

    // up sensor check

    // stop when interupts
    while (left_distance < min_dis or right_distance < min_dis){
        stop();
        movement();
    }

}

void rest(int sleep){
    // stop motors
    stop();
    for (int i = 0; i < sleep; i++){
        interupts_check();
        movement();
        delay(10);
    }
}
