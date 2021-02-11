#ifndef _MAPPI_TELEGRAM_H_
#define _MAPPI_TELEGRAM_H_

#include "Arduino.h"
#include <math.h>
#include <SPI.h>
#include <LoRa.h>
#include <CTBot.h>

void MappiTelegram_setup(String ssid, String pass, String token,int id);
unsigned int MappiTelegram_msgAvailable(); 
String MappiTelegram_readMsg();
String MappiTelegram_sendMsg(String pesan);

#endif
