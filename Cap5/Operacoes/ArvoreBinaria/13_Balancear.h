#ifndef BALANCEAR_ARVORE_H
#define BALANCEAR_ARVORE_H

//-----------------------------------------------------
pNohArvore RotacaoDireita(pNohArvore raiz)
{
    pNohArvore u;
    u = raiz->esquerda;
    raiz->esquerda = u->direita;
    u->direita = raiz;
    return u;
}

//-----------------------------------------------------

pNohArvore RotacaoEsquerda(pNohArvore raiz)
{
    pNohArvore u;
    u = raiz->direita;
    raiz->direita = u->esquerda;
    u->esquerda = raiz;
    return u;
}

//-----------------------------------------------------

pNohArvore RotacaoEsquerdaDireita(pNohArvore raiz)
{
    raiz->esquerda = RotacaoEsquerda(raiz->esquerda);
    return RotacaoDireita(raiz);
}

//-----------------------------------------------------

pNohArvore RotacaoDireitaEsquerda(pNohArvore raiz)
{
    raiz->direita = RotacaoDireita(raiz->direita);
    return RotacaoEsquerda(raiz);
}

//-----------------------------------------------------

pNohArvore BalancearRecursivo(pNohArvore raiz)
{
    int fb = CalcularFatorBalanceamento(raiz);

    if (fb == 2)
    {
        if (CalcularFatorBalanceamento(raiz->direita) >= 0)
        {
            raiz = RotacaoEsquerda(raiz);
        }
        else
        {
            raiz = RotacaoDireitaEsquerda(raiz);
        }
    }
    else if (fb == -2)
    {
        if (CalcularFatorBalanceamento(raiz->esquerda) <= 0)
        {
            raiz = RotacaoDireita(raiz);
        }
        else
        {
            raiz = RotacaoEsquerdaDireita(raiz);
        }
    }

    return raiz;
}

void Balancear(pDArvore arvore)
{
    arvore->raiz = BalancearRecursivo(arvore->raiz);
}

#endif