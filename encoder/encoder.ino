int pinA = 3;
int pinB = 4; 
int count = 0; 
int totaldegree = 0;
int lastPin;  
int aValue;
boolean operate;

 void setup() 
 { 
   pinMode (pinA,INPUT);
   pinMode (pinB,INPUT);
   lastPin = digitalRead(pinA);
   Serial.begin (9600);
   Serial.println("BEGIN");
   Serial.println();
 } 

 void loop() 
 { 
   aValue = digitalRead(pinA);
   if (aValue != lastPin)
   { 
     if (digitalRead(pinB) != aVal) //We're Rotating Clockwise
     { 
       count ++;
       operate = true;  
       
     } 
     
     else 
     
     {
       operate = false;
       count--;
     }

     if (count % 40 == 0)
     {
       totaldegree += 1;
       Serial.print("Encoder Count: ");
       Serial.println(totaldegree);
       Serial.println();
     }
   } 
   lastPin = aValue;
 } 
