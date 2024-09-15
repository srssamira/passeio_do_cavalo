#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
        O PASSEIO DO CAVALO
            -   Daniel
            -   Samira Rodrigues Silva [12311BSI203] 
            -   Victor
*/

#define boardSize 4

int main() {
    char board[boardSize][boardSize];
    int movement[8][2] = { {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1} };
    int coordinateX, coordenateY;
    int *pointerToLine = &coordinateX;
    int *pointerToColumn = &coordenateY;

    // Inicializa o tabuleiro
    for (int index = 0; index < boardSize; index++) {
        for (int subIndex = 0; subIndex < boardSize; subIndex++) {
            board[index][subIndex] = '.';
        }
    }

    srand(time(NULL)); // função que indica que a cada execução do programa o numero aleatorio gerado será diferente
    *pointerToLine = rand() % boardSize; // uma posiçao aleatoria vai ser gerada dentro do limite de linhas do tabuleiro
    *pointerToColumn = rand() % boardSize; // uma posiçao aleatoria vai ser gerada dentro do limite de colunas do tabuleiro
    board[*pointerToLine][*pointerToColumn] = 'C'; // o cavalo vai começar dentro da linha aleatoria e da coluna aleatoria

    // imprimir o tabuleiro
    while (1) {

        for (int index = 0; index < boardSize; index++) {
            for (int subIndex = 0; subIndex < boardSize; subIndex++) {
                printf("%c ", board[index][subIndex]);
            }
            printf("\n");
        }

        printf("Coordenada do cavalo: (%d, %d)\n", *pointerToLine, *pointerToColumn);

        // movimentos possíveis
        int count = 0;
        for (int index = 0; index < 8; index++) {
            int newCoordinateX = *pointerToLine + movement[index][0];
            int newCoordinateY = *pointerToColumn + movement[index][1];
            if (newCoordinateX >= 0 && newCoordinateX < boardSize && newCoordinateY >= 0 && newCoordinateY < boardSize && board[newCoordinateX][newCoordinateY] == '.') {
                printf("%d: (%d, %d)\n", index + 1, newCoordinateX, newCoordinateY);
                count++;
            }
        }

        if (count == 0) {
            printf("Sem movimentos possiveis. Voce perdeu!\n");
            break;
        }

        int choose;
        printf("Escolha um movimento: ");
        scanf("%d", &choose);

        if (choose < 1 || choose > 8) {
            printf("Movimento invalido!\n");
            continue;
        }

        int newCoordinateX = *pointerToLine + movement[choose - 1][0];
        int newCoordinateY = *pointerToColumn + movement[choose - 1][1];

        if (newCoordinateX >= 0 && newCoordinateX < boardSize && newCoordinateY >= 0 && newCoordinateY < boardSize && board[newCoordinateX][newCoordinateY] == '.') {
            board[*pointerToLine][*pointerToColumn] = 'X';
            *pointerToLine = newCoordinateX;
            *pointerToColumn = newCoordinateY;
            board[*pointerToLine][*pointerToColumn] = 'C';
        } else {
            printf("Movimento invalido.\n");
        }

        int win = 1;
        for (int index = 0; index < boardSize; index++) {
            for (int subIndex = 0; subIndex < boardSize; subIndex++) {
                if (board[index][subIndex] == '.') {
                    win = 0;
                    break;
                }
            }
            if (!win) break;
        }

        if (win) {
            for (int index = 0; index < boardSize; index++) {
                for (int subIndex = 0; subIndex < boardSize; subIndex++) {
                    printf("%c ", board[index][subIndex]);
                }
                printf("\n");
            }
            printf("Voce ganhou, parabens!\n");
            break;
        }
    }

    return 0;
}