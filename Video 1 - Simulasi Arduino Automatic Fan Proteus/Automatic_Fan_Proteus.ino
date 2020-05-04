const int tempPin = A0;
const int relayPin  = 3;
int analogValue;
float tempValue;
float temperature;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogValue = analogRead(tempPin);
  tempValue = (analogValue/1024.0)*5000;
  temperature = tempValue/10;

  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println(" C");

  if(temperature > 33.0){
  // Relay menyala   
    digitalWrite(relayPin, LOW);  
  } else {
   // Relay Mati
    digitalWrite(relayPin, HIGH);  
  }

  delay(500);
  
}
