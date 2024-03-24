#ifndef LISTA_TAD_H
#define LISTA__TAD_H
/*------------------------------------------*/
/* tipos de dados                           */
/*------------------------------------------*/
typedef struct noh Noh;
typedef Noh *pNoh;

/* descritor da lista */
typedef struct dLista DLista;
typedef DLista *pDLista;

/* 3 tipos que representam ponteiros para funcao */
typedef int (*FuncaoComparacao)(void *, void *);
typedef void (*FuncaoImpressao)(void *);
typedef void *(*FuncaoAlocacao)(void *);
typedef void (*FuncaoLiberacao)(void *);

/*------------------------------------------*/
/* operacoes                                */
/*------------------------------------------*/
pDLista CriarLista();

void IncluirInfo(pDLista, void *);

void IncluirInfoInicio(pDLista, void *);

void IncluirInfoNoMeio(pDLista, void *, int);

int ExcluirInfo(pDLista, void *, FuncaoComparacao);

void *ExcluirInfoPos(pDLista pd, int pos);

int ContemInfo(pDLista, void *, FuncaoComparacao);

void ImprimirLista(pDLista, FuncaoImpressao);

void InverterLista(pDLista pd);

void DestruirLista(pDLista);

pDLista DuplicarLista(pDLista, FuncaoAlocacao);

pDLista DividirLista(pDLista, int);

pDLista UnirListas(pDLista, pDLista, FuncaoComparacao);

void *BuscarNohInfo(pDLista, void *, FuncaoComparacao);

void *BuscarInfoPos(pDLista, int);

#endif
