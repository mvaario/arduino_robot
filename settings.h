int on = false;                 // lets GOOOOO

//switch
const int switch_pin = 5;       // switch pin
int on_switch = 0;
int old_switch = 0;

//leds
// const int green_led = 0;    //led pin
// const int red_led = 0;      //led pin

// distance sensors
long duration;                  //time measure

const int left_trig = 3;        // left trigger (send)
const int left_echo = 2;        // left echo (receive)
float left_distance;            // calculated left distance

const int right_trig = 5;       // right trigger (send)
const int right_echo = 4;       // right echo (receive)
float right_distance;           // calculated right distance

// const int center_trig = 7;      // center trigger (send)
// const int center_echo = 6;      // center echo (receive)
// float center_distance;          // calculated center distance

// motors settings
const int left_enable = 6;          // left motor enable pin
const int left_1 = 22;              // left motor control 
const int left_2 = 24;              // left motor control 2

const int right_enable = 9;         // left motor enable pin
const int right_1 = 26;             // left motor control 
const int right_2 = 28;             // left motor control 2

const int turning_speed = 50;       // motor turning speed
const int straight_speed = 80;      // motor straight / backward speed
int motor_speed = 0;                // motor speed

int rest_time = 20;                 // rest time

//Servo setups
Servo myServo;

const int servo_pin = 10;        // servo pin
int angle = 90;                 // servo angle

