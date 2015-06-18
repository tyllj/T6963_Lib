// A demo for the display

//#define boolean bool
#include "T6963.h"
#include "gfxdata.h"
#include "Times_New_Roman__14.h"

T6963 LCD(160,128,8,32);// 240x64 Pixel and 6x8 Font


//PROGMEM prog_uchar* animdemo[] = 	   // Flash Images for Animation 24 Frames 
//{   
//  IMG01bmp,IMG02bmp,IMG03bmp,IMG04bmp,IMG05bmp,IMG06bmp,IMG07bmp,IMG08bmp,IMG09bmp,IMG10bmp,IMG11bmp,IMG12bmp,IMG13bmp,IMG14bmp,IMG15bmp,IMG16bmp,IMG17bmp,
//  IMG18bmp,IMG19bmp,IMG20bmp,IMG21bmp,IMG22bmp,IMG23bmp,IMG24bmp  
//a};

char textmode[] = { '0','5','8','D'};
char* textmessage[] = { "           * Normal Display *           ", "          * Reverse Display *          ", "      * Blink of normal Display *      ", "      * Blink of reverse Display *      "};
int pcount;

void setup(){
  Serial.begin(9600);
  Serial.print("TH: ");
  Serial.print(LCD.getTH(), HEX);
  Serial.print("\n");
  Serial.print(LCD.getTH2(), HEX);
  Serial.print("\nGH: ");
  Serial.print(LCD.getGH(), HEX);
  Serial.print("\n");
  Serial.print(LCD.getGH2(), HEX);
  Serial.print("\n---\n");
  
  #if (defined(__AVR_ATmega1280__) || \
     defined(__AVR_ATmega1281__) || \
     defined(__AVR_ATmega2560__) || \
     defined(__AVR_ATmega2561__))      //--- Arduino Mega ---
  Serial.println("Arduino Mega");
  # else  //--- other Arduino ---
  Serial.println("not Arduino Mega");
  # endif
  
  LCD.Initialize(true);
  
  Serial.println("Initialized");
}

void loop(){
  for(byte _b=0;_b<128;_b +=8){
    LCD.TextGoTo(_b/8,_b/8);
    char str[20];
    sprintf(str, "%d Hello World", _b/8);
    LCD.writeString(str);
  }
  delay(3000);
  LCD.clearText();
  LCD.clearGraphic();
  
  LCD.setPixel(0,0);
  LCD.setPixel(159,0);
  LCD.setPixel(159,127);
  LCD.setPixel(0,127);
  delay(1000);
  LCD.createLine(0,0,0,127,1);
  delay(500);
  LCD.createLine(0,127,159,127,1);
  delay(500);
  LCD.createLine(159,127,159,0,1);
  delay(500);
  LCD.createLine(159,0,0,0,1); 
  delay(1000);
  LCD.clearGraphic();
  
  for(int x=0;x<127;x+=3){
    LCD.createLine(0,x,x*160/128,127,1);
    delay(50);
  }
  for(int x=0;x<159;x+=3){
    LCD.createLine(x,127,159,127-x*128/160,1);
    delay(50);
  }
  for(int x=0;x<127;x+=3){
    LCD.createLine(159,127-x,159-x*160/128,0,1);
    delay(50);
  }
  for(int x=0;x<159;x+=3){
    LCD.createLine(159-x,0,0,x*128/160,1);
    delay(50);
  }
  delay(3000);
  LCD.clearGraphic();
  
  for(int x=0; x<80; x+=2){
    LCD.createCircle(x,x,x,1);
    delay(10);
  }
  delay(3000);
  
  LCD.clearGraphic();
  LCD.clearText();

  //Font Demo
  LCD.glcd_print1_P(0, 0, "Times New Roman 14", &Times_New_Roman__14, 0);
  LCD.glcd_print1_P(0, 40, "Hello World", &Times_New_Roman__14, 0);
  LCD.glcd_print1_P(0, 80, "Hello World", &Times_New_Roman__14, 1);
  delay (4000);
  LCD.clearGraphic();
}
