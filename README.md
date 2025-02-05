Controle de Semáforo com Raspberry Pi Pico

Este projeto implementa um controle de semáforo utilizando um Raspberry Pi Pico e três LEDs para representar os estados vermelho, amarelo e verde. O código usa um temporizador para alternar entre os estados a cada 3 segundos.

🛠️ Requisitos

Raspberry Pi Pico

3 LEDs (vermelho, amarelo e verde)

3 resistores (220Ω a 1kΩ)

Fios de conexão

Protoboard

📌 Funcionamento

O código faz com que os LEDs se alternem no seguinte ciclo:

Vermelho ligado por 3 segundos

Amarelo ligado por 3 segundos

Verde ligado por 3 segundos

Esse ciclo se repete indefinidamente.

🔧 Configuração do Hardware

Os LEDs devem ser conectados aos seguintes pinos do Raspberry Pi Pico:

LED

GPIO

Vermelho

11

Amarelo

12

Verde

13

Cada LED deve estar em série com um resistor (nesse caso, de 330Ω) para limitar a corrente.

🚀 Como Executar

Instale o SDK do Raspberry Pi Pico e configure o ambiente de desenvolvimento.

Compile o código e envie o código para o Raspberry Pi Pico.


