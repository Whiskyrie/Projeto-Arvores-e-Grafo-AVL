#ifndef FATOR_DE_BALANCEAMENTO_H
#define FATOR_DE_BALANCEAMENTO_H

void CalcularFatorBalanceamentoRecursivo(pNohArvore raiz)
{
    if (raiz == NULL)
        return;

    int alturaEsquerda = AlturaRecursiva(raiz->esquerda);
    int alturaDireita = AlturaRecursiva(raiz->direita);

    raiz->fb = alturaDireita - alturaEsquerda;

    CalcularFatorBalanceamentoRecursivo(raiz->esquerda);
    CalcularFatorBalanceamentoRecursivo(raiz->direita);
}

void CalcularFatorBalanceamento(pDArvore arvore)
{
    CalcularFatorBalanceamentoRecursivo(arvore->raiz);
}

#endif