// Valores para exibição dos números nos LEDs
int num[7][7] = { 
{0,0,0,0,0,0,0},
{0,1,1,0,0,0,0}, // 1
{1,1,0,1,1,0,1}, // 2
{1,1,1,1,0,0,1}, // 3
{0,1,1,0,0,1,1}, // 4
{1,0,1,1,0,1,1}, // 5
{1,0,1,1,1,1,1}, // 6
};

// Definição de pinos dos 7 LEDs do display
const int pino[7] = {2,4,6,7,8,10,11};

void setup(){
    Serial.begin(9600);
  
    pinMode(13, INPUT); // Botão no pino 13 como entrada
  
  for (int i=0; i<7; i++) {
    pinMode(pino[i], OUTPUT); // 7 pinos do display como saída
  } 
}

void loop(){

  if(digitalRead(13) == 1){ // Se o botão for pressionado
    short int sorteio = random(1,7); // Ssortear um número entre 1 e 6
    
    Serial.println(sorteio); // Exibir sorteio no monitor do PC
    
	// Leitura dos valores e apresentação do número sorteado
      for (int i=0; i<7; i++) {
        digitalWrite(pino[i], num[sorteio][i]);
      }
  }
  delay(70); // Intervalo de 70 milissegundos
}
