#ifndef UNIR_LISTA_H
#define UNIR_LISTA_H

pDLista UnirListas(pDLista lista1, pDLista lista2, FuncaoComparacao fc)
{
    pDLista novaLista = CriarLista();
    pDLista atual = novaLista;

    while (lista1 != NULL && lista2 != NULL)
    {
        struct noh *novoNoh;
        if (fc(lista1->primeiro->info, lista2->primeiro->info) <= 0)
        {
            novoNoh = lista1->primeiro;
            lista1->primeiro = lista1->primeiro->prox;
            if (lista1->primeiro != NULL)
            {
                lista1->primeiro->ant = NULL;
            }
        }
        else
        {
            novoNoh = lista2->primeiro;
            lista2->primeiro = lista2->primeiro->prox;
            if (lista2->primeiro != NULL)
            {
                lista2->primeiro->ant = NULL;
            }
        }

        if (atual->primeiro == NULL)
        {
            atual->primeiro = atual->ultimo = novoNoh;
        }
        else
        {
            atual->ultimo->prox = novoNoh;
            novoNoh->ant = atual->ultimo;
            atual->ultimo = novoNoh;
        }
        novoNoh->prox = NULL;
    }

    if (lista1->primeiro != NULL)
    {
        atual->ultimo->prox = lista1->primeiro;
        lista1->primeiro->ant = atual->ultimo;
    }

    if (lista2->primeiro != NULL)
    {
        atual->ultimo->prox = lista2->primeiro;
        lista2->primeiro->ant = atual->ultimo;
    }

    return novaLista;
}

#endif