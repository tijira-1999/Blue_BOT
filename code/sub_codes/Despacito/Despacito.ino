/*
  Melody
 
 Plays a melody 
 
 circuit:
 * 8-ohm speaker on digital pin 8
 
 created 21 Jan 2010
 modified 30 Aug 2011
 by Tom Igoe 

This example code is in the public domain.
 
 http://arduino.cc/en/Tutorial/Tone
 
 */
#include "pitches.h"


int led=3;
int soundpin = 4;
int noteDuration;
int pauseBetweenNotes = 0;
int negra;


void setup() 
{
  pinMode(led, OUTPUT);   
  digitalWrite(led, LOW);
  negra=640;
  chorus();
  chorus();
     
}

void loop() {

 //chorus();
}

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
