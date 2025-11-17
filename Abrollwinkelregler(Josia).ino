// ---- Parameter der äußeren Regelung ----
float Kp_outer = 1.0;     // Verstärkung äußere Regelung
float Ki_outer = 0.0;     // Optional: Integrationsanteil
float integral_outer = 0; // Integrator

// ---- Eingangsgrößen ----
float sollAbrollwinkel = 0;  // von der Kinematik
float istAbrollwinkel  = 0;  // vom Sensor (Encoder, IMU etc.)

// ---- Ausgang zur inneren Regelung ----
float sollwert_Innere = 0;

void setup() { }

void loop() {
    // Eingänge aktualisieren (Platzhalter):
    sollAbrollwinkel = getSollAbrollwinkel();
    istAbrollwinkel  = getIstAbrollwinkel();

    // --- äußere Regelung ---
    float fehler = sollAbrollwinkel - istAbrollwinkel;

    integral_outer += fehler;   // nur verwenden, wenn Ki_outer > 0

    sollwert_Innere = Kp_outer * fehler + Ki_outer * integral_outer;

    // Ausgabe an die innere Regelung:
    setSollwertInnereRegelung(sollwert_Innere);
}

// ---- Platzhalterfunktionen (werden im Gesamtprojekt ersetzt) ----
float getSollAbrollwinkel() { return 0; }
float getIstAbrollwinkel()  { return 0; }
void setSollwertInnereRegelung(float x) { }
