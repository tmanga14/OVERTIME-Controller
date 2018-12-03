#include <Adafruit_NeoPixel.h>
#include <Keyboard.h>

#define CLK 6
#define DT 9
#define SW 12
#define Button 10

int counter = 0;
int state;
int Laststate; 
bool isPressing;

void setup() {
  pinMode(CLK,INPUT);
  pinMode(DT,INPUT);
  pinMode(SW,INPUT);
  pinMode(Button, INPUT);
  Serial.begin(9600);
  isPressing = false;

  Laststate = digitalRead(CLK);
}

void loop() {
  state = digitalRead(CLK);
  if(state != Laststate)
  {
    if(digitalRead(DT) != state)
    {
      counter++;
      Serial.println("Left");
      Keyboard.write('A');
      }
      else
      {
        counter--;
        Serial.println("Right");
        Keyboard.write('D');
        }
  
         //Serial.println(counter);
  }
  if(digitalRead(Button)){
    if(isPressing == false){
      isPressing = true;
      Keyboard.write('W');
    }
    else {
      
    }
  } else if (isPressing){//if this is reached, it means the button is no longer held but was being held before
    Keyboard.write('S');
    isPressing = false;
  }
  
  if(digitalRead(SW) != 1)
  {
    //counter=0;
    //Serial.println(counter);
    //Serial.println("Stationary");
    }
    
    Laststate= state;
   
   }

