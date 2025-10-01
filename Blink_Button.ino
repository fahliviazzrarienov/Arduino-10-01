const int redPin = 9;    // Red on PWM pin
const int greenPin = 10; // Green on PWM pin
const int bluePin = 11;  // Blue on PWM pin
const int pressButton = 2;

int buttonState = 0;
int lastButtonState = HIGH; 
int value = 1;      
String colorLed ="Led";        

void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(pressButton, INPUT);

}

void loop() {
  buttonState = digitalRead(pressButton);

  // check if button just went from HIGH to LOW
  if (lastButtonState == HIGH && buttonState == LOW) {
    value = random(1, 8);   // generate new random only once
  }

  if (buttonState == HIGH) {
    // turn off LED (common anode = 255 = OFF)
    analogWrite(redPin, 255); 
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 255);
  } else {
    // show the color from getLight() using the stored value
    getLight(value);
    Serial.println(colorLed);
  }

  lastButtonState = buttonState; // save for next loop
}

void getLight(int value) {
  if (value == 1) {
    colorLed = "Red";
    analogWrite(redPin, 0);   
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 255);  
  } else if (value == 2) {
    colorLed = "Green";
    analogWrite(redPin, 255);   
    analogWrite(greenPin, 0);   
    analogWrite(bluePin, 255);
  } else if (value == 3) {    
    colorLed = "Blue";
    analogWrite(redPin, 255);   
    analogWrite(greenPin, 255); 
    analogWrite(bluePin, 0);  
  } else if (value == 4) {
    colorLed = "Yellow";
    analogWrite(redPin, 0);   
    analogWrite(greenPin, 0);   
    analogWrite(bluePin, 255);  
  } else if (value == 5) {
    colorLed = "Cyan";
    analogWrite(redPin, 255);   
    analogWrite(greenPin, 0);   
    analogWrite(bluePin, 0);  
  } else if (value == 6) {
    colorLed = "Purple";
    analogWrite(redPin, 0);   
    analogWrite(greenPin, 255);   
    analogWrite(bluePin, 0);  
  } else if (value == 7) {
    colorLed = "White";
    analogWrite(redPin, 0);   
    analogWrite(greenPin, 0);   
    analogWrite(bluePin, 0);  
  }
}
