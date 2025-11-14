#include <stdio.h>

#define N5 5
#define N10 10

void zerarTabuleiro(int n, int tab[n][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            tab[i][j] = 0;
}

void imprimirTabuleiro(int n, int tab[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", tab[i][j]);
        printf("\n");
    }
}

void navioVertical(int n, int tab[n][n], int row, int col, int len, int marcador) {
    for (int k = 0; k < len; k++) {
        tab[row + k][col] = marcador;
        printf("Navio vertical: (%d, %d)\n", row + k, col);
    }
}

void navioHorizontal(int n, int tab[n][n], int row, int col, int len, int marcador) {
    for (int k = 0; k < len; k++) {
        tab[row][col + k] = marcador;
        printf("Navio horizontal: (%d, %d)\n", row, col + k);
    }
}

int main() {
    // Novato: 5x5
    int tab5[N5][N5];
    zerarTabuleiro(N5, tab5);
    navioVertical(N5, tab5, 1, 2, 3, 3);
    navioHorizontal(N5, tab5, 0, 0, 2, 3);
    printf("\nTabuleiro 5x5 (Novato):\n");
    imprimirTabuleiro(N5, tab5);

    // Aventureiro: 10x10
    int tab10[N10][N10];
    zerarTabuleiro(N10, tab10);
    navioHorizontal(N10, tab10, 2, 2, 4, 3);
    navioVertical(N10, tab10, 5, 7, 3, 3);

    int row = 1, col = 1, len = 3;
    for (int i = 0; i < len; i++) {
        tab10[row + i][col + i] = 3;
        printf("Navio diagonal ↘: (%d, %d)\n", row + i, col + i);
    }
    row = 6; col = 6; len = 4;
    for (int i = 0; i < len; i++) {
        tab10[row + i][col - i] = 3;
        printf("Navio diagonal ↙: (%d, %d)\n", row + i, col - i);
    }
    printf("\nTabuleiro 10x10 (Aventureiro):\n");
    imprimirTabuleiro(N10, tab10);

    // Mestre: padrões 5x5
    int H = 5;
    int cone[5][5], cruz[5][5], octa[5][5];
    zerarTabuleiro(H, cone);
    zerarTabuleiro(H, cruz);
    zerarTabuleiro(H, octa);

    cone[0][2] = 1;
    for (int c = 1; c <= 3; c++) cone[1][c] = 1;
    for (int c = 0; c <= 4; c++) cone[2][c] = 1;

    for (int c = 0; c < H; c++) cruz[2][c] = 1;
    for (int r = 0; r < H; r++) cruz[r][2] = 1;

    octa[0][2] = 1;
    octa[1][1] = octa[1][2] = octa[1][3] = 1;
    octa[2][2] = 1;

    printf("\nHabilidade: Cone (5x5)\n");
    imprimirTabuleiro(H, cone);

    printf("\nHabilidade: Cruz (5x5)\n");
    imprimirTabuleiro(H, cruz);

    printf("\nHabilidade: Octaedro (5x5)\n");
    imprimirTabuleiro(H, octa);

    return 0;
}
