#include <stdio.h>
#include "Utils.h"
#include "Lista.h"

int main()
{
    pDLista pListaData = CriarLista();

    /* teste de inclusao */
    IncluirInfo(pListaData, AlocaData(05, 03, 2007));
    IncluirInfo(pListaData, AlocaData(12, 05, 2012));
    IncluirInfo(pListaData, AlocaData(10, 8, 2006));
    IncluirInfo(pListaData, AlocaData(01, 12, 2015));
    IncluirInfo(pListaData, AlocaData(23, 9, 2020));
    IncluirInfo(pListaData, AlocaData(18, 04, 2003));
    printf("\nResultado da Inclusao \n");
    ImprimirLista(pListaData, ImprimeData);

    /* teste de exclusao */
    ExcluirInfo(pListaData, AlocaData(18, 04, 2003), ComparaData);
    printf("\nResultado da Exclusao \n");
    ImprimirLista(pListaData, ImprimeData);

    /* teste de busca */
    int result = ContemInfo(pListaData, AlocaData(18, 04, 2003), ComparaData);
    printf("\nResultado da Busca: 0-[Nao encontrou], 1-[Ok] -> %d\n", result);

    /* teste de duplicacao de lista */
    pDLista copia = DuplicarLista(pListaData, AlocaInfoData);
    printf("Resultado da Duplicacao \n");
    ImprimirLista(copia, ImprimeData);

    /* teste de divisao de lista */
    pDLista novaLista = DividirLista(pListaData, 1);
    printf("\nResultado da Divisao \n");
    printf("Lista Original: ");
    ImprimirLista(pListaData, ImprimeData);
    printf("\nNova Lista: ");
    ImprimirLista(novaLista, ImprimeData);

    /* teste de destruicao da lista */
    DestruirLista(pListaData);
    printf("\nResultado da destruicao da lista \n");
    ImprimirLista(pListaData, ImprimeData);
}
