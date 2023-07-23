//CODE DONE BY BOSH MACSIS && DR SURESAN PARETH
#include <IRremote.h>
#define irPin 12

#define in1 2 //L298n Motor Driver pins.
#define in2 4
#define in3 6
#define in4 7

IRrecv irrecv(irPin);
decode_results rslts;


int command; //Int to store app command state.
int Speed = 150; // 0 - 255.
int Speedsec;
int buttonState = 0;
int lastButtonState = 0;
int Turnradius = 0; //Set the radius of a turn, 0 - 255 Note:the robot will malfunction if this is higher than int Speed.
int brakeTime = 45;
int brkonoff = 1;



 
void setup() 
{
   pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
 //Set the LED pin.
  Serial.begin(9600);
  irrecv.enableIRIn();
}
 
void loop() {
   if (irrecv.decode(&rslts)) {
      Serial.println(rslts.value);
      
      switch (rslts.value) {
        
         case 12582914:            //  FORDWARD Button
            Forward();
            break;
 
         case 12582916:            //  LEFT Button
            Left();
            break;   
 
         case 12582918:            //  RIGHT Button
            Right();
            break;
 
         case 12582920:            //  BACK Button
            Back();
            break;
        
         default:            // STOP Button
            Stop();
            break;
   }      
   irrecv.resume();
   }
}
 
void Back()
{
            digitalWrite(5, HIGH);
            digitalWrite(3, HIGH);
            
            digitalWrite(2, HIGH);
             digitalWrite(4, LOW);
            digitalWrite(6, HIGH);
            digitalWrite(7, LOW);
            
           
}
 
void Forward()
{ 
            digitalWrite(5, HIGH);
            digitalWrite(3, HIGH);
            
            digitalWrite(2, LOW);
            digitalWrite(4, HIGH);
            digitalWrite(6, LOW);            
            digitalWrite(7, HIGH);
            
            
            
}    
void Left()
{ 
            
            digitalWrite(5, HIGH);
            digitalWrite(3, HIGH);

            digitalWrite(2, HIGH);
             digitalWrite(4, LOW);
            digitalWrite(6, LOW);            
            digitalWrite(7, HIGH);
           
           
}
 
void Right()
{
          digitalWrite(5, HIGH);
            digitalWrite(3, HIGH);
            digitalWrite(2, LOW);
            digitalWrite(4, HIGH);
           digitalWrite(6, HIGH);            
            digitalWrite(7, LOW);
           
           
} 
void Stop()
{
            digitalWrite(5, LOW);
            digitalWrite(3, LOW);
            digitalWrite(2, LOW);
            digitalWrite(4, LOW);
            digitalWrite(6, LOW);
            digitalWrite(7, LOW);
}
