INTRODUÇÃO:

  O projeto tem o objetivo geral de controlar a temperatura de qualquer coisa de forma
inteligente, seja: um espaço físico, a temperatura de um motor a combustão, um refrigerador
um forno etc.
  Muitos sistemas de controle de temperatura são mecânicos e sem inteligência, como é
o exemplo do controle de temperatura de um motor a combustão, que depende de uma
válvula mecânica que é acionada pela pressão de vapor de água do sistema de refrigeração. O
mal funcionamento da válvula pode levar a um superaquecimento do motor de forma
repentina, correndo o risco de danos irreversíveis.
  O projeto aqui apresentado pode, por exemplo, substituir os sistemas mecânicos de
veículos por um sistema inteligente que monitora em tempo real a temperatura do motor e
pode, junto com outros dados obtidos por outros sensores, mostrar a quem conduz os veículos
ou as fabricantes o melhor rendimento do motor.

Nesse projeto iremos utilizar a seguinte lista de materiais:
  1-  Cooler, como função de atuador;
  2-Sensor de temperatura (DHT11) e encoder do cooler;
  3-ATMega328 (Arduíno UNO), como controlador;
  4-Protoboard, Transistor, Cabos, Conectores e Fonte USB completam a lista de
    materiais.
    
EMBASAMENTO TEÓRICO/PRÁTICO:

Esquemático do projeto.

Foram usadas portas analógicas e digitais do arduino para o sensor e atuador
respectivamente, porem para o atuador a porta está em modo pwm. Na parte da
alimentação foi usada a porta de 5v para o sensor e o cooler e um Gnd comum para
todos.

IMPLEMENTAÇÃO:

- Arduino: É uma plataforma de desenvolvimento de hardware, microcontrolada
usando um processador ATMega328 e sendo de código aberto, que em termos práticos, o
Arduino é um pequeno computador em que é possível se interagir com o ambiente.
No nosso projeto ele atua como controlador, implementado um código para aferir
sempre a temperatura do sensor, com base nessa leitura, fazer o controle do cooler, fazendo o
mesmo ter diferentes velocidade de rotação, assim tendo um maior controle da temperatura
desejada.

Funcionamento
#include &lt;dht.h&gt; //Inclusão da biblioteca do sensor de temperatura

#define dhtpin A1 // pino a1 como leitor de temperatura do sensor

#define vent 9 // pino 9 como clock do pwn do ventilador

float Temperatura = 0; // variavel que armazena temperatura do sensor

int rotacao = 0; // variavel que armazena a rotacao do motor

dht DHT; //Inicializa o sensor como DHT


- Cooler: Sua função principal é fazer a ventilação do objeto a ser verificado pelo sensor
de temperatura. Fazendo alteração na sua tensão, tem-se um melhor controle da sua
velocidade.

if (Temperatura > 21)
{
rotacao = 100; // define rotacao do motor

analogWrite (vent,rotacao); // pwm na porta vent com a frequência
da variável rotacao
}

- Fonte USB: Alimentação do nosso projeto em si.
- Encoder: Elementos ou equipamentos eletromecânicos para conversão de
movimentos rotativos ou lineares em pulsos elétricos de onda quadrada (TTL). Mais
precisamente usaremos para obter a função de transferência.
Sensor: DHT11, permitindo fazermos a leitura da temperatura para ser controlada.
#define dhtpin A1
DHT.read11(dhtpin); //lê as informações do sensor

CONCLUSÃO:
  
  O projeto de Sensor de Temperatura, tem aplicações bem específicas e que não exija um
alto nível de precisão, como um forno industrial ou até mesmo um motor a combustão (motor
automotivo).
Usando o exemplo do motor automotivo, colocaríamos nosso projeto para acompanhar os
níveis de temperatura do motor, caso a temperatura se elevasse, o sensor acionaria o sistema de
arrefecimento (sistema de refrigeração) do automóvel e passaria as devidas informações para o
motorista.
  A aplicação do nosso sensor de temperatura seria de bastante utilidade para seus usuários,
pois sabemos que, dependendo do sistema, grandes temperaturas podem causar grandes falhas e
danos irreparáveis. Sendo assim, nosso projeto pode ser vendido como soluções para sistemas que
exijam um monitoramento de temperatura, pois além do sensor, venderíamos toda a plataforma e
sistema a ser aplicado.

- O QUE SERIA NECESSÁRIO MELHORAR NO SEU PROJETO PARA QUE ISSO
OCORRA?

  Dentro do nosso protótipo, usamos a plataforma Arduíno com Microcontrolador ATMega328 e
um protoboard para ajudar nas ligações, porém, para colocarmos nosso produto disponível, será
necessário projetarmos nosso própria placa com as devidas entrada dos componentes, incluindo o
soquete do processador e o sensor de temperatura. Isso reduziria o tamanho do projeto para facilitar a
aplicação.
Usaremos uma comunicação Bluetooth para passar as informações ao supervisório, tudo isso
projetado em nossa placa.
