//Task 4 (bonus)
#include <LiquidCrystal.h>
#include <Servo.h>
Servo servo;
int servoPos;
float distance;
long time;
const int echoPin = 6;
const int trigPin = 7;
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.setCursor(0, 1);
  servo.attach(9);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600);

}

void loop() {
  digitalWrite(trigPin,LOW);
  delay(3);
  digitalWrite(trigPin,HIGH);
  delay(10);
  digitalWrite(trigPin,LOW);
  time = pulseIn(echoPin,HIGH);
  distance = time*0.034/2;
  Serial.println(distance);
  if(distance<150){
    for (servoPos=0;servoPos<=120;servoPos+=1){
       servo.write(servoPos);
       delay(15);
        lcd.setCursor(0, 0);
  			// print the number of seconds since reset:
  		lcd.print("hello, world!");
    }
  }
  lcd.clear();
  delay(1000);
}
