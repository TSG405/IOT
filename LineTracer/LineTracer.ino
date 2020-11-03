  // PROJECT, 2018
  
  // Physical Setup ----------------------------------
  
  int vSpeed = 120;       
  int turn_speed = 240;    
  int turn_delay = 5;
 
  const int motorA1      = 8;     //PINS....
  const int motorA2      = 10; 
  const int motorAspeed  = 9;
  const int motorB1      = 11; 
  const int motorB2      = 13; 
  const int motorBspeed  = 12;
  
  int left_sensor_state;
  int right_sensor_state;

  const int left_sensor_pin =A0;
  const int right_sensor_pin =A1;


void setup() 
{
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);

  Serial.begin(9600);
  delay(3000);
  
}


void loop() 
{
left_sensor_state = analogRead(left_sensor_pin);
right_sensor_state = analogRead(right_sensor_pin);

if(right_sensor_state > 550 && left_sensor_state < 550)
{
  Serial.println("Turn right");
  digitalWrite (motorA1,LOW);
  digitalWrite(motorA2,HIGH);                       
  digitalWrite (motorB1,LOW);
  digitalWrite(motorB2,HIGH);

  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, turn_speed);
  }
  
if(right_sensor_state < 500 && left_sensor_state > 500)
{
  Serial.println("Turn left");
  digitalWrite (motorA1,HIGH);
  digitalWrite(motorA2,LOW);                       
  digitalWrite (motorB1,HIGH);
  digitalWrite(motorB2,LOW);

  analogWrite (motorAspeed, turn_speed);
  analogWrite (motorBspeed, vSpeed);

  delay(turn_delay);
  }

if(right_sensor_state > 500 && left_sensor_state > 500)
{
  Serial.println("Forward");

  digitalWrite (motorA2,LOW);
  digitalWrite(motorA1,HIGH);                       
  digitalWrite (motorB2,HIGH);
  digitalWrite(motorB1,LOW);

  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, vSpeed);

  delay(turn_delay);
  }

if(right_sensor_state < 550 && left_sensor_state < 550)
{ 

  Serial.println(" HALT! ");
  
  analogWrite (motorAspeed, 0);
  analogWrite (motorBspeed, 0);
  
  } 
}
