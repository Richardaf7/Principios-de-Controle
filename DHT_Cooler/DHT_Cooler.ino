#include <dht.h> //InclusÃ£o da biblioteca do sensor de temperatura
#define dhtpin A1 // pino a1 como leitor de temperatura do sensor
#define vent 9 // pino5 como clock do pwn do ventilador
float Temperatura = 0; // variavel que armazena temperatura do sensor 
float Erro;
float Erro_Ant=0;
float DErro;
int rotacao = 0; // variavel que armazena a rotacao do motor
int Sp = 25;
float Kp = 18;
float Ki = .03999;
float Kd = 30;
dht DHT; //Inicializa o sensor como DHT
float T_atual = 0;
float T_anterior;
float dt;
float P, D, I, PiD;

void setup()
{
      Serial.begin(9600); // inicia a entrada serial      
}
 
void loop()
{          
      T_anterior = T_atual;
      T_atual = millis();
      dt = (T_atual - T_anterior)-2000;
      Erro_Ant = Erro;
      Erro = Sp - Temperatura;
      DErro = Erro - Erro_Ant;
  
      DHT.read11(dhtpin); //le as informaÃ§Ãµes do sensor
      Temperatura = DHT.temperature; // temperatura do sensor = variavel Temperatura
      Serial.print(" \nTemperatura "); // print temperatura no serial
      Serial.print(Temperatura); // print serial variavel temperatura
      Serial.println(" Celsius   "); // print celsius no serial

      if (Temperatura > Sp) // entra na condicao se a temperatua > Stop Point 
      {
        
        onVentilador(); // inicia a funÃ§Ã£o de ligar o ventilador
      }
      
      else 
      {
      offVentilador(); // inicia a funcao offVentilador
     
      }
     delay(2000); //Delay de tres segundos entre as leituras da informaÃ§Ã£o
      
     
}

void onVentilador ()
{
P = (Erro*Kp);
I += Ki * Erro * dt;
D = (Kd*(DErro/dt));
PiD = P + I + D;
rotacao = 100 - (PiD);
//constrain(rotacao, 0, 255);
if(rotacao >255){
  rotacao = 255;
  Serial.print(" \tMENOR QUE 255 \n"); // print temperatura no serial

  analogWrite (vent,rotacao);
  }
else{
  Serial.print(" \tMENOR QUE 255 \n"); // print temperatura no serial

  analogWrite (vent,rotacao);
}

}

void offVentilador ()
{
  Serial.print("offVentilador \n"); // print temperatura no serial

  I = 0;
  rotacao = 0; // desliga o motor 
  analogWrite (vent,rotacao); // pwm na porta vent com a frequencia da vaariavel rotacao
}
