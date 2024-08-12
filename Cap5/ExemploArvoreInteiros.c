#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Utils.h"
#include "ArvoreBinariaBalanceada.h"

pDArvore ConstroiArvore(int raiz)
{
    pDArvore arvore = CriarArvore(raiz);
    int num;

    printf("Digite os valores para inserir na arvore (0 para sair): ");
    scanf("%d", &num);

    while (num != 0)
    {
        IncluirInfo(arvore, AlocaInt(num), ComparaInt);
        DesenhaArvore(arvore, ImprimeInt);
        printf("Digite os valores para inserir na arvore (0 para sair): ");
        scanf("%d", &num);
    }

    return arvore;
}

int main()
{
    pDArvore pArvoreInt;
    int raiz, opcao, valorBuscado, valorInserido;

    printf("Informe a raiz da arvore: ");
    scanf("%d", &raiz);
    pArvoreInt = ConstroiArvore(raiz);

    do
    {
        system("cls"); // Limpa o console a cada seleção
        printf("\nMenu:\n");
        printf("1. Desenhar Arvore\n");
        printf("2. Calcular Altura da Arvore\n");
        printf("3. Calcular Quantidade de Folhas\n");
        printf("4. Calcular Quantidade de Nos\n");
        printf("5. Buscar Valor na Arvore\n");
        printf("6. Remover Valor da Arvore\n");
        printf("7. Inserir Valor da Arvore\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            DesenhaArvore(pArvoreInt, ImprimeInt);
            break;
        case 2:
            printf("Altura da Arvore: %d\n", Altura(pArvoreInt));
            break;
        case 3:
            printf("Quantidade de Folhas: %d\n", QuantidadeFolhas(pArvoreInt));
            break;
        case 4:
            printf("Quantidade de Nos: %d\n", QuantidadeNohs(pArvoreInt));
            break;
        case 5:
            printf("Digite o valor a ser buscado: ");
            scanf("%d", &valorBuscado);
            if (BuscarInfo(pArvoreInt, AlocaInt(valorBuscado), ComparaInt))
            {
                printf("Valor %d encontrado na arvore!\n", valorBuscado);
            }
            else
            {
                printf("Valor %d nao encontrado na arvore!\n", valorBuscado);
            }
            break;
        case 6:
            printf("Digite o valor a ser removido: ");
            scanf("%d", &valorBuscado);
            if (ExcluirInfo(pArvoreInt, AlocaInt(valorBuscado), ComparaInt) == 0)
            {
                printf("Valor %d removido com sucesso!\n", valorBuscado);
            }
            else
            {
                printf("Falha ao remover o valor %d.\n", valorBuscado);
            }
            break;
        case 7:
            printf("Digite o valor a ser inserido: ");
            scanf("%d", &valorInserido);
            IncluirInfo(pArvoreInt, AlocaInt(valorInserido), ComparaInt);
            printf("Valor %d inserido na arvore!\n", valorInserido);
            break;
        case 8:
            printf("Benchmark!");
            realizarBenchmark(pArvoreInt);
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida!\n");
        }

        printf("\nAperte Qualquer tecla Para Continuar.");
        getchar();
        getchar(); // Pausa o programa até que o usuário pressione uma tecla
    } while (opcao != 0);

    return 0;
}