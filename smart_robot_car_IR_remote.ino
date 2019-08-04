#include <IRremote.h>
 int RECV_PIN = 12;
 IRrecv irrecv(RECV_PIN);
 decode_results results;
 
   const int motorA1      = 3;  
   const int motorA2      = 4; 
   const int motorAspeed  = 5;
   const int motorB1      = 7; 
   const int motorB2      = 8; 
   const int motorBspeed  =6;
   int vSpeed = 80;        
   int turn_speed = 90;
   
void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver

}

void loop() {
 
  if (irrecv.decode(&results)) {
    Serial.println(results.value, DEC);
    irrecv.resume(); // Receive the next value

    if (results.value == 16736925){
    forward();
    }
 
   if (results.value == 16754775){
    backward();
    }

    if (results.value == 16761405){
    Tright();
    delay(500);
    st();
    }

    if (results.value == 1386468383){
    Tleft();
    delay(500);
    st();
    }

     if (results.value == 16732845){
    st();
    }
}
}

void backward(){
   digitalWrite (motorA1,LOW);
   digitalWrite (motorA2,HIGH);                       
   digitalWrite (motorB1,LOW);
   digitalWrite (motorB2,HIGH);

  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, vSpeed);

   }

  void forward(){
  digitalWrite (motorA1,HIGH);
   digitalWrite (motorA2,LOW);                       
   digitalWrite (motorB1,HIGH);
   digitalWrite (motorB2,LOW);

  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, vSpeed);
  }

void Tleft(){
   digitalWrite (motorA1,HIGH);
   digitalWrite (motorA2,LOW);                       
   digitalWrite (motorB1,LOW);
   digitalWrite (motorB2,HIGH);

  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, vSpeed);
   }  

  void Tright(){
   digitalWrite (motorA1,LOW);
   digitalWrite (motorA2,HIGH);                       
   digitalWrite (motorB1,HIGH);
   digitalWrite (motorB2,LOW);

  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, vSpeed);
  }

  void st(){
  analogWrite (motorAspeed, 0);
  analogWrite (motorBspeed, 0);
    }

