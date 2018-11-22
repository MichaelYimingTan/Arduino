#include "Keyboard.h"
//setting pins for buttons
const int Up_Button = 13;
const int Down_Button = 12;
const int Left_Button = 11;
const int Right_Button = 10;

//setting pins for lights 
const int Red = 8;
const int Green = 7;
const int Blue = 2; 

//setting costants in calculation
const double change = 0.1;
const int port = 9600;
const int deltaTime = 10;//in mils



//settting press detectors 
int isPressedUp = 0;
int isPressedDown = 0;
int isPressedLeft = 0;
int isPressedRight = 0;


//setting v and a
double velocity = 0;
int acel = 1;



void setup(){
  
    Serial.begin(port);

    //setting up the input for the buttons of arrow keys
    
    pinMode(Up_Button, INPUT);
  //digitalWrite(Up_Button, LOW);
    pinMode(Down_Button, INPUT);
  //digitalWrite(Down_Button, LOW);
    pinMode(Left_Button, INPUT);
  //digitalWrite(Left_Button, LOW);
    pinMode(Right_Button, INPUT);
  //digitalWrite(Right_Button, LOW);

    //setting up the input for different lights
    pinMode(Green,OUTPUT);
    pinMode(Red,OUTPUT);
    pinMode(Blue,OUTPUT);
    
    Keyboard.begin();
     
  
}

void loop(){

     delay(deltaTime);
     digitalWrite(Green, LOW);
     digitalWrite(Red, LOW);
     digitalWrite(Blue, LOW);

     //press up botton
     isPressedUp = digitalRead(Up_Button);
     if(isPressedUp==HIGH){
       digitalWrite(Green, HIGH);
       digitalWrite(Blue, HIGH);
       Keyboard.write('w');
       velocity += change;
     }
      
     //press down botton
     isPressedDown = digitalRead(Down_Button);
     if(isPressedDown==HIGH){
       digitalWrite(Blue, HIGH);
       digitalWrite(Red, HIGH);
       Keyboard.write('s');
       velocity -= change;
     }

    //press left botton
    isPressedLeft = digitalRead(Left_Button);    
    if(isPressedLeft==HIGH){
       Keyboard.write('a');
       digitalWrite(Blue, HIGH);        
     }

     //press right botton
     isPressedRight = digitalRead(Right_Button);
     if(isPressedRight==HIGH){
       Keyboard.write('d');
       digitalWrite(Blue, HIGH);
     }

  Serial.println(velocity);    
  
}
