int blink_length = 200;  
int buttonPin = 2;            
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(buttonPin, INPUT); 
}int buttonState = 0;         
int lastButtonState = 1;     
bool isBlinking = false;     
bool restartBlinking = false; 

void loop() {
  buttonState = digitalRead(buttonPin);


  if (buttonState == LOW && lastButtonState == HIGH) {
    if (isBlinking) {
      restartBlinking = true;  // Signal to restart blinking
    } else {
      isBlinking = true;  // Start blinking
    }
  }

  
  if (isBlinking) {
    displayMorse("...");   // S
    if (restartBlinking) { restart(); return; }
    displayMorse(".-");    // A
    if (restartBlinking) { restart(); return; }
    displayMorse("--");    // M
    if (restartBlinking) { restart(); return; }
    displayMorse(".-");    // A
    if (restartBlinking) { restart(); return; }
    displayMorse("-.");   // N
    if (restartBlinking) { restart(); return; }
    displayMorse("-.--"); //Y
    if (restartBlinking) { restart(); return; }
    displayMorse("..-");  // U
    if (restartBlinking) { restart(); return; }
    isBlinking = false;    
    delay(1000);           
  }


  lastButtonState = buttonState;
}
void restart() {
  restartBlinking = false;  
  isBlinking = true;        
}
void displayMorse(String symbol) {
  for (int i = 0; i < symbol.length(); i++) {
    if (restartBlinking) {
      return;  
    }
    if (symbol[i] == '.') {
      digitalWrite(LED_BUILTIN, HIGH);
      delay(blink_length);      
    } else if (symbol[i] == '-') {   
      digitalWrite(LED_BUILTIN, HIGH);
      delay(blink_length * 3.5); 
    }
    digitalWrite(LED_BUILTIN, LOW);
    delay(blink_length);
  }
  /
  delay(blink_length * 3);
}