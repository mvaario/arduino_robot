void movement(){
    if (on){
        // motors
        analogWrite(left_enable, motor_speed);
        analogWrite(right_enable, motor_speed);

        // servo
        myServo.write(angle);
    }
    else{
        motor.stop();
        analogWrite(left_enable, motor_speed);
        analogWrite(right_enable, motor_speed);
    }
}

void interupts(){
    // switch check
    button.start_button();

    // sensor info
    sensor.left_sensor();
    sensor.right_sensor();
    // sensor.center_sensor();

    // vika sensori
    // sensor.up_sensor();

    // Interupts parameters
    while (left_distance < min_dis or right_distance < min_dis){
        motor.stop();
        movement();
    }





}

void rest(){
    // stop motors
    motor_speed = 0;
    angle = myServo.read();
    for (int i = 0; i < rest_time; i++){
        if (on){
            // movement();
            delay(10);
        }
        else{
            loop();
        }
    }
}
