//Blinking LEDs Liam Piper

//sets up which digital pins with be assgnined to each LED
int LED1 = 0;
int LED2 = 1;
int LED3 = 2;
int LED4 = 3;
int LED5 = 4;

// This setup loop will run once to start the looping of LEDs
void setup() {                
  // initialize the digital pins to be in output mode 
  pinMode(LED1, OUTPUT);   
  pinMode(LED2, OUTPUT);  
  pinMode(LED3, OUTPUT);    
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
}

//the voild loop runs over and over creating the blinking LEDs
void loop() {
  digitalWrite(LED1, HIGH);   // This turns on the LEDs by writing to the digital pins in high power mode
  delay(80);                      // Pauses the code by a half-second to run
  digitalWrite(LED1, LOW);    // This turns the LEDs off by being in low power mode
  digitalWrite(LED2, HIGH);    // This turns on the LEDs by writing to the digital pins in high power mode
  delay(80);                      // Pauses the code by a half-second to run
  digitalWrite(LED2, LOW);     // This turns the LEDs off by being in low power mode
  digitalWrite(LED3, HIGH);     // This turns on the LEDs by writing to the digital pins in high power mode
  delay(80);                      // Pauses the code by a half-second to run
  digitalWrite(LED3, LOW);      // This turns the LEDs off by being in low power mode
  digitalWrite(LED4, HIGH);     // This turns on the LEDs by writing to the digital pins in high power mode
  delay(80);                      // Pauses the code by a half-second to run
  digitalWrite(LED4, LOW);      // This turns the LEDs off by being in low power mode
  digitalWrite(LED5, HIGH);     // This turns on the LEDs by writing to the digital pins in high power mode
  delay(80);                      // Pauses the code by a half-second to run
  digitalWrite(LED5, LOW);      // This turns the LEDs off by being in low power mode
  delay(80);                     // Last delay that occurs for a half second
}
