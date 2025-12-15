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

void setSollwertInnereRegelung(String as1,String as2,String aI1,String aI2) {
  String sS1 = as1 -aI1
  String sS2 = as2 - aI2
  return sS1,sS2
  
 
}




