#include <MappiTelegram.h>

String ssid = "KMTech";
String pass= "mappi32";
String token = "xxxxxx";//isi dengan token API telegram bot kalian
int id = 1386224063;//isi dengan id telegram kalian

String inputString = "";         // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete

unsigned int windSpeedCounter = 0;
unsigned long prevMillis = 0;//deklarasi nilai awal millis
unsigned int recordTime = 3;// waktu pembacaan sensor
float windSpeed;

void IRAM_ATTR isr() {
  windSpeedCounter++;
}

void setup() {
  // put your setup code here, to run once:
//  MappiTelegram_setup(...);
  Serial.begin(9600);
  MappiTelegram_setup(ssid,pass,token, id);
  attachInterrupt(18, isr, FALLING);
}

void loop() {
  String Status;
  
  if(millis() - prevMillis > recordTime*1000){
  windSpeed = (float)windSpeedCounter/(float)recordTime * 2.4;
  windSpeedCounter = 0;
  prevMillis = millis();  
  }
  Serial.print("Wind Speed: ");
  Serial.print(windSpeed);       //Speed in km/h
  Serial.print(" km/h - ");
  Serial.print(windSpeed / 3.6); //Speed in m/s
  Serial.println(" m/s");
  delay(1000);

  if(windSpeed < 45)
    {
        Status = "aman ";
        Serial.println(Status);
    }
  if(windSpeed >45)
    {
        Status = "angin kencang ";
        Serial.println(Status);
    }  
    
  if(MappiTelegram_msgAvailable()>0){
    Serial.println(MappiTelegram_readMsg());
    if(MappiTelegram_readMsg()== "wind speed"){
      String windspeed = String (windSpeed);
      
      Serial.println( MappiTelegram_sendMsg(windspeed));
      Serial.println( MappiTelegram_sendMsg(Status));
    }
  }
  }
  
