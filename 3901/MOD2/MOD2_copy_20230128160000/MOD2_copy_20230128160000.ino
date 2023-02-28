// defines pins numbers

const int trigPin = 9;
const int echoPin = 10;

// defines variables

long duration;
int distance;
int improveddistance;
unsigned long StartTime = 0;

void setup() {

pinMode(trigPin, OUTPUT); //Sets the trigPin as an output
pinMode(echoPin, INPUT); //Sets the echoPin as an input
Serial.begin(9600); //Starts the serial communication

//start a timer
unsigned long StartTime = millis();


}

void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

//Sets the trigPin on HIGH state for 10 microseconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

//Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

//Calculating the distance
//Speed of sound = 343 m/s at 20 oC = 0.0343 cm/us
distance = duration * 0.0343 / 2;

if (distance < 500) // rule out any stray glitches or measurements greater than 5m

{
//Below is the added line
improveddistance = 1.0429 * distance - 0.1905;
//Print the distance on the serial monitor
unsigned long CurrentTime = millis();
float ElapsedTime = (CurrentTime - StartTime) / 1000.0;
Serial.print("After "); Serial.print(ElapsedTime); Serial.print(" seconds, the distance (cm) was: ");
Serial.println(improveddistance);
delay(500);
}
}