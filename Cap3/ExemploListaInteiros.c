#include <stdio.h>
#include <stdlib.h>
#include "Utils.h"
#include "Lista.h"

int main()
{
  pDLista pListaInt = CriarLista();

  int *pi = AlocaInt(5);

  /* teste de inclusao */
  IncluirInfo(pListaInt, pi);
  IncluirInfo(pListaInt, AlocaInt(3));
  IncluirInfo(pListaInt, AlocaInt(9));
  IncluirInfo(pListaInt, AlocaInt(1));
  IncluirInfo(pListaInt, AlocaInt(2));

  printf("Resultado da Inclusao:\n");
  ImprimirLista(pListaInt, ImprimeInt);

  /* teste de exclusao */
  ExcluirInfo(pListaInt, AlocaInt(9), ComparaInt);
  printf("\nResultado da Exclusao \n");
  ImprimirLista(pListaInt, ImprimeInt);

  /* teste de busca */
  int result = ContemInfo(pListaInt, AlocaInt(5), ComparaInt);
  printf("\nResultado da busca do numero 5: \n 0-[Nao encontrou], 1-[Ok] -> %d\n", result);

  /* teste de duplicacao de lista */
  pDLista copia = DuplicarLista(pListaInt, AlocaInfoInt);
  printf("Resultado da Duplicacao \n");
  ImprimirLista(copia, ImprimeInt);

  /* teste de divisao de lista */
  pDLista novaLista = DividirLista(pListaInt, 3);
  printf("\nResultado da Divisao \n");
  printf("Lista Original: ");
  ImprimirLista(pListaInt, ImprimeInt);
  printf("\nNova Lista: ");
  ImprimirLista(novaLista, ImprimeInt);

  /* teste de destruicao da lista */
  // destruirListaInfo(pListaInt, liberaInt);
  // printf("\nResultado da destruicao da lista \n");
  // imprimirLista(pListaInt, imprimeInt);

  //  unirListas(pListaInt, pListaInt, ComparaInt);
}
