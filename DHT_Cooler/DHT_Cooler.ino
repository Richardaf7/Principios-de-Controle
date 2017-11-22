#include <dht.h> //Inclusão da biblioteca do sensor de temperatura
#define dhtpin A1 // pino a1 como leitor de temperatura do sensor
#define vent 9 // pino 9 como clock do pwn do ventilador
float Temperatura = 0; // variavel que armazena temperatura do sensor 
float Erro;
float Erro_Ant;
float DErro;
int rotacao = 0; // variavel que armazena a rotacao do motor
int Sp = 25;
float Kp = 10;
float Ki = .0005;
dht DHT; //Inicializa o sensor como DHT
float T_atual = 0;
float T_anterior;
float dt;
float P, I, PiT;

void setup()
{
      Serial.begin(9600); // inicia a entrada serial
      delay(1000); //Delay para o início da execução do programa
      
}
 
void loop()
{
      Erro_Ant = Erro;
      Erro = Sp - Temperatura;
      DErro = Erro - Erro_Ant;
      
      T_anterior = T_atual;
      T_atual = millis();
      dt = T_atual - T_anterior;
      
      DHT.read11(dhtpin); //le as informações do sensor
      Temperatura = DHT.temperature; // temperatura do sensor = variavel Temperatura
      Serial.print(" Temperatura "); // print temperatura no serial
      Serial.print(Temperatura); // print serial variavel temperatura
      Serial.println(" Celsius "); // print celsius no serial

      if (Temperatura >= Sp) // entra na condicao se a temperatua > Stop Point 
      {
       
        onVentilador(); // inicia a função de ligar o ventilador      
      }
      
      else 
      {
      offVentilador(); // inicia a funcao offVentilador
      }
      //delay(500); //Delay de tres segundos entre as leituras da informação
     
     Serial.print(" Rotacao \n"); // print temperatura no serial
     Serial.print(rotacao); // print serial variavel temperatura
     Serial.print("\n dt\n "); // print temperatura no serial
     Serial.print(dt); // print serial variavel temperatura
     Serial.print(" \n PiT \n "); // print temperatura no serial
     Serial.print(PiT); // print serial variavel temperatura
     Serial.print("\n P \n"); // print temperatura no serial
     Serial.print(P); // print serial variavel temperatura
     Serial.print("\n I \n" ); // print temperatura no serial
     Serial.print(I); // print serial variavel temperatura
     
     
}

void onVentilador ()
{   
Erro = Sp - Temperatura;
P = (Erro*Kp);
I = Ki * Erro * dt;
PiT = P + I ;
rotacao = 100 - (PiT);
constrain(rotacao, 0, 255);
analogWrite (vent,rotacao);

}

void offVentilador ()
{
  rotacao = 0; // desliga o motor 
  analogWrite (vent,rotacao); // pwm na porta vent com a frequencia da vaariavel rotacao
}
