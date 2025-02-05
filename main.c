#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define led_vermelho 11
#define led_amarelo 12
#define led_verde 13

volatile int semaforo_estado = 0; // 0: vermelho, 1: amarelo, 2: verde

bool temporizador_callback(struct repeating_timer *t) {
    // Desliga todos os LEDs antes de acionar o próximo
    gpio_put(led_vermelho, 0);
    gpio_put(led_amarelo, 0);
    gpio_put(led_verde, 0);
   
    // Liga o LED conforme o estado do semáforo
    if (semaforo_estado == 0) {
        gpio_put(led_vermelho, 1);
    } else if (semaforo_estado == 1) {
        gpio_put(led_amarelo, 1);
    } else {
        gpio_put(led_verde, 1);
    }
   
    semaforo_estado = (semaforo_estado + 1) % 3; // Ciclo: vermelho -> amarelo -> verde
    return true; // Permite que o timer continue executando
}

int main() {
   
    // Inicializa os LEDs como saída
    gpio_init(led_vermelho);
    gpio_set_dir(led_vermelho, GPIO_OUT);
    gpio_init(led_amarelo);
    gpio_set_dir(led_amarelo, GPIO_OUT);
    gpio_init(led_verde);
    gpio_set_dir(led_verde, GPIO_OUT);
   
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, temporizador_callback, NULL, &timer);
   
    while (true) {
        printf("Semáforo em funcionamento... Estado: %d\n", semaforo_estado);
        sleep_ms(1000);
    }
}
