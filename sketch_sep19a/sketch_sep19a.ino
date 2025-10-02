#include <ps5Controller.h>


int m1p1 = 14;
int m1p2 = 27;
int m2p1 = 33;
int m2p2 = 32;

int m1ena = 26;
int m2ena = 25;

//não lembro qual que está em cada, ajustamos isso quando verificar!!
void virarDireta(int analogico){
  //aqui ajustei a intensidade com os valores q vc me passou:
  int velocidade = map(intensidade, 11, 127, 200, 150);
  analogWrite(m1ena, 200); // Motor 1 mais
  analogWrite(m2ena, velocidade); // Motor 2 menos
}

void virarEsquerda(int analogico){
  // intensidade: 11 a 127 → velocidade: 200 a 80 (proporcional)
  int velocidade = map(abs(intensidade), 11, 128, 200, 150);
  analogWrite(m1ena, velocidade); 
  analogWrite(m2ena, 200);
   
}

void valorAnalogico(){
  int analogicoX = ps5.LStickX();
   if(analogicoX > 10) {
    virarDireita(analogicoX);
  } else if(analogicoX < -10) {
    virarEsquerda(analogicoX);
  } else {
    //é p parar d virar(sei que voce é burrinho e ia me perguntar dps) não tenho certeza se já controla a intensidade do motor, mas acho que sim
    analogWrite(m1ena, 200);
    analogWrite(m2ena, 200);
  }
}

void notify()
{
  digitalWrite(m1p1, ps5.R2());
  digitalWrite(m1p2, ps5.L2());
  digitalWrite(m2p1, ps5.R2());
  digitalWrite(m2p2, ps5.L2());
}

void onConnect()
{
  Serial.println("Connected!.");
}

void onDisConnect()
{
  Serial.println("Disconnected!.");    
}

void setPins(){
  pinMode(m1p1, OUTPUT);
  pinMode(m1p2, OUTPUT);
  pinMode(m2p1, OUTPUT);
  pinMode(m2p2, OUTPUT);
  pinMode(m1ena, OUTPUT);
  pinMode(m2ena, OUTPUT);
}

void setup() {
  setPins();
  Serial.begin(115200);
  ps5.attach(notify,valorAnalogico);
  ps5.attachOnConnect(onConnect);
  ps5.attachOnDisconnect(onDisConnect);
  ps5.begin("7c:66:ef:47:77:74");
}

void loop() {

  
}

