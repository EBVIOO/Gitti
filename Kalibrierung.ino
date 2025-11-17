const int esl = 52;     //Endschalter links Pin
const int esr = 53;     //Endschalter rechts Pin

int eslstate = 0;     // variable for reading the pushbutton status
int esrstate = 0;     // variable for reading the pushbutton status
bool Autohome = HIGH;     //Vorgang ist aktiv

void setup() {
  pinMode(esl, INPUT);
  pinMode(esr, INPUT);

  Serial.begin(9600);
}

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
}

