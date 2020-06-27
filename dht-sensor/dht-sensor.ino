#include "dht.h"
#define dht_apin A0 
 
dht DHT;
 
void setup(){
 
  Serial.begin(9600);
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
    Serial.println("C  ");
    
    delay(5000); // wait some more before another reading
 
}