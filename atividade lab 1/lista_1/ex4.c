#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo a estrutura para um projeto
struct Projeto {
    char nome[50];
    char area[20];   // Pode ser "marketing", "operacional" ou "inovacao"
    float valorTotal;
    char dataInicio[11];  // Formato "DD/MM/AAAA"
    int duracaoMeses;
};

// Função para cadastrar um projeto
void cadastrarProjeto(struct Projeto *p) {
    printf("Digite o nome do projeto: ");
    fgets(p->nome, sizeof(p->nome), stdin);
    p->nome[strcspn(p->nome, "\n")] = 0;  // Remove o caractere de nova linha
    
    printf("Digite a área do projeto (marketing, operacional, inovacao): ");
    fgets(p->area, sizeof(p->area), stdin);
    p->area[strcspn(p->area, "\n")] = 0;  // Remove o caractere de nova linha
    
    printf("Digite o valor total do projeto: ");
    scanf("%f", &p->valorTotal);
    getchar();  // Limpa o buffer do teclado

    printf("Digite a data de início prevista (DD/MM/AAAA): ");
    fgets(p->dataInicio, sizeof(p->dataInicio), stdin);
    p->dataInicio[strcspn(p->dataInicio, "\n")] = 0;  // Remove o caractere de nova linha

    printf("Digite a duração do projeto em meses: ");
    scanf("%d", &p->duracaoMeses);
    getchar();  // Limpa o buffer do teclado

    printf("Projeto cadastrado com sucesso!\n");
}

// Função para exibir os detalhes de um projeto
void exibirProjeto(struct Projeto p) {
    printf("\nNome do Projeto: %s\n", p.nome);
    printf("Área: %s\n", p.area);
    printf("Valor Total: R$ %.2f\n", p.valorTotal);
    printf("Data de Início: %s\n", p.dataInicio);
    printf("Duração: %d meses\n", p.duracaoMeses);
}

int main() {
    int n, i;

    // Solicitar a quantidade de projetos
    printf("Quantos projetos deseja cadastrar? ");
    scanf("%d", &n);
    getchar();  // Limpa o buffer do teclado

    // Alocar dinamicamente a memória para os projetos
    struct Projeto *projetos = (struct Projeto *)malloc(n * sizeof(struct Projeto));
    if (projetos == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1; // Encerra o programa caso não consiga alocar memória
    }

    // Cadastrar os projetos
    for (i = 0; i < n; i++) {
        printf("\nCadastro do Projeto %d:\n", i + 1);
        cadastrarProjeto(&projetos[i]);
    }

    // Exibir os projetos cadastrados
    printf("\n---- Projetos Cadastrados ----\n");
    for (i = 0; i < n; i++) {
        printf("\nProjeto %d:\n", i + 1);
        exibirProjeto(projetos[i]);
    }

    // Liberar a memória alocada
    free(projetos);

    return 0;
}
