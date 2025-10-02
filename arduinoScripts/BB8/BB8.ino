#define motor1pin1 14
#define motor1pin2 27
#define motor2pin1 33
#define motor2pin2 32


#define motor1ena 26
#define motor2ena 25




void setup() {
  // put your setup code here, to run once:
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(motor1ena, OUTPUT);
  pinMode(motor2ena, OUTPUT);

 
  
  Serial.begin(115200);
}

void loop() {
  
  // put your main code here, to run repeatedly:
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  analogWrite(motor1ena, 210);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  analogWrite(motor2ena, 246);

 
}