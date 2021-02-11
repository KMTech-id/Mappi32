#include "MappiTelegram.h"

CTBot MappiTelegram_mybot;
String MappiTelegram_pesan;
int MappiTelegram_id;
void MappiTelegram_setup(String ssid, String pass, String token, int id)
{
  #if MappiTelegram_serial == 1
  Serial.println("Memulai telegram bot. koneksi ke wifi");
  #endif
  
  MappiTelegram_mybot.wifiConnect(ssid, pass);
  MappiTelegram_mybot.setTelegramToken(token);
  MappiTelegram_id= id;
}

unsigned int MappiTelegram_msgAvailable(){
  TBMessage msg;  
  if(MappiTelegram_mybot.getNewMessage(msg)) // >0
  {
    MappiTelegram_pesan = msg.text;// halo
    return 1;
  }
  return 0;
}

String MappiTelegram_readMsg(){
  return MappiTelegram_pesan;
}
String MappiTelegram_sendMsg(String pesan){
  String ret = "OK";
  if(!MappiTelegram_mybot.testConnection())
  ret="gagal";
  MappiTelegram_mybot.sendMessage(MappiTelegram_id,pesan);
  return ret;
}
