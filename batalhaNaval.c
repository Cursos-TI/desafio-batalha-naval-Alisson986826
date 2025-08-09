#include<stdio.h>

int main() {
    int tabuleiro[10][10];
    int i, j;
    for (i = 0; i < 10; i++) {
        for(j = 0; j < 10; j++){
            tabuleiro[i][j] = 0;
        }
    }
    //coordenadas dos navios
    int linha_navio_horizontal = 2;
    int coluna_navio_horizontal = 4;
    int linha_navio_vertical = 5;
    int coluna_navio_vertical = 7;
    //posicões dos navios
    for (j = 0; j < 3; j++) {
        tabuleiro[linha_navio_horizontal][coluna_navio_horizontal + j] = 3;
    }

    for (i = 0; i < 3; i++){
        if (tabuleiro[linha_navio_vertical + i][coluna_navio_vertical] == 0){
            tabuleiro[linha_navio_vertical + i][coluna_navio_vertical] = 3;
        }
    }
    //Exibindo o tabuleiroo
    printf("    ");
    for (j = 0; j < 10; j++){
        printf("%c ", 'A' + j);}

        printf("\n");

        for (i = 0; i < 10; i++) {
            printf("%2d  ",i);
            for (j = 0; j < 10; j++) {
                printf("%d ", tabuleiro[i][j]);
            }
            printf("\n");
        }

        return 0;
    }



