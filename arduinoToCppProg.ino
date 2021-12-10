
#include <Servo.h> 
 
Servo myservo1;
//Servo myservo2;

//int ledPin=13;
const int buzz=10;

void setup(){
  Serial.begin(9600);
  myservo1.attach(9);       // attaching servo at pin 9
  pinMode(buzz,OUTPUT);
  //pinMode(ledPin, OUTPUT);
  }

void loop(){
      if(Serial.available()>0){
          String info;
          info=Serial.readStringUntil('\n');
          if(info.equals("LEFT")){
            myservo1.write(180);
            delay(5000);                                //wait for 5 second then again close the door
            myservo1.write(90);
            delay(500);
            //digitalWrite(ledPin, HIGH);
            //Serial.println("LEFT GATE was OPENED");
          }
          else if(info.equals("RIGHT")){
            myservo1.write(0);
            delay(5000);                              //wait for 5 second then again close the door
            myservo1.write(90);
            delay(500);
             // digitalWrite(ledPin,LOW);
             // Serial.println("RIGHT GATE was OPENED");
          }
          else if(info.equals("ALERT")){
            tone(buzz,1000);
            delay(5000);
            noTone(buzz);
             // digitalWrite(ledPin,LOW);
             // Serial.println("Unknown person ALERT!! ALERT!! ALERT!!");
          }
      }
}
