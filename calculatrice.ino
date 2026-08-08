#include <math.h>

String cmd = "";

void setup() {
  Serial.begin(9600);
  Serial.println("Mode d'emploi a lire avant première utilisation.");
  Serial.println("Calculatrice externe pour personne qui n'on pas de procésseur assez puissant pour calculer des chiffres sur le processeur et donc calculer sur un arduino externe branché en usb sur l'ordinateur pour ne pas encombrer les recources du pauvre pc meme si ca utilise encore des recources mais ca en utilise moins que si on calcule directement sur le processeur pourit et donc risquer de faire crash le pc");
  Serial.println("Je paris que tu n'as pas lu en haut");
  Serial.println("Operations :");
  Serial.println("+  -  x  /  ^");
  Serial.println("s nombre = racine carree");
  Serial.println("p nombre = 10^nombre");
  Serial.println("2026");
}

void loop() {

  if (Serial.available()) {

    cmd = Serial.readStringUntil('\n');
    cmd.trim();

    if (cmd.length() == 0)
      return;


    // Racine carrée
    if (cmd[0] == 's') {

      float x = cmd.substring(1).toFloat();

      if (x < 0) {
        Serial.println("Erreur : nombre negatif");
      } else {
        Serial.print("sqrt(");
        Serial.print(x);
        Serial.print(") = ");
        Serial.println(sqrt(x));
      }

      return;
    }


    // Puissance de 10
    if (cmd[0] == 'p') {

      float x = cmd.substring(1).toFloat();

      Serial.print("10^");
      Serial.print(x);
      Serial.print(" = ");
      Serial.println(pow(10, x));

      return;
    }


    // Operateurs classiques
    int pos = -1;
    char op = 0;


    for (int i = 1; i < cmd.length(); i++) {

      if (cmd[i] == '+' ||
          cmd[i] == '-' ||
          cmd[i] == 'x' ||
          cmd[i] == '/' ||
          cmd[i] == '^') {

        pos = i;
        op = cmd[i];
        break;
      }
    }


    if (pos == -1) {
      Serial.println("Commande inconnue");
      return;
    }


    float a = cmd.substring(0, pos).toFloat();
    float b = cmd.substring(pos + 1).toFloat();

    float resultat;


    switch(op) {

      case '+':
        resultat = a + b;
        break;

      case '-':
        resultat = a - b;
        break;

      case 'x':
        resultat = a * b;
        break;

      case '/':
        resultat = a / b;
        break;

      case '^':
        resultat = pow(a, b);
        break;
      case 'a':
      resultat = 67;
      break;
    }

   if (resultat == 67 )
   {
    Serial.print("67!!!!!!!!!67");
   }
   else
   {
    Serial.print(a);
    Serial.print(" ");
    Serial.print(op);
    Serial.print(" ");
    Serial.print(b);
    Serial.print(" = ");
    Serial.println(resultat);
   }
  }
}
