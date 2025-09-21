#include <ps5Controller.h>


int m1p1 = 14;
int m1p2 = 27;
int m2p1 = 33;
int m2p2 = 32;

int m1ena = 26;
int m2ena = 25;


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
  ps5.attach(notify);
  ps5.attachOnConnect(onConnect);
  ps5.attachOnDisconnect(onDisConnect);
  ps5.begin("7c:66:ef:47:77:74");
}

void loop() {
  
}
