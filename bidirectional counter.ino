#include<LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);
#define in 8 // Entry IR Sensor Pin
#define out 9 // Exit IR Sensor Pin
#define section_A 10//PIR in Section A
#define section_B 11//PIR in Section B
#define led_A 12// LED Pin or room light
#define led_B 13 // LED Pin or room light
int count=0;

void setup()
{
  lcd.begin(16,2);
  lcd.print("Visitor Counter");
  delay(2000);
  pinMode(in, INPUT);
  pinMode(out, INPUT);
  pinMode(section_A, INPUT);
  pinMode(section_B, INPUT);
  pinMode(led_A, OUTPUT);
  pinMode(led_B, OUTPUT);
}
void loop()
{  
  int in_value = digitalRead(in);
  int A_Value = digitalRead(in);
  int out_value = digitalRead(out);
  int B_Value = digitalRead(in);
  if(in_value == 1)
  {
    count++;
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("Person In Room:");
    lcd.setCursor(0,1);
    lcd.print(count);
    delay(1000);
  }
  if(A_Value==1)
   {
  digitalWrite(led_A,HIGH); //IF Person is in Section A then it will turn on led_A
   }  
   if(B_Value==1)
   {
  digitalWrite(led_B,HIGH); //IF Person is in Section B then it will turn on led_B
   }     
  if(out_value == 1)
  {
    count--;
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("Person In Room:");
    lcd.setCursor(0,1);
    lcd.print(count);
    delay(1000);
  }


  if(count==0)
  {
    lcd.clear();
    lcd.setCursor(1,0); 
    lcd.print("Nobody In Room");
    lcd.setCursor(0,1);
    lcd.print(count);
    delay(1000);
  }
  else
  {
   digitalWrite(led_A,LOW);   
   digitalWrite(led_B,LOW);   
  }  
delay(2000);
} 
