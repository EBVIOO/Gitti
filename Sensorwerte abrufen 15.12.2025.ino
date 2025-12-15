// Parameter
const float COUNTS_PER_REV = 4096.0;  // Encoder-Auflösung
const float Zeit = 0.001;             // Abtastzeit [s]

//Encoder-Zähler
volatile long encoder1Counts = 0;
volatile long encoder2Counts = 0;

float aI1, aI2;   // Abrollwinkel
float sI1, sI2;   // Geschwindigkeit

// interne Speicher 
static float aI1_alt = 0.0;
static float aI2_alt = 0.0;

// Sensorwerte abrufen
void readSensorwerte() {

  aI1 = (encoder1Counts / COUNTS_PER_REV) * 2.0 * PI;
  aI2 = (encoder2Counts / COUNTS_PER_REV) * 2.0 * PI;


  sI1 = (aI1 - aI1_alt) / Zeit;
  sI2 = (aI2 - aI2_alt) / Zeit;


  aI1_alt = aI1;
  aI2_alt = aI2;
}


void setup() {
  Serial.begin(9600);  

  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);

}


void loop() {
  readSensorwerte(); // Sensorwerte abrufen

  // Serial Monitor Ausgabe
  Serial.print("aI1: "); Serial.print(aI1);
  Serial.print("  sI1: "); Serial.print(sI1);
  Serial.print(" | aI2: "); Serial.print(aI2);
  Serial.print("  sI2: "); Serial.println(sI2);

  delay(100); 
}
