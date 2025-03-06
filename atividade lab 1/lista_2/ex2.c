#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declarando um ponteiro para float e um ponteiro para string (char*)
    float *decimalValue;
    char *stringValue;

    // Alocando memória para o ponteiro float
    decimalValue = (float*) malloc(sizeof(float));

    // Verificando se a alocação foi bem-sucedida
    if (decimalValue == NULL) {
        printf("Erro ao alocar memória para o valor decimal!\n");
        return 1;
    }

    // Solicitando ao usuário que insira um valor decimal
    printf("Digite um valor decimal: ");
    scanf("%f", decimalValue);

    // Alocando memória para a string que armazenará a representação do número
    stringValue = (char*) malloc(50 * sizeof(char));  // Alocando memória suficiente para 50 caracteres

    // Verificando se a alocação foi bem-sucedida
    if (stringValue == NULL) {
        printf("Erro ao alocar memória para a string!\n");
        free(decimalValue); // Liberando a memória do ponteiro float
        return 1;
    }

    // Convertendo o valor decimal para uma string usando sprintf
    sprintf(stringValue, "%.2f", *decimalValue);

    // Imprimindo o valor decimal e a string resultante
    printf("Valor decimal: %.2f\n", *decimalValue);
    printf("Valor como string: %s\n", stringValue);

    // Liberando a memória alocada dinamicamente
    free(decimalValue);
    free(stringValue);

    return 0;
}
