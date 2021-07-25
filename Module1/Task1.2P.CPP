// Constant Global Variables  
const uint8_t BTN_PIN = 2; 
const uint8_t LED_PIN = 13; 

// Global Variables 
uint8_t buttonPrevState = LOW; 
uint8_t ledState = LOW; 

// Setup and Define Pins and IO 
void setup() 
{
  // Configure pin behaviour 
  pinMode(BTN_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);

  // Attach interrupt to button change 
  attachInterrupt(digitalPinToInterrupt(BTN_PIN), setLed, CHANGE);

  // Setting Framerate 
  Serial.begin(9600);
}

void setLed()
{ 
  // Setting buttonState to read BTN_PIN
  uint8_t buttonState = digitalRead(BTN_PIN);

  // Output to serial terminal 
  Serial.print(buttonState);
  Serial.print(buttonPrevState);
  Serial.print(ledState);
  Serial.println();

  // Toggle LED_PIN on press
  if(buttonState != buttonPrevState) 
  {
    ledState = !ledState; 
    digitalWrite(LED_PIN, ledState); 
  }

  buttonPrevState = buttonState; 
} 

void loop()  
{ 
}
