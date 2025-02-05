#include <ESP32Servo.h>

// 2 servo devices
Servo myservo;
Servo theservo;

// Pin definitions for servos and potentiometer
int servoPin = 32;  //servo 1
int servoPin2 = 33; //servo 2
int potPin = 36; //ADC pin
int ADC_Max = 4096; //initialize ADC
int ADC_Dark = 2000;
int ADC_Light = 100;

// Position variables
int pos = 0;
int pos2 = 0;    
int val;
int val2; //portentiometer value for adc
void setup() {
  Serial.begin(9600);
  // timers from ESP32 sample code
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);

  // Set servo period to 50Hz or 20ms
  myservo.setPeriodHertz(50);
  theservo.setPeriodHertz(50);

  // Attach the servos to their pins
  myservo.attach(servoPin, 500, 2500);  // servo1 to 32
  theservo.attach(servoPin2, 500, 2500);  // Servo2 to 33
}

void loop() {
  val = analogRead(potPin);
  val2 = analogRead(potPin); //read ADC
  val = map(val, ADC_Light, ADC_Dark, 0, 180); //map servo 1 value
  val2 = map(val2, ADC_Light, ADC_Dark, 0, 180); //map it and its bounds
  myservo.write(val); // write to both servos
  theservo.write(val2);
  Serial.println(val);
  Serial.println(val2); //temp debug
  delay(200);
}