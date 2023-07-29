#include <Servo.h>
Servo myServo; 
float percent;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
myServo.attach(9);
myServo.write(0);
delay(1000);
myServo.write(130);
}

void loop() {
  // put your main code here, to run repeatedly:
int lightLevel = analogRead(A0);

if(lightLevel <= 204){
  percent = lightLevel/204.0;
  myServo.write((26 * percent));
}else if(lightLevel <= 408){
  percent = lightLevel/408.0;
  myServo.write((26 * percent) + 26);
}else if(lightLevel <= 612){
  percent = lightLevel/612.0;
  myServo.write((26 * percent) + 52);
}else if(lightLevel <= 816){
  percent = lightLevel/816.0;
  myServo.write((26 * percent) + 78);
}else{
  percent = lightLevel/1024.0;
  myServo.write((26 * percent) + 104);
}
delay(1000);
Serial.println(percent);
Serial.println(lightLevel);
}