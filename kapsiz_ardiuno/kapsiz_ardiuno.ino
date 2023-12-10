int motorPin1 = 8;          //step motorun pinlerini belirledik
int motorPin2 = 9;
int motorPin3 = 10;
int motorPin4 = 11;
int motorDelayTime = 2;

int buttonPinIleri=2;    //butonların data pinlerini belirledik 
int buttonPinGeri=3;     //board'da butonların - kısmına direnç bağlamayı unutmayın!

int buttonStatusIleri=0; //butonların ilk çalışma durumunda 0 (LOW) olarak ayarladık
int buttonStatusGeri=0;

void setup() {
  pinMode(motorPin1, OUTPUT);  //step motorun pinlerini OUTPUT olarak yazdık
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  
  pinMode(buttonPinIleri, INPUT);  // butonları INPUT olarak ayarladık
  pinMode(buttonPinGeri, INPUT);
}

void loop() {
  buttonStatusIleri=digitalRead(buttonPinIleri);      //butonun data pininden gelen veriyi okuyup pin durumu için oluşturduğumuz değişkene yaz
  buttonStatusGeri=digitalRead(buttonPinGeri);
  if (buttonStatusIleri == HIGH)                     //eğer ileri durum değişkeni HIGH ise saat yönünde döndür 
      {
           
          digitalWrite(motorPin1, HIGH);            // step motorun saat yönünde dönmesi için gereken kodlar
          digitalWrite(motorPin2, LOW);
          digitalWrite(motorPin3, LOW);
          digitalWrite(motorPin4, LOW);
          delay(motorDelayTime);
          digitalWrite(motorPin1, LOW);
          digitalWrite(motorPin2, HIGH);
          digitalWrite(motorPin3, LOW);
          digitalWrite(motorPin4, LOW);
          delay(motorDelayTime);
          digitalWrite(motorPin1, LOW);
          digitalWrite(motorPin2, LOW);
          digitalWrite(motorPin3, HIGH);
          digitalWrite(motorPin4, LOW);
          delay(motorDelayTime);
          digitalWrite(motorPin1, LOW);
          digitalWrite(motorPin2, LOW);
          digitalWrite(motorPin3, LOW);
          digitalWrite(motorPin4, HIGH);
          delay(motorDelayTime);
      }
      else {
          digitalWrite(motorPin1, LOW);      // eğer ileri durum değişkeni LOW ise tüm pinlere 0V (LOW) ver 
          digitalWrite(motorPin2, LOW);
          digitalWrite(motorPin3, LOW);
          digitalWrite(motorPin4, LOW);
      }
        
      if (buttonStatusGeri == HIGH){        //eğer geri durum değikeni HIGH ise saat yönünün tersi tarafa döndür 
         
        digitalWrite(motorPin1, LOW);       // step motorun saat yönünün tersine dönmesi için gerekli kodlar
        digitalWrite(motorPin2, LOW);
        digitalWrite(motorPin3, LOW);
        digitalWrite(motorPin4, HIGH);
        delay(motorDelayTime);
        digitalWrite(motorPin1, LOW);
        digitalWrite(motorPin2, LOW);
        digitalWrite(motorPin3, HIGH);
        digitalWrite(motorPin4, LOW);
        delay(motorDelayTime);
        digitalWrite(motorPin1, LOW);
        digitalWrite(motorPin2, HIGH);
        digitalWrite(motorPin3, LOW);
        digitalWrite(motorPin4, LOW);
        delay(motorDelayTime);
        digitalWrite(motorPin1, HIGH);
        digitalWrite(motorPin2, LOW);
        digitalWrite(motorPin3, LOW);
        digitalWrite(motorPin4, LOW);
        delay(motorDelayTime);
      }
     else {                               //eğer geri durum değişkeni LOW ise tüm pinlere 0V (LOW) ver
          digitalWrite(motorPin1, LOW);
          digitalWrite(motorPin2, LOW);
          digitalWrite(motorPin3, LOW);
          digitalWrite(motorPin4, LOW);
      }

}
