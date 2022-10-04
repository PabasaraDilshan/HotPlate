
int HEATER = 3;
int test = 0;
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  Serial.println("test");
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(2,INPUT);
   pinMode(HEATER, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2), zero_cross, CHANGE);
}

// the loop function runs over and over again forever
void loop() {
  Serial.println(test);
    test = analogRead(A0);
//  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
//  delay(1000);                       // wait for a second
//  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
//  delay(1000);                       // wait for a second
}

void zero_cross()
{

  int dimming_time = (9800.0/1023.0)*test;

  delayMicroseconds(dimming_time);  


  digitalWrite(HEATER, HIGH);


  delayMicroseconds(10);


  digitalWrite(HEATER, LOW);


}
