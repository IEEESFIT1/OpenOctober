// Code created by Kartikey Sharma
// Contribution to OpenOctober

int led = 3;           // attach LED to this pin
int brightness = 255;    // initial brightness of LED
int fadeAmount = 5;    // fade gradient per operation

void setup()  
{ 
  pinMode(led, OUTPUT);
} 

void loop()  
{ 
  // Set LED to initial brightness = 255
  analogWrite(led, brightness);    
  
  // Update brightness variable
  brightness = brightness - fadeAmount;

  // Reverse direction of fade once it reaches max or min 
  // value possible, ie, 0-255 
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ; 
  }        
  delay(100);                            
}
