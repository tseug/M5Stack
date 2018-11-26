#include <M5Stack.h>
#include <WiFi.h>
#include <Time.h>
#include <Timezone.h>

#include "ntp.h"

String wifi_ssid = "BOCOITS";
String wifi_password = "boco85308686";

// 北京时间时区
#define STD_TIMEZONE_OFFSET +8    

TimeChangeRule mySTD = {"", First,  Sun, Jan, 0, STD_TIMEZONE_OFFSET * 60};
Timezone myTZ(mySTD, mySTD);


void setup() {
  int count = 0;

  // 初始化M5Stack
  M5.begin();
  M5.Lcd.setTextColor(RED);
  M5.Lcd.setTextSize(2);

  // 初始化WIFI
  WiFi.begin(wifi_ssid.c_str(), wifi_password.c_str());
  
  M5.Lcd.setCursor(100,100);
  M5.Lcd.print(wifi_ssid);

  M5.Lcd.setCursor(100, 120);
  M5.Lcd.print(".");
  
  while ( count < 30 ) {
    if (WiFi.status() == WL_CONNECTED) {
      M5.Lcd.setCursor(100, 120);
      M5.Lcd.println("Connected!");
    }

    delay(500);
    count++;
  }

}

void loop() {

    // 更新显示内容
    M5.update();
}