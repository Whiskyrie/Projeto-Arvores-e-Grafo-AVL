#ifndef DUPLICAR_LISTA_H
#define DUPLICAR_LISTA_H

pDLista DuplicarLista(pDLista pd, FuncaoAlocacao fa)
{
    pDLista pNovaLista = CriarLista();

    pNoh atual = pd->primeiro;
    while (atual != NULL)
    {
        /* aloca memoria e copia do valor do campo info */
        void *auxInfo = fa(atual->info);
        /* adiciona a copia da informacao na nova lista */
        IncluirInfo(pNovaLista, auxInfo);

        atual = atual->prox;
    }
    return pNovaLista;
}

#endif
