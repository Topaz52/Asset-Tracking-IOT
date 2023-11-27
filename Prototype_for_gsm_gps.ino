#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <AltSoftSerial.h>

// ---------------------Motion and Vibration Alarm ------------------------------
// Libraries
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
// Intialized
Adafruit_MPU6050 mpu;
int irSensor = 6;

// Create a TinyGPS++ object
TinyGPSPlus gps;

// Create a software serial port called "gpsSerial"
SoftwareSerial gpsSerial(2, 3);
AltSoftSerial SIM900A(8, 9);
String googleMapsLink;  // Global variable to store the Google Maps link

void setup() {
  //-------------------------START OF Motion and Vibration Alarm
  pinMode(irSensor, INPUT);

  Serial.begin(9600);
  while (!Serial)
    delay(10);  // will pause Zero, Leonardo, etc until serial console opens

  Serial.println("Adafruit MPU6050 test!");

  // Try to initialize!
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");

  //setupt motion detection
  mpu.setHighPassFilter(MPU6050_HIGHPASS_0_63_HZ);
  mpu.setMotionDetectionThreshold(1);
  mpu.setMotionDetectionDuration(20);
  mpu.setInterruptPinLatch(true);  // Keep it latched.  Will turn off when reinitialized.
  mpu.setInterruptPinPolarity(true);
  mpu.setMotionInterrupt(true);

  // Serial.println("");
  delay(100);
  // -----------------------------------------END of Motion and Vibration Alarm----


  SIM900A.begin(9600);
  delay(1000);
  // Start the Arduino hardware serial port at 9600 baud
  //Serial.begin(9600);

  // Start the software serial port at the GPS's default baud
  gpsSerial.begin(9600);
}

void loop() {
  // --------------------------------------- START OF Motion and Vibration Alarm
  int value = digitalRead(irSensor);
  // Serial.println("");
  // Serial.print("Sensor Value = ");
  // Serial.print(value);

  if (value == 0) {
    tone(8, 349);
  } else {
    noTone(8);
  }
  delay(50);

  if (mpu.getMotionInterruptStatus()) {
    tone(8, 349);
    delay(1000);
    noTone(8);
    delay(1000);
    //SendMessage();
    delay(2000);

    /* Get new sensor events with the readings */
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);
  }

  delay(10);
  // ---------------------------------------------END OF Motion and Vibration Alarm

  // if (Serial.available()>0)
  //  switch(Serial.read())
  // {
  //   case 's':
  //     SendMessage();
  //     break;
  //   case 'r':
  //     RecieveMessage();
  //     break;
  // }

  if (SIM900A.available() > 0)
    Serial.write(SIM900A.read());
  //=================================================================================
  // This sketch displays information every time a new sentence is correctly encoded.
  while (gpsSerial.available() > 0)
    if (gps.encode(gpsSerial.read()))
      displayInfo();


  // If 5000 milliseconds pass and there are no characters coming in
  // over the software serial port, show a "No GPS detected" error
  if (millis() > 5000 && gps.charsProcessed() < 10) {
    Serial.println("No GPS detected");
    while (true)
      ;
  }
}
//=======================================================

//===========================================================================
void displayInfo() {

  if (gps.location.isValid()) {
    Serial.print("Latitude: ");
    Serial.println(gps.location.lat(), 6);
    Serial.print("Longitude: ");
    Serial.println(gps.location.lng(), 6);
    Serial.print("Altitude: ");
    Serial.println(gps.altitude.meters());

    googleMapsLink = String(gps.location.lat(), 6) + "," + String(gps.location.lng(), 6);

  } else {
    Serial.println("Location: Not Available");
  }

  Serial.println();
  Serial.println();
  delay(1000);
}

void SendMessage() {

  Serial.println("Sending Message");
  SIM900A.println("AT+CMGF=1\r");  // Set the GSM Module in Text Mode with \r
  delay(1000);

  Serial.println("Set SMS Number");
  delay(1000);
  SIM900A.println("AT+CMGS=\"+60193450165\"\r");  // Mobile phone number to send message with \r
  delay(1000);

  Serial.println("Set SMS Content");
  SIM900A.println(googleMapsLink);  // Message content
  delay(1000);

  Serial.println("Finish");
  SIM900A.println((char)26);  // ASCII code of CTRL+Z
  delay(1000);

  Serial.println("Message has been sent -> SMS Selesai dikirim");
}

void RecieveMessage() {
  Serial.println("SIM900A Membaca SMS");
  delay(1000);
  SIM900A.println("AT+CNMI=2,2,0,0,0");  // AT Command to receive a live SMS
  delay(1000);
  Serial.write("Unread Message done");
}