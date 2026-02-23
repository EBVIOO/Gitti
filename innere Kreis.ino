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
