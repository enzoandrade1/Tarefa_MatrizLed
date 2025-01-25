#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ws2818b.pio.h"

// Biblioteca para enviar animações para a matriz de leds
#include "lib/matriz_leds.h"

#define LED_PIN 27

// Numero de frames de cada animacao
#define ANIMACAO_6 9

// Frames da animacao 6
extern uint32_t anim6[][25];

void animation6(uint32_t sprites[][25],PIO pio, uint sm) {
    // 20 Frames e 25 LEDS
    rgb_led rgb_data[ANIMACAO_6][25];
    
    // Convertendo de HEX para RGB decimal
    hex_to_rgb(anim6, rgb_data, ANIMACAO_6);

    // Diminuindo o brilho para 10%(0.1) da intensidade original
    ajustar_brilho(rgb_data, 0.1, ANIMACAO_6);

    // Renderizando a animacao na matriz de LEDs
    enviar_animacao(rgb_data, pio, sm, ANIMACAO_6);
}

int main() {
    stdio_init_all();
    char command[1024];
    // Inicializando o componente pio responsavel por manipular o LED
    PIO pio = pio0;
    // Configurando a maquina de estado 
    uint sm = configurar_matriz(pio, LED_PIN);


    while (true) {
        printf("Hello world!");
        sleep_ms(1000);
    }
}
