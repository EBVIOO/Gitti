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
