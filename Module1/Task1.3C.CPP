int const motion = 2;		
int const button = 3;		
int const BlueLed = 13;		
int const GreenLed = 10;			


// Program setup code
void setup()
{
  pinMode(motion,INPUT); 		// Set up PIR sensor to get input
  pinMode(button,INPUT); 		// Set up button to get input
  pinMode(BlueLed, OUTPUT);	    // Set up Blue Led to show output
  pinMode(GreenLed, OUTPUT);	// Set up Green LED to show output
  
  attachInterrupt(digitalPinToInterrupt(motion),MotionInterrupt,CHANGE); // using interrupt for motion 
  attachInterrupt(digitalPinToInterrupt(button),ButtonInterrupt,CHANGE); // using interrupt for button 
	Serial.begin(9600); 		
}

// keep runing reapetly
void loop()
{
  delay(500);
}

// this function will handle the interrupt of motion
void MotionInterrupt()
{

  if (digitalRead(motion)== HIGH) // if motion detect an object the led will turn on
  {
    Serial.println();
    digitalWrite(BlueLed, HIGH);
    Serial.print("Motion Detected Now Blue Led Is ON!");
  }
   else							// else the led will turn off
   {
     Serial.println();
     digitalWrite(BlueLed, LOW);
     Serial.print("NO Motion Detected Now Blue Led Is OFF");
   }
}

// this function will handle the interrupt of button
void ButtonInterrupt()
{

  if (digitalRead(button)== HIGH) // if button is pressed the green led will turn on
  {
    Serial.println();
    digitalWrite(GreenLed, HIGH);
    Serial.print("Button Pressed Now Green Led Is ON");
    
  }
   else							// else the button is released and the led will turn off
   {
    Serial.println();
    digitalWrite(GreenLed, LOW);
    Serial.print("Button released Now Green Led Is OFF");
   }
}
