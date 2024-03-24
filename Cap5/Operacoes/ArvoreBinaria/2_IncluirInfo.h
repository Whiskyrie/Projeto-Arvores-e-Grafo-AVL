#ifndef CRIAR_ARVORE_BINARIA_H
#define CRIAR_ARVORE_BINARIA_H

/* --------------------------*/
pNohArvore IncluirInfoRecursivo(pNohArvore raiz, void *info, FuncaoComparacao pfc)
{
    // caso base
    if (raiz == NULL)
    {
        pNohArvore pnh = malloc(sizeof(NohArvore));
        pnh->info = info;
        pnh->esquerda = NULL;
        pnh->direita = NULL;
        return pnh;
    }

    // caso recursivo
    int comparacao = pfc(raiz->info, info);
    if (comparacao > 0) // info é menor que raiz->info
        raiz->esquerda = IncluirInfoRecursivo(raiz->esquerda, info, pfc);
    else
        raiz->direita = IncluirInfoRecursivo(raiz->direita, info, pfc);

    return raiz;
}

/* ----------------------------------------------------------*/
void IncluirInfo(pDArvore arvore, void *info, FuncaoComparacao pfc)
{
    arvore->raiz = IncluirInfoRecursivo(arvore->raiz, info, pfc);
}

#endif
