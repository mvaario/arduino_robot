// parametres for forward
void forward(){
    // Motors speed
    motor_speed = straight_speed;

    // left motor direction
    digitalWrite(left_1, HIGH);
    digitalWrite(left_2, LOW);

    // right motor direction
    digitalWrite(right_1, HIGH);
    digitalWrite(right_2, LOW);

    // servo
    angle = straight_angle;
}

// parametres for backward
void backward(){
    motor_speed = straight_speed;

    // left motor
    digitalWrite(left_1, LOW);
    digitalWrite(left_2, HIGH);

    // right motor
    digitalWrite(right_1, LOW);
    digitalWrite(right_2, HIGH);

     // servo
    angle = straight_angle;
}

// parametres for right turn
void right(){
    motor_speed = straight_speed;

    // left motor
    digitalWrite(left_1, HIGH);
    digitalWrite(left_2, LOW);

    // right motor
    digitalWrite(right_1, LOW);
    digitalWrite(right_2, HIGH);

    // servo
    angle = right_angle;
}

// parametres for left turn
void left(){
    motor_speed = straight_speed;

    // left motor
    digitalWrite(left_1, LOW);
    digitalWrite(left_2, HIGH);

    // right motor
    digitalWrite(right_1, HIGH);
    digitalWrite(right_2, LOW);

    // servo
    angle = left_angle;

}

// parametres for stop
void stop(){
    motor_speed = 0;

    // left motor
    digitalWrite(left_1, LOW);
    digitalWrite(left_2, LOW);

    // right motor
    digitalWrite(right_1, LOW);
    digitalWrite(right_2, LOW);

    // servo
    angle = turning_servo.read();
}
