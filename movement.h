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

    // stop and return to idle state
    if (on = false){
        stop();
        movement();
        loop();
    }

    // left sensor check
    trig = left_trig;
    echo = left_echo;
    left_distance = sensor_check(trig, echo);

    // right sensor check
    trig = right_trig;
    echo = right_echo;
    right_distance = sensor_check(trig, echo);

    // up sensor check
    // if (digitalRead(ir_sensor) == 1){
    //     stop();
    //     movement();
    //     // GIVING ARGUMENTS
    // }

    // stop when interupts
    while (left_distance < min_dis or right_distance < min_dis){
        stop();
        movement();
    }

}

void rest(int time){
    // stop motors
    stop();
    for (int i = 0; i < time; i++){
        interupts_check();
        movement();
        delay(10);
    }
}
