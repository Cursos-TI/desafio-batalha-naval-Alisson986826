#include<stdio.h>

int main() {
    int tabuleiro[10][10];
    int i, j;
    for (i = 0; i < 10; i++) {
        for(j = 0; j < 10; j++){
            tabuleiro[i][j] = 0;
        }
    
    }

    int tamanho_navio = 3;

    //coordenadas dos navios
    int l1 = 2, c1 = 4;
    int l2 = 5, c2 = 7;
    int l3 = 0, c3 = 0;
    int l4 = 0, c4 = 9;
    #define LIVRE(l,c) (tabuleiro[l][c] == 0)

    if (c1 + tamanho_navio <= 10) {
        for (j = 0; j < tamanho_navio; j++) {
            if (LIVRE(l1, c1 + j))
            tabuleiro[l1][c1 + j] = 3;
        }
    }
     if (l2 + tamanho_navio <= 10) {
        for (i = 0; i < tamanho_navio; i++) {
            if (LIVRE(l2 + i, c2))
            tabuleiro[l2 + i][c2] = 3;
        } 
    }
     if (l3 + tamanho_navio <= 10 && c3 + tamanho_navio <= 10) {
        for (i = 0; i < tamanho_navio; i++) {
            if (LIVRE(l3 + i, c3 + i))
            tabuleiro[l3 + i][c3 + i] = 3; 
        } 
    }
     if (l4 + tamanho_navio <= 10 && c4 - (tamanho_navio - 1) >= 0) {
        for (i = 0; i < tamanho_navio; i++) {
            if (LIVRE(l4 + i, c4 - i))
            tabuleiro[l4 + i][c4 - i] = 3; 
        } 
    }

    //Exibindo tabuleiro
    printf("    ");
    for (j = 0; j < 10; j++) {
        printf("%c ", 'A' + j);
    }
    printf("\n");

    for(i = 0; i < 10; i++) {
        printf("%2d  ", i);
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0; 
}






