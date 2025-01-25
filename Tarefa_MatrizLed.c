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

// Frames da animacao 6
extern uint32_t anim6[][25];

// Melodia para a animacao 6
extern uint16_t frequencies[18];
extern uint16_t durations[18];

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

    // Ativa o buzzer
    buzz(BUZZER_PIN, frequencies, durations);
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
                    //Escrever a função aqui
                    break;

                case '2':
                    //Escrever a função aqui
                    break;

                case '3':
                    //Escrever a função aqui
                    break;

                case '4':
                    //Escrever a função aqui
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
                    //Escrever a função aqui
                    break;

                case 'C':
                    //Escrever a função aqui
                    break;

                case 'D':
                    tecla_d(pio, sm);
                    break;

                case '*':
                    //Escrever a função aqui  
                    break;

                case '#':
                    //Escrever a função aqui
                    break;

                default:
                    break;
            }
        }
    }

    return 0;
}