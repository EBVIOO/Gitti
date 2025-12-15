String x = "x";
String Y = "Y";



void setup() {
  Serial.begin(9600); // Serial Monitor starten
}

void loop() {
  
                 
}



void setSollwertAussereRegelung(float as1,float as2,float aI1,float aI2) {
  float sS1 = as1 -aI1
  float sS2 = as2 - aI2
  return sS1,sS2

 
}



Spannung RegelungInnenAndri(float sS1, float sI1,
                            float sS2, float sI2) {
    float Kp = 1.0;
    float uS1 = Kp * (sS1 - sI1);
    float uS2 = Kp * (sS2 - sI2);

    return new Spannung(uS1, uS2);
}
