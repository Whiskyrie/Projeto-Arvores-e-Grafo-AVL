#ifndef DESTRUIR_LISTA_H
#define DESTRUIR_LISTA_H

void DestruirListaRecursiva(pNoh atual)
{
    if (atual == NULL)
        return;
    DestruirListaRecursiva(atual->prox);
    free(atual);
}

/* -------------------------------------*/
void DestruirLista(pDLista pd)
{
    DestruirListaRecursiva(pd->primeiro);
    pd->primeiro = NULL;
    pd->ultimo = NULL;
    pd->quantidade = 0;
}

#endif
