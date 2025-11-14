#include <stdio.h>

int main() {

    int tabuleiro[10][10];
    int linha, coluna;

    // inicializa o tabuleiro 10x10 com água (0)
    for (linha = 0; linha < 10; linha++) {
        for (coluna = 0; coluna < 10; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }

    // navios simples com tamanho 3
    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3]   = {3, 3, 3};

    // coordenadas iniciais dos navios
    int linhaH = 2;
    int colunaH = 1;

    int linhaV = 5;
    int colunaV = 7;

    int podeHorizontal = 1;
    int podeVertical = 1;

    // valida limites para o navio horizontal
    if (linhaH < 0 || linhaH >= 10 || colunaH < 0 || colunaH + 3 > 10) {
        podeHorizontal = 0;
    }

    // valida limites para o navio vertical
    if (colunaV < 0 || colunaV >= 10 || linhaV < 0 || linhaV + 3 > 10) {
        podeVertical = 0;
    }

    // verifica sobreposição horizontal
    if (podeHorizontal == 1) {
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linhaH][colunaH + i] != 0) {
                podeHorizontal = 0;
            }
        }
    }

    // verifica sobreposição vertical
    if (podeVertical == 1) {
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linhaV + i][colunaV] != 0) {
                podeVertical = 0;
            }
        }
    }

    // posiciona o navio horizontal
    if (podeHorizontal == 1) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
        }
    }

    // posiciona o navio vertical
    if (podeVertical == 1) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[linhaV + i][colunaV] = navioVertical[i];
        }
    }

    int cone[5][5];
    int cruz[5][5];
    int octaedro[5][5];

    int centro = 2;

    // monta habilidade cone
    for (linha = 0; linha < 5; linha++) {
        for (coluna = 0; coluna < 5; coluna++) {
            cone[linha][coluna] = 0;
            if (linha == 0 && coluna == centro) cone[linha][coluna] = 1;
            else if (linha == 1 && coluna >= centro - 1 && coluna <= centro + 1) cone[linha][coluna] = 1;
            else if (linha == 2 && coluna >= centro - 2 && coluna <= centro + 2) cone[linha][coluna] = 1;
        }
    }

    // monta habilidade cruz
    for (linha = 0; linha < 5; linha++) {
        for (coluna = 0; coluna < 5; coluna++) {
            if (linha == centro || coluna == centro) cruz[linha][coluna] = 1;
            else cruz[linha][coluna] = 0;
        }
    }

    // monta habilidade octaedro
    for (linha = 0; linha < 5; linha++) {
        for (coluna = 0; coluna < 5; coluna++) {
            int dr = linha - centro; if (dr < 0) dr = -dr;
            int dc = coluna - centro; if (dc < 0) dc = -dc;
            if (dr + dc <= 1) octaedro[linha][coluna] = 1;
            else octaedro[linha][coluna] = 0;
        }
    }

    // pontos de origem das habilidades
    int origemConeLinha = 2, origemConeColuna = 2;
    int origemCruzLinha = 5, origemCruzColuna = 5;
    int origemOctLinha = 7, origemOctColuna = 3;

    // aplica cone no tabuleiro
    for (linha = 0; linha < 5; linha++) {
        for (coluna = 0; coluna < 5; coluna++) {
            if (cone[linha][coluna] == 1) {
                int lt = origemConeLinha + (linha - centro);
                int ct = origemConeColuna + (coluna - centro);
                if (lt >= 0 && lt < 10 && ct >= 0 && ct < 10 && tabuleiro[lt][ct] == 0) {
                    tabuleiro[lt][ct] = 5;
                }
            }
        }
    }

    // aplica cruz
    for (linha = 0; linha < 5; linha++) {
        for (coluna = 0; coluna < 5; coluna++) {
            if (cruz[linha][coluna] == 1) {
                int lt = origemCruzLinha + (linha - centro);
                int ct = origemCruzColuna + (coluna - centro);
                if (lt >= 0 && lt < 10 && ct >= 0 && ct < 10 && tabuleiro[lt][ct] == 0) {
                    tabuleiro[lt][ct] = 5;
                }
            }
        }
    }

    // aplica octaedro
    for (linha = 0; linha < 5; linha++) {
        for (coluna = 0; coluna < 5; coluna++) {
            if (octaedro[linha][coluna] == 1) {
                int lt = origemOctLinha + (linha - centro);
                int ct = origemOctColuna + (coluna - centro);
                if (lt >= 0 && lt < 10 && ct >= 0 && ct < 10 && tabuleiro[lt][ct] == 0) {
                    tabuleiro[lt][ct] = 5;
                }
            }
        }
    }

    // exibe o tabuleiro final
    for (linha = 0; linha < 10; linha++) {
        for (coluna = 0; coluna < 10; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}
