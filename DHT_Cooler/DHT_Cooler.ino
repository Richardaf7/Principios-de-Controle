#include <dht.h> //Inclusão da biblioteca do sensor de temperatura
#define dhtpin A1 // pino a1 como leitor de temperatura do sensor
#define vent 9 // pino 9 como clock do pwn do ventilador
float Temperatura = 0; // variavel que armazena temperatura do sensor 
float Erro;
float Erro_Ant;
float DErro;
int rotacao = 0; // variavel que armazena a rotacao do motor
int SP = 25;
int Kp = 16;
int Ki = 5;
dht DHT; //Inicializa o sensor como DHT
int T_atual = 0;
int T_anterior;
int dt;
int P;

void setup()
{
      Serial.begin(9600); // inicia a entrada serial
      delay(1000); //Delay para o início da execução do programa
      
}
 
void loop()
{
      
      DHT.read11(dhtpin); //le as informações do sensor
      Temperatura = DHT.temperature; // temperatura do sensor = variavel Temperatura
      Serial.print("Temperatura "); // print temperatura no serial
      Serial.print(Temperatura); // print serial variavel temperatura
      Serial.println(" Celsius "); // print celsius no serial

      if (Temperatura >= SP) // entra na condicao se a temperatua > Stop Point 
      {
        onVentilador(); // inicia a função de ligar o ventilador      
      }
      
      else 
      {
      offVentilador(); // inicia a funcao offVentilador
      }
      
      delay(500); //Delay de tres segundos entre as leituras da informação
      T_anterior = T_atual;
      T_atual = millis();
      dt = T_atual - T_anterior;
}

void onVentilador ()
{
Erro_Ant = Erro;
Erro = Sp - Teperatura;
DErro = Erro - Erro_Ant;
      
Erro = SP - Temperatura;
P = (Erro*Kp);
I += Ki * Erro * dt;
int PI = P+I;
rotacao = 100 - (PI);
constrain(rotacao, 0, 255);
analogWrite (vent,rotacao);

}

void offVentilador ()
{
  rotacao = 0; // desliga o motor 
  analogWrite (vent,rotacao); // pwm na porta vent com a frequencia da vaariavel rotacao
}
