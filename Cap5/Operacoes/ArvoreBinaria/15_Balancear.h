#ifndef BALANCEAR_H
#define BALANCEAR_H

pNohArvore BalancearArvore(pNohArvore raiz)
{
    if (raiz == NULL)
        return NULL;

    int fatorBalanceamento = raiz->fb;

    // Caso esquerda esquerda
    if (fatorBalanceamento > 1 && raiz->esquerda->fb >= 0)
        return RotacaoDireita(raiz);

    // Caso esquerda direita
    if (fatorBalanceamento > 1 && raiz->esquerda->fb < 0)
    {
        raiz->esquerda = RotacaoEsquerda(raiz->esquerda);
        return RotacaoDireita(raiz);
    }

    // Caso direita direita
    if (fatorBalanceamento < -1 && raiz->direita->fb <= 0)
        return RotacaoEsquerda(raiz);

    // Caso direita esquerda
    if (fatorBalanceamento < -1 && raiz->direita->fb > 0)
    {
        raiz->direita = RotacaoDireita(raiz->direita);
        return RotacaoEsquerda(raiz);
    }

    return raiz;
}

#endif