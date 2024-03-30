#ifndef ENCONTRAMAIOR_H
#define ENCONTRAMENOR_H

pNohArvore EncontrarMaior(pNohArvore raiz)
{
    if (raiz == NULL)
        return NULL;

    pNohArvore atual = raiz;
    while (atual->direita != NULL)
        atual = atual->direita;

    return atual;
}

#endif