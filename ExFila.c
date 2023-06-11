#include <stdio.h>
#define N 5

struct TipoNodo
{
    int codigo;
};

typedef struct TipoNodo TipoNodo;

int menu();
int inserirInicio(TipoNodo LL[], int IA, int FA, int *IL, int *FL, TipoNodo infoNodo);
int removerInicio(TipoNodo LL[], int IA, int FA, int *IL, int *FL, TipoNodo infoNodo);
int quantidadeelementos(int IA, int FA, int IL, int FL);
int mostrartopo(TipoNodo LL[], int IA);
int mostrarultimo(TipoNodo LL[], int FL);
int mostrar(TipoNodo LL[], int IA, int FA, int IL, int FL);

int main()
{
    TipoNodo LL[N], infoNodo;
    int opcao, quant, IA = 0, FA = N - 1, IL = -1, FL = -1;
    do
    {
        opcao = menu();
        switch (opcao)
        {
        case 1:
            printf("\n>>>>>> Inserir um nó <<<<<\n");
            printf("\nCódigo...: ");
            scanf("%d", &infoNodo.codigo);
            if (inserirInicio(LL, IA, FA, &IL, &FL, infoNodo))
                printf("Lista cheia, não foi possível inserir\n");
            else
                printf("Inserido com sucesso!!!\n");
            break;
        case 2:
            removerInicio(LL, IA, FA, &IL, &FL, infoNodo);
            break;
        case 3:
            printf("\nQuantidade de elementos\n");
            quantidadeelementos(IA, FA, IL, FL);
            break;
        case 4:
            printf("\nMostrar Inicio Lista\n");
            mostrartopo(LL, IA);
            break;
        case 5:
            printf("\nMostrar final Lista\n");
            mostrarultimo(LL, FL);
            break;
        case 6:
            printf("\nMostrar Lista\n");
            mostrar(LL, IA, FA, IL, FL);
            break;
        case 0:
            printf("Encerrando...\n");
            break;
        default:
            printf("Invalido\n");
            break;
        }
    } while (opcao != 0);
}

int menu()
{
    int opcao;
    printf("_________ M E N U _________\n");
    printf("[1] Inserir no início\n");
    printf("[2] Remover no início\n");
    printf("[3] Quantidade de elementos\n");
    printf("[4] Mostrar inicio\n");
    printf("[5] Mostrar final\n");
    printf("[6] Mostrar \n");
    printf("[0] Sair\n");
    printf("___________________________\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    return opcao;
}

int inserirInicio(TipoNodo LL[], int IA, int FA, int *IL, int *FL, TipoNodo infoNodo)
{
    if (IA == *IL && FA == *FL)
        return 1;
    else
    {
        if (*IL == -1)
            *IL = *FL = IA;
        else if (*IL > IA)
            *IL = *IL - 1;
        else
        {
            for (int i = *FL; i >= *IL; i--)
                LL[i + 1] = LL[i];
            *FL = *FL + 1;
        }
        LL[*IL] = infoNodo;
        return 0;
    }
}

int removerInicio(TipoNodo LL[], int IA, int FA, int *IL, int *FL, TipoNodo infoNodo)
{
    for (int i = *FL; i >= *IL; i--)
        LL[i - 1] = LL[i];
    *FL = *FL - 1;
    return 0;
}

int quantidadeelementos(int IA, int FA, int IL, int FL)
{
    int quant = 0;
    for (int i = IA; i <= FA; i++)
    {
        if (i >= IL && i <= FL)
            quant++;
    }
    printf("%d\n", quant);
}

int mostrartopo(TipoNodo LL[], int IA)
{
    printf("%4d\n", LL[IA].codigo);
}

int mostrarultimo(TipoNodo LL[], int FL)
{
    printf("%4d\n", LL[FL].codigo);
}

int mostrar(TipoNodo LL[], int IA, int FA, int IL, int FL)
{
    for (int i = IA; i <= FA; i++)
    {
        if (i >= IL && i <= FL)
            printf("%4d\n", LL[i].codigo);
        else
            printf("----------\n");
    }
    return 0;
}