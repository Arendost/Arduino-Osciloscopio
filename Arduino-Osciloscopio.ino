#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);   
SoftwareSerial BT (0,1); 


float dato1=5.0;
float dato2=0.0;

void readd()
{
  dato1= (analogRead(A0)*0.00488);
  dato2=00.0;
}

void sendd()
{
 Serial.print('$');
 readd();
 Serial.print(dato1);
 Serial.print(dato2);
 Serial.print ('#');   
}


void setup() {
 Serial.begin(9600);
 lcd.begin(16,2); 
 
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Osciloscopio");
}

void loop() {
readd();   
lcd.setCursor(0,1);
lcd.print("Voltaje =");
lcd.setCursor(10,1); 
lcd.print(dato1);
sendd();
delay(1000); 
}
