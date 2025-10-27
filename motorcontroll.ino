#include <Encoder.h>

int directionPin = 12; // Es wird int-Variable für den Direction-Pin deklariert und mit dem wert 12 initialisiert
int pwmPin = 3;        // Es wird int-Variable für den pwmPin deklariert und mit dem wert 3 initialisiert

//boolean to switch direction
bool directionState;  // Es wird eine bool-Variable für den directionState deklariert. Die variable wird automatisch mit false initialisert 

void setup() { // Funktionsbereich START 

Serial.begin(9600);
    
//define pins
pinMode(directionPin, OUTPUT); //  PIN-Konfiguration auf OUTPUT-Modus
pinMode(pwmPin, OUTPUT);       //  PIN-Konfiguration auf OUTPUT-Modus

} // Funktionsbereich ENDE 


void loop() {// Funktionsbereich START 

set_power(30);
delay(2000);
set_power(-100);
delay(2000);
}



void set_power( int given_power){
  
 given_power = map(given_power,-100,100,-100,100);
 float positive_power = abs(given_power);
 int direct;
 float power_percentage;
 int real_power;

 if ( given_power > 0){
  direct = 1;
  analogWrite(directionPin,direct);
  
 }
 else{

  direct = -1;
  analogWrite(directionPin,direct);
 }
 power_percentage = (positive_power / 100);
 real_power = 255 * power_percentage;
 analogWrite(pwmPin,real_power);
}
                                                                                                                                
