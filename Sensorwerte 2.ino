#include <Encoder.h>

// --- Encoder-Instanzen  ---
Encoder myEnc1(5, 6);
Encoder myEnc2(7, 8);

// --- Konfiguration ---
const long PULSES_PER_REV = 720L; // ticks pro Umdrehung (anpassen falls nötig)
const unsigned long SAMPLE_MS = 100UL; // Messintervall in ms
const int SERIAL_BAUD = 9600;

// Richtung (1 oder -1)
const int DIR1 = 1;
const int DIR2 = 1;

// Laufvariablen
unsigned long lastSampleMs = 0;
long lastCount1 = 0;
long lastCount2 = 0;

// Ausgabevariablen
float al1 = 0.0f, al2 = 0.0f; // Winkel in Grad
float sl1 = 0.0f, sl2 = 0.0f; // Geschwindigkeit in deg/s

void setup() {
  Serial.begin(SERIAL_BAUD);
  while (!Serial) { ; }
  Serial.println(F("Encoder Millis-Direct gestartet"));
  Serial.print(F("PULSES_PER_REV = ")); Serial.println(PULSES_PER_REV);
  Serial.print(F("SAMPLE_MS = ")); Serial.println(SAMPLE_MS);

  lastCount1 = myEnc1.read();
  lastCount2 = myEnc2.read();
  lastSampleMs = millis();
}

void loop() {
  unsigned long now = millis();
  unsigned long dt_ms = now - lastSampleMs;

  if (dt_ms >= SAMPLE_MS) {
    // Aktuelle Zählerstände
    long cur1 = myEnc1.read();
    long cur2 = myEnc2.read();

    // Delta counts seit letzter Messung
    long dc1 = cur1 - lastCount1;
    long dc2 = cur2 - lastCount2;

    // Winkel (Gesamt seit Reset) in Grad
    al1 = ((float)cur1 / (float)PULSES_PER_REV) * 360.0f * (float)DIR1;
    al2 = ((float)cur2 / (float)PULSES_PER_REV) * 360.0f * (float)DIR2;

    // Geschwindigkeit berechnen: direkt mit dt_ms (Millisekunden)
    // countsPerSec = dc * 1000 / dt_ms
    // deg/s = countsPerSec * (360 / PULSES_PER_REV)
    if (dt_ms > 0) {
      float countsPerSec1 = (float)dc1 * 1000.0f / (float)dt_ms;
      float countsPerSec2 = (float)dc2 * 1000.0f / (float)dt_ms;
      sl1 = countsPerSec1 * (360.0f / (float)PULSES_PER_REV) * (float)DIR1;
      sl2 = countsPerSec2 * (360.0f / (float)PULSES_PER_REV) * (float)DIR2;
    } else {
      // Sicherheits-Fallback (falls dt_ms==0, sehr unwahrscheinlich)
      sl1 = 0.0f;
      sl2 = 0.0f;
    }

    // Ausgabe
    Serial.print("al1(deg)="); Serial.print(al1, 3);
    Serial.print("  sl1(deg/s)="); Serial.print(sl1, 3);
    Serial.print("  |  al2(deg)="); Serial.print(al2, 3);
    Serial.print("  sl2(deg/s)="); Serial.println(sl2, 3);

    // Update letzte Werte
    lastCount1 = cur1;
    lastCount2 = cur2;
    lastSampleMs = now;
  }

  // andere nicht-blockierende Aufgaben hier
}

// Reset-Funktion (setzt Zähler und Werte zurück)
void resetEncoders() {
  myEnc1.write(0);
  myEnc2.write(0);
  lastCount1 = 0;
  lastCount2 = 0;
  lastSampleMs = millis();
  al1 = al2 = sl1 = sl2 = 0.0f;
  Serial.println(F("Encoder reset"));
}
