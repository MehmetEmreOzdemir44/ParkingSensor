
#include <LiquidCrystal_I2C.h>
#define trigger      2
#define  echo         3
#define led1 4
#define led2 5
#define led3 6
#define led4 7
#define beep        11
#define beep_basla 50
#define min_mesafe  5

LiquidCrystal_I2C lcd(0x27,16,2);


#define c 0.0343


long tempo;
float mesafe;

void setup() {
  
  lcd.init();
  lcd.backlight();
  pinMode(trigger, OUTPUT);
  pinMode(echo,  INPUT);
  pinMode(beep, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  


  
  Serial.begin(9600);
}

void loop() {
  
  
  digitalWrite(trigger, LOW);
  delayMicroseconds(5);

  
  digitalWrite(trigger,  HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  
  tempo =  pulseIn(echo, HIGH) ;
  
  mesafe  = (tempo/2) * c;

  
  Serial.println("Mesafe  = " + String(mesafe, 1) + " cm");
  lcd.setCursor(0,0);
  lcd.print("Mesafe : ");
  lcd.print(mesafe);
  lcd.print("cm");

  
  if (mesafe < beep_basla) { 
    
    tone(beep, 1000); 
    delay(40);
    
    if (mesafe > min_mesafe)  {
      noTone(beep); 
      delay(mesafe * 4);
    }
  } 
  if(mesafe<=10)
  {
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,HIGH);
    
  }
  else if(mesafe<=20)
  {
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,LOW);
  }
  else if(mesafe<=30)
  {
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
  }
  else if(mesafe<=40)
  {
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
  }
  else
  {
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
  }
  
  
  delay(50);
}
