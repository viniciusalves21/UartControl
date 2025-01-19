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

void buzzer_off(uint gpio) {
    uint slice_num = pwm_gpio_to_slice_num(gpio);
    // Desabilita PWM
    pwm_set_enabled(slice_num, false);
    gpio_set_function(gpio, GPIO_FUNC_SIO);
    gpio_set_dir(gpio, GPIO_OUT);
    gpio_put(gpio, 0);
}

int main() {
    stdio_init_all();
    sleep_ms(2000);

    // Configurar LEDs como saída
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);
    gpio_init(LED_AZUL);
    gpio_set_dir(LED_AZUL, GPIO_OUT);
    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);

    // Buzzer inicialmente OFF
    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);
    gpio_put(BUZZER, 0);

    printf("Sistema iniciado. Aguardando comandos...\n");
