#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ws2818b.pio.h"

// Biblioteca para enviar animações para a matriz de leds
#include "lib/matriz_leds.h"

#define LED_PIN 7

// Numero de frames de cada animacao
#define ANIMACAO_6 9

// Frames da animacao 6
extern uint32_t anim6[][25];

// A ser chamada quando a tecla 'D' for pressionada
void tecla_d(PIO pio, uint sm){
    Matriz_leds_config matriz;
    for(int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matriz[i][j].red = 0.0;
            matriz[i][j].green = 0.5;
            matriz[i][j].blue = 0.0;
        }
    }
    imprimir_desenho(matriz,pio,sm);
}

// A ser chamado quando a tecla '6' for pressionada 
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

        limpar_matriz(pio, sm);
    }
}
