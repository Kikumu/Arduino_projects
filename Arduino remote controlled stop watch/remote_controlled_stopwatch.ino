#include<IRremote.h>
#include <TimerOne.h>
int receiver = 13;
int led1 = 12;
int led2 = 8;
long int num;
unsigned long i = millis();
unsigned long count;



volatile int tsecs;
decode_results results;
decode_results results1;
IRrecv irrecv(receiver);
unsigned long start,finish,elapsed,start1,finish1,elapsed1;
void translate()
{
  switch(results.value){
    case 0xFFA25D:
    //Serial.println("CH-           ");
     Timer1.attachInterrupt(caller);
    break;
    case 0xFF629D:
    //Serial.println("CH              ");
    Timer1.detachInterrupt();
    break;
    case 0xFFE21D:
    //Serial.println("CH+             ");
    count = 0;
    break;
    case  0xFF22DD:
    //Serial.println("<<              ");
    Serial.println("Runner 1");
    if((count/60000)<10)
    {
    Serial.print("0");
    }
    Serial.print((count/60000));
    Serial.print(":");
    if(((count/1000)%60)<10)
    {
      Serial.print("0");
    }
    Serial.print((count/1000)%60);
      
//    Serial.print("        ");
//    Serial.print("minutes:");
//    Serial.print((count/60000));
    Serial.println("");
    break;
    case 0xFF02FD:
   // Serial.println(" >>              ");
   Serial.println("Runner 2");
    if((count/60000)<10)
    {
    Serial.print("0");
    }
    Serial.print((count/60000));
    Serial.print(":");
    if(((count/1000)%60)<10)
    {
      Serial.print("0");
    }
    Serial.print((count/1000)%60);
      
//    Serial.print("        ");
//    Serial.print("minutes:");
//    Serial.print((count/60000));
    Serial.println("");
    break;
  }
}

//count pins
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

void setup() {
  // put your setup code here, to run once:
  pinMode(receiver,INPUT);

//count setups
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
Serial.begin(9600);

Timer1.initialize(1000);
  Timer1.attachInterrupt(caller);
  irrecv.enableIRIn();
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
digitalWrite(decimal,LOW);
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
digitalWrite(decimal,LOW);




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



void caller()
 {
  count++;
  
  tsecs = count %10;
  unsigned char ten  = (count/10)%10;
  unsigned char Lmiliseconds =(count/10)%10;
  unsigned char seconds = (count/10)%10;

  if (count <60000000)
  {
    
   // pixelmins();
  }
   
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
 unsigned long P = count/1000;
 unsigned long h = P%60;

unsigned long b =count/60000;
unsigned long c = b%600;
void loop() {
//  segment(4);
//  numbers(count/1000);
//delay(time);
//
//
//    segment(3);
// numbers((count/100)%10);
//delay(time);
//
//
//  segment(2);
//  numbers((count/10)%10);
//delay(time);
//
//
// segment(1);
//  numbers(count%10);
//  delay(time);

 unsigned long P = count/1000;
unsigned long h = P%60;
 seven_segment2(h);
 unsigned long b =count/60000;
unsigned long c = b%600;
seven_segment1(b*100);
  /*
if(irrecv.decode(&results))
  {
    num = results.value;
    long int num1;
    num1 = results.value;
    while(num1==0xFFA25D){
          //Keypad button "CH-"
          start1 = millis();
          results.value = irrecv.decode(&results);
          num1 = results.value;
          seven_segment(start1);
    }
   while(num1==0xFF629D){
          //Keypad button "CH"
         finish = millis();
         elapsed = (finish - start)/1000;
         results.value = irrecv.decode(&results);
         num1 = results.value;
         seven_segment(1111);
            
          }
   irrecv.resume();
     
  
  }

  
  // put your main code here, to run repeatedly:
*/
 if (irrecv.decode(&results)) {
   translate();
          
     irrecv.resume(); // Receive the next value
   }   

}
