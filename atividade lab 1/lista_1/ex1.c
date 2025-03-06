#include<stdio.h>

int findConta(int *conta, int cc[1000], int n);
void openConta(int conta, float *saldo, int cc[1000], int *n);
void fazerDeposito(float saldo[1000], int i);
void fazerSaque(float saldo[1000], int i);
void fazerPIX(float saldo[1000], int i, int cc[1000], int n);
float tomaValor(void);
void menu(int *p);

int main(void)
{
    int cc[1000], n = 0, i, op, conta;
    float saldo[1000];

    for (i = 0; i < 1000; i++)
    {
        cc[i] = 0;
        saldo[i] = 0;
    }

    do {
        menu(&op);
        switch(op) {
            case 1: // Abrir conta
                i = findConta(&conta, cc, n);
                if (i != n) printf("Esta conta-corrente já existe\n");
                else openConta(conta, saldo, cc, &n);
                break;

            case 2: // Verificar saldo
                i = findConta(&conta, cc, n);
                if (i == n) printf("Número de conta-corrente inválido\n");
                else printf("Saldo: R$ %.2f\n", saldo[i]);
                break;

            case 3: // Fazer Depósito
                i = findConta(&conta, cc, n);
                if (i == n) printf("Número de conta-corrente inválido\n");
                else fazerDeposito(saldo, i);
                break;

            case 4: // Fazer Saque
                i = findConta(&conta, cc, n);
                if (i == n) printf("Número de conta-corrente inválido\n");
                else fazerSaque(saldo, i);
                break;

            case 5: // Fazer PIX
                i = findConta(&conta, cc, n);
                if (i == n) printf("Número de conta-corrente inválido\n");
                else fazerPIX(saldo, i, cc, n);
                break;

            case 6: // Sair do sistema
                printf("Saindo do sistema...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }
    } while (op != 6);

    return 0;
}

void menu(int *p)
{
    printf("1) Abrir conta\n");
    printf("2) Verificar saldo\n");
    printf("3) Fazer Depósito\n");
    printf("4) Fazer Saque\n");
    printf("5) Fazer PIX\n");
    printf("6) Sair do sistema\n");
    printf("Escolha uma opção: ");
    scanf("%d", p);
}

int findConta(int *conta, int cc[1000], int n)
{
    int j;
    printf("Número da conta: ");
    scanf("%d", conta);
    for (j = 0; j < n && *conta != cc[j]; j++);
    return j;
}

void openConta(int conta, float *saldo, int cc[1000], int *n)
{
    printf("Valor do depósito inicial: ");
    saldo[*n] = tomaValor();
    cc[*n] = conta;
    (*n)++;
    printf("Operação realizada com sucesso\n");
}

void fazerDeposito(float saldo[1000], int i)
{
    printf("Valor do depósito: ");
    saldo[i] += tomaValor();
    printf("Operação realizada com sucesso\n");
}

void fazerSaque(float saldo[1000], int i)
{
    float valor;
    printf("Valor do saque: ");
    valor = tomaValor();
    if (valor > saldo[i])
        printf("Saldo insuficiente!\n");
    else {
        saldo[i] -= valor;
        printf("Saque realizado com sucesso!\n");
    }
}

void fazerPIX(float saldo[1000], int i, int cc[1000], int n)
{
    int contaDestino, j;
    float valor;
    printf("Conta destino: ");
    scanf("%d", &contaDestino);

    for (j = 0; j < n && contaDestino != cc[j]; j++);

    if (j == n) {
        printf("Conta destino inválida!\n");
        return;
    }

    printf("Valor do PIX: ");
    valor = tomaValor();

    if (valor > saldo[i])
        printf("Saldo insuficiente!\n");
    else {
        saldo[i] -= valor;
        saldo[j] += valor;
        printf("PIX realizado com sucesso!\n");
    }
}

float tomaValor(void)
{
    float valor;
    scanf("%f", &valor);
    while (valor <= 0)
    {
        printf("O valor deve ser positivo.\nValor: ");
        scanf("%f", &valor);
    }
    return valor;
}
