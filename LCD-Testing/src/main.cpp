#include <Arduino.h>
#include <LiquidCrystal.h>
#define BUTTON_S1 2

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 6;
int count = 0;
bool buttonpressed=false;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

/* ISR for Button S1 */
void s1Pressed(void){
buttonpressed=true;
}

void setup() {
  pinMode(BUTTON_S1, INPUT);
  attachInterrupt(digitalPinToInterrupt(BUTTON_S1), s1Pressed, RISING);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.setCursor(0, 0);
  lcd.print("niemand ontsmet");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  if(buttonpressed){
count++;
count %=4;

lcd.clear();
lcd.setCursor(0, 0);
if(count>0)
{
lcd.print("aantal ontsmette");
lcd.setCursor(0, 1);
lcd.print("mensen: ");
lcd.setCursor(8, 1);
lcd.print(count);
}
else 
{
  lcd.print("iedereen is ");
  lcd.setCursor(0, 1);
  lcd.print("ontsmet");
}
/*
switch (count) {
  case 0:
    lcd.print("#ontsmet = 0");
    break;
  case 1:
    lcd.print("#ontsmet = 1");
    break;
  case 2:
    lcd.print("#ontsmet = 2");
    break;
  case 3:
    lcd.print("#ontsmet = 3");
    break;
  case 4:
    lcd.print("Iedereen is");
    lcd.setCursor(0, 1);
    lcd.print("ontsmet");
    break;  
  default:
    count=0;
    break;
}*/

buttonpressed=false;
}







  
  
}