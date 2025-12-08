#include <Encoder.h>

String empfangen = "a";   
String erweitert = empfangen + "b";  

void setup() {
  Serial.begin(9600);
  Serial.println(erweitert);  
}

void loop() {
}
