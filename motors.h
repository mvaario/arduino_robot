class motor_setups {
public:

void fordward(){
    // parametres for forward
    motor_speed = straight_speed;

    // left motor
    digitalWrite(left_1, HIGH);
    digitalWrite(left_2, LOW);

    // right motor
    digitalWrite(right_1, HIGH);
    digitalWrite(right_2, LOW);

    // servo angle
    angle = 90;
}

void backward(){
    // parametres for backward
    motor_speed = straight_speed;

    // left motor
    digitalWrite(left_1, LOW);
    digitalWrite(left_2, HIGH);

    // right motor
    digitalWrite(right_1, LOW);
    digitalWrite(right_2, HIGH);

    // servo angle
    angle = 90;
}

void right(){
    // parametres for right turn
    motor_speed = turning_speed;

    // left motor
    digitalWrite(left_1, HIGH);
    digitalWrite(left_2, LOW);

    // right motor
    digitalWrite(right_1, LOW);
    digitalWrite(right_2, HIGH);

    // servo angle
    angle = 180;
}

void left(){
    // parametres for left turn
    motor_speed = turning_speed;

    // left motor
    digitalWrite(left_1, LOW);
    digitalWrite(left_2, HIGH);

    // right motor
    digitalWrite(right_1, HIGH);
    digitalWrite(right_2, LOW);

    // servo angle
    angle = 0;
}
void stop(){
    // parametres for left turn
    motor_speed = 0;

    // left motor
    digitalWrite(left_1, LOW);
    digitalWrite(left_2, LOW);

    // right motor
    digitalWrite(right_1, LOW);
    digitalWrite(right_2, LOW);

    // servo angle
    angle = 0;
}


};