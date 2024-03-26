#ifndef FATOR_DE_BALANCEAMENTO_H
#define FATOR_DE_BALANCEAMENTO_H

void CalcularFatorBalanceamentoRecursivo(pNohArvore raiz)
{

    if (raiz == NULL)
        return;

    raiz->fb = AlturaRecursiva(raiz->direita) - AlturaRecursiva(raiz->esquerda);
    CalcularFatorBalanceamentoRecursivo(raiz->esquerda);
    CalcularFatorBalanceamentoRecursivo(raiz->direita);
}

void CalcularFatorBalanceamento(pDArvore arvore)
{
    CalcularFatorBalanceamentoRecursivo(arvore->raiz);
}

#endif