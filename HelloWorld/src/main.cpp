#include <M5Stack.h>

void setup() {
  // 初始化M5Stack
  M5.begin();

  // LCD 显示
  M5.Lcd.setCursor(100, 120);

  M5.Lcd.setTextColor(RED);

  M5.Lcd.setTextSize(2);

  M5.Lcd.printf("Hello world!");
}

void loop() {

    // 更新显示内容
    M5.update();
}