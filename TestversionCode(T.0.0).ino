#include <Encoder.h>

Encoder myEnc1(5, 6);
Encoder myEnc2(7, 8);

const float Zeit = 0.001; // Abtastzeit [s]

long pos1_alt = 0;
long pos2_alt = 0;

long pos1, pos2;
float sI1, sI2;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Positionswerte auslesen
  pos1 = myEnc1.read();
  pos2 = myEnc2.read();

  // Geschwindigkeit = Differenz der Counts / Zeit
  sI1 = (pos1 - pos1_alt) / Zeit;
  sI2 = (pos2 - pos2_alt) / Zeit;

  // Alte Position speichern
  pos1_alt = pos1;
  pos2_alt = pos2;




}
void setSollwertAussereRegelung(float as1,float as2,float aI1,float aI2) {
  float sS1 = as1 -aI1
  float sS2 = as2 - aI2
  return sS1,sS2

 
}



public class Regler {
    public Spannung RegelungInnenAndri(float sS1, float sI1,
                                       float sS2, float sI2, float Kp) {
        float Kp = 1.0f;
        float uS1 = Kp * (sS1 - sI1);
        float uS2 = Kp * (sS2 - sI2);

        return new Spannung(uS1, uS2);
    }
}
