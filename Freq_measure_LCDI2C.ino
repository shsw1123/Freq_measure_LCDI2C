#include <LiquidCrystal_I2C.h> 
#include <Wire.h>   //comunicate with I2C
LiquidCrystal_I2C lcd(0x27, 16, 2) ; // ระบุประเภท LCD
float ontime,offtime,period ; //ประกาศตัวแปร
int pin = 5; //ประกาศตัวแปร

float freq ; //ทศนิยม

void setup()
{
  pinMode(pin,INPUT);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight(); //เปิด backlight
  lcd.setCursor(0,0);
  lcd.print("Starting...");
  delay(2000);
  lcd.clear();
  
  //lcd.setCursor(1,0); // ที่ตำแหน่ง คอลัม 0 แถว 1
  //lcd.print("Frequency:"); // แสดงคำ
  //lcd.setCursor(8,1);
  //lcd.print("Hz");
  
    
}
void loop()
{
   lcd.setCursor(1,0); // ที่ตำแหน่ง คอลัม 0 แถว 1
   lcd.print("Frequency:"); // แสดงคำ
   lcd.setCursor(8,1);
   lcd.print("Hz");
   ontime = pulseIn(pin,HIGH); //เวลาที่ใช้จนถึง High
   offtime = pulseIn(pin,LOW); //เวลาที่ใช้จนถึง Low
   period = ontime+offtime; //ผลรวมเวลาที่ใช้
   freq = abs(1000000/period); //สูตรการหา Frequency
   Serial.println(freq,2);
   lcd.setCursor(1,1); // แสดงที่ตำแหน่ง 
   lcd.print(freq,2) ;
   
   delay(1000);
   lcd.clear();
}
