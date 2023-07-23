#include<Wire.h>
#include<LCD_I2C.h>
#include<DHT.h>
#define DHTPIN 5
#define DHTTYPE DHT11
LCD_I2C lcd(0x27,16,2);
DHT dht(DHTPIN,DHTTYPE);
int buzzer=12;
int sensor=2;
int detect;
void setup() {
  // put your setup code here, to run once:
  lcd.begin();
  lcd.backlight();

  pinMode(buzzer,OUTPUT);
  pinMode(sensor,INPUT);
  dht.begin();
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
    detect=digitalRead(sensor);
    delay(200);
    if(detect==0){
    int h=dht.readHumidity();
    int t=dht.readTemperature();
    lcd.setCursor(1,0);
    lcd.print("Humidity:");
    lcd.print(h);
    lcd.setCursor(1,1);
    lcd.print("Temp:");
    lcd.print(t);
    }
    else if(detect==1){
      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("Fire");
      tone(buzzer,450,500);
      delay(400);
      noTone(buzzer);
      delay(200);
    }
    digitalWrite(buzzer,LOW);    
}
