#include <dht.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define dht_apin A0 
 
dht DHT;

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
 
void setup(){
 
  Serial.begin(9600);
  lcd.begin(16, 2); // turn on lcd for both lines
  lcd.backlight();
  lcd.setCursor(0,0); // line 1
  lcd.print("Whoa Baby!");
  lcd.setCursor(0,1); // line 2
  lcd.print("I'm alive!");
  delay(500);//Delay for stability
  Serial.println("Reading the room\n");
  delay(1000);// wait a bit more
 
}
 
void loop(){
  //Start of Program 
 
    DHT.read11(dht_apin);
    
    Serial.print(" H = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("T = ");
    Serial.print(DHT.temperature); 
    Serial.println("ºC  ");
    lcd.setCursor(0,0); // line 1
    lcd.print("Humidity = ");
    lcd.print(DHT.humidity);
    lcd.print("%");
    lcd.setCursor(0,1); // line 2
    lcd.print("Temp = ");
    lcd.print(DHT.temperature); 
    lcd.print((char)223);
    lcd.print("C");
    
    delay(5000); // wait some more before another reading
 
}
