#include <SimpleDHT.h>


// for DHT11, 
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2
int pinDHT11 = D0;
int relay =D1;
int val=0;

SimpleDHT11 dht11(pinDHT11);

void setup() {
  pinMode(relay,OUTPUT);// RELAY
  pinMode(D2,INPUT);// IR
  pinMode(D3,OUTPUT);// BUZZER

  
  Serial.begin(115200);
}

void loop() {
  // start working...
  Serial.println("=================================");
  Serial.println("Sample DHT11...");
  
  // read without samples.
  byte temperature = 0;
  int maxtem =80;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess)
  {
    Serial.print("Read DHT11 failed, err="); 
    Serial.print(SimpleDHTErrCode(err));
    Serial.print(",");
    Serial.println(SimpleDHTErrDuration(err)); 
    delay(1000);
    return;
  }
   val=digitalRead(D2);
  int temp=(int)temperature;
  int hum=(int)humidity;
  if((temp>=40 || hum>=70) && val ==HIGH)
  {
    digitalWrite(D1,LOW); //relay
    digitalWrite(D3,LOW); // buzzer
    Serial.println("motor is on");
     Serial.print(val);
    
  }
  else 
  {
    digitalWrite(D1,HIGH); //relay
    digitalWrite(D3,HIGH); //buzzer
    Serial.print("motor is off AND rain is falling");
     Serial.print(val);
  }
    
  
  Serial.print("Sample OK: ");
  Serial.print(temp); 
  Serial.print(" *C, "); 
  Serial.print(hum);
  Serial.println(" H");
  
  // DHT11 sampling rate is 1HZ.
  delay(1500);

 

    
  }
  
  
  
  
  
