#ifndef ENCONTRAMENOR_H
#define ENCONTRAMENOR_H

pNohArvore EncontrarMenor(pNohArvore raiz)
{
    if (raiz == NULL)
        return NULL;

    pNohArvore menor = raiz;
    while (menor->esquerda != NULL)
    {
        menor = menor->esquerda;
    }

    return menor;
}

#endif