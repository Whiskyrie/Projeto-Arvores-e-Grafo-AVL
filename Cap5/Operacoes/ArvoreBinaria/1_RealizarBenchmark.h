#ifndef REALIZAR_BENCHMARK_H
#define REALIZAR_BENCHMARK_H
#define NUM_ELEMENTOS 1000000
#define NUM_OPERACOES 1000000

void realizarBenchmark(pDArvore arvore)
{
    int i;
    clock_t inicio, fim;
    double tempo_insercao, tempo_busca, tempo_exclusao;
    int *numeros_inseridos = malloc(NUM_ELEMENTOS * sizeof(int));

    if (numeros_inseridos == NULL)
    {
        printf("Erro: Não foi possível alocar memória para o array de números.\n");
        return;
    }

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    printf("Iniciando benchmark...\n");

    // Benchmark de inserção
    printf("Inserindo %d números...\n", NUM_ELEMENTOS);
    inicio = clock();
    for (i = 0; i < NUM_ELEMENTOS; i++)
    {
        numeros_inseridos[i] = rand() % (NUM_ELEMENTOS * 10) + 1;
        IncluirInfo(arvore, AlocaInt(numeros_inseridos[i]), ComparaInt);
    }
    fim = clock();
    tempo_insercao = ((double)(fim - inicio)) / CLOCKS_PER_SEC * 1000.0;

    // Benchmark de busca
    printf("Realizando %d buscas aleatórias...\n", NUM_OPERACOES);
    inicio = clock();
    for (i = 0; i < NUM_OPERACOES; i++)
    {
        int indice_aleatorio = rand() % NUM_ELEMENTOS;
        BuscarInfo(arvore, AlocaInt(numeros_inseridos[indice_aleatorio]),
                   ComparaInt);
    }
    fim = clock();
    tempo_busca = ((double)(fim - inicio)) / CLOCKS_PER_SEC * 1000.0;

    // Benchmark de exclusão
    printf("Realizando %d exclusões aleatórias...\n", NUM_OPERACOES);
    inicio = clock();
    for (i = 0; i < NUM_OPERACOES; i++)
    {
        int indice_aleatorio = rand() % NUM_ELEMENTOS;
        ExcluirInfo(arvore, AlocaInt(numeros_inseridos[indice_aleatorio]),
                    ComparaInt);
    }
    fim = clock();
    tempo_exclusao = ((double)(fim - inicio)) / CLOCKS_PER_SEC * 1000.0;

    // Resultados
    printf("\nResultados do Benchmark:\n");
    printf("Tempo total para inserção de %d números: %.2f milissegundos\n",
           NUM_ELEMENTOS, tempo_insercao);
    printf("Média de tempo por inserção: %.6f milissegundos\n",
           tempo_insercao / NUM_ELEMENTOS);
    printf("Tempo total para %d buscas: %.2f milissegundos\n", NUM_OPERACOES,
           tempo_busca);
    printf("Média de tempo por busca: %.6f milissegundos\n",
           tempo_busca / NUM_OPERACOES);
    printf("Tempo total para %d exclusões: %.2f milissegundos\n", NUM_OPERACOES,
           tempo_exclusao);
    printf("Média de tempo por exclusão: %.6f milissegundos\n",
           tempo_exclusao / NUM_OPERACOES);

    free(numeros_inseridos);
}
#endif // REALIZAR_BENCHMARK_H
