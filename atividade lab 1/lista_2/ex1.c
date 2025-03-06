#include <stdio.h>
#include <stdlib.h>
#define LINHAS 3
#define COLUNAS 3

int main(int argc, char *argv[])
{
    // Declaração de variável ponteiro para ponteiro
    int **mat, **matrizB, **matrizC;
    
    // Alocando o vetor de ponteiros para as 3 matrizes
    mat = (int**)malloc(LINHAS * sizeof(int*));
    matrizB = (int**)malloc(LINHAS * sizeof(int*));
    matrizC = (int**)malloc(LINHAS * sizeof(int*));
    
    // Alocando cada uma das linhas das matrizes
    int i;
    for(i = 0; i < LINHAS; i++) {
        mat[i] = (int*)malloc(COLUNAS * sizeof(int));
        matrizB[i] = (int*)malloc(COLUNAS * sizeof(int));
        matrizC[i] = (int*)malloc(COLUNAS * sizeof(int));
    }

    int j;
    
    // Preenchendo a matriz mat com valores (i + j)
    for(i = 0; i < LINHAS; i++) {
        for(j = 0; j < COLUNAS; j++) {
            mat[i][j] = i + j;
        }
    }
    
    // Preenchendo a matriz matrizB com valores arbitrários
    for(i = 0; i < LINHAS; i++) {
        for(j = 0; j < COLUNAS; j++) {
            matrizB[i][j] = i * j;  // Exemplo de valores para matrizB
        }
    }
    
    // Somando mat com matrizB e armazenando o resultado em matrizC
    for(i = 0; i < LINHAS; i++) {
        for(j = 0; j < COLUNAS; j++) {
            matrizC[i][j] = mat[i][j] + matrizB[i][j];
        }
    }
    
    // Imprimindo a matrizC
    printf("Matriz C (Resultado da soma):\n");
    for(i = 0; i < LINHAS; i++) {
        for(j = 0; j < COLUNAS; j++) {
            printf("%d\t", matrizC[i][j]);
        }
        printf("\n");
    }

    // Liberando o espaço de memória
    for(i = 0; i < LINHAS; i++) {
        free(mat[i]);
        free(matrizB[i]);
        free(matrizC[i]);
    }
    free(mat);
    free(matrizB);
    free(matrizC);

    return 0;
}
