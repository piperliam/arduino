/*  Arduino DC Motor Control - PWM | H-Bridge | L298N  -  Example 01


    by Dejan Nedelkovski, www.HowToMechatronics.com
*/

#define PWMA 9
#define in1 6
#define in2 7
#define button 4

int rotDirection = 0;
int pressed = false;

void setup() {
  pinMode(PWMA , OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(button, INPUT);
  // Set initial rotation direction
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}

void loop() {
  int potValue = analogRead(A0); // Read potentiometer value
  int pwmOutput = map(potValue, 0, 1023, 0 , 255); // Map the potentiometer value from 0 to 255
  analogWrite(PWMA , pwmOutput); // Send PWM signal to L298N Enable pin
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

    delay(20);
  }
}
 