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