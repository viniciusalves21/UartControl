#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define LED_VERDE     11
#define LED_AZUL      12
#define LED_VERMELHO  13
#define BUZZER        21

void desligar_leds(void) {
    gpio_put(LED_VERDE, 0);
    gpio_put(LED_AZUL, 0);
    gpio_put(LED_VERMELHO, 0);
}
// Função para ativar o buzzer em um pino GPIO específico, com uma frequência definida
void buzzer_on(uint gpio, uint freq_hz) {

    // Obtém o número do "slice" de PWM associado ao pino GPIO
    uint slice_num = pwm_gpio_to_slice_num(gpio);

    // Configura o pino GPIO para funcionar no modo PWM
    gpio_set_function(gpio, GPIO_FUNC_PWM);

    // Define o divisor de clock para ajustar a frequência do PWM
    float divider = 125.0f;

    // Define o valor máximo do contador PWM antes de reiniciar (controla a frequência final)
    uint32_t wrap = 499;

    // Configura o divisor de clock para o slice de PWM
    pwm_set_clkdiv(slice_num, divider);

    // Configura o valor máximo do contador (wrap) para o slice de PWM
    pwm_set_wrap(slice_num, wrap);

    // Define o nível do PWM no pino GPIO (50% do ciclo de trabalho, onda quadrada)
    pwm_set_gpio_level(gpio, wrap / 2);

    // Habilita o PWM para começar a gerar o sinal no pino
    pwm_set_enabled(slice_num, true);
}
