# Arduino Code ( requires Adruino UNO, HC-SR04 Ultrasonic Sensor, Single channel Relay Module [5V-DC], LED Bulb )


const int trigPin = 4;
const int echoPin = 2;
const int relay = 9;
const int led = 13;
long duration;
float level;
void setup() 
{
  pinMode(trigPin, OUTPUT);                 // Sets the trigPin as an Output
  pinMode(relay, OUTPUT);                   // Sets the relay as an Output ----- for turning pump ON and OFF
  pinMode(led, OUTPUT);                     // Sets the LED as an Output
  pinMode(echoPin, INPUT);                  // Sets the echoPin as an Input
  digitalWrite (led, LOW);
  Serial.begin(9600);                       // Starts the serial communication
}

void loop() 
{
  digitalWrite(trigPin, LOW);
  delay(200);
  digitalWrite(trigPin, HIGH);  
  delay(1000);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);     
  float level = duration*0.034/2;
  delay (300);
  
  if (level <=5.0)
  {
    digitalWrite(led, HIGH);
    digitalWrite(relay, LOW);
    Serial.println("Water level HIGH, stop pump");
  }
  
  else if (level >=30.0)
  {    
    digitalWrite(led, HIGH);
    digitalWrite(relay, HIGH);
    Serial.println("Water level LOW, start pump");
  }
  else
  {
    //BY Dsync Team
    digitalWrite(led,LOW);
    digitalWrite(relay, LOW);
  }
  Serial.print("Current water level in cm: ");
 Serial.println(level);
 delay(2000);
}
