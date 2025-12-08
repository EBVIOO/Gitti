

void setup() {
}
void loop(){
Julian()
}

String Julian() {
  String A = "A";
  return A;
}

void setup() {
  Serial.begin(9600); // Serial Monitor starten
}

void loop() {
  String Sebastian = "B";                    
  String AB = Julian() + Sebastian;
  String AbdulOne= "C";
  String ABC = setSollwertInnereRegelung(AB,AbdulOne);
  String AbdulTwo ="D";
  Serial.println(SebastianErgebnis);         
  delay(1000);                               
}

String Julian() {
  String A = "A";
  return A;


String setSollwertInnereRegelung(String A_B,String C) {
  String ABC =(A_B - C);
  return ABC
}


