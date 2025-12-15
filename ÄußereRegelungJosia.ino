int AB = 0;   // Soll-Abrollwinkel
int C  = 0;   // Ist-Abrollwinkel

int Ergebnis = 0;

void setup() {}

void loop() {
  // Beispielwerte
  AB = 20;
  C  = 12;

  // äußere Regelung: nur Soll minus Ist
  Ergebnis = AB - C;

  // Ergebnis als "ABC" weitergeben
  setSollwertInnereRegelung(Ergebnis);
}

void setSollwertInnereRegelung(stri) {
 
}

