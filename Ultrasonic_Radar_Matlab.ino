#include <Servo.h> 
Servo myservo; 

#define echo 6    //Echo pin
#define trigger 7 //Trigger pin

#define G_led 8 // choose the pin for the Green Led
#define R_led 9 // choose the pin for the Red Led

int distance;
int degree;
 
void setup() { // put your setup code here, to run once 
Serial.begin(9600);

myservo.attach(2); // declare Servo Motor as output

pinMode(echo, INPUT );// declare ultrasonic sensor Echo pin as input
pinMode(trigger, OUTPUT); // declare ultrasonic sensor Trigger pin as Output 

pinMode(R_led,OUTPUT); // declare Red LED as output
pinMode(G_led,OUTPUT); // declare Green LED as output

delay(100); 
} 
 
 
void loop() { 

for(degree=1; degree<180; degree+=1){ 
myservo.write(degree);   
delay(80);
data();   
}

for(degree=180; degree>1; degree-=1){ 
myservo.write(degree);   
delay(80);
data();   
}

}


void data(){
digitalWrite(trigger, LOW); 
delayMicroseconds(2); 
digitalWrite(trigger, HIGH); 
delayMicroseconds(10); 
long time = pulseIn(echo, HIGH); 
distance = time / 28.5 / 2;

if(distance>100){distance = 100;}
  
if(distance>50){ 
digitalWrite(G_led, HIGH); // LED Turn On   
digitalWrite(R_led, LOW); // LED Turn Off 
}else{ 
digitalWrite(G_led, LOW); // LED Turn Off   
digitalWrite(R_led, HIGH); // LED Turn On 
}
  
Serial.print(degree); Serial.print( " "); Serial.println(distance);
}



