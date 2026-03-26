# 🤖 LineFollowerCar

Voiture suiveuse de ligne avec Adafruit Motor Shield

---

## 🎯 À quoi ça sert

LineFollowerCar permet à une voiture robot de suivre automatiquement une ligne noire :

* 🔍 2 capteurs IR (A4 gauche, A5 droite) détectent la ligne
* ⚙️ Adafruit Motor Shield contrôle 2 moteurs DC (M3 et M4)
* 🧠 Algorithme simple basé sur les capteurs pour tourner automatiquement

---

## 🌍 Utilisations

* 🏁 Compétitions de robot suiveur de ligne
* 🎓 Projet scolaire (SI / Arduino)
* 🤖 Base pour robots (labyrinthe, IA simple)

---

## 🛠️ Matériel requis

* Arduino UNO
* Adafruit Motor Shield (v1/v2)
* 2 moteurs DC (6–12V)
* 2 capteurs IR (ligne) → A4 (gauche), A5 (droite)
* Châssis robot 2 roues + roue folle
* Batterie (ex: 9V ou pack batterie)

---

## 📚 Bibliothèques Arduino

Bibliothèque requise :

* `AFMotor.h` (Adafruit Motor Shield)

Installation :

* Arduino IDE → Gérer les bibliothèques
* Rechercher : **Adafruit Motor Shield**

---

## 🚀 Installation

1. Monter le Motor Shield sur l’Arduino
2. Brancher les moteurs :

   * M3 → moteur droit
   * M4 → moteur gauche
3. Connecter les capteurs :

   * Gauche → A4
   * Droite → A5
4. Placer une ligne noire au sol
5. Ouvrir le Serial Monitor (**9600 bauds**)

---

## 🧠 Logique automatique

Seuil utilisé : **400**

* Capteur ≤ 400 → NOIR détecté
* Capteur > 400 → BLANC

### Comportement :

* 🛑 **NOIR / NOIR** → STOP (intersection)
* ⬅️ **GAUCHE NOIR / DROITE BLANC** → Tourne à gauche
* ➡️ **GAUCHE BLANC / DROITE NOIR** → Tourne à droite
* 🚗 **BLANC / BLANC** → Avance tout droit

---

## ⚙️ Paramètres modifiables

```cpp
motor1.setSpeed(200);  // Vitesse moteur gauche (0-255)
motor2.setSpeed(200);  // Vitesse moteur droite

int lineThreshold = 400;  // Seuil détection ligne
```

---

## 📊 Sortie Serial (debug)

```text
512   // Capteur gauche (BLANC)
289   // Capteur droit (NOIR)
```

Permet de voir les valeurs en temps réel et ajuster le seuil.

---

## ⚠️ Conseils

* Ajuster le seuil (400) selon ton tapis
* Nettoyer les capteurs pour meilleure précision
* Utiliser une bonne alimentation pour les moteurs
* Tester différentes vitesses pour stabilité

---

## 🔧 Fonctionnement moteurs

* `FORWARD` → avance
* `BACKWARD` → recule
* `RELEASE` → stop

---

## ✨ Améliorations possibles

* 🧠 PID (plus précis que simple logique)
* ⚡ Capteurs supplémentaires (3 ou 5 capteurs)
* 🖥️ Écran LCD (debug en direct)
* 📡 Bluetooth (contrôle manuel)
* 🤖 IA (suivi avancé / labyrinthe)

---

## 👨‍💻 Auteur

Projet Robotique Arduino 🤖
