#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "pico/bootrom.h"
#include "ws2818b.pio.h"

// Biblioteca para enviar animações para a matriz de leds
#include "lib/matriz_leds.h"

// Bilioteca para utilizar o buzzer
#include "lib/buzzer.h"

// Definição do teclado matricial
#define ROWS 4
#define COLS 4

// Pinos conectados às linhas (ROWS) e colunas (COLS) do teclado
const uint8_t row_pins[ROWS] = {8, 7, 6, 5};
const uint8_t col_pins[COLS] = {4, 3, 2, 28};

// Mapeamento das teclas no teclado matricial
const char key_map[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

// Pino do led
#define LED_PIN 27

#define BUZZER_PIN 21

// Numero de frames de cada animacao
#define ANIMACAO_6 9
#define ANIMACAO_4 6
#define ANIMACAO_3 10
#define ANIMACAO_2 7
#define ANIMACAO_1 9

// Frames da animacao 6
extern uint32_t anim6[][25];

// Frames da animacao 4
extern uint32_t anim4[][25];

// Frames da animacao 3
extern uint32_t anim3[][25];

// Frames da animacao 2
extern uint32_t anim2[][25];

// Frames da animacao 1
extern uint32_t anim1[][25];

// Melodia para a animacao 6
extern uint16_t frequencies[18];
extern uint16_t durations[18];

// A ser chamada quando a tecla 'A' for pressionada
void apagar_leds(PIO pio, uint sm) {
    Matriz_leds_config matriz;

    // Itera sobre cada posição da matriz para apagar os LEDs
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matriz[i][j].red = 0.0;   // Desliga o componente vermelho
            matriz[i][j].green = 0.0; // Desliga o componente verde
            matriz[i][j].blue = 0.0;  // Desliga o componente azul
        }
    }

    // Envia a configuração de apagar para a matriz de LEDs
    imprimir_desenho(matriz, pio, sm);
}

// A ser chamada quando a tecla 'B' for pressionada
void tecla_b(PIO pio, uint sm){
    Matriz_leds_config matriz;
    for(int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matriz[i][j].red = 0.0;
            matriz[i][j].green = 0.0;
            matriz[i][j].blue = 1.0; //Acenderá os leds na cor azul com 100% de intensidade
        }
    }
    imprimir_desenho(matriz,pio,sm);
}

// A ser chamada quando a tecla 'C' for pressionada
void acender_leds_vermelho(PIO pio, uint sm) {
    Matriz_leds_config matriz;

    // Itera sobre cada posição da matriz para acender os LEDs
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matriz[i][j].red = 0.8;   // Liga todos os led vermelho em 80% 
            matriz[i][j].green = 0.0; // Desliga os leds verde
            matriz[i][j].blue = 0.0;  // Desliga os leds azul
        }
    }

    // Envia a configuração para a matriz de LEDs
    imprimir_desenho(matriz, pio, sm);
}

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

// A ser chamada quando a tecla '#' for pressionada
void acender_leds_brancos(PIO pio, uint sm){
    Matriz_leds_config matriz;

    for(int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matriz[i][j].red = 0.2;
            matriz[i][j].green = 0.2;
            matriz[i][j].blue = 0.2;
        }
    }

    imprimir_desenho(matriz,pio,sm);
}

// A ser chamado quando a tecla '3' for pressionada 
void animation3(uint32_t sprites[][25],PIO pio, uint sm) {
    
    rgb_led rgb_data[ANIMACAO_3][25];
    
    hex_to_rgb(anim3, rgb_data, ANIMACAO_3);

    ajustar_brilho(rgb_data, 0.5, ANIMACAO_3);

    enviar_animacao(rgb_data, pio, sm, ANIMACAO_3);

    enviar_animacao(rgb_data, pio, sm, ANIMACAO_3);
}

// A ser chamado quando a tecla '6' for pressionada 
void animation6(uint32_t sprites[][25],PIO pio, uint sm) {

    // 20 Frames e 25 LEDS
    rgb_led rgb_data[ANIMACAO_6][25];
    
    // Convertendo de HEX para RGB decimal
    hex_to_rgb(anim6, rgb_data, ANIMACAO_6);

    // Diminuindo o brilho para 10%(0.1) da intensidade original
    ajustar_brilho(rgb_data, 0.5, ANIMACAO_6);

    // Renderizando a animacao na matriz de LEDs
    enviar_animacao(rgb_data, pio, sm, ANIMACAO_6);

    // Ativa o buzzer
    buzz(BUZZER_PIN, frequencies, durations);
}

// A ser chamado quando a tecla '4' for pressionada 
void animation4(uint32_t sprites[][25],PIO pio, uint sm) {
    
    rgb_led rgb_data[ANIMACAO_4][25];
    
    hex_to_rgb(anim4, rgb_data, ANIMACAO_4);

    ajustar_brilho(rgb_data, 0.5, ANIMACAO_4);

    enviar_animacao(rgb_data, pio, sm, ANIMACAO_4);

}

// A ser chamado quando a tecla '2' for pressionada 
void animation2(uint32_t sprites[][25],PIO pio, uint sm) {
    
    rgb_led rgb_data[ANIMACAO_2][25];
    
    hex_to_rgb(anim2, rgb_data, ANIMACAO_2);

    ajustar_brilho(rgb_data, 1.0, ANIMACAO_2);

    enviar_animacao(rgb_data, pio, sm, ANIMACAO_2);
}

// A ser chamado quando a tecla '1' for pressionada
void animation1(uint32_t sprites[][25], PIO pio, uint sm) {

    rgb_led rgb_data[ANIMACAO_1][25];  
    
    hex_to_rgb(anim1, rgb_data, ANIMACAO_1);

    ajustar_brilho(rgb_data, 1, ANIMACAO_1);

    enviar_animacao(rgb_data, pio, sm, ANIMACAO_1);

    // Looping para rodar a animação em loop
    enviar_animacao(rgb_data, pio, sm, ANIMACAO_1);

}

//Função para dar reboot na placa
void reboot() {
    reset_usb_boot(0,0);
}

// Inicializa os pinos do teclado matricial.
void inicializar_keypad() {
    for (int i = 0; i < ROWS; i++) {
        gpio_init(row_pins[i]);
        gpio_set_dir(row_pins[i], GPIO_OUT);
        gpio_put(row_pins[i], 0); 
    }

    for (int i = 0; i < COLS; i++) {
        gpio_init(col_pins[i]);
        gpio_set_dir(col_pins[i], GPIO_IN);
        gpio_pull_down(col_pins[i]);  
    }
}

// Verifica se alguma tecla do teclado foi pressionada.
// Retorna o caractere correspondente ou '\0' se nenhuma tecla for pressionada.
char ler_keypad() {
    for (int row = 0; row < ROWS; row++) {
        gpio_put(row_pins[row], 1);  // Coloca a linha atual em nível alto
        for (int col = 0; col < COLS; col++) {
            if (gpio_get(col_pins[col])) {  // Verifica se há uma tecla pressionada
                gpio_put(row_pins[row], 0);  // Retorna a linha ao estado baixo
                sleep_ms(20);  // Tempo para evitar leituras incorretas (debounce)
                return key_map[row][col];  // Retorna a tecla correspondente
            }
        }
        gpio_put(row_pins[row], 0);  // Garante que a linha retorna ao estado baixo
    }
    return '\0';  // Nenhuma tecla foi pressionada
}

int main() {
    char key;  // Variável para armazenar a tecla pressionada
    stdio_init_all();
    inicializar_keypad();
    buzzer_init(BUZZER_PIN);

    // Inicializando o componente pio responsavel por manipular o LED
    PIO pio = pio0;

    // Configurando a maquina de estado 
    uint sm = configurar_matriz(pio, LED_PIN);

    while (true) {
        key = ler_keypad();  // Lê o teclado matricial

        if (key != '\0') {  // Processa apenas se uma tecla for pressionada
            switch (key) {
                case '1':
                    animation1(anim1, pio, sm);
                    break;

                case '2':
                    animation2(anim2, pio, sm);
                    break;

                case '3':
                    animation3(anim3, pio, sm);
                    break;

                case '4':
                    animation4(anim4, pio, sm);
                    break;

                case '5':
                    //Escrever a função aqui
                    break;

                case '6':
                    animation6(anim6, pio, sm);
                    break;

                case 'A':
                    apagar_leds(pio, sm);
                    break;

                case 'B':
                    tecla_b(pio, sm);
                    break;

                case 'C':
                    acender_leds_vermelho(pio, sm);
                    break;

                case 'D':
                    tecla_d(pio, sm);
                    break;

                case '*':
                    reboot();
                    break;

                case '#':
                    acender_leds_brancos(pio, sm);
                    break;

                default:
                    break;
            }
        }
    }

    return 0;
}
