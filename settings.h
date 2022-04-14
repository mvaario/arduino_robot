// direction you want to go, available parameters {"forward", "left", "right", "backward"}
String users_direction[] = {"forward", "left", "forward", "right", "left"};

// Amount you want to go defined direction (100ms * x)
int users_distances[] = {20, 20, 20, 20, 20};

int on = true;                      // lets GOOOOO
String direction;
int move_times;

//switch
const int switch_pin = 5;           // switch pin
int on_switch;
int old_switch;

// motors settings
const int left_enable = 6;          // left motor enable pin
const int left_1 = 24;              // left motor control pin 1
const int left_2 = 22;              // left motor control pin 2

const int right_enable = 7;         // left motor enable pin
const int right_1 = 28;             // left motor control pin 1
const int right_2 = 26;             // left motor control pin 2

const int straight_speed = 80;      // motor straight / backward speed
const int turning_speed = 80;       // motor turning speed
const int motor_calibration = 0;    // change one motor speed: negative = left motor faster postive = right motor faster
int motor_speed;                    // motor speed

int rest_time = 5;                  // resting time (100ms * x)

// turning servo
Servo turning_servo; 
const int turning_servo_pin = 9;    // servo pin
               
int angle;                          // servo angle
const int straight_angle = 90;      // servo straight angle
const int left_angle = 10;          // servo left angle
const int right_angle = 170;        // servo right angle

// IR sensor
int ir_sensor;
const int ir_sensor_pin = 4;        // ir sensor pin

// giving servo
const int give_servo_pin = 11;
int give_on = false;
int give_servo_time = 1000;

// distance sensors
int trig;
int echo;
int distance;

const int left_trig = 1;            // left trigger (send)
const int left_echo = 42;           // left echo (receive)
long left_duration;                 // left sensor duration

const int right_trig = 3;           // left trigger (send)
const int right_echo = 2;          // left echo (receive)
long right_duration;                // right sensor duration

int min_distance = 5;              // distance to stop
