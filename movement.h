void movement(){
    // Check interupts
    interrupts();

    // Stop and return to idle state
    if (!on){
        stop();
        // motors
        analogWrite(left_enable, motor_speed);
        analogWrite(right_enable, motor_speed);

        // servo
        myServo.write(angle);

        loop();
    }

    // stop while interupted
    while (left_distance < min_dis or right_distance < min_dis){
        // hard code ei välttämättä paras, mut en keksiny parempaa ilma ylimmääräst callausta
        // motors
        analogWrite(left_enable, 0);
        analogWrite(right_enable, 0);

        // servo
        myServo.write(myServo.read());
        // timer could be nice here
    }

    // motors
    analogWrite(left_enable, motor_speed);
    analogWrite(right_enable, motor_speed);

    // servo
    myServo.write(angle);
    
}

void interupts(){
    // sensor info
    left_sensor();
    right_sensor();
    // sensor.center_sensor();

    // vika sensori
    // sensor.up_sensor();
}

void rest(){
    // stop motors
    stop();
    for (int i = 0; i < rest_time; i++){
        movement();
        delay(10);
    }
}
