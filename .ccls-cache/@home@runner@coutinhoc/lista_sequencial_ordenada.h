#define FALSE 0
#define TRUE 1

#define LISTA_ORDENADA

typedef int Boolean;
typedef int Elemento;

typedef struct {
  int linha[1000];
  int size;
} lcont;

typedef struct {
  lcont linhas;
  char palavra[50];
  int Total;
} NO;

typedef struct {

  NO lista[1000];
  int livre;
  int capacidade;

} ListaSequencial;

ListaSequencial *cria_lista(int capacidade);
void destroi_lista(ListaSequencial *lista);
int tamanho(ListaSequencial *lista);
void imprime(ListaSequencial *lista);
int busca(ListaSequencial *lista, char *e);
Boolean insere(ListaSequencial * list, char * e,int linha);
