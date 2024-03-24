#ifndef BUSCAR_INFO_H
#define BUSCAR_INFO_H

pNohArvore BuscarInfoRecursivo(pNohArvore raiz, void *info, FuncaoComparacao pfc)
{
    if (raiz == NULL)
    {
        return NULL;
    }

    int comparacao = pfc(raiz->info, info);
    if (comparacao == 0)
    {
        return raiz;
    }
    else if (comparacao < 0)
    {
        return BuscarInfoRecursivo(raiz->direita, info, pfc);
    }
    else
    {
        return BuscarInfoRecursivo(raiz->esquerda, info, pfc);
    }
}

pNohArvore BuscarInfo(pDArvore arvore, void *info, FuncaoComparacao pfc)
{
    if (arvore == NULL || arvore->raiz == NULL)
    {
        return NULL;
    }

    return BuscarInfoRecursivo(arvore->raiz, info, pfc);
}

#endif