#include <Servo.h>   //servo ve step kütüphaneleri
#include <Stepper.h>

Servo servo1;  // Servo nesnesi oluşturuyoruz
Servo servo2;
Servo servo3;

int potpin1 = A0;   // Potansiyometrelerin bağlı olduğu pinler
int potpin2 = A1;   
int potpin3 =A2;


  
int pos = 0;         // Servo motorun açı değeri(ilk çalıştığında 0 derece)

void setup() {
servo1.attach(4);  // Servo motorların sinyal pinini belirtiyoruz
servo2.attach(5);
servo3.attach(6);


}

void loop() {
servo1a();
servo2a();
servo3a();
}

void servo1a(){                      //burda her servo için void açtım sebebi;tek loop içinde her servoya güç gitmesidir
  pos = analogRead(potpin1);  
  pos = map(pos, 0, 1023, 0, 180);
  servo1.write(pos);
  delay(20); 

}
void servo2a(){
   pos = analogRead(potpin2);  
  pos = map(pos, 0, 1023, 0, 180);  
 servo2.write(pos); 
 delay(20);
}
void servo3a(){
  pos = analogRead(potpin3);  
  pos = map(pos, 0, 1023, 0, 180);  
 servo3.write(pos);
 delay(20);
}
