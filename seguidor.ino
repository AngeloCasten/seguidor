// Pinos dos sensores
#define SENSOR_ESQ 2
#define SENSOR_DIR 3

// Pinos do motor esquerdo
#define IN1 4
#define IN2 5

// Pinos do motor direito
#define IN3 6
#define IN4 7

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
    // Linha centralizada -> anda reto
    frente();
  } 
  else if (esq == HIGH && dir == LOW) {  
    // Detectou linha na esquerda -> vira para a esquerda (para motor esq)
    pararEsq();
    frenteDir();
  } 
  else if (esq == LOW && dir == HIGH) {  
    // Detectou linha na direita -> vira para a direita (para motor dir)
    pararDir();
    frenteEsq();
  } 
  else {  
    // Perdeu a linha -> pode parar ou girar em busca
    parar();
  }
}

void frente() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void frenteEsq() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

void frenteDir() {
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void pararEsq() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

void pararDir() {
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void parar() {
  pararEsq();
  pararDir();
}
