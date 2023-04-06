#define PININ1 3
#define PININ2 2
#define PININ3 7
#define PININ4 5
#define PINENA 4
#define PINENB 6
#define DIREITA A2
#define ESQUERDA A3
#define TRESHOLD 400                    
#define SPEED0 255                   
#define SPEED1 0                       

void setup() {
  Serial.begin(9600);
}

void loop() {
int s[2];
readSensors(true, s);
followLineMEF();
}

void motorControl(int speedLeft, int speedRight) {
  pinMode(PININ1, OUTPUT);
  pinMode(PININ2, OUTPUT);
  pinMode(PININ3, OUTPUT);
  pinMode(PININ4, OUTPUT);
  pinMode(PINENA, OUTPUT);
  pinMode(PINENB, OUTPUT);
  // Ajustes motor da esquerda
  if (speedLeft <= 0) {
    speedLeft = -speedLeft;
    digitalWrite (PININ3, HIGH);
    digitalWrite (PININ4, LOW);
  } else {
    digitalWrite (PININ3, LOW);
    digitalWrite (PININ4, HIGH);
  }

  // Ajustes motor da direita
  if (speedRight < 0) {
    speedRight = -speedRight;
    digitalWrite (PININ1, HIGH);
    digitalWrite (PININ2, LOW);
  } else {
    digitalWrite (PININ1, LOW);
    digitalWrite (PININ2, HIGH);
  }
  analogWrite (PINENA, speedLeft);
  analogWrite (PINENB, speedRight);
}

void motorOption(char option, int speedLeft, int speedRight) {
  // Função para controle de motor com pre definições
  switch (option) {
    case '8': // Frente
      motorControl(speedLeft, speedRight);
      break;
    case '2': // Tras
      motorControl(-speedLeft, -speedRight);
      break;
    case '4': // Esqueda
      motorControl(-speedLeft, speedRight);
      break;
    case '6': // Direita
      motorControl(speedLeft, -speedRight);
      break;
    case '0': // Parar
      motorControl(0, 0);
      break;
  }
}

void readSensors(bool readSerial, int *sensors) {
  // Função para leitura dos sensores
  sensors[0] = analogRead(DIREITA);
  sensors[1] = analogRead(ESQUERDA);
    Serial.print(sensors[0]);
    Serial.print(' ');
    Serial.print(sensors[1]);
    Serial.print(' ');
    Serial.print(sensors[2]);
    Serial.println(' ');
}

void followLineMEF(void) {
  bool flag = true;
  while (flag) {
    // Leitura sensores
    int s[3];
    readSensors(false, s);
    int v1,v2;

    if (s[0] >= TRESHOLD){ 
      v1 = 1;
        } else {
            v1 = 0;
         }
    if (s[1] >= TRESHOLD){
        v2 = 1;
        } else{
          v2 = 0;
         }

    if (v1==1 && v2==1) {
      motorOption('8', SPEED0, SPEED0);
    } else if (v1==0 && v2==1) {
      motorOption('8', SPEED1, SPEED1);
    } else if (v1==1 && v2==0) {
      motorOption('8', SPEED1, SPEED1);
    }
    }
  }