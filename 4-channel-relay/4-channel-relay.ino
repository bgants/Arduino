
#define RELAY1 2
#define RELAY2 3
#define RELAY3 4
#define RELAY4 5
#define PIR 6

int pirState = LOW;   //assume no motion
int val = 0;          //var for reading pir

void setup() {
 pinMode(RELAY1, OUTPUT);
 pinMode(RELAY2, OUTPUT);

 pinMode(PIR, INPUT);

 digitalWrite(RELAY1,HIGH); //turn relay off  
 digitalWrite(RELAY2,HIGH); //turn relay off

 Serial.begin(9600);
}

void loop() {
  val = digitalRead(PIR);   // read input val
  if (val == HIGH) {
    if (pirState == LOW) {
      // we have just turned on
      Serial.println("Motion detected!");
      digitalWrite(RELAY1,LOW);  //turn relay on       
      digitalWrite(RELAY2,LOW);  //turn relay on     
      delay(90000);               //wait 2 seconds
      digitalWrite(RELAY1,HIGH); //turn relay off  
      digitalWrite(RELAY2,HIGH); //turn relay off    
      pirState = HIGH;       
    }
   } else {
      if (pirState == HIGH){
        // we have just turned of
        Serial.println("Motion ended!");
        // We only want to print on the output change, not state
        pirState = LOW;
        delay(60000);  
    } 
  }
}





 
