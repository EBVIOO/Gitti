// Eingänge
float aS1 = 0;   // Soll-Abrollwinkel Motor 1
float aS2 = 0;   // Soll-Abrollwinkel Motor 2
float aI1 = 0;   // Ist-Abrollwinkel Motor 1
float aI2 = 0;   // Ist-Abrollwinkel Motor 2

// Ausgang
float sS1 = 0;   // Soll-Geschwindigkeit Motor 1
float sS2 = 0;   // Soll-Geschwindigkeit Motor 2

// Umrechnungsfaktor Winkel -> Geschwindigkeit
float k = 1.0;

void setup() {
}

void loop() {
  // Beispielwerte (werden später ersetzt)
  aS1 = 30;
  aI1 = 25;

  aS2 = 40;
  aI2 = 35;

  // äußere Regelung: nur Differenz * Faktor
  sS1 = (aS1 - aI1) * k;
  sS2 = (aS2 - aI2) * k;
}
