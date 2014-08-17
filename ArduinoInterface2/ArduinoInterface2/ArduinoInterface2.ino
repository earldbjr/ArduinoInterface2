/***************************************************************
 * Name:      ArduinoInterface2
 * Purpose:   Code for Arduino Transceiver
 * Author:    Gizmo (earldbjr@gmail.com)
 * Created:   17 Aug 2014
 * Copyright: Gizmo
 * License:
 **************************************************************/
#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

//int  intMenu, intSubmenu, intChoice, intEnd = -1;

void setup(){
  lcd.begin(16, 2);
  lcd.print("Booted");
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}
// :58 ;59
void loop() {
  String buffer;
  String argument;
  while(!Serial.available()){
    //Catch
  }
  if(Serial.peek() == '$'){
    Serial.read();//Remove start token
    while(Serial.peek() != ':'){
      buffer.concat(char(Serial.read()));
      delay(10);
    }
    buffer.toLowerCase();
    if(Serial.peek() == ':'){
      Serial.read();
      delay(10);
    }
    while(Serial.peek() != ';'){
      argument.concat(char(Serial.read()));
      delay(10);  
    }
    argument.toLowerCase();
    if(Serial.peek() == ';'){
      Serial.read();
    }
    lcd.setCursor(0,1);
    lcd.print("                ");
    lcd.setCursor(0,1);
    for(int i=0; i < buffer.length(); i++){
      lcd.print(buffer[i]
        );
    }
    lcd.print(":");
    for(int i=0; i < argument.length();i++){
      lcd.print(argument[i]);
    }
    Serial.read();//remove me
  }
  
}







