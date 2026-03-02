1)
float diff = soll - ist;

float faktor = 0.2 + 0.05 * (abs(diff) / 100.0);
faktor = constrain(faktor, 0.2, 0.7);

float speedValue = faktor * 40;

if (diff == 0) {
    speed = 0;
} else {
    speed = (diff > 0) ? speedValue : -speedValue;
}


2)

float diff = soll - ist;

float faktor = 0.2 + 0.05 * (abs(diff) / 100.0);
faktor = constrain(faktor, 0.2, 0.7);

float speedCommand = faktor * 40;

if (diff == 0) {
    speedCommand = 0;
} else {
    speedCommand = (diff > 0) ? speedCommand : -speedCommand;
}

float istSpeed = getIstSpeed();

float speedError = speedCommand - istSpeed;

float Kp_speed = 1.0;
float correctedSpeed = speedCommand + Kp_speed * speedError;

float minSpeed = 0.2 * 40;
float maxSpeed = 0.7 * 40;

if (correctedSpeed > 0) {
    correctedSpeed = constrain(correctedSpeed, minSpeed, maxSpeed);
} else if (correctedSpeed < 0) {
    correctedSpeed = constrain(correctedSpeed, -maxSpeed, -minSpeed);
} else {
    correctedSpeed = 0;
}

speed = correctedSpeed;

3)
float diff = ABC;

float faktor = 0.2 + 0.05 * (abs(diff) / 100.0);
faktor = constrain(faktor, 0.2, 0.7);

float speedCommand = faktor * 40;

if (diff == 0) {
    speedCommand = 0;
} else {
    speedCommand = (diff > 0) ? speedCommand : -speedCommand;
}

float istSpeed = D;

float speedError = speedCommand - istSpeed;

float Kp_speed = 1.0;
float correctedSpeed = speedCommand + Kp_speed * speedError;

float minSpeed = 0.2 * 40;
float maxSpeed = 0.7 * 40;

if (correctedSpeed > 0) {
    correctedSpeed = constrain(correctedSpeed, minSpeed, maxSpeed);
} else if (correctedSpeed < 0) {
    correctedSpeed = constrain(correctedSpeed, -maxSpeed, -minSpeed);
} else {
    correctedSpeed = 0;
}

speed = correctedSpeed;   

4) Spannung RegelungInnenAndri(float sS1, float sI1,
                            float sS2, float sI2) {
    float Kp = const;
    float uS1 = Kp * (sS1 - sI1);
    float uS2 = Kp * (sS2 - sI2);

    return(uS1, uS2);
}

5) // innere Regelung 

void InnereRegelung(float sS1, float sI1,
                    float sS2, float sI2,
                    ReglerState* state)
{
    float Kp = 0.5;  
   
    state->u1 += Kp * (sS1 - sI1);
    state->u2 += Kp * (sS2 - sI2);

    
    if (state->u1 > 255) state->u1 = 255;
    if (state->u1 < -255)   state->u1 = -255;

    if (state->u2 > 255) state->u2 = 255;
    if (state->u2 < -255)   state->u2 = -255;
}  

6) typedef struct {
    float u1;
    float u2;
} ReglerState;


ReglerState state = {0, 0};


void InnereRegelung(float sS1, float sI1,
                    float sS2, float sI2,
                    ReglerState* state)
{
    float Kp = 0.5;
    
    state->u1 += Kp * (sS1 - sI1);
    state->u2 += Kp * (sS2 - sI2);

    if (state->u1 > 255) state->u1 = 255;
    if (state->u1 < -255) state->u1 = -255;

    if (state->u2 > 255) state->u2 = 255;
    if (state->u2 < -255) state->u2 = -255;
}


float sS1, sI1, sS2, sI2;

void setup() {
    
}

void loop() {
 

    InnereRegelung(sS1, sI1, sS2, sI2, &state);

}

 typedef struct {
    float u1;
    float u2;
} ReglerState;

ReglerState state = {0, 0};

// Функция регулятора
void InnereRegelung(float sS1, float sI1,
                    float sS2, float sI2,
                    ReglerState* state)
{
    float Kp = 0.5;

    state->u1 += Kp * (sS1 - sI1);
    state->u2 += Kp * (sS2 - sI2);

    if (state->u1 > 255) state->u1 = 255;
    if (state->u1 < -255) state->u1 = -255;

    if (state->u2 > 255) state->u2 = 255;
    if (state->u2 < -255) state->u2 = -255;
}

// Переменные для теста
float sS1 = 100;  // желаемое значение 1
float sI1 = 100;   // измеренное значение 1
float sS2 = 120;  // желаемое значение 2
float sI2 = 170;  // измеренное значение 2

void setup() {
    Serial.begin(9600);
}

void loop() {
    // Вызываем регулятор
    InnereRegelung(sS1, sI1, sS2, sI2, &state);

    // Печатаем результат
    Serial.print("u1 = "); Serial.print(state.u1);
    Serial.print("   u2 = "); Serial.println(state.u2);

    delay(500);  // полсекунды между выводами, чтобы было видно изменения
} 
int beispielVariable4 = 4;

void setupAndrii()
{
  
}

void AndriiSpeedRegelung()
{
  // CODE
  uS1 = 255;
  uS2 = 255;
  dM1 = true;  
  dM2 = false;  
} 
letzte 


const int pwmPin1 = 1;
const int dirPin1 = 1;
const int pwmPin2 = 1;
const int dirPin2 = 1;

typedef struct {
    float u1;
    float u2;
} ReglerState;

ReglerState state = {0, 0};

float sS1, sI1, sS2, sI2;  // Soll и Ist
int uS1, uS2;
bool dM1, dM2;


void setup() {
    Serial.begin(9600);

    pinMode(pwmPin1, OUTPUT);
    pinMode(dirPin1, OUTPUT);
    pinMode(pwmPin2, OUTPUT);
    pinMode(dirPin2, OUTPUT);

    
    sS1 = 100; sI1 = 0;
    sS2 = 120; sI2 = 0;
    uS1 = uS2 = 0;
    dM1 = dM2 = true;
}



{
    float Kp = 0.5;

    state->u1 += Kp * (sS1 - sI1);
    state->u2 += Kp * (sS2 - sI2);

    if (state->u1 > 255) state->u1 = 255;
    if (state->u1 < -255) state->u1 = -255;

    if (state->u2 > 255) state->u2 = 255;
    if (state->u2 < -255) state->u2 = -255;
}


void loop() {
    InnereRegelung(sS1, sI1, sS2, sI2, &state);

    
    uS1 = (int)abs(state.u1);
    uS2 = (int)abs(state.u2);

    dM1 = (state.u1 >= 0);
    dM2 = (state.u2 >= 0);

    
    analogWrite(pwmPin1, uS1);
    digitalWrite(dirPin1, dM1);
    analogWrite(pwmPin2, uS2);
    digitalWrite(dirPin2, dM2);

    Serial.print("u1="); Serial.print(state.u1);
    Serial.print(" PWM1="); Serial.print(uS1);
    Serial.print(" dir1="); Serial.print(dM1);
    Serial.print(" | u2="); Serial.print(state.u2);
    Serial.print(" PWM2="); Serial.print(uS2);
    Serial.print(" dir2="); Serial.println(dM2);

    delay(500);
}
