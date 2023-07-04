#define FALSE 0
#define TRUE 1
 
typedef int Boolean;

typedef struct{
  char* wordtxt;
  int linha;
} WORD;

typedef struct _no_ {

	WORD valor;
	struct _no_ * proximo;

} No;

typedef struct {
	
	No * primeiro;

} ListaLigada;
