#include <SoftwareSerial.h>
#include "pitches.h"
#include <Servo.h>        //add Servo Motor library   

#define TRIG_PIN A1 // Pin A0 on the Motor Drive Shield soldered to the ultrasonic sensor
#define ECHO_PIN A0 // Pin A1 on the Motor Drive Shield soldered to the ultrasonic sensor
#define COLL_DIST 25 // sets distance at which robot stops and reverses to 30cm

Servo myservo;  // create servo object to control a servo 

bool p = true;
int leftDistance, rightDistance; //distances on either side
int curDist = 0;
float duration,distance;

unsigned int i, j, k;
const int x = 400, y = 1000, t1 = 7, t2 = 500;  // t1 = delay in milliseconds, t2 = delay in microseconds

//notes in the melody
int melody[]={NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4};

//note durations. 4=quarter note / 8=eighth note
int noteDurations[]={4, 8, 8, 4, 4, 4, 4, 4};

int soundpin = 4;
int noteDuration;
int pauseBetweenNotes = 0;
int negra;

SoftwareSerial BT(0, 1); //TX, RX respetively
String readvoice;

int RightSpd = 125;
int LeftSpd = 100;

//Define enable pins of the Motors
const int enbA = 6;
const int enbB = 11;

int led = 3;           // the PWM pin the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by


//Define control pins of the Motors
//If the motors rotate in the opposite direction, you can change the positions of the following pin numbers
const int IN1 = 8;    //Right Motor (-)
const int IN2 = 7;    //Right Motor (+)
const int IN3 = 9;    //Left Motor (+)
const int IN4 = 10;    //Right Motor (-)

void setup() 
{
  
  myservo.attach(5);  // attaches the servo on pin 10 (SERVO_1 on the Motor Drive Shield to the servo object 
  myservo.write(74);
  delay(300);
  pinMode(TRIG_PIN,OUTPUT);
  pinMode(ECHO_PIN,INPUT);
  //Serial.begin(9600);
  
  pinMode(soundpin, OUTPUT);
  digitalWrite(soundpin,HIGH);
  delay(100);
  digitalWrite(soundpin,LOW);
  delay(100);
  digitalWrite(soundpin,HIGH);
  delay(100);
  digitalWrite(soundpin,LOW);
  delay(100);
  
  BT.begin(9600);
  //Serial.begin(9600);
  pinMode(enbB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(enbA, OUTPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);

  negra=640;


}
//-----------------------------------------------------------------------// 
void loop() 
{
  while (BT.available())
  {  
    //Check if there is an available byte to read
    delay(10); //Delay added to make thing stable
    char c = BT.read(); //Conduct a serial read
    readvoice += c; //build the string- "forward", "reverse", "left" and "right"
    //automode();
  }  

    if (readvoice.length() > 0)
    {
      if(readvoice == "*forward#")
      { 
        forward();
      }
                      
      else if(readvoice == "*short forward#")
      { 
        shortforward();
      }
                           
      else if(readvoice == "*long forward#")
      { 
        longforward();
      }
                          
      else if(readvoice == "*back#" || readvoice == "*backward#")
      { 
        backward();
      }
                       
      else if(readvoice == "*short back#" || readvoice == "*short backward#")
      { 
        shortbackward();
      }
                            
      else if(readvoice == "*long back#" || readvoice == "*long backward#")
      { 
        longbackward();
      }
                           
      else if ( readvoice == "*right#" || readvoice == "*write#")
      { 
        right();
      }
                    
      else if (readvoice == "*short right#" || readvoice == "*short write#" || readvoice == "*short ride#")
      { 
        shortright();
      }
                         
      else if (readvoice == "*long right#" || readvoice == "*long write#" || readvoice == "*long ride#")
      { 
        longright();
      }
                        
      else if (readvoice == "*left#")
      { 
        left();
      }
                   
      else if (readvoice == "*Short left#" || readvoice == "*shirtless#")
      { 
        shortleft();
      }
                         
      else if (readvoice == "*long left#")
      { 
        longleft();
      }
                              
      else if (readvoice == "*stop#")
      { 
        p = true;
        stop1();
      }
                  
      else if (readvoice == "*auto mode#")
      { 
        p = false;
        //automode();
      }
                       
      else if (readvoice == "*turn around right#")
      { 
        turnaroundright();
      }
                                
      else if (readvoice == "*turn around left#")
      { 
        turnaroundleft();
      }
                               
      else if (readvoice == "*fade#")
      { 
        fade();
      }
                  
      else if (readvoice == "*blink#")
      { 
        blink1();
      }
                   
      else if (readvoice == "*lights on#")
      { 
        lightson();
      }
                        
      else if (readvoice == "*lights off#")
      { 
        lightsoff();
      }
                        
      else if (readvoice == "*despacito#")
      { 
        despacito();
      }
                        
      else if (readvoice == "*bus#")
      { 
        bus();
      }
                  
      else if (readvoice == "*Boom#")
      { 
        Boom();
      }
                  
    readvoice = "";
  }  //Reset the variable
  automode();
}

void forward()
{
      //forward 
      analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      
      delay(2000);
      analogWrite(enbA, 0);
      analogWrite(enbB, 0);
    
}

void shortforward()
{
      //forward 
      analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      
      delay(200);
      analogWrite(enbA, 0);
      analogWrite(enbB, 0);
    
}

void longforward()
{
      //forward 
      analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      
      delay(5000);
      analogWrite(enbA, 0);
      analogWrite(enbB, 0);
    
}

void backward()
{
      //backward          
      analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      
      delay(2000);
      analogWrite(enbA, 0);
      analogWrite(enbB, 0);
}

void shortbackward()
{
      //backward          
      analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      
      delay(200);
      analogWrite(enbA, 0);
      analogWrite(enbB, 0);
}

void longbackward()
{
      //backward          
      analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      
      delay(5000);
      analogWrite(enbA, 0);
      analogWrite(enbB, 0);
}

void left()
{
      //left
      analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);

      delay(290);
      analogWrite(enbA, 0);
      analogWrite(enbB, 0);
}

void shortleft()
{
      //left
      analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);

      delay(100);
      analogWrite(enbA, 0);
      analogWrite(enbB, 0);
}

void longleft()
{
      //left
      analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);

      delay(370);
      analogWrite(enbA, 0);
      analogWrite(enbB, 0);
}

void right()
{
      //right
      analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);

      delay(300);
      analogWrite(enbA, 0);
      analogWrite(enbB, 0);
}

void shortright()
{
      //right
      analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);

      delay(300);
      analogWrite(enbA, 0);
      analogWrite(enbB, 0);
}

void longright()
{
      //right
      analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);

      delay(300);
      analogWrite(enbA, 0);
      analogWrite(enbB, 0);
}

void stop1()
{
      //stop car
      analogWrite(enbA, 0);
      analogWrite(enbB, 0);
}

void automode()
{
  if(p == false)
  {
    curDist = readPing();   // read distance
    if (curDist < COLL_DIST) 
    {
      changePath();  // if forward is blocked change direction
    }
    else 
    { 
      moveForward();  // move forward
    }            
  }
}

void turnaroundright()
{
      //right
      analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);

      delay(550);
      analogWrite(enbA, 0);
      analogWrite(enbB, 0);
}

void turnaroundleft()
{
      //left
      analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);

      delay(550);
      analogWrite(enbA, 0);
      analogWrite(enbB, 0);
}

void fade()
{
      for(int d=0;d<=10;d++)
      {
        for(int a=0;a<=255;a+=5)
          {
          // set the brightness of pin 9:
          analogWrite(led, brightness);
        
          // change the brightness for next time through the loop:
          brightness = brightness + fadeAmount;
        
          // reverse the direction of the fading at the ends of the fade:
          if (brightness <= 0 || brightness >= 255) {
            fadeAmount = -fadeAmount;
          }
          // wait for 30 milliseconds to see the dimming effect
          delay(30);  
        }
      }
      
      digitalWrite(led,LOW);
}

void blink1()
{
      for(int a=0;a<=10;a++)
      {
          digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
          delay(200);                       // wait for a second
          digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
          delay(200);                       // wait for a second
      }
      digitalWrite(led,LOW);
}
void lightson()
{
      digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
}

void lightsoff()
{
      digitalWrite(led, LOW);   // turn the LED off (LOW is the voltage level)
}

void despacito()
{
      chorus();
      chorus();
      chorus();
      digitalWrite(soundpin,LOW);
}

void bus()
{
      for(int b=0;b<=2;b++)
      {
        for (int thisNote=0; thisNote <8; thisNote++)
        {
  
          //to calculate the note duration, take one second. Divided by the note type
          int noteDuration = 1000 / noteDurations [thisNote];
          tone(soundpin, melody [thisNote], noteDuration);
    
          //to distinguish the notes, set a minimum time between them
          //the note's duration +30% seems to work well
          int pauseBetweenNotes = noteDuration * 1.30;
          delay(pauseBetweenNotes);
    
          //stop the tone playing
          noTone(soundpin);
        }
      }
      digitalWrite(soundpin,LOW);
}

void Boom()
{
      pol();
           
      //blink
      for(int a=0;a<=10;a++)
      {
          digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
          delay(200);                       // wait for a second
          digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
          delay(200);                       // wait for a second
      }
      digitalWrite(led,LOW);
      
      //1
      //left
      analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);

      delay(200);
      analogWrite(enbA, 0);
      analogWrite(enbB, 0);

      //right
      analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);

      delay(200);
      analogWrite(enbA, 0);
      analogWrite(enbB, 0);

      //2
      //left
      analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);

      delay(200);
      analogWrite(enbA, 0);
      analogWrite(enbB, 0);

      //right
      analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);

      delay(200);
      analogWrite(enbA, 0);
      analogWrite(enbB, 0);

      //3
      //left
      analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);

      delay(200);
      analogWrite(enbA, 0);
      analogWrite(enbB, 0);

      //right
      analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);

      delay(200);
      analogWrite(enbA, 0);
      analogWrite(enbB, 0);

      //short forward 
      analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      
      delay(700);
      analogWrite(enbA, 0);
      analogWrite(enbB, 0);

      //short backward          
      analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      
      delay(700);
      analogWrite(enbA, 0);
      analogWrite(enbB, 0);
      
      //turn around right
      analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);

      delay(550);
      analogWrite(enbA, 0);
      analogWrite(enbB, 0);

      //turn around left
      analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);

      delay(1000);
      analogWrite(enbA, 0);
      analogWrite(enbB, 0);

      //short forward 
      analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      
      delay(700);
      analogWrite(enbA, 0);
      analogWrite(enbB, 0);

      //short backward          
      analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      
      delay(500);
      analogWrite(enbA, 0);
      analogWrite(enbB, 0);

      pol();
      
      //blink
      for(int a=0;a<=10;a++)
      {
          digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
          delay(200);                       // wait for a second
          digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
          delay(200);                       // wait for a second
      }
      digitalWrite(led,LOW);
}




//--------------------------------------------------------------------------------------------------------------------------------------------------------
// despacito sound code.
 void chorus(){
     notars(negra, NOTE_D5);
     notars(negra, NOTE_CS5);digitalWrite(led, HIGH);   // (1)
     notars(negra/2, NOTE_B4);
     notars(negra/4, NOTE_FS4);digitalWrite(led, LOW);    // (2)
     delay(negra/4); digitalWrite(led, HIGH);   // (3)
     notars(negra/4, NOTE_FS4);
     notars(negra/4, NOTE_FS4);
digitalWrite(led, LOW);    // (4)
     notars(negra/4, NOTE_FS4);
     notars(negra/4, NOTE_FS4);digitalWrite(led, HIGH);   //  (1) 
     
     notars(negra/4, NOTE_FS4);

     notars(negra/4, NOTE_B4);
     notars(negra/4, NOTE_B4);digitalWrite(led, LOW);    //  (2) 
     notars(negra/4, NOTE_B4);digitalWrite(led, HIGH);   //  (3)  
     notars(negra/2, NOTE_B4);digitalWrite(led, LOW);    //  (4)   

     notars(negra/4, NOTE_A4);  
          
     notars(negra/4, NOTE_B4);digitalWrite(led, HIGH);   //  (1) 
     delay(negra/4); 
     delay(negra/4); 
     notars(negra/4, NOTE_G4);  digitalWrite(led, LOW);    //  (2) 
     delay(negra/4);digitalWrite(led, HIGH);   //  (3) 
//......
     notars(negra/4, NOTE_G4);  
     notars(negra/4, NOTE_G4);digitalWrite(led, LOW);    //  (4)   
     notars(negra/4, NOTE_G4);  
     notars(negra/4, NOTE_G4);digitalWrite(led, HIGH);   //  (1)   
     notars(negra/4, NOTE_G4);  

     notars(negra/4, NOTE_B4);  
     notars(negra/4, NOTE_B4);  digitalWrite(led, LOW);    //  (2) 
     notars(negra/4, NOTE_B4);digitalWrite(led, HIGH);   //  (3) 
     notars(negra/2, NOTE_B4);digitalWrite(led, LOW);    //  (4) 
     
     notars(negra/4, NOTE_CS5);
     notars(negra/4, NOTE_D5);digitalWrite(led, HIGH);   //  (1) 
     delay(negra/4);
     delay(negra/4);
     notars(negra/4, NOTE_A4);digitalWrite(led, LOW);    //  (2)      
     delay(negra/4);digitalWrite(led, HIGH);   //  (3) 
     
     notars(negra/4, NOTE_A4);     
     notars(negra/4, NOTE_A4);digitalWrite(led, LOW);    //  (4)           
     notars(negra/4, NOTE_A4);               
     notars(negra/4, NOTE_A4);digitalWrite(led, HIGH);   //  (1)                
     
     notars(negra/4, NOTE_D5);          
     notars(negra/4, NOTE_CS5);               
     notars(negra/4, NOTE_D5);digitalWrite(led, LOW);    //  (2)           
     notars(negra/4, NOTE_CS5);digitalWrite(led, HIGH);   //  (3)          
     notars(negra/2, NOTE_D5);digitalWrite(led, LOW);    //  (4)                
     //
     notars(negra/4, NOTE_E5);
     notars_jai(negra/2, NOTE_E5,negra/4);  // (1)
//     notars(negra/2, NOTE_E5);  

    //-----------------------------------------------
      tone(soundpin,NOTE_CS5 ,negra*3/4);
    //-----------------------------------------------
      delay(negra/4);
      delay(negra/4);
     digitalWrite(led, LOW);    //  (2)                     
      delay(negra/4);
     digitalWrite(led, HIGH);   //  (3)                     
     noTone(soundpin);
     delay(negra/4);
     
     //--------------
     delay(negra/4);
     digitalWrite(led, LOW);    //  (4) 

     delay(negra/4);
     delay(negra/4);       
  
}
void notars(int noteDuration,int LaNota ){

    //noteDuration=negra/4;
  tone(soundpin,LaNota ,noteDuration*0.9);
//      pauseBetweenNotes = noteDuration * 1.30;
      pauseBetweenNotes = noteDuration * 1.1;
      delay(pauseBetweenNotes);
      noTone(soundpin);  


}
void notars_jai(int noteDuration,int LaNota ,int Desfase){

    //noteDuration=negra/4;
  tone(soundpin,LaNota ,noteDuration*0.9);
//      pauseBetweenNotes = noteDuration * 1.30;
      pauseBetweenNotes = noteDuration * 1.1;
      delay(Desfase);
      
       digitalWrite(led, HIGH);   //  (1)   
      
        delay(pauseBetweenNotes-Desfase);
      noTone(soundpin);  


}


// police siren


void pol() 
{

  k = (y - x) / 10;
  //Serial.println(k);

   sound0_1();
   sound1_1();
      
   sound2_1();
   sound2_6();
   
  noTone(soundpin);
  delay(1000);
}


void sound0_1() 
{
  for (j = 1; j <= 3; j++) 
  {
    for (i = x; i <= y-150; i += 2) 
    {
      tone(soundpin, i);
      delay(t1);
    }
    noTone(soundpin);
    delay(300);
  }
  noTone(soundpin);
  delay(10);
}

void sound1_1() 
{
  for (j = 1; j <= 3; j++) 
  {
    for (i = x; i <= y; i += 2) 
    {
      tone(soundpin, i);
      delay(t1);
    }
    for (i = y; i >= x; i -= 2) 
    {
      tone(soundpin, i);
      delay(t1);
    }
  }
  noTone(soundpin);
  delay(10);
}

void sound2_1() 
{
  for (j = 1; j <= 10; j++) 
  {
    for (i = x; i <= y; i += 2) 
    {
      tone(soundpin, i);
      delayMicroseconds(t2);
    }
    for (i = y; i >= x; i -= 2) 
    {
      tone(soundpin, i);
      delayMicroseconds(t2);
    }
  }
  noTone(soundpin);
  //delay(10);
}


void sound2_6() 
{
  for (j = 1; j <= 10; j++) 
  {    
    for (i = x; i <= y; i += 2) 
    {
      tone(soundpin, i);
      delayMicroseconds(t2);
    }
    for (i = y; i >= x; i -= 2) 
    {
      tone(soundpin, i);
      delayMicroseconds(t2);
    }   
  }
  noTone(soundpin);
  //delay(10);
}



void changePath() {
  moveBackward1();   // stop forward movement
  moveStop();
  myservo.write(28);  // check distance to the right
    delay(500);
    rightDistance = readPing(); //set right distance
    //delay(500);
    myservo.write(130);  // check distace to the left
    delay(700);
    leftDistance = readPing(); //set left distance
    //delay(500);
    myservo.write(74); //return to center
    delay(100);
    compareDistance();
  }

  
void compareDistance()   // find the longest distance
{
  if ((leftDistance>rightDistance)&&(rightDistance>10 && leftDistance>10)) //if left is less obstructed 
  {
    //Serial.print("left");
    turnLeft();
  }
  else if ((rightDistance>leftDistance)&&(rightDistance>10 && leftDistance>10)) //if right is less obstructed
  {
    //Serial.print("right");
    turnRight();
  }
  else if (rightDistance<=10 && leftDistance<=10) 
  {
    //Serial.print("backwards"); 
    moveBackward();
  }
  else     //if they are equally obstructed
  {
    //Serial.print("back");
    if (leftDistance<10)
    {
      //Serial.print("turnaroundR");
      turnAroundR();
    }
    else 
    {
      //Serial.print(" turnAroundL");
      turnAroundL();
    }
  }
}


//-------------------------------------------------------------------------------------------------------------------------------------

int readPing() 
{ // read the ultrasonic sensor distance
   analogWrite(TRIG_PIN,0);
 delayMicroseconds(2);
  analogWrite(TRIG_PIN,255);
 delayMicroseconds(10);
  digitalWrite(TRIG_PIN,0);

 duration = pulseIn(ECHO_PIN,255);
 distance = (duration*.0343)/2;
 //Serial.print("Distance: ");
 //Serial.println(distance);
 return distance;
 
}


void moveForward() 
{
   analogWrite(enbA, RightSpd);
   analogWrite(enbB, LeftSpd);
   digitalWrite(IN1, HIGH);
   digitalWrite(IN2, LOW);
   digitalWrite(IN3, HIGH);
   digitalWrite(IN4, LOW);
            
   delay(200);
   analogWrite(enbA, 0);
   analogWrite(enbB, 0);
          
}
//-------------------------------------------------------------------------------------------------------------------------------------
void moveBackward() 
{
    //backward          
      analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      
      delay(1000);
      analogWrite(enbA, 0);
      analogWrite(enbB, 0);
      
      moveStop();   // stop forward movement
      myservo.write(0);  // check distance to the right
      delay(500);
      rightDistance = readPing(); //set right distance
      //delay(500);
      myservo.write(180);  // check distace to the left
      delay(800);
      leftDistance = readPing(); //set left distance
      //delay(500);
      myservo.write(74); //return to center
      delay(100);
  
      if(rightDistance>10 || leftDistance>10)
      {
        if(rightDistance>leftDistance)
        {
         turnAroundR();
        }
        else
        {
         turnAroundL();
        }
      }
      else{moveBackward();}
}  
//-------------------------------------------------------------------------------------------------------------------------------------
void turnRight() 
{
      //right
      analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);

      delay(300);
      analogWrite(enbA, 0);
      analogWrite(enbB, 0); 
 
}  
//-------------------------------------------------------------------------------------------------------------------------------------
void turnLeft() 
{
      //left
      analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);

      delay(290);
      analogWrite(enbA, 0);
      analogWrite(enbB, 0);
  
  
}  
//-------------------------------------------------------------------------------------------------------------------------------------
void turnAroundR() 
{
      //right
      analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);

      delay(550);
      analogWrite(enbA, 0);
      analogWrite(enbB, 0);
    
}
void turnAroundL() 
{
      //left
      analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);

      delay(550);
      analogWrite(enbA, 0);
      analogWrite(enbB, 0);
     
}   

void moveStop()  // stop the motors.
{
      //stop car
      analogWrite(enbA, 0);
      analogWrite(enbB, 0);
  
} 

void moveBackward1()
{
      //stop          
      analogWrite(enbA, RightSpd);
      analogWrite(enbB, LeftSpd);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      
      delay(50);
}

