void movement(){
  if (on){
      if (myServo.read() != angle){
      myServo.write(angle);
      delay(50);
      }
  }
}



