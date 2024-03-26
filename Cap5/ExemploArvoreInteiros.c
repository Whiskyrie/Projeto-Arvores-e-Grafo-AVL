#include <stdio.h>
#include "Utils.h"
#include "ArvoreBinariaBalanceada.h"

pDArvore ConstroiArvore(int dados[], int tam)
{

    pDArvore arvore = CriarArvore(2);
    int i;
    for (i = 0; i < tam; i++)
    {
        IncluirInfo(arvore, AlocaInt(dados[i]), ComparaInt);
        DesenhaArvore(arvore, ImprimeInt);
    }

    return arvore;
}

int main()
{

    int ex1[] = {5, 10, 3, 7, 6};             // rotacao simples - direita
    int ex2[] = {5, 10, 3, 12, 14};           // rotacao simples - esquerda
    int ex3[] = {5, 10, 3, 7, 8};             // rotacao dupla - esquerda/direita
    int ex4[] = {5, 10, 3, 4, 12, 9, 14, 13}; // rotacao dupla - direita/esquerda
    int ex5[] = {5, 10, 3, 4, 12, 9, 14};     // N�o precisa rotacionar

    // ConstroiArvore(ex1, 5);
    // ConstroiArvore(ex2, 5);
    ConstroiArvore(ex3, 5);
    // ConstroiArvore(ex4, 8);
    // ConstroiArvore(ex5, 7);
}
