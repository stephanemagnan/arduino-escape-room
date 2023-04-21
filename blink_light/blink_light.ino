#define LED 13  // The pin the LED is connected to

void setup() {
  pinMode(LED, OUTPUT); // Declare the LED as an output
}

void loop() {
  
  for(int i=0; i<=7; i++){
    digitalWrite(LED, HIGH); // Turn the LED on
    delay(500);
    digitalWrite(LED, LOW); // Turn the LED on
    delay(500);
  }
  delay(2000);
  for(int i=0; i<=0; i++){
    digitalWrite(LED, HIGH); // Turn the LED on
    delay(500);
    digitalWrite(LED, LOW); // Turn the LED on
    delay(500);
  }
  delay(2000);
  for(int i=0; i<=1; i++){
    digitalWrite(LED, HIGH); // Turn the LED on
    delay(500);
    digitalWrite(LED, LOW); // Turn the LED on 
    delay(500);   
  }
  delay(10000);

  
}
