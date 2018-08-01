/*
  LiquidCrystal Library - Hello World
 
 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the 
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.
 
 This sketch prints "Hello World!" to the LCD
 and shows the time.
 
  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 
 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7/11/2014
 by Jingjing Yi, LinkSprite
 
 This example code is in the public domain.
 
http://www.arduino.cc/en/Tutorial/LiquidCrystal
 
 */
 
#define Rbase ((unsigned long)47)
#define Rup ((unsigned long)75)  
#define Rdown  ((unsigned long)62) 
#define Rleft  ((unsigned long)47)  
#define Rright ((unsigned long)39)  
#define Rselect  ((unsigned long)28) 
 
// include the library code:
#include <LiquidCrystal.h>
 
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
 
int sensorValue ;
int KeyTable[31];
 
void GenerateKeyTable(int vcc,int* array)
{
  float resistor;
 
//////////////1key//////////////////////  
  resistor = ((float)Rup)/(Rbase + Rup);
  *array++ = resistor*vcc;
 
  resistor = ((float)Rdown)/(Rbase + Rdown);
  *array++ = resistor*vcc;
 
  resistor = ((float)Rleft)/(Rbase + Rleft);
  *array++ = resistor*vcc;
 
  resistor = ((float)Rright)/(Rbase + Rright);
  *array++ = resistor*vcc;
 
  resistor = ((float)Rselect)/(Rbase + Rselect);
  *array++ = resistor*vcc;
 
//////////////2 key/////////////////////////
  resistor = ((float)Rup)*Rdown/(Rup+Rdown);
  resistor = resistor/(resistor+Rbase);
  *array++ = resistor*vcc;
 
  resistor = ((float)Rup)*Rright/(Rup+Rright);
  resistor = resistor/(resistor+Rbase);
  *array++ = resistor*vcc;
 
  resistor = ((float)Rup)*Rleft/(Rup+Rleft);
  resistor = resistor/(resistor+Rbase);
  *array++ = resistor*vcc;
 
  resistor = ((float)Rup)*Rselect/(Rup+Rselect);
  resistor = resistor/(resistor+Rbase);
  *array++ = resistor*vcc;
 
  resistor = ((float)Rdown)*Rleft/(Rdown+Rleft);
  resistor = resistor/(resistor+Rbase);
  *array++ = resistor*vcc;
 
  resistor = ((float)Rdown)*Rright/(Rdown+Rright);
  resistor = resistor/(resistor+Rbase);
  *array++ = resistor*vcc;
 
  resistor = ((float)Rdown)*Rselect/(Rdown+Rselect);
  resistor = resistor/(resistor+Rbase);
  *array++ = resistor*vcc;
 
  resistor = ((float)Rright)*Rleft/(Rright+Rleft);
  resistor = resistor/(resistor+Rbase);
  *array++ = resistor*vcc;
 
  resistor = ((float)Rright)*Rselect/(Rright+Rselect);
  resistor = resistor/(resistor+Rbase);
  *array++ = resistor*vcc;
 
  resistor = ((float)Rleft)*Rselect/(Rleft+Rselect);
  resistor = resistor/(resistor+Rbase);
  *array++ = resistor*vcc;
 
  ///////////////3 key//////////////////////
  resistor = ((float)Rup*Rdown*Rright/(Rup*Rright + Rdown*Rright + Rup*Rdown));
  resistor = resistor/(resistor+Rbase);
  *array++ = resistor*vcc;
 
  resistor = ((float)Rup*Rdown*Rleft/(Rup*Rleft + Rdown*Rleft + Rup*Rdown));
  resistor = resistor/(resistor+Rbase);
  *array++ = resistor*vcc;
 
  resistor = ((float)Rup*Rdown*Rselect/(Rup*Rselect + Rdown*Rselect + Rup*Rdown));
  resistor = resistor/(resistor+Rbase);
  *array++ = resistor*vcc;
 
  resistor = ((float)Rleft*Rdown*Rright/(Rleft*Rright + Rdown*Rright + Rleft*Rdown));
  resistor = resistor/(resistor+Rbase);
  *array++ = resistor*vcc;
 
  resistor = ((float)Rleft*Rdown*Rselect/(Rleft*Rselect + Rdown*Rselect + Rleft*Rdown));
  resistor = resistor/(resistor+Rbase);
  *array++ = resistor*vcc;
 
  resistor = ((float)Rleft*Rup*Rright/(Rleft*Rright + Rup*Rright + Rleft*Rup));
  resistor = resistor/(resistor+Rbase);
  *array++ = resistor*vcc;
 
  resistor = ((float)Rleft*Rup*Rselect/(Rleft*Rselect + Rup*Rselect + Rleft*Rup));
  resistor = resistor/(resistor+Rbase);
  *array++ = resistor*vcc;
 
  resistor = ((float)Rup*Rright*Rselect/(Rup*Rright + Rright*Rselect + Rup*Rselect));
  resistor = resistor/(resistor+Rbase);
  *array++ = resistor*vcc;
 
  resistor = ((float)Rdown*Rright*Rselect/(Rdown*Rright + Rright*Rselect + Rdown*Rselect));
  resistor = resistor/(resistor+Rbase);
  *array++ = resistor*vcc;
 
 resistor = ((float)Rleft*Rright*Rselect/(Rleft*Rright + Rright*Rselect + Rleft*Rselect));
  resistor = resistor/(resistor+Rbase);
  *array++ = resistor*vcc;
 
  ////////////////4 key///////////////////////////
  resistor = ((float)Rup*Rdown*Rleft*Rright/(Rdown*Rleft*Rright + Rup*Rleft*Rright + Rup*Rdown*Rright + Rup*Rdown*Rleft));
  resistor = resistor/(resistor+Rbase);
  *array++ = resistor*vcc;
 
  resistor = ((float)Rup*Rdown*Rleft*Rselect/(Rdown*Rleft*Rselect + Rup*Rleft*Rselect + Rup*Rdown*Rselect + Rup*Rdown*Rleft));
  resistor = resistor/(resistor+Rbase);
  *array++ = resistor*vcc;
 
  resistor = ((float)Rup*Rselect*Rleft*Rright/(Rselect*Rleft*Rright + Rup*Rleft*Rright + Rup*Rselect*Rright + Rup*Rselect*Rleft));
  resistor = resistor/(resistor+Rbase);
  *array++ = resistor*vcc;
 
  resistor = ((float)Rselect*Rdown*Rleft*Rright/(Rdown*Rleft*Rright + Rselect*Rleft*Rright + Rselect*Rdown*Rright + Rselect*Rdown*Rleft));
  resistor = resistor/(resistor+Rbase);
  *array++ = resistor*vcc;
 
  resistor = ((float)Rselect*Rdown*Rup*Rright/(Rdown*Rup*Rright + Rselect*Rup*Rright + Rselect*Rdown*Rright + Rselect*Rdown*Rup));
  resistor = resistor/(resistor+Rbase);
  *array++ = resistor*vcc;
 
  /////////////////5 key//////////////////////////
  resistor = ((float)Rup*Rdown*Rleft*Rright*Rselect/(Rdown*Rleft*Rright*Rselect + Rup*Rleft*Rright*Rselect + Rup*Rdown*Rright*Rselect + Rup*Rdown*Rleft*Rselect + Rup*Rdown*Rleft*Rright));
  resistor = resistor/(resistor+Rbase);
  *array = resistor*vcc;
}
 
unsigned char GetKey(int value)
{
  char tmpChar;
  unsigned int Rst;
 
  tmpChar = 0;
  do{
      if(value > KeyTable[tmpChar]) Rst = value - KeyTable[tmpChar];
      else  Rst = KeyTable[tmpChar] - value;
     tmpChar ++;
  }while(Rst > 1);
 
  return tmpChar--;
 
}
 
void setup() 
{
  int tmpInt;
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
  sensorValue  = 1023;
   Serial.begin(9600); 
 
   GenerateKeyTable(analogRead(A0),KeyTable);
   for(tmpInt = 0;tmpInt <31;tmpInt++)
   {
     Serial.println(KeyTable[tmpInt]);
   }
}
 
void loop() 
{
  unsigned char key;
 
  if(sensorValue != analogRead(A0))
  {
     sensorValue = analogRead(A0);
     lcd.setCursor(0, 1);
     lcd.print(sensorValue);   
      key = GetKey(sensorValue);
      if(key < 31)
      {
        lcd.print("---");
        lcd.print(key);
        lcd.print(' ');
      }
      else  lcd.print("        ");
 
  }
}
