#ifndef ARVORE_TAD_H
#define ARVORE_TAD_H
/*------------------------------------------*/
/* tipos de dados                           */
/*------------------------------------------*/
/* estrutura do noh da arvore */

typedef struct nohArvore
{
    void *info;
    struct nohArvore *esquerda;
    struct nohArvore *direita;

} NohArvore, *pNohArvore;

typedef struct nohArvore NohArvore;
typedef NohArvore *pNohArvore;

/* descritor da arvore */
typedef struct dArvore DArvore;
typedef DArvore *pDArvore;

/* tipos referentes aos ponteiros para funcao */
typedef int (*FuncaoComparacao)(void *, void *);
typedef void (*FuncaoImpressao)(void *);

/*------------------------------------------*/
/* operacoes                                */
/*------------------------------------------*/
pDArvore CriarArvore(int);

void IncluirInfo(pDArvore, void *, FuncaoComparacao);
int ExcluirInfo(pDArvore, void *, FuncaoComparacao);
pNohArvore BuscarInfo(pDArvore, void *, FuncaoComparacao);

/* percursos */
void EmOrdem(pNohArvore, FuncaoImpressao);
void PreOrdem(pNohArvore, FuncaoImpressao);
void PosOrdem(pNohArvore, FuncaoImpressao);

int Altura(pDArvore);
int Grau(pDArvore);
int Nivel(pDArvore, void *, FuncaoComparacao);
int QuantidadeFolhas(pDArvore);
int QuantidadeNohs(pDArvore);
int EhFolha(pDArvore, void *, FuncaoComparacao);
int ArvoreVazia(pDArvore);
pNohArvore EncontrarMenor(pNohArvore raiz);
void DesenhaArvore(pDArvore, FuncaoImpressao);
void Balancear(pDArvore arvore);
void RecalcularFB(pDArvore arvore);

#endif
