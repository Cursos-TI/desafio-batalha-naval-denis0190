#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    int tabuleiro[5][5];
    int linha, coluna;

    // inicializa tudo com 0 (água)
    for (linha = 0; linha < 5; linha++) {
        for (coluna = 0; coluna < 5; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }

    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3]   = {3, 3, 3};

    // coordenadas iniciais dos navios (linha, coluna)
    int linhaH = 1;
    int colunaH = 0;  // navio horizontal vai de (1,0) até (1,2)

    int linhaV = 0;
    int colunaV = 3;  // navio vertical vai de (0,3) até (2,3)

    int podeHorizontal = 1;
    int podeVertical = 1;

    // checa limites pro horizontal (tamanho 3 em um tabuleiro 5x5)
    if (colunaH < 0 || colunaH + 3 > 5 || linhaH < 0 || linhaH >= 5) {
        podeHorizontal = 0;
    }

    // checa limites pro vertical
    if (linhaV < 0 || linhaV + 3 > 5 || colunaV < 0 || colunaV >= 5) {
        podeVertical = 0;
    }

    // verifica se tem sobreposição no horizontal
    if (podeHorizontal == 1) {
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linhaH][colunaH + i] != 0) {
                podeHorizontal = 0;
            }
        }
    }

    // verifica se tem sobreposição no vertical
    if (podeVertical == 1) {
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linhaV + i][colunaV] != 0) {
                podeVertical = 0;
            }
        }
    }

    // coloca o navio horizontal no tabuleiro
    if (podeHorizontal == 1) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
        }
    }

    // coloca o navio vertical no tabuleiro
    if (podeVertical == 1) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[linhaV + i][colunaV] = navioVertical[i];
        }
    }

    // mostra as coordenadas de cada parte dos navios
    printf("Navio horizontal (valor 3):\n");
    for (int i = 0; i < 3; i++) {
        printf("Parte %d: (%d, %d)\n", i + 1, linhaH, colunaH + i);
    }

    printf("\nNavio vertical (valor 3):\n");
    for (int i = 0; i < 3; i++) {
        printf("Parte %d: (%d, %d)\n", i + 1, linhaV + i, colunaV);
    }

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}

