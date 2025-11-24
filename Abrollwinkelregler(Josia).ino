float sollAbrollwinkel = 0;   // kommt aus Kinematik
float istAbrollwinkel  = 0;   // kommt vom Sensor
float sollwert_Innere  = 0;   // geht an die innere Regelung

void setup() { }

void loop() {
    // Werte holen
    sollAbrollwinkel = getSollAbrollwinkel();
    istAbrollwinkel  = getIstAbrollwinkel();

    // einfachste äußere Regelung: Fehler = Soll - Ist
    sollwert_Innere = sollAbrollwinkel - istAbrollwinkel;

    // an innere Regelung weitergeben
    setSollwertInnereRegelung(sollwert_Innere);
}

// Platzhalter – werden im Gesamtprojekt ersetzt
float getSollAbrollwinkel() { return 0; }
float getIstAbrollwinkel()  { return 0; }
void setSollwertInnereRegelung(float x) { }
