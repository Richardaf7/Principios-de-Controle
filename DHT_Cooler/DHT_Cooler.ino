#include <dht.h> //Inclusão da biblioteca do sensor de temperatura
#define dhtpin A1 // pino a1 como leitor de temperatura do sensor
#define vent 9 // pino 9 como clock do pwn do ventilador
float Temperatura = 0; // variavel que armazena temperatura do sensor 
float Erro;
float Erro_Ant;
float DErro;
int rotacao = 0; // variavel que armazena a rotacao do motor
float SP = 25;
float Kp = 16;
float Ki = 5;
dht DHT; //Inicializa o sensor como DHT
float T_atual = 0;
float T_anterior;
float dt;
float P, I;

void setup()
{
      Serial.begin(9600); // inicia a entrada serial
      delay(1000); //Delay para o início da execução do programa
      
}
 
void loop()
{
      Erro_Ant = Erro;
      Erro = Sp - Teperatura;
      DErro = Erro - Erro_Ant;
      
      T_anterior = T_atual;
      T_atual = millis();
      dt = T_atual - T_anterior;
      
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
      
}

void onVentilador ()
{   
Erro = SP - Temperatura;
P = (Erro*Kp);
I + = Ki * Erro * dt;
int PI = P + I;
rotacao = 100 - (PI);
constrain(rotacao, 0, 255);
analogWrite (vent,rotacao);

}

void offVentilador ()
{
  rotacao = 0; // desliga o motor 
  analogWrite (vent,rotacao); // pwm na porta vent com a frequencia da vaariavel rotacao
}
