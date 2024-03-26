#ifndef CRIAR_ARVORE_BINARIA_H
#define CRIAR_ARVORE_BINARIA_H

/* --------------------------*/
pNohArvore IncluirInfoRecursivo(pNohArvore raiz, void *info, FuncaoComparacao pfc)
{
    if (raiz == NULL)
    {
        pNohArvore pnh = malloc(sizeof(NohArvore));
        pnh->info = info;
        pnh->esquerda = NULL;
        pnh->direita = NULL;
        pnh->fb = 0;
        return pnh;
    }

    if (pfc(raiz->info, info) <= 0)
    {
        raiz->esquerda = IncluirInfoRecursivo(raiz->esquerda, info, pfc);
    }
    else
    {
        raiz->direita = IncluirInfoRecursivo(raiz->direita, info, pfc);
    }

    CalcularFatorBalanceamentoRecursivo(raiz);

    if (raiz->fb == 2)
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
    else if (raiz->fb == -2)
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

/* ----------------------------------------------------------*/
void IncluirInfo(pDArvore arvore, void *info, FuncaoComparacao pfc)
{
    printf("\n --- Incluindo info: %d ---\n", *((int *)info));
    arvore->raiz = IncluirInfoRecursivo(arvore->raiz, info, pfc);
}

#endif