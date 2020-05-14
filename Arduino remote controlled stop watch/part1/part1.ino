#include <TimerOne.h>
unsigned long count;
int time = 5;
int pinA = 2;       //pin 11 on display 
int pinB = 3;       //pin 7 on display 
int pinC = 4;       //pin 4 on display 
int pinD = 5;       //pin 2 on display 
int pinE = 6;       //pin 1 on display 
int pinF= 7;       //pin 10 on display 
int pinG = 8;       //pin 5 on display 

int D1 = 9;         //pin 12 on display 
int D2 = 10;        //pin 9 on display 
int D3 = 11;        //pin 8 on display 
int D4 = 12;        //pin 6 on display 
int decimal = A0;

const int reset = A5;
const int stopstart = A4;

 unsigned char thousands ;
  unsigned char hundreds ;
  unsigned char tens ;
  unsigned char ones ;

long n = 0;// n represents the value displayed on the LED display. For example, when n=0, 0000 is displayed. The maximum value is 9999. 
int x = 100;
int del = 5;//Set del as 5; the value is the degree of fine tuning for the clock
//int time = 5;//Set count=0. Here count is a count value that increases by 1 every 0.1 second, which means 1 second is counted when the value is 10
int State;
int State2;
unsigned long time1 = 0;
unsigned long now = 0;
unsigned long then = 0;
int pushbutton = 0;
int pushbutton2 = 0;
bool paused;
bool lastState;
//unsigned long count;
bool reseted;
int resets;

void setup() {
  // put your setup code here, to run once:
pinMode(pinA, OUTPUT);     
pinMode(pinB, OUTPUT);     
pinMode(pinC, OUTPUT);     
pinMode(pinD, OUTPUT);     
pinMode(pinE, OUTPUT);     
pinMode(pinF, OUTPUT);     
pinMode(pinG, OUTPUT);   
pinMode(D1, OUTPUT);  
pinMode(D2, OUTPUT);  
pinMode(D3, OUTPUT);  
pinMode(D4, OUTPUT);  
pinMode(decimal,OUTPUT);

Timer1.initialize(1000);
Timer1.attachInterrupt(caller);
}
void segment(int segmentToDisplay)
{
  switch(segmentToDisplay)
  {
case 1:
digitalWrite(D1, HIGH);
digitalWrite(D2, HIGH);
digitalWrite(D3, HIGH);
digitalWrite(D4, LOW); 
digitalWrite(decimal,LOW);
break;

case 2:
digitalWrite(D1, HIGH);
digitalWrite(D2, HIGH);
digitalWrite(D3, LOW);
digitalWrite(D4, HIGH); 
digitalWrite(decimal,HIGH);
break;

case 3:
digitalWrite(D1, HIGH);
digitalWrite(D2, LOW);
digitalWrite(D3, HIGH);
digitalWrite(D4, HIGH); 
digitalWrite(decimal,HIGH);
break;

case 4:
digitalWrite(D1, LOW);
digitalWrite(D2, HIGH);
digitalWrite(D3, HIGH);
digitalWrite(D4, HIGH); 
digitalWrite(decimal,HIGH);




  }
  
}

void numbers(int numberToDisplay)
{
  switch(numberToDisplay){

    
case 0:
digitalWrite(pinA, HIGH);   
digitalWrite(pinB, HIGH);   
digitalWrite(pinC, HIGH);   
digitalWrite(pinD, HIGH);   
digitalWrite(pinE, HIGH);   
digitalWrite(pinF, HIGH);   
digitalWrite(pinG, LOW);  
break;

case 1:
digitalWrite(pinA, LOW);   
digitalWrite(pinB, HIGH);   
digitalWrite(pinC, HIGH);   
digitalWrite(pinD, LOW);   
digitalWrite(pinE, LOW);   
digitalWrite(pinF, LOW);   
digitalWrite(pinG, LOW); 
break;
  

case 2:
digitalWrite(pinA, HIGH);   
digitalWrite(pinB, HIGH);   
digitalWrite(pinC, LOW);   
digitalWrite(pinD, HIGH);   
digitalWrite(pinE, HIGH);   
digitalWrite(pinF, LOW);   
digitalWrite(pinG, HIGH);   
break;

case 3:
digitalWrite(pinA, HIGH);   
digitalWrite(pinB, HIGH);   
digitalWrite(pinC, HIGH);   
digitalWrite(pinD, HIGH);   
digitalWrite(pinE, LOW);   
digitalWrite(pinF, LOW);   
digitalWrite(pinG, HIGH); 
break;

case 4:
digitalWrite(pinA, LOW);   
digitalWrite(pinB, HIGH);   
digitalWrite(pinC, HIGH);   
digitalWrite(pinD, LOW);   
digitalWrite(pinE, LOW);   
digitalWrite(pinF, HIGH);   
digitalWrite(pinG, HIGH); 
break;


case 5:
digitalWrite(pinA, HIGH);   
digitalWrite(pinB, LOW);   
digitalWrite(pinC, HIGH);   
digitalWrite(pinD, HIGH);   
digitalWrite(pinE, LOW);   
digitalWrite(pinF, HIGH);   
digitalWrite(pinG, HIGH);
break;    

case 6:
digitalWrite(pinA, HIGH);   
digitalWrite(pinB, LOW);   
digitalWrite(pinC, HIGH);   
digitalWrite(pinD, HIGH);   
digitalWrite(pinE, HIGH);   
digitalWrite(pinF, HIGH);   
digitalWrite(pinG, HIGH);  
break;   

case 7:
digitalWrite(pinA, HIGH);   
digitalWrite(pinB, HIGH);   
digitalWrite(pinC, HIGH);   
digitalWrite(pinD, LOW);   
digitalWrite(pinE, LOW);   
digitalWrite(pinF, LOW);   
digitalWrite(pinG, LOW);  
break; 


case 8:
digitalWrite(pinA, HIGH);   
digitalWrite(pinB, HIGH);   
digitalWrite(pinC, HIGH);   
digitalWrite(pinD, HIGH);   
digitalWrite(pinE, HIGH);   
digitalWrite(pinF, HIGH);   
digitalWrite(pinG, HIGH);    
break;

case 9:
digitalWrite(pinA, HIGH);   
digitalWrite(pinB, HIGH);   
digitalWrite(pinC, HIGH);   
digitalWrite(pinD, LOW);   
digitalWrite(pinE, LOW);   
digitalWrite(pinF, HIGH);   
digitalWrite(pinG, HIGH);   
break;
  }
}


void segmenter()
{
  segment(4);
  numbers(thousands);
  delay(time);

  segment(3);
  numbers(hundreds);
  delay(time);

  segment(2);
  numbers(tens);
  delay(time);

  segment(1);
  numbers(ones);
  delay(time);
}

void seven_segment1(int number)
{
  unsigned char thousands = int (number/1000);
  unsigned char hundreds = int((number/100)%10);

numbers(hundreds);
  segment(3);
  delay(time);
  
//thousands
  numbers(thousands);
  segment(4);
  delay(time);
  
}

void seven_segment2(int number)
{
  unsigned char tens = int ((number/10)%10);
  unsigned char ones = int(number %10);

  //ones
  numbers(ones);
  segment(1);
  delay(time);

//tens
  numbers(tens);
  segment(2);
  delay(time);
}
void loop() {
  // put your main code here, to run repeatedly:
segmenter();

State = digitalRead(A4);// Reads inputy of start stop button
Serial.print(State);
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
  segmenter();
}

void caller()
 {
//  unsigned char tsecs = count %10;
//  unsigned char ten  = (count/10)%10;
//  unsigned char Lmiliseconds =(count/10)%10;
//  unsigned char seconds = (count/10)%10;

thousands =  (count/1000);
 hundreds = ((count/100)%10);
  tens = ((count/10)%10);
   ones = (count %10);
  
if(paused == false)
  {
  count++;
 if(resets==HIGH)
{count=0;}
  }  
  if (count >9999)
  {
    count = 9999;
   // pixelmins();
  }
   
 }
