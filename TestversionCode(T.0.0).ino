


void setup() {
  Serial.begin(9600); // Serial Monitor starten
}

void loop() {
  
  String Sebastian = "B";                    
  String AB = Julian() + Sebastian;
  String AbdulOne= "C";
  String ABC = RegelungAussenJosia(AB,AbdulOne);
  String AbdulTwo ="D";
  String Ergebnis = Andri(ABC,AbdulTwo);

  
  Serial.println(Ergebnis);         
  delay(1000);                               
}

String Julian() {
  String A = "A";
  return A;
}

String RegelungAussenJosia(String A_B,String C) {
  String ABC =(A_B + C);
  return ABC
}

String RegelungInnenAndri(String ABC,String D) {

  String E = "E";
  String ABCDE = ABC + D + E;
  return ABCDE
    }

