// Sensores
#define SENSOR_ESQ 2
#define SENSOR_DIR 3

// Motores (usando pinos PWM)
#define IN1 5   // motor esquerdo (PWM)
#define IN2 4
#define IN3 6   // motor direito (PWM)
#define IN4 7

// Velocidades
int VELOCIDADE_BASE = 200; // 0–255
int CURVA = 120;           // velocidade reduzida na curva

void setup() {
  pinMode(SENSOR_ESQ, INPUT);
  pinMode(SENSOR_DIR, INPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  int esq = digitalRead(SENSOR_ESQ);
  int dir = digitalRead(SENSOR_DIR);

  if (esq == LOW && dir == LOW) {
    // Linha centralizada -> reto
    mover(VELOCIDADE_BASE, VELOCIDADE_BASE);
  }
  else if (esq == HIGH && dir == LOW) {
    // Linha na esquerda -> curva à esquerda
    mover(CURVA, VELOCIDADE_BASE);
  }
  else if (esq == LOW && dir == HIGH) {
    // Linha na direita -> curva à direita
    mover(VELOCIDADE_BASE, CURVA);
  }
  else {
    // Fora da linha -> parar
    mover(0, 0);
  }
}

void mover(int velEsq, int velDir) {
  // Motor esquerdo
  if (velEsq > 0) {
    analogWrite(IN1, velEsq);
    digitalWrite(IN2, LOW);
  } else {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
  }

  // Motor direito
  if (velDir > 0) {
    analogWrite(IN3, velDir);
    digitalWrite(IN4, LOW);
  } else {
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }
}
