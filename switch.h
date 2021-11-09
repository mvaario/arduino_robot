void button_check(){
    // reading on switch
    on_switch = digitalRead(switch_pin);
    delay(1);

    if (on_switch == HIGH && old_switch == 0){
        old_switch = 1;
        if (on = false){
            on = true;
        }     
        else{
            on = false;
        }
    }
    else if (on_switch == LOW && old_switch == 1){
        old_switch = 0;
    }


    // for leds if needed
    // if (on){
    //     digitalWrite(red_led, LOW);
    //     digitalWrite(green_led, HIGH);
    // }
    // else{
    //     digitalWrite(red_led, HIGH);
    //     digitalWrite(green_led, LOW);
    // }
}