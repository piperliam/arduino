//Coded by Liam Piper
// 12/19/2021
//check out my website at: piperliam.github.io

//the connections are here: 
//vcc (+) -> +5v Adriuno 
//GND (-) -> Ground Adriuno
//TX -> D pin 2
//RX -> D pin 3




#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <time.h>

// Choose two Arduino pins to use for software serial (basiclly the input for the ardiuno from the GPS Mod
int RXPin = 2;
int TXPin = 3;

int GPSBaud = 9600;

// Create a TinyGPS++ object
TinyGPSPlus gps;

// Create a software serial port called "gpsSerial"
SoftwareSerial gpsSerial(RXPin, TXPin);



void setup()
{
  // Start the Arduino hardware serial port at 9600 baud
  Serial.begin(9600);

  // Start the software serial port at the GPS's default baud
  gpsSerial.begin(GPSBaud);
}

void loop()
{
  
  // This sketch displays information every time a new sentence is correctly encoded.
  while (gpsSerial.available() > 0)
    if (gps.encode(gpsSerial.read()))
      displayInfo();

  // If 5000 milliseconds pass and there are no characters coming in
  // over the software serial port, show a "No GPS detected" error
  if (millis() > 5000 && gps.charsProcessed() < 10)
  {
    Serial.println("No GPS detected");
    while(true);
  }
}

void displayInfo()
{
  if (gps.location.isValid())
  {
    Serial.print("Latitude: ");
    Serial.println(gps.location.lat(), 6);
    Serial.print("Longitude: ");
    Serial.println(gps.location.lng(), 6);
    Serial.print("Altitude: ");
    Serial.print(gps.altitude.meters());
    Serial.println(" Meters");

    
  }
  else
  {
    Serial.println("Location: Not Available");
  }
  
  Serial.print("Date (UTC): ");
  if (gps.date.isValid())
  {
    Serial.print(gps.date.month());
    Serial.print("/");
    Serial.print(gps.date.day());
    Serial.print("/");
    Serial.println(gps.date.year());
  }
  else
  {
    Serial.println("Not Available");
  }

  Serial.print("Time (UTC): ");
  if (gps.time.isValid())
  {
    if (gps.time.hour() < 10) Serial.print(F("0"));
 
    Serial.print(gps.time.hour());
    Serial.print(":");
    if (gps.time.minute() < 10) Serial.print(F("0"));
    Serial.print(gps.time.minute());
    Serial.print(":");
    if (gps.time.second() < 10) Serial.print(F("0"));
    Serial.print(gps.time.second());
    Serial.print(".");
    if (gps.time.centisecond() < 10) Serial.print(F("0"));
    Serial.println(gps.time.centisecond());
  }
  else
  {
    Serial.println("Not Available");
  }


  
//liam add
  Serial.print("Time (EST): ");
  if (gps.time.isValid())
  {
    if ((gps.time.hour()) < 10) Serial.print(F("0"));
 
    Serial.print(gps.time.hour()-5);
    Serial.print(":");
    if (gps.time.minute() < 10) Serial.print(F("0"));
    Serial.print(gps.time.minute());
    Serial.print(":");
    if (gps.time.second() < 10) Serial.print(F("0"));
    Serial.print(gps.time.second());
    Serial.print(".");
    if (gps.time.centisecond() < 10) Serial.print(F("0"));
    Serial.println(gps.time.centisecond());
  }
  else
  {
    Serial.println("Not Available");
  }


//speed print in for knots (very buggy but is here for you to mess with)
//Serial.print("Speed: ");
//Serial.print(gps.speed.value());
//Serial.print(" knots");
//Serial.println();

//displays the speed in miles per hour
Serial.print("Speed: ");
Serial.print(gps.speed.mph()); // Speed in miles per hour (double)
Serial.println(" MPH");

//displays the current gps based course in degrees
Serial.print("Course: ");
Serial.print(gps.course.value());
Serial.print(" degrees");
Serial.println();

//tells us how many satalites were connected at the time of transmitmsion
Serial.print("Satellites connected: ");
Serial.print(gps.satellites.value());
Serial.println();


//function returns horizontal diminution of precision
Serial.print("Horiz dimiution of precision: ");
Serial.print(gps.hdop.value());
Serial.println();

Serial.println("-------------------------------------");
  delay(1000);
}
