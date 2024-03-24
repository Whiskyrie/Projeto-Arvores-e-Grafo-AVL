#ifndef DESENHA_ARVORE_H
#define DESENHA_ARVORE_H

#define ESPACO 5

void DesenhaArvoreRecursivo(pNohArvore raiz, int depth, char *path, int right, FuncaoImpressao fi)
{
    // Caso base
    if (raiz == NULL)
        return;

    // Incrementa a profundidade
    depth++;

    // Desenha a subárvore direita primeiro
    DesenhaArvoreRecursivo(raiz->direita, depth, path, 1, fi);

    // Atualiza o caminho
    path[depth - 2] = right ? 1 : 0;
    if (raiz->esquerda)
        path[depth - 1] = 1;

    // Imprime a linha vertical
    printf("\n");
    for (int i = 0; i < depth - 1; i++)
    {
        printf("%s", (i == depth - 2) ? "+" : (path[i] ? "|" : " "));
        for (int j = 1; j < ESPACO; j++)
            printf("%s", (i < depth - 2) ? " " : "-");
    }

    // Imprime a informação do nó
    fi(raiz->info);

    // Imprime os espaços após a informação do nó
    for (int i = 0; i < depth; i++)
    {
        printf(" ");
        for (int j = 1; j < ESPACO; j++)
            printf(" ");
    }

    // Desenha a subárvore esquerda
    DesenhaArvoreRecursivo(raiz->esquerda, depth, path, 0, fi);
}

void DesenhaArvore(pDArvore arvore, FuncaoImpressao fi)
{
    char path[255] = {};

    // Inicia o desenho da árvore a partir da raiz
    DesenhaArvoreRecursivo(arvore->raiz, 0, path, 0, fi);
    printf("\n");
}

#endif
