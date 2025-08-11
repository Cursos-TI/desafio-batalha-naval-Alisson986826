#include <stdio.h>
#include <stdlib.h> // para abs()

#define TAM 10   // tamanho do tabuleiro
#define HAB 5    // tamanho das matrizes de habilidade

void aplicaHabilidade(int tabuleiro[TAM][TAM], int matriz[HAB][HAB], int origem_l, int origem_c) {
    int i, j;
    for (i = 0; i < HAB; i++) {
        for (j = 0; j < HAB; j++) {
            if (matriz[i][j] == 1) {
                int tl = origem_l + i - HAB / 2;
                int tc = origem_c + j - HAB / 2;
                if (tl >= 0 && tl < TAM && tc >= 0 && tc < TAM && tabuleiro[tl][tc] == 0)
                    tabuleiro[tl][tc] = 5; // área de efeito
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    int cone[HAB][HAB];
    int cruz[HAB][HAB];
    int octaedro[HAB][HAB];
    int i, j;

    // Inicializa o tabuleiro com água (0)
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Coloca alguns navios (valor 3)
    tabuleiro[2][4] = 3;
    tabuleiro[2][5] = 3;
    tabuleiro[2][6] = 3;

    tabuleiro[5][7] = 3;
    tabuleiro[6][7] = 3;
    tabuleiro[7][7] = 3;

    // Gera cone (origem no topo central)
    for (i = 0; i < HAB; i++) {
        for (j = 0; j < HAB; j++) {
            if (j >= (HAB / 2) - i && j <= (HAB / 2) + i)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }

    // Gera cruz (origem no centro)
    for (i = 0; i < HAB; i++) {
        for (j = 0; j < HAB; j++) {
            if (i == HAB / 2 || j == HAB / 2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }

    // Gera octaedro (losango)
    for (i = 0; i < HAB; i++) {
        for (j = 0; j < HAB; j++) {
            if (abs(i - HAB / 2) + abs(j - HAB / 2) <= HAB / 2)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

    // Posições de origem das habilidades no tabuleiro
    int origem_cone_l = 0, origem_cone_c = 0;
    int origem_cruz_l = 4, origem_cruz_c = 4;
    int origem_octa_l = 7, origem_octa_c = 2;

    // Aplica cada habilidade no tabuleiro
    aplicaHabilidade(tabuleiro, cone, origem_cone_l, origem_cone_c);
    aplicaHabilidade(tabuleiro, cruz, origem_cruz_l, origem_cruz_c);
    aplicaHabilidade(tabuleiro, octaedro, origem_octa_l, origem_octa_c);

    // Exibe cabeçalho com letras
    printf("    ");
    for (j = 0; j < TAM; j++) {
        printf("%c ", 'A' + j);
    }
    printf("\n");

    // Exibe tabuleiro
    for (i = 0; i < TAM; i++) {
        printf("%2d  ", i);
        for (j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == 0) printf(". "); // água
            else if (tabuleiro[i][j] == 3) printf("N "); // navio
            else if (tabuleiro[i][j] == 5) printf("* "); // habilidade
        }
        printf("\n");
    }

    return 0;
}


