
//RGB LED PİNLER
const int redLed = 11;
const int greenLed = 10;
const int blueLed = 9;

const int fourLed = 5;

const int defButtonPin = 4;
const int buttonPin = 7;
const int buzzerPin = 6;

bool runningMac = false;
bool defused = false;

int i = 450;//Bip Sound Start Count

int defSec = 5;//Defuse Second
int sec = 0;

void setup() {

  Serial.begin(9600);
  
  //RGB LED PİN TANIMLAMA
  pinMode(redLed,OUTPUT);
  pinMode(greenLed,OUTPUT);
  pinMode(blueLed,OUTPUT);

  pinMode(fourLed,OUTPUT);
  
  pinMode(buttonPin,INPUT);
  pinMode(defButtonPin,INPUT);
}

void loop() {

 //changeColor("Red");
 
 
  //BAŞLAT // DURDUR
  if(digitalRead(buttonPin) == 1){
    
    runningMac = !runningMac;
    defused = false;
    i = 450;
    sec = 0;
    delay(150);
    
  }

   if(digitalRead(defButtonPin) == 1 && runningMac){

     if(sec<=defSec){
      
        delay(100);
        sec += 1;
        Serial.print(sec);
     }
    }else{
      sec = 0; 
    }

  if(runningMac){
    changeColor("Red"); 

   
    
      if(i>0){
        if(sec<=defSec && !defused){
          Serial.print(i);
          digitalWrite(fourLed,HIGH);
          melodi(i);
          digitalWrite(fourLed,LOW);
          delay(100);
          i-=20;
        }else{
          defused = true;
          changeColor("Green");
          digitalWrite(fourLed,LOW);
        }
      }else{
        changeColor("Green");
        defused = true;
        digitalWrite(fourLed,LOW);
      }
     
   
    
  }else{
    changeColor("Green");
    digitalWrite(fourLed,LOW);
  }
  
 
}




void changeColor(String color){

  if(color == "Red"){
    
    digitalWrite(redLed,LOW);
    digitalWrite(greenLed,HIGH);
    digitalWrite(blueLed,HIGH);
    
  }else if(color == "Green"){
    
    digitalWrite(redLed,HIGH);
    digitalWrite(greenLed,LOW);
    digitalWrite(blueLed,HIGH);
    
  }else if(color == "Blue"){
    
    digitalWrite(redLed,HIGH);
    digitalWrite(greenLed,HIGH);
    digitalWrite(blueLed,LOW);
    
  }else if(color == "White"){
    
    digitalWrite(redLed,LOW);
    digitalWrite(greenLed,LOW);
    digitalWrite(blueLed,LOW);
    
  }else{
    digitalWrite(redLed,HIGH);
    digitalWrite(greenLed,HIGH);
    digitalWrite(blueLed,HIGH);
  }

  /*if(R > 255 || G > 255 || B > 255){
    
    analogWrite(redLed,255);
    analogWrite(greenLed,255);
    analogWrite(blueLed,255);
    
  }else{
    
    analogWrite(redLed,255-R);
    analogWrite(greenLed,255-G);
    analogWrite(blueLed,255-B);
  }*/
  
}

void melodi(int dly){
  tone(buzzerPin , 440);
  delay(dly);
  noTone(buzzerPin);
  delay(dly);
}
