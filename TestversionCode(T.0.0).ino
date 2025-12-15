String x = "x";
String Y = "Y";



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


void setSollwertInnereRegelung(String as1,String as2,String aI1,String aI2) {
  String sS1 = as1 + aI1
  String sS2 = as2 + aI2
  return sS1,sS2
  
 
}


String RegelungInnenAndri(String ss1,String ss2,String sI1,String sI2) {
  
  String uS1 = sS1 - sI1;
  String uS2 = sS2 - sI2;
  return uS1, uS2
    }
