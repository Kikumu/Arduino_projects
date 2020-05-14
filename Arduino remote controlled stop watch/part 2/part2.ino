#include <Adafruit_NeoPixel.h> 
#define PIN 8
#include <TimerOne.h>
Adafruit_NeoPixel strip = Adafruit_NeoPixel(84, PIN, NEO_GRB + NEO_KHZ800); 

int r =0;
int g = 0;
int b = 100;
int segment;

const int reset = 8;
const int stopstart = A4;

unsigned char ten;
unsigned char seconds;
unsigned char Lmiliseconds;
unsigned char mili;

long n = 0;// n represents the value displayed on the LED display. For example, when n=0, 0000 is displayed. The maximum value is 9999. 
int x = 100;
int del = 5;//Set del as 5; the value is the degree of fine tuning for the clock
int time = 5;//Set count=0. Here count is a count value that increases by 1 every 0.1 second, which means 1 second is counted when the value is 10
int State;
int State2;
unsigned long time1 = 0;
unsigned long now = 0;
unsigned long then = 0;
int pushbutton = 0;
int pushbutton2 = 0;
bool paused;
bool lastState;
unsigned long count;
bool reseted;
int resets;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(reset, INPUT);
  pinMode(stopstart, INPUT);
  Timer1.initialize(10000);
  Timer1.attachInterrupt(startcount);
  strip.begin();

}
/*
void screen(int number)
{
   unsigned char thousands = int (number/1000);
  unsigned char hundreds = int((number/100)%10);
  unsigned char tens = int ((number/10)%10);
  unsigned char ones = int(number %10);
//1234
  //ones
  segmentPicker(4); 
  numbers(ones);
  strip.show();

  
//tens
segmentPicker(3);
  numbers(tens);
  strip.show();


//hundreds
   segmentPicker(2);
 numbers(hundreds);
 strip.show();
  
//thousands
   segmentPicker(1);
  numbers(thousands);
strip.show();
  
}
*/
void screen(){
segmentPicker(4);
  numbers(Lmiliseconds);

 delay (time);
    segmentPicker(3);
 numbers(mili);

delay (time);
  segmentPicker(2);
  numbers(seconds);

delay (time);
 segmentPicker(1);
  numbers(ten);

 delay (time);
}

void loop() {
  // put your main code here, to run repeatedly:
  screen();
  State = digitalRead(A4);// Reads inputy of start stop button

  if (State != lastState) // if button is pressed and has a value >0
  { 
    if (State == HIGH) // if state is high
    {
      pushbutton++; // Increase the amount of times pushed
    }
  }
  lastState = State; // reset the amount of times pushed
 
  if (pushbutton %2 != 1) // fiqures out what state the button is in
  {
      paused = false;
  }
  else  {paused = true;}

  resets = digitalRead(A5);

if(resets==HIGH)
{count=0;}

screen();

}


void startcount()
{
  ten = (count/1000);
  seconds = ((count%1000)/100);
  mili =  ((count%100)/10);
  Lmiliseconds = (count%10);
  Serial.println(count);

  if(paused == false)
  {
  count++;
 if(resets==HIGH)
{count=0;}
  }  
  if(count>1000000)
   {
    //Timer1.detachInterrupt();
    count=100000;
   }
}
void numbers(int numberToDisplay)
{
  switch (numberToDisplay)
  {
    case 0:
strip.setPixelColor(0+segment,r,g,b); //Segment A
strip.setPixelColor(1+segment,r,g,b); //Segment A
strip.setPixelColor(2+segment,r,g,b); //Segment A
strip.setPixelColor(3+segment,r,g,b); //Segment B
strip.setPixelColor(4+segment,r,g,b); //Segment B
strip.setPixelColor(5+segment,r,g,b); //Segment Bm
strip.setPixelColor(6+segment,r,g,b); //Segment C
strip.setPixelColor(7+segment,r,g,b); //Segment C
strip.setPixelColor(8+segment,r,g,b); //Segment C
strip.setPixelColor(9+segment,r,g,b); //Segment D
strip.setPixelColor(10+segment,r,g,b); //Segment D
strip.setPixelColor(11+segment,r,g,b); //Segment D
strip.setPixelColor(12+segment,r,g,b); //Segment E
strip.setPixelColor(13+segment,r,g,b); //Segment E
strip.setPixelColor(14+segment,r,g,b); //Segment E
strip.setPixelColor(15+segment,r,g,b); //Segment F
strip.setPixelColor(16+segment,r,g,b); //Segment F
strip.setPixelColor(17+segment,r,g,b); //Segment F
strip.setPixelColor(18+segment, 0, 0, 0);
strip.setPixelColor(19+segment, 0, 0, 0);
strip.setPixelColor(20+segment, 0, 0, 0);
strip.setPixelColor(21+segment, 0, 0, 0);
strip.show();
break;

case 1:
strip.setPixelColor(0+segment,0,0,0); //Segment A
strip.setPixelColor(1+segment,0,0,0); //Segment A
strip.setPixelColor(2+segment,0,0,0); //Segment A
strip.setPixelColor(3+segment,r,g,b); //Segment B
strip.setPixelColor(4+segment,r,g,b); //Segment B
strip.setPixelColor(5+segment,r,g,b); //Segment B
strip.setPixelColor(6+segment,r,g,b); //Segment C
strip.setPixelColor(7+segment,r,g,b); //Segment C
strip.setPixelColor(8+segment,r,g,b); //Segment C
strip.setPixelColor(9+segment,0,0,0); //Segment D
strip.setPixelColor(10+segment,0,0,0); //Segment D
strip.setPixelColor(11+segment,0,0,0); //Segment D
strip.setPixelColor(12+segment,0,0,0); //Segment E
strip.setPixelColor(13+segment,0,0,0); //Segment E
strip.setPixelColor(14+segment,0,0,0); //Segment E
strip.setPixelColor(15+segment,0,0,0); //Segment F
strip.setPixelColor(16+segment,0,0,0); //Segment F
strip.setPixelColor(17+segment,0,0,0); //Segment F
strip.setPixelColor(18+segment, 0, 0, 0);
strip.setPixelColor(19+segment, 0, 0, 0);
strip.setPixelColor(20+segment, 0, 0, 0);
strip.setPixelColor(21+segment, 0, 0, 0);
strip.show();
break;

case 2:

strip.setPixelColor(0+segment,r,g,b); //Segment A
strip.setPixelColor(1+segment,r,g,b); //Segment A
strip.setPixelColor(2+segment,r,g,b); //Segment A
strip.setPixelColor(3+segment,r,g,b); //Segment B
strip.setPixelColor(4+segment,r,g,b); //Segment B
strip.setPixelColor(5+segment,r,g,b); //Segment B
strip.setPixelColor(6+segment, 0, 0, 0);
strip.setPixelColor(7+segment, 0, 0, 0);
strip.setPixelColor(8+segment, 0, 0, 0);
strip.setPixelColor(9+segment,r,g,b); //Segment D
strip.setPixelColor(10+segment,r,g,b); //Segment D
strip.setPixelColor(11+segment,r,g,b); //Segment D
strip.setPixelColor(12+segment,r,g,b); //Segment E
strip.setPixelColor(13+segment,r,g,b); //Segment E
strip.setPixelColor(14+segment,r,g,b); //Segment E
strip.setPixelColor(15+segment, 0, 0, 0);
strip.setPixelColor(16+segment, 0, 0, 0);
strip.setPixelColor(17+segment, 0, 0, 0);
strip.setPixelColor(18+segment,r,g,b); //Segment G
strip.setPixelColor(19+segment,r,g,b); //Segment G
strip.setPixelColor(20+segment,r,g,b); //Segment G
strip.setPixelColor(21+segment, 0, 0, 0);
strip.show();
break;

case 3:

strip.setPixelColor(0+segment,r,g,b); //Segment A
strip.setPixelColor(1+segment,r,g,b); //Segment A
strip.setPixelColor(2+segment,r,g,b); //Segment A
strip.setPixelColor(3+segment,r,g,b); //Segment B
strip.setPixelColor(4+segment,r,g,b); //Segment B
strip.setPixelColor(5+segment,r,g,b); //Segment B
strip.setPixelColor(6+segment,r,g,b); //Segment C
strip.setPixelColor(7+segment,r,g,b); //Segment C
strip.setPixelColor(8+segment,r,g,b); //Segment C
strip.setPixelColor(9+segment,r,g,b); //Segment D
strip.setPixelColor(10+segment,r,g,b); //Segment D
strip.setPixelColor(11+segment,r,g,b); //Segment D
strip.setPixelColor(12+segment, 0, 0, 0);
strip.setPixelColor(12+segment, 0, 0, 0);
strip.setPixelColor(13+segment, 0, 0, 0);
strip.setPixelColor(14+segment, 0, 0, 0);
strip.setPixelColor(15+segment, 0, 0, 0);
strip.setPixelColor(16+segment, 0, 0, 0);
strip.setPixelColor(17+segment, 0, 0, 0);
strip.setPixelColor(18+segment,r,g,b); //Segment G
strip.setPixelColor(19+segment,r,g,b); //Segment G
strip.setPixelColor(20+segment,r,g,b); //Segment G
strip.setPixelColor(21+segment, 0, 0, 0);
strip.show();
break;

case 4:
strip.setPixelColor(0+segment, 0, 0, 0);
strip.setPixelColor(1+segment, 0, 0, 0);
strip.setPixelColor(2+segment, 0, 0, 0);
strip.setPixelColor(3+segment,r,g,b); //Segment B
strip.setPixelColor(4+segment,r,g,b); //Segment B
strip.setPixelColor(5+segment,r,g,b); //Segment B
strip.setPixelColor(6+segment,r,g,b); //Segment C
strip.setPixelColor(7+segment,r,g,b); //Segment C
strip.setPixelColor(8+segment,r,g,b); //Segment C
strip.setPixelColor(9+segment, 0, 0, 0);
strip.setPixelColor(10+segment, 0, 0, 0);
strip.setPixelColor(11+segment, 0, 0, 0);
strip.setPixelColor(12+segment, 0, 0, 0);
strip.setPixelColor(13+segment, 0, 0, 0);
strip.setPixelColor(14+segment, 0, 0, 0);
strip.setPixelColor(15+segment,r,g,b); //Segment F
strip.setPixelColor(16+segment,r,g,b); //Segment F
strip.setPixelColor(17+segment,r,g,b); //Segment F
strip.setPixelColor(18+segment,r,g,b); //Segment G
strip.setPixelColor(19+segment,r,g,b); //Segment G
strip.setPixelColor(20+segment,r,g,b); //Segment G
strip.setPixelColor(21+segment, 0, 0, 0);
strip.show();
break;

case 5:
strip.setPixelColor(0+segment,r,g,b); //Segment A
strip.setPixelColor(1+segment,r,g,b); //Segment A
strip.setPixelColor(2+segment,r,g,b); //Segment A
strip.setPixelColor(3+segment, 0, 0, 0);
strip.setPixelColor(4+segment, 0, 0, 0);
strip.setPixelColor(5+segment, 0, 0, 0);
strip.setPixelColor(6+segment,r,g,b); //Segment C
strip.setPixelColor(7+segment,r,g,b); //Segment C
strip.setPixelColor(8+segment,r,g,b); //Segment C
strip.setPixelColor(9+segment,r,g,b); //Segment D
strip.setPixelColor(10+segment,r,g,b); //Segment D
strip.setPixelColor(11+segment,r,g,b); //Segment D
strip.setPixelColor(12+segment, 0, 0, 0);
strip.setPixelColor(13+segment, 0, 0, 0);
strip.setPixelColor(14+segment, 0, 0, 0);
strip.setPixelColor(15+segment,r,g,b); //Segment F
strip.setPixelColor(16+segment,r,g,b); //Segment F
strip.setPixelColor(17+segment,r,g,b); //Segment F
strip.setPixelColor(18+segment,r,g,b); //Segment G
strip.setPixelColor(19+segment,r,g,b); //Segment G
strip.setPixelColor(20+segment,r,g,b); //Segment G
strip.setPixelColor(21+segment, 0, 0, 0);
strip.show();
break;

case 6:

strip.setPixelColor(0+segment,r,g,b); //Segment A
strip.setPixelColor(1+segment,r,g,b); //Segment A
strip.setPixelColor(2+segment,r,g,b); //Segment A
strip.setPixelColor(3+segment, 0, 0, 0);
strip.setPixelColor(4+segment, 0, 0, 0);
strip.setPixelColor(5+segment, 0, 0, 0);
strip.setPixelColor(6+segment,r,g,b); //Segment C
strip.setPixelColor(7+segment,r,g,b); //Segment C
strip.setPixelColor(8+segment,r,g,b); //Segment C
strip.setPixelColor(9+segment,r,g,b); //Segment D
strip.setPixelColor(10+segment,r,g,b); //Segment D
strip.setPixelColor(11+segment,r,g,b); //Segment D
strip.setPixelColor(12+segment,r,g,b); //Segment E
strip.setPixelColor(13+segment,r,g,b); //Segment E
strip.setPixelColor(14+segment,r,g,b); //Segment E
strip.setPixelColor(15+segment,r,g,b); //Segment F
strip.setPixelColor(16+segment,r,g,b); //Segment F
strip.setPixelColor(17+segment,r,g,b); //Segment F
strip.setPixelColor(18+segment,r,g,b); //Segment G
strip.setPixelColor(19+segment,r,g,b); //Segment G
strip.setPixelColor(20+segment,r,g,b); //Segment G
strip.setPixelColor(21+segment, 0, 0, 0);
strip.show();
break;

case 7:

strip.setPixelColor(0+segment,r,g,b); //Segment A
strip.setPixelColor(1+segment,r,g,b); //Segment A
strip.setPixelColor(2+segment,r,g,b); //Segment A
strip.setPixelColor(3+segment,r,g,b); //Segment B
strip.setPixelColor(4+segment,r,g,b); //Segment B
strip.setPixelColor(5+segment,r,g,b); //Segment B
strip.setPixelColor(6+segment,r,g,b); //Segment C
strip.setPixelColor(7+segment,r,g,b); //Segment C
strip.setPixelColor(8+segment,r,g,b); //Segment C
strip.setPixelColor(9+segment, 0, 0, 0);
strip.setPixelColor(10+segment, 0, 0, 0);
strip.setPixelColor(11+segment, 0, 0, 0);
strip.setPixelColor(12+segment, 0, 0, 0);
strip.setPixelColor(13+segment, 0, 0, 0);
strip.setPixelColor(14+segment, 0, 0, 0);
strip.setPixelColor(15+segment, 0, 0, 0);
strip.setPixelColor(16+segment, 0, 0, 0);
strip.setPixelColor(17+segment, 0, 0, 0);
strip.setPixelColor(18+segment, 0, 0, 0);
strip.setPixelColor(19+segment, 0, 0, 0);
strip.setPixelColor(20+segment, 0, 0, 0);
strip.setPixelColor(21+segment, 0, 0, 0);
strip.show();
break;

case 8:

strip.setPixelColor(0+segment,r,g,b); //Segment A
strip.setPixelColor(1+segment,r,g,b); //Segment A
strip.setPixelColor(2+segment,r,g,b); //Segment A
strip.setPixelColor(3+segment,r,g,b); //Segment B
strip.setPixelColor(4+segment,r,g,b); //Segment B
strip.setPixelColor(5+segment,r,g,b); //Segment B
strip.setPixelColor(6+segment,r,g,b); //Segment C
strip.setPixelColor(7+segment,r,g,b); //Segment C
strip.setPixelColor(8+segment,r,g,b); //Segment C
strip.setPixelColor(9+segment,r,g,b); //Segment D
strip.setPixelColor(10+segment,r,g,b); //Segment D
strip.setPixelColor(11+segment,r,g,b); //Segment D
strip.setPixelColor(12+segment,r,g,b); //Segment E
strip.setPixelColor(13+segment,r,g,b); //Segment E
strip.setPixelColor(14+segment,r,g,b); //Segment E
strip.setPixelColor(15+segment,r,g,b); //Segment F
strip.setPixelColor(16+segment,r,g,b); //Segment F
strip.setPixelColor(17+segment,r,g,b); //Segment F
strip.setPixelColor(18+segment,r,g,b); //Segment G
strip.setPixelColor(19+segment,r,g,b); //Segment G
strip.setPixelColor(20+segment,r,g,b); //Segment G
strip.setPixelColor(21+segment, 0, 0, 0);
strip.show();
break;

case 9:

strip.setPixelColor(0+segment,r,g,b); //Segment A
strip.setPixelColor(1+segment,r,g,b); //Segment A
strip.setPixelColor(2+segment,r,g,b); //Segment A
strip.setPixelColor(3+segment,r,g,b); //Segment B
strip.setPixelColor(4+segment,r,g,b); //Segment B
strip.setPixelColor(5+segment,r,g,b); //Segment B
strip.setPixelColor(6+segment,r,g,b); //Segment C
strip.setPixelColor(7+segment,r,g,b); //Segment C
strip.setPixelColor(8+segment,r,g,b); //Segment C
strip.setPixelColor(9+segment, 0, 0, 0);
strip.setPixelColor(10+segment, 0, 0, 0);
strip.setPixelColor(11+segment, 0, 0, 0);
strip.setPixelColor(12+segment, 0, 0, 0);
strip.setPixelColor(13+segment, 0, 0, 0);
strip.setPixelColor(14+segment, 0, 0, 0);
strip.setPixelColor(15+segment,r,g,b); //Segment F
strip.setPixelColor(16+segment,r,g,b); //Segment F
strip.setPixelColor(17+segment,r,g,b); //Segment F
strip.setPixelColor(18+segment,r,g,b); //Segment G
strip.setPixelColor(19+segment,r,g,b); //Segment G
strip.setPixelColor(20+segment,r,g,b); //Segment G
strip.setPixelColor(21+segment, 0, 0, 0);
strip.show();
break;
  }
}

void segmentPicker(int segmentToDisplay)
{
  switch (segmentToDisplay)
  {
    case 1:
  
    segment =(0);
    break;

    case 2:
    
    segment =(21);
    break;

    case 3:
   
    segment =(42);
    break;

    case 4:
    segment =(63);
    break;
  }
}
