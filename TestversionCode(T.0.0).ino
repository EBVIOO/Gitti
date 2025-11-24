#include <Encoder.h>

Encoder encoder1(18,19);
Encoder encoder2(20,21);





float Kp_outer = 1.0;     // Verstärkung äußere Regelung
float Ki_outer = 0.0;     // Optional: Integrationsanteil
float integral_outer = 0; // Integrator

// ---- Eingangsgrößen ----
float sollAbrollwinkel = 0;  // von der Kinematik
float istAbrollwinkel  = 0;  // vom Sensor (Encoder, IMU etc.)

// ---- Ausgang zur inneren Regelung ----
float sollwert_Innere = 0;

void setup() {
  calibrate()
}
void loop() {



    // Eingänge aktualisieren (Platzhalter):
    sollAbrollwinkel = getSollAbrollwinkel();
    istAbrollwinkel  = getIstAbrollwinkel();

    // --- äußere Regelung ---
    float fehler = sollAbrollwinkel - istAbrollwinkel;

    integral_outer += fehler;   // nur verwenden, wenn Ki_outer > 0

    sollwert_geschwindigkeit = Kp_outer * fehler + Ki_outer * integral_outer;

    // Ausgabe an die innere Regelung:
    Geschwindigkeitsregelung(sollwert_geschwindigkeit );
}

// ---- Platzhalterfunktionen (werden im Gesamtprojekt ersetzt) ----
float getSollAbrollwinkel() { return 0; }
float getIstAbrollwinkel()  { return 0; }



float Geschwindigkeitsregelung(float x) {
float diff = soll - ist;

float faktor = 0.2 + 0.05 * (abs(diff) / 100.0);
faktor = constrain(faktor, 0.2, 0.7);

float speedValue = faktor * 40;

if (diff == 0) {
    speed = 0;
} else {
    speed = (diff > 0) ? speedValue : -speedValue;
}


}  /*Andri´s Funktion*/

void calibrate() {
  
  while(Autohome == HIGH){
    eslstate = digitalRead(esl);      //Endschalter auslesen während Autohome
    esrstate = digitalRead(esr);      //

    //Rolle L aufrollen und Rolle R abrollen
    if(esl=HIGH){
      //stoppe rollen
    }

    //Rolle L gezielt abrollen umd Rolle R aufrollen
    if(esr=HIGH){
    //stoppe Rollen  
    }
    //fahre beide Rollen auf 0/0
  }
}//funktion von brennain


void _read_encoder(Encoder ENC){
  ENC.read();



  
}
