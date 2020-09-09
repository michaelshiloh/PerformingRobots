void setup()
{
  pinMode(12, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop()
{
  int switch1 = digitalRead(2);
  int switch2 = digitalRead(0);
  
  if (switch1 == HIGH) {
	  digitalWrite(12, HIGH);
  } else {
      digitalWrite(12, LOW);
  }
  
   if (switch2 == HIGH) {
	  digitalWrite(9, HIGH);
  } else {
      digitalWrite(9, LOW);
  }
  
}