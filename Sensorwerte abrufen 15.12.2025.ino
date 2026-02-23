#include <Encoder.h>

Encoder myEnc1(5, 6);
Encoder myEnc2(7, 8);



long pos1_alt = 0;
long pos2_alt = 0;

long pos1, pos2;
float aI1, aI2;
float sI1, sI2;
float t1 = 0;
float t2 = 0;

unsigned long Zeit;

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  
  // Positionswerte auslesen
  pos1 = myEnc1.read();
  pos2 = myEnc2.read();

  aI1 = (pos1 - pos1_alt)/2;
  aI2 = (pos2 - pos2_alt)/2;

  if (pos1_alt !=  pos1){
    t1 = t2;
    t2 = millis();
    Zeit = t2-t1;

  }



  // WinkelGeschwindigkeit = Differenz der Counts / Zeit

  if (Zeit > 0.0){
    sI1 = (aI1) / Zeit;
    sI2 = (aI2) / Zeit;
  }


  

  // Alte Position speichern
  pos1_alt = pos1;
  pos2_alt = pos2;

  // Ausgabe
  Serial.print("Encoder1 Counts: "); Serial.print(pos1);
  Serial.print("  Speed1: "); Serial.print(sI1);
  Serial.print(" | Encoder2 Counts: "); Serial.print(pos2);
  Serial.print("  Speed2: "); Serial.println(sI2);

  delay(200);
}




