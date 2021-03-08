#include <Adafruit_NeoPixel.h>
#include "frames.h"
//#include <Bounce2.h>;

Adafruit_NeoPixel strip(24, 0);
//Bounce button1 = Bounce();
//boolean button1Toggle = false;
char but = 1;
char count = 0;
char whichFrame = 0;
char whichFrame2 = 0;

char stap = 500;
char startTime = millis();
char endTime;


char stap2 = 500;
char startTime2 = millis();
char endTime2;

char colors[4][3]{
  {200,0,255},
  {200,0,100},
  {0,255,255},
  {150,255,0}
};
void setup() {
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.setBrightness(1000);
  strip.clear();
  //pinMode(but, INPUT);

//  button1.attach(1,INPUT);
//  button1.interval(5);
  
}

void loop() {

  int  butState = digitalRead(but);
  if(butState == HIGH){
    count = (count + 1) %4; 
    }

  //button1.update();

//  if(button1.rose()){
//    button1Toggle = !button1Toggle;
//    if(button1Toggle){count = (count+ 1) &4;}
//  }
  switch(count){
      case 0: 
      off();
      break;
      case 1:
      still(); 
      break;
      case 2:
      animate();
      break;
      case 3:
      mappy(); 
      break;
      default:
      off();
      break;
      }
      
}

void off(){
    strip.clear();
    strip.show();
}

void still(){
    strip.clear();
    for(int i = 0; i < strip.numPixels(); i++){
     // int pixAddress = stat[i];   
     // if(pixAddress != -1){
     if(i>9){
    strip.setPixelColor(i,255,0,255);
   }
   else{strip.setPixelColor(i,255,0,0);
  }
  strip.show(); 
}
}

void animate(){
  strip.clear();
  endTime = millis(); 


  for(int i = 0; i < strip.numPixels(); i++){
   int whichColor = simple[whichFrame][i];

   int red = colors[whichColor][0];
   int green = colors[whichColor][1];
   int blue = colors[whichColor][2];

   strip.setPixelColor(i,red,green,blue);

  
}
   if(endTime - startTime >= stap){
    whichFrame = (whichFrame + 1) %2;
    startTime = millis();
   }
   strip.show(); 
}

void mappy(){
  strip.clear();
   endTime2 = millis(); 

  for(int i = 0; i < strip.numPixels(); i++){
   int whichColor = mapped[whichFrame2][i];

   int red = colors[whichColor][0];
   int green = colors[whichColor][1];
   int blue = colors[whichColor][2];

   strip.setPixelColor(i,red,green,blue);

}
   if(endTime2 - startTime2 >= stap2){
  whichFrame2 = (whichFrame2 + 1) %4;
  startTime2 = millis();
   }
      strip.show(); 

}
