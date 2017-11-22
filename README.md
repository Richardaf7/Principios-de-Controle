**INTRODUÇÃO:**

  O projeto tem o objetivo geral de controlar a temperatura de qualquer objeto ou ambiente de forma
inteligente, seja: um espaço físico, a temperatura de um motor a combustão, um refrigerador,
um forno etc.
  Muitos sistemas de controle de temperatura são mecânicos e sem inteligência, como é
o exemplo do controle de temperatura de um motor a combustão, que depende de uma
válvula mecânica que é acionada pela pressão de vapor de água do sistema de refrigeração. O
mal funcionamento da válvula pode levar a um superaquecimento do motor de forma
repentina, correndo o risco de danos irreversíveis.
  O projeto aqui apresentado pode, por exemplo, substituir os sistemas mecânicos de
veículos por um sistema inteligente que monitora em tempo real a temperatura do motor e
pode, junto com outros dados obtidos por outros sensores, mostrar a quem conduz os veículos
ou aos fabricantes o melhor rendimento do motor.

Nesse projeto iremos utilizar a seguinte lista de materiais: 
1. Cooler, como função de atuador e encoder interno; 
2. Sensor de temperatura (DHT11); 
3. ATMega328 (Arduíno UNO), como controlador; 
4. Protoboard, Transistor, Cabos, Conectores e Fonte USB completam a lista de materiais. 
    
   ![capturar](https://user-images.githubusercontent.com/33470518/32812351-eef15100-c97a-11e7-92de-84e06cd545ff.PNG)
   
   *Protótipo Final do Controlador de Temperatura*
   

    
**EMBASAMENTO TEÓRICO/PRÁTICO:**

**TÉCNICA DE CONTROLE ON-OFF:**

Conceito: O atuador tem somente duas posições fixas (Ligado / Desligado). A principal vantagem é sua simplicidade e sua desvantagem é a falta de precisão e linearidade.


**TÉCNICA DE CONTROLE PID:**

Conceito: Consiste em calcular um valor de atuação sobre o processo a partir das informações do valor desejado e do valor atual da variável do processo. Esse valor de atuação sobre o processo é transformado em um sinal adequado ao atuador utilizado (Válvula,  motor, relé), e deve garantir um controle estável e preciso.

- P = Proporcional = Correção proporcional ao erro
- I = Integral = Correção proporcional ao produto erro*tempo
- D = Derivativa = Correção proporcional à taxa de variação do erro.

**Ação de controle proporcional:**

A correção a ser aplicada ao processo deve crescer na proporção que cresce o erro entre o valor real e o desejado.
Equação: u(t) = Kpr x e(t) ou Kpr = U(s) / E(s)
onde: Kpr = Ganho proporcional
Função de transferência do controlador: Gc(s) = Kpr

**Ação de controle proporcional + integral:**

Ação integral: Consiste em uma resposta na saída do controlador que é proporcional à amplitude e duração do desvio. 
Erros pequenos, mas existem há muito tempo, requerem correção mais intensa.
Ação proporcional + integral: A ação integral não é usada isoladamente. Sempre vem em conjunto com a ação proporcional. A ação integral tem o efeito de eliminar o desvio caracteristico de um controle proporcional.
Equação: u(t) = Kpr*e(t) + Ki*(Integral)e(t)dt  onde: Ki = ganho integral
         U(s) = Kpr*E(s) + Ki*E(s)/s
Função de transferência do controlador: Gc(s) = U(s)/E(s) = Kpr + Ki/s = (Kprs + Ki)/s
                                     ou ainda = Gc(s) = {Kpr*(s + Ki/Kpr)]/s
                                     
**Ação de controle proporcional + derivativa:**

Ação derivativa: Consiste em uma resposta na saída do controlador que é proporcional à taxa de variação do desvio. Se o erro está variando muito rápido, esta taxa de variação deve ser reduzida para evitar oscilações.
Ação proporcional + derivativa: A ação derivativa não é utilizada isoladamente. Sempre vem em conjunto com a çãao proporcional. A ação derivativa tem o efeito de reduzir a velocidade das variações de PV, evitando que se eleve ou reduza rapidamente.
Equação: u(t) = Kpr*e(t) + Kd*(d e(t)/dt) onde Kd = Ganho derivativo
         U(s) = Kpr*E(s) + Kds*E(s)
Função de transferência do controlador: Gc(s) = U(s)/E(s) = Kpr + Kds = Kd[s + (Kpr/Kd)] = Kd [s+ (1/Td)]
                              ou ainda: Gc(s) = Kpr[1 + (Kd / Kpr)s] = Kpr[1 + Tds]
                              onde: 1/Td = (Kpr/Kd) ou Td = (Kd/Kpr) = Constante de tempo derivativa.

**ESQUEMÁTICO DO PROJETO:**

![capturar3](https://user-images.githubusercontent.com/33470518/32812826-60e2b180-c97d-11e7-95fa-f5228a2784ba.PNG)

 Foram usadas portas analógicas e digitais do arduino para o sensor e atuador,
respectivamente, porém para o atuador, a porta está em modo PWM. Na parte da
alimentação foi usada a porta de 5V para o sensor e o cooler e um GND comum para
todos.

![capturar 2](https://user-images.githubusercontent.com/33470518/32812561-141203ac-c97c-11e7-9d7c-51e0f9f45d54.PNG)

*Fluxograma Baseado na Primeira Lógica de Programação*

**IMPLEMENTAÇÃO:**

- Arduino: É uma plataforma de desenvolvimento de hardware, microcontrolada,
usando um processador ATMega328 e sendo de código aberto, que em termos práticos, o
Arduino é um pequeno computador em que é possível se interagir com o ambiente.
No nosso projeto ele atua como controlador, implementando um código para aferir
sempre a temperatura do sensor, com base nessa leitura, faz o controle do cooler, fazendo o
mesmo ter diferentes velocidade de rotação, assim tendo um maior controle da temperatura
desejada.

      Funcionamento
      #include &lt;dht.h&gt; //Inclusão da biblioteca do sensor de temperatura

      #define dhtpin A1 // pino a1 como leitor de temperatura do sensor

      #define vent 9 // pino 9 como clock do pwn do ventilador

      float Temperatura = 0; // variavel que armazena temperatura do sensor

      int rotacao = 0; // variavel que armazena a rotacao do motor

      dht DHT; //Inicializa o sensor como DHT


*- Cooler:* Sua função principal é fazer a ventilação do objeto a ser verificado pelo sensor
de temperatura. Fazendo alteração na sua tensão, tem-se um melhor controle da sua
velocidade.

      if (Temperatura > 21)
      {
      rotacao = 100; // define rotacao do motor

      analogWrite (vent,rotacao); // pwm na porta vent com a frequência
      da variável rotacao
      }

*- Fonte USB:* Alimentação do nosso projeto em si.
- Encoder: Elementos ou equipamentos eletromecânicos para conversão de
movimentos rotativos ou lineares em pulsos elétricos de onda quadrada (TTL). Mais
precisamente usaremos para obter a função de transferência.
Sensor: DHT11, permitindo fazermos a leitura da temperatura para ser controlada.
#define dhtpin A1
DHT.read11(dhtpin); //lê as informações do sensor

*Código Atualizado*: [Código Atualizado para a NP2] (https://github.com/Richardaf7/Principios-de-Controle/blob/master/DHT_Cooler/DHT_Cooler.ino)

**CONCLUSÃO:**
  
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

**- O QUE SERIA NECESSÁRIO MELHORAR NO SEU PROJETO PARA QUE ISSO
OCORRA?**

  Dentro do nosso protótipo, usamos a plataforma Arduíno com Microcontrolador ATMega328 e
um protoboard para ajudar nas ligações, porém, para colocarmos nossa produto disponível, será
necessário projetarmos nosso própria placa com as devidas entrada dos componentes, incluindo o
soquete do processador e o sensor de temperatura. Isso reduziria o tamanho do projeto para facilitar a
aplicação.
  Usaremos uma comunicação Bluetooth para passar as informações ao supervisório, tudo isso
projetado em nossa placa.





