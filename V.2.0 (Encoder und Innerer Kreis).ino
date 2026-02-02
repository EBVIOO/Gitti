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

  // Ausgabe
  Serial.print("Encoder1 Counts: "); Serial.print(pos1);
  Serial.print("  Speed1: "); Serial.print(sI1);
  Serial.print(" | Encoder2 Counts: "); Serial.print(pos2);
  Serial.print("  Speed2: "); Serial.println(sI2);

  delay(200);
}


void InnereRegelung(float sS1, float sI1,
                    float sS2, float sI2,
                    ReglerState* state)
{
    float Kp = 0.5;  
   
    state->u1 += Kp * (sS1 - sI1);
    state->u2 += Kp * (sS2 - sI2);

    
    if (state->u1 > 255) state->u1 = 255;
    if (state->u1 < 0)   state->u1 = 0;

    if (state->u2 > 255) state->u2 = 255;
    if (state->u2 < 0)   state->u2 = 0;
}
