#ifndef EXCLUIRINFO_ARVORE_BINARIA_H
#define EXCLUIRINFO_ARVORE_BINARIA_H

pNohArvore ExcluirInfoRecursivo(pNohArvore raiz, void *info, FuncaoComparacao pfc, void **auxiliar)
{
    if (raiz == NULL)
        return NULL;
    int comparacao = pfc(info, raiz->info);

    if (comparacao > 0)
        raiz->esquerda = ExcluirInfoRecursivo(raiz->esquerda, info, pfc, auxiliar);
    else if (comparacao < 0)
        raiz->direita = ExcluirInfoRecursivo(raiz->direita, info, pfc, auxiliar);
    else
    {
        // Caso 1: O nó a ser excluído não tem filhos
        if (raiz->esquerda == NULL && raiz->direita == NULL)
        {
            free(raiz->info);
            free(raiz);
            return NULL;
        }

        // Caso 2: O nó a ser excluído tem somente um filho
        if (raiz->esquerda == NULL)
        {
            pNohArvore temp = raiz->direita;
            free(raiz->info);
            free(raiz);
            return temp;
        }
        else if (raiz->direita == NULL)
        {
            pNohArvore temp = raiz->esquerda;
            free(raiz->info);
            free(raiz);
            return temp;
        }

        // Caso 3: O nó a ser excluído tem os dois filhos
        else
        {
            pNohArvore aux = raiz->direita;
            while (aux->esquerda != NULL)
            {
                aux = aux->esquerda;
            }
            // Troca as informações
            void *temp_info = raiz->info;
            raiz->info = aux->info;
            aux->info = temp_info;

            // Exclui o nó sucessor da subárvore direita
            raiz->direita = ExcluirInfoRecursivo(raiz->direita, info, pfc, auxiliar);
        }
    }

    // Obter o fator de balanceamento desta árvore
    CalcularFatorBalanceamentoRecursivo(raiz);

    // Rebalancear a árvore
    raiz = BalancearArvore(raiz);

    return raiz;
}

int ExcluirInfo(pDArvore arvore, void *info, FuncaoComparacao pfc)
{
    if (arvore == NULL || arvore->raiz == NULL)
        return -1; // Árvore vazia

    void *auxiliar = NULL;
    pNohArvore novaRaiz = ExcluirInfoRecursivo(arvore->raiz, info, pfc, &auxiliar);

    if (novaRaiz == NULL)
    {
        // Se a nova raiz for NULL, significa que a árvore ficou vazia após a exclusão
        free(arvore);
        arvore = NULL;
    }
    else
    {
        // Caso contrário, atualiza a raiz da árvore
        arvore->raiz = novaRaiz;
    }

    // Libera a memória alocada para o valor excluído
    if (auxiliar != NULL)
    {
        free(auxiliar);
    }

    return 0; // Exclusão bem-sucedida
}
#endif // EXCLUIRINFO_ARVORE_BINARIA_H