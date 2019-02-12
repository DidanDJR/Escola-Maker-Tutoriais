/*
 * Criado pela Escola Maker DJR TECH, https://www.djrtech.com.br
 * Guia completo para o Sensor Ultrassônico HC-SR04
 *
    Pinos do Sensor Ultrassônico:
        VCC: +5VDC
        Trig : Trigger (INPUT) - Pin11
        Echo: Echo (OUTPUT) - Pin 12
        GND: GND
 */
 
int trigPin = 11;    // Trigger
int echoPin = 12;    // Echo

long duracao, cm, inches;
 
void setup() 
{
  //Inicializa a porta serial
  Serial.begin (9600);
  //Define os pinos de entrada e saída
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
 
void loop() {
  // O sensor é trigado por um pulso de nível lógico Alto de 10 ou mais microsegundos 
  
  // Da um pulso curto antecepadamente para garantir um pulso de nível Alto   
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Lê o sinal vindo do sensor: pulso de nível lógico Alto 
  // Duração é o tempo (em microsegundos) a partir do envio 
  // do ping a recepção do seu echo off de um objeto
  
  pinMode(echoPin, INPUT);
  duracao = pulseIn(echoPin, HIGH);
 
  // Converte o tempo em distância 
  
  cm = (duracao/2) / 29.1;     // Divida por 29.1 ou multiplique por 0.0343
  inches = (duracao/2) / 74;   // Divida por 74 ou multiplique por 0.0135
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  delay(500);
}
