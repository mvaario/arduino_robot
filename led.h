class led_setups {
public:

void control(){
  if (base){
    digitalWrite(red_led_pin, HIGH);
    digitalWrite(green_led_pin, HIGH);
  }

  else if (empty){
    blink();
  }

  else if (on){
    digitalWrite(red_led_pin, LOW);
    digitalWrite(green_led_pin, HIGH);
  }
  else {
    digitalWrite(red_led_pin, HIGH);
    digitalWrite(green_led_pin, LOW);
  }
}

void blink(){
  digitalWrite(green_led_pin, LOW);

  if (blinker > 200){
    blink_dif = -1;
  }
  else if (blinker < 0){
    blink_dif = 1;
  }
  blinker += blink_dif;

  if (blinker < 100){
    digitalWrite(red_led_pin, LOW);
  }
  else {
    digitalWrite(red_led_pin, HIGH);
  }
}
};

