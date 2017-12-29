int pinLed [5] = {4, 6, 8, 10, 12} ; //Déclaration tableau une dimension contenant les pins associés aux LEDs
unsigned long valeurLuminosite = 0 ;  //Variable qui contiendra la valeur de la luminosité

void setup() {

  for (int i = 0 ; i < 5 ; i++) //Affectation des pins comme étant des sorties + définition de l'état initial des LEDs
  {
    pinMode (pinLed[i], OUTPUT) ;
    digitalWrite (pinLed[i], LOW) ;
  }
  Serial.begin (9600) ;
}

void loop() {

  valeurLuminosite = analogRead (A1) ;  //On lit la valeur de l'intensité (on la stock)
  valeurLuminosite = map (valeurLuminosite, 0, 1023, 0, 5) ;  //On remplace la valeur de la luminosité par une valeur entre 0 et 5
  Serial.println (valeurLuminosite) ;
  for (int i = 0; i < valeurLuminosite; i++) //On allume le nombre de LED adequat
  {
    digitalWrite (pinLed [i], HIGH);
  }

  delay (10) ;
  for (int i = 0; i < valeurLuminosite; i++) //On les éteins
  {
    digitalWrite (pinLed [i], LOW);
  }
}
