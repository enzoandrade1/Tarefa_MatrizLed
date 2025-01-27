**GERAÇÃO DE ANIMAÇÕES EM UMA MATRIZ DE LEDs 5X5**

"Este repositório contém o código-fonte e o diagrama referentes à atividade 1 da aula síncrona realizada em 20/01, pertencente à unidade U4 - Microcontroladores do curso Embarcatech. A atividade consiste em utilizar o microcontrolador Raspberry Pi Pico W e um teclado matricial 4x4 para controlar uma matriz de LEDs coloridos (5x5 WS2812), criando diferentes tipos de animações de curta duração. Os 25 LEDs da matriz devem ser acionados e simulados no Wokwi, integrado ao ambiente de desenvolvimento VS Code."

**DIVISÃO DAS ATIVIDADES**

Analisando o que foi pedido na atividade, se dividiu a tarefa em 17 subtarefas, que ficou com a seguinte estrutura:

1. Construir diagrama.json no simulador wokwi; *(realizado por Camila).*
	*Diagrama construído no simulador wowki com os componentes pedidos.*
2. Declarar estrutura do keypad e a função para inicializá-la; *(realizado por Enzo).*
   *Declaração da estrutura do keypad e a criação da função para inicializar.*
3. Definir a estrutura da matriz de LEDs 5x5 e a função para inicializá-la.; *(realizado por Guilherme).*
    *Declaração da estrutura da matriz de LED e a criação da função para inicializar.*
4. Animação da tecla 1; *(realizado por Enzo).*
    *Criação de uma pequena animação de curta duração.*
5. Animação da tecla 2; *(realizada por Camila).*
    *Criação de uma pequena animação de curta duração.*
6. Animação da tecla 3; *(realizado por Mateus)*
    *Criação de uma pequena animação de curta duração.*
7. Animação da tecla 4. *(realizado por Marcus).*
    *Criação de uma pequena animação de curta duração.*
8. Animação da tecla 5. *(realizado por Vitória).*
    *Criação de uma pequena animação de curta duração.*
9. Animação da tecla 6. *(realizado por Guilherme).*
    *Criação de uma pequena animação de curta duração.*
10. Função da tecla A. *(realizado por Marcus).*
    *Criação da função que ao ser acionada, todos os LEDs desliguem.*
11. Função da tecla B. *(realizado por Camila).*
    *Criação da função que ao ser acionada, todos os LEDs fiquem azul na intensidade de 100% de luminosidade máxima.*    
12. Função da tecla C. *(realizado por Mateus).*
    *Criação da função que ao ser acionada, todos os LEDs fiquem vermelho na intesidade de 80% de luminosidade máxima.*
13. Função da tecla D. *(realizado por Guilherme).*
    *Criação da função que ao ser acionada, todos os LEDs figuem verdes na intesidade de 50% de luminosidade máxima.*
14. Função da tecla #. *(realizado por Enzo).*
    *Criação da função que ao ser acionada, todos os LEDs figuem brancos na intesidade de 20% de luminosidade máxima.*   
15. Função da tecla *. *(realizado por Enzo).*
    *Criação da função que ao ser acionada o raspberry pi pico w entre no modo reboot.*
16. Mapeamento de intruções para apertar cada tecla. *(realizado por Enzo).*
    *Criação de instruções.*
17. Escrever o README.md e produzir o vídeo explicativo do projeto. *(realizado por Vitória).*
    *Escrita do arquivo README.md, o qual contém as atividades realizadas, descrição do projeto e detalhamento da atividade realizada. Produção do vídeo demonstrativo do projeto.*

E o líder (Enzo) também ficou responsável pela gestão do repositório.

**COMPONENTES E FERRAMENTAS UTILIZADAS**
	Para a realização do projeto, foram utilizadas as seguintes ferramentas:
- Simulador Wowki;
- Microcontrolador Raspberry Pi Pico w;
- Matriz de LEDs coloridos (LED-RGB 5x5 WS2812);
- 01 buzzer Passivo Eletromagnético MLT-8530 SMD 3.6V;
- 01 teclado matricial 4x4;
- Visual Studio Code.

**PRODUÇÃO DAS ATIVIDADES** 

A execução da tarefa foi organizada com a designação de um líder, responsável por oferecer suporte e supervisionar as atividades realizadas pelos desenvolvedores. Enquanto isso, os integrantes da equipe assumiram responsabilidades específicas para garantir a conclusão do projeto.
Inicialmente, foi criado o arquivo 'diagram.json' na plataforma Wokwi. Em seguida, o desenvolvimento continuou no VS Code, onde os códigos foram implementados. Durante esse processo, os GPIOs e funções foram definidos e integrados à função 'main'. Dessa maneira, foram realizados testes para a conclusão do projeto.

**LINGUAGEM UTILIZADA**
- C

**EQUIPE**
- Líder: Enzo Andrade
- Desenvolvedores:
    - Camila Ramos
    - Guilherme Emetério
    - Mateus Moreira
    - Marcus Vinicius
    - Vitória Freire
    
**LINK DO VÍDEO EXPLICATIVO**
[Link do video explicativo da tarefa](https://drive.google.com/file/d/1FnlwmY75_cBlzBXjFD6jwUMksTNUW_p-/view?usp=sharing)