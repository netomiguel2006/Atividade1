#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

void readMatrix(int matrix[SIZE][SIZE], char name);
void printMatrix(int matrix[SIZE][SIZE], char *name);
void multiplyMatrices(int a[SIZE][SIZE], int b[SIZE][SIZE], int c[SIZE][SIZE]);
void subtractMatrices(int a[SIZE][SIZE], int b[SIZE][SIZE], int c[SIZE][SIZE]);
void addMatrices(int a[SIZE][SIZE], int b[SIZE][SIZE], int c[SIZE][SIZE]);
void transposeMatrix(int matrix[SIZE][SIZE], int result[SIZE][SIZE]);

int main() {
    int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];
    int option;

    printf("Digite os valores da matriz A (3x3):\n");
    readMatrix(A, 'A');

    printf("\nDigite os valores da matriz B (3x3):\n");
    readMatrix(B, 'B');

    while (1) {
        printf("\nMenu de Opções:\n");
        printf("1. C = A * B\n");
        printf("2. C = A - B\n");
        printf("3. C = A + B\n");
        printf("4. Transposta de C (C = A * B)\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                multiplyMatrices(A, B, C);
                printMatrix(C, "C = A * B");
                break;
            case 2:
                subtractMatrices(A, B, C);
                printMatrix(C, "C = A - B");
                break;
            case 3:
                addMatrices(A, B, C);
                printMatrix(C, "C = A + B");
                break;
            case 4:
                multiplyMatrices(A, B, C);
                int transposed[SIZE][SIZE];
                transposeMatrix(C, transposed);
                printMatrix(transposed, "Transposta de C (C = A * B)");
                break;
            case 5:
                printf("Saindo do programa...\n");
                exit(0);
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    }
    return 0;
}

void readMatrix(int matrix[SIZE][SIZE], char name) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c[%d][%d]: ", name, i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[SIZE][SIZE], char *name) {
    printf("\n%s:\n", name);
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrices(int a[SIZE][SIZE], int b[SIZE][SIZE], int c[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            c[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void subtractMatrices(int a[SIZE][SIZE], int b[SIZE][SIZE], int c[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}

void addMatrices(int a[SIZE][SIZE], int b[SIZE][SIZE], int c[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void transposeMatrix(int matrix[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}
