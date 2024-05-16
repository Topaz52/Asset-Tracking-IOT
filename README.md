# **Asset Tracking using IOT**
## **About this Project**
This is group project consists of two members per team. The contribution of this project is to develop a comprehensive and user-friendly asset tracking system that can be used to track assets in real time and protect them from theft. This project will develop an IoT-based asset tracking system that uses a combination of microcontroller called Arduino UNO, sensors, and communication devices to track the coordinates of the location. The sensors used are MPU6050, and IR Sensor. For communication devices, the Global Positioning System (GPS) and global system for mobile communication (GSM) are implemented in the system. The results of this project show the result of the GPS and GSM which are the coordinates and the coordinates sent via the message. The IR Sensor produces result in binary while the MPU6050 produces the axes of 3-dimension, X, Y, and Z.

## **Objectives**
1. To develop an asset tracking that uses GPS and GSM to track the location of the things.
2. To design the prototype for asset tracking.
3. To combine the coordinates tracker with alarm module.

## **Hardware Requirements**
  - Arduino UNO/ ESP8266
  - GSM Module <br />
  - GPS Module <br />
  - Power Supply <br />
  - Jumper Wires <br />
  - Buzzer <br />
  - MPU6050 Gyro + Accelerometer Sensor <br />
  - IR Sensor <br />
  - Breadboard <br />

## **Circuit Diagram**
![digital circuit diagram](https://github.com/Topaz52/Asset-Tracking-IOT/assets/86181104/c3f171ba-5f95-4b98-bc2e-8d4b0ee526f7)

## **Implementation**
1. Connect all the modules to the Arduino UNO as shown in the figure 8.
2. Then, connect the Arduino UNO to the computer.
3. For module 1, the libraries that are used is TinyGPS++ , SoftwareSerial and AltSoftSerial.
4. For module 2, the libraries used is MPU6050 by Sensor libraries by Adafruit.
5. Write the code.
6. The baud rate used for module 2 is 115200, while 9600 is used for module 1.
7. Make sure the wires that connected digital output are parallel to the written code before uploading the code to the Arduino board.
8. Upload the code to Arduino board.
9. Shake the MPU6050 to see whether it works or not. It if works, the buzzer will trigger, and the GSM will send the coordinates through message.
10. Put an object in front of IR Sensor. The built-in LED on IR Sensor would turn on if the object placed near the sensor.
11. Monitor the coordinates provided by GPS module using the serial monitor.
12. Type ‘S’ in the serial message box to send the coordinates the owner.

## **Results**
*Module 1: Coordinates Tracker System*

* GPS Serial Monitor

![gps result](https://github.com/Topaz52/Asset-Tracking-IOT/assets/86181104/8752a521-7213-48b9-89bc-37d3dc4d5141)

* GSM Serial Monitor

![gsm result](https://github.com/Topaz52/Asset-Tracking-IOT/assets/86181104/eede77e9-c0a9-4586-b942-3c63407931c4)

*Module 2: Motion and Vibration Alarm
*IR Sensor Output

![ir sensor](https://github.com/Topaz52/Asset-Tracking-IOT/assets/86181104/715b7ebd-5bd9-46f2-9df2-c0f1dff9a7ca)

*MPU6050 Output

![serial monitor for mpu6050](https://github.com/Topaz52/Asset-Tracking-IOT/assets/86181104/ff1717c6-0ef1-40ed-872b-58817ac31216)

* The coordinates is sent via message to users by GSM

![message sent by gsm](https://github.com/Topaz52/Asset-Tracking-IOT/assets/86181104/15b8fba5-b280-48b8-9aef-10edd72637a6)

## **Challenges**
* **Power consumption:** the Arduino UNO cannot handle too many powers or voltage. Because there are too many components used, some components cannot function properly. This is due to low voltage. The max voltage of Arduino UNO can provide is 5V. To fix this, additional power supply has been added to support the microcontroller.
* **Simple Message:** The message that sent to the user is only contain latitude and longitude. No Google Maps link provided. So, the user need to input the coordinates given into Google Maps to find the location.
* **Inaccuracy:** The accuracy when the coordinates has been inputted in the Google Maps app is not very accurate. The inaccuracy of the GPS is about 5 meters to 10 meters.
Delay in sending message: Since the GSM used SIM Card to send message, it might interfere with any device that use signal waves. The SIM Card also depends on signal strength. The lower the signal, the more delay will be, even worst, the message might not be sent.
* **Difference of baud rate used:** The baud rate used is 9600 for module 1 and 115200 for module 2. The problem occurs when the two modules are merged into a single module.
