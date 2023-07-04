#define FALSE 0
#define TRUE 1

#define INDEFINIDO -1
#define ESQUERDO 0
#define DIREITO 1

typedef int Boolean;

typedef struct{
  char* wordtxt;
  int linha;
} WORD_A;
//elemento->WORD_A
typedef struct _no_arvore_ {
//valor->palavra
	WORD_A palavra;
  int linhas[1000];
	struct _no_arvore_ * esq;
	struct _no_arvore_ * dir;
} No_a;

typedef struct {

	No_a * raiz;

} Arvore;

