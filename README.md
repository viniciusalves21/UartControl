# Controle de LEDs e Buzzer com Raspberry Pi Pico (KitBitDogLab)

Este projeto demonstra o controle de LEDs (Verde, Azul e Vermelho) e um buzzer usando um Raspberry Pi Pico. O código em C implementa um sistema simples de controle via entrada serial, onde diferentes comandos numéricos acionam diferentes combinações de LEDs e o buzzer.

## Funcionalidades

*   **Controle de LEDs:**
    *   Ligar LED Verde (Comando '1')
    *   Ligar LED Azul (Comando '2')
    *   Ligar LED Vermelho (Comando '3')
    *   Ligar todos os LEDs (Comando '4')
    *   Desligar todos os LEDs (Comando '5')
*   **Controle do Buzzer:**
    *   Acionar o buzzer por 2 segundos usando PWM (Comando '6')
*   **Comunicação Serial:** O sistema interage através da entrada serial, aguardando comandos do usuário.
*   **Feedback:** Mensagens informativas são impressas no terminal serial para indicar o estado dos LEDs e do buzzer.

## Como Usar

1.  **Clone o repositório:** `https://github.com/viniciusalves21/UartControl`.
2.  **Compile o código:** Utilize o ambiente de desenvolvimento do Raspberry Pi Pico para compilar o código.
3.  **Carregue o código no Pico:** Conecte o Pico ao seu computador em modo BOOTSEL e carregue o arquivo `.uf2` gerado.
4.  **Abra o monitor serial:** Abra um monitor serial no seu computador configurado para a porta serial do Pico(BitDogLab).
5.  **Envie comandos:** Envie os comandos numéricos ('1', '2', '3', '4', '5' ou '6') pelo monitor serial para controlar os LEDs e o buzzer.

## Código

O código principal contém as seguintes funções principais:

*   `desligar_leds()`: Desliga todos os LEDs.
*   `buzzer_on(uint gpio, uint freq_hz)`: Ativa o buzzer usando PWM na frequência especificada.
*   `buzzer_off(uint gpio)`: Desativa o buzzer.
*   `main()`: Função principal que inicializa os GPIOs, aguarda comandos seriais e executa as ações correspondentes.
