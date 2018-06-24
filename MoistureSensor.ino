//Connect the Soil Mosture Sensor to anolog input pin 0, 
//and your 5 led to digital out 2-6</p><p>*/
int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
int pump = 7;
int dryCount = 0;

int mostureSensor = 0;

void setup() {
  // Serial Begin so we can see the data from the mosture sensor in our serial input window. 
  Serial.begin(9600);
  // setting the led pins to outputs
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(pump, OUTPUT); // Brown = Ground, Red = 5v, Orange = Signal (Pin 7)
}

void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(mostureSensor);

  if (sensorValue < 816)
    dryCount = 0;
  if (sensorValue >= 816) {
    if (dryCount > 10)
      Serial.println((String)"LED 6 - RUN PUMP (" + (String)sensorValue + (String)")");
    else
      Serial.println((String)"LED 6 (" + (String)sensorValue + (String)")");
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, HIGH);
    digitalWrite(pump, HIGH);
    dryCount++;
  }
  else if (sensorValue >= 612  && sensorValue < 816) {
    Serial.println((String)"LED 4 (" + (String)sensorValue + (String)")");
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, LOW);
    digitalWrite(pump, LOW);
  }  
  else if (sensorValue >= 408 && sensorValue < 612) {
    Serial.println((String)"LED 3 (" + (String)sensorValue + (String)")");
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(pump, LOW);
  }    
  else if (sensorValue >= 204 && sensorValue < 408) {
    Serial.println((String)"LED 2 (" + (String)sensorValue + (String)")");
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(pump, LOW);
  }
  else if (sensorValue >= 0 && sensorValue < 204) {
    Serial.print("LED 1 (");
    Serial.print(sensorValue);
    Serial.println(")");
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(pump, LOW);
  } else {
    Serial.println("All LEDs (Error)");
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    digitalWrite(pump, LOW);
  }
  delay(1000 * 4);        // delay 4 seconds between reads
}
