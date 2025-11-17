// soll, ist und istGeschwindigkeit existieren bereits!
// hier wird NUR die neue Geschwindigkeit berechnet

float faktor = 0.2 + 0.05 * (abs(soll - ist) / 100.0);
faktor = constrain(faktor, 0.2, 0.7);

float speed = faktor * 40;   // das ist deine neue Geschwindigkeit
