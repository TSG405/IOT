const int led=11;                      // LED PIN - LOCATION
int value=0;                           // INSTANTIATION


void setup() 
   { 
      Serial.begin(9600);             // BAUD-RATE set to 9600
      pinMode(led, OUTPUT);           // LED configuration
      
      digitalWrite (led, LOW);
      Serial.println("... Connection successfully Established ...");
   }


void loop() 
   {
     while (Serial.available())
        {
           value = Serial.read();
        }
     
     if (value == '1')                // CONDITION ONE(1)
        digitalWrite (led, HIGH);
     
     else if (value == '0')           // CONDITION TWO(2)
        digitalWrite (led, LOW);       
   }


//CODED BY TSG405
