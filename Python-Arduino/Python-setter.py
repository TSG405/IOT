import serial         # Using SERIAL module to connect to comm ports via ARDUINO                        

Arduino_Serial = serial.Serial('/dev/ttyACM0',9600)       # Connecting via ttyACM0 port (LINUX)

print (Arduino_Serial.readline())                         # Status

print ("Please enter --------> 1 <------- to TURN ON THE LED and  ---------> 0 <-------- to TURN OFF THE LED")

while (True): 
                                                   # InFinite LOOP
    input_data = input()                  
    print ( "USER Entered... ", input_data )     
    
    if (input_data == '405'):                      # Exit Condition
        print ("--- Thank You ---")
        print ("--- ! BYE ! ---")
        break;
        
    elif (input_data == '1'):                      # Condition ONE
        Arduino_Serial.write( '1'.encode() )       # For Python 3 and above --> use "encode" to convert raw input into bytes!    
        print ("--- LED IS ON NOW ---")
        print ("PRESS 405 to exit!!")
    
    elif (input_data == '0'):                      # Condition TWO              
        Arduino_Serial.write( '0'.encode() )       # For Python 3 and above --> use "encode" to convert raw input into bytes!      
        print ("--- LED IS OFF NOW ---")
        print ("PRESS 405 to exit!!")
        
                
'''
CODED BY TSG405
'''
