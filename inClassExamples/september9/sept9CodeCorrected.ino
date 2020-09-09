void setup()
{
  pinMode(12, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int switch1 = digitalRead(2);
  int switch2 = digitalRead(4);
  
  // why isn't my program working?
  // Let's check to see if the switches are correct:
  Serial.print("switch 1 reading is ");
  Serial.print(switch1);
  Serial.print("  switch 2 reading is ");
  Serial.print(switch2);
  Serial.println(); // start a new line the next time
  
  if (switch1 == HIGH) {
	  digitalWrite(12, HIGH);
  } else {
      digitalWrite(12, LOW);
  }
  
   if (switch2 == HIGH) {
	  digitalWrite(9, HIGH);
     Serial.println("LED on pin 9 should be on");
  } else {
      digitalWrite(9, LOW);
  }
  
}