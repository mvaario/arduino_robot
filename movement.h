void movement(){
    // Check interupts
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

    // servo
    myServo.write(angle);

    // motors
    analogWrite(left_enable, motor_speed);
    analogWrite(right_enable, motor_speed);


    // testing movement by printing things
    Serial.println("speed");
    Serial.println(motor_speed);
    Serial.println("angle");
    Serial.println(angle);
    delay(100);
}

void interupts(){
    start_button();
    // sensor info
    left_sensor();
    right_sensor();
    // sensor.center_sensor();

    // vika sensori
    // sensor.up_sensor();

    // stop while interupted
    while (left_distance < min_dis or right_distance < min_dis){
        // motors
        analogWrite(left_enable, 0);
        analogWrite(right_enable, 0);

        // servo
        myServo.write(myServo.read());
        // timer could be nice here

        start_button();
    }
}

void rest(){
    // stop motors
    stop();
    for (int i = 0; i < 1; i++){
        movement();
        delay(10);
    }
}
