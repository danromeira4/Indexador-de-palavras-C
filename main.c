#include <time.h>
#include "lista_ligada.h"
#include "arvore_binaria.h"

#define TAMANHO 10000

clock_t start,stop;

//  start = clock();
//  stop = clock();
//printf ("Tempo: %.3f segundos",(double)(stop-start)/CLOCKS_PER_MILISEC);
//Tempo para carregar o arquivo e construir o indice: XXXXX ms


char fim[] = "fim";
char busca[] = "busca";
char arvore[] = "arvore";
char lista[] = "lista";


int main(int argc, char **argv) { /*argc conta quantos parametros foram passados no terminal argv é uma matriz que guarda as palavras passadas no terminal*/
printf("Tipo de indice: '%s'\n",argv[2]);
  
printf("Arquivo texto: '%s'\n",argv[1]);

start = clock();
  
//cria lista ligada e arranjo copia das linhas
char** LinhasCopia = (char**) malloc (sizeof(char*)*TAMANHO);

  
  FILE *in;  // está guardando o endereço de memória de um arquivo qualquer
  char *linha; //ponteiro utilizado para manipular as linhas
  char *copia_ponteiro_linha; // ponteiro utilizado para manipular as linhas com segurança
  char *quebra_de_linha;     //guardará as quebras de linhas na função strrchr
  char *palavra;  //guardará as palavras cortadas no final          
  int contador_linha; // vai contar as linhas, trabalhará em conjunto com strrchr
  ListaLigada * listaPalavras;
  Arvore * arvorePalavras;
  
int indice = 0;
if (strcasecmp(argv[2],lista) == 0) {
  indice = 1;
  listaPalavras = cria_lista();
  }
if (strcasecmp(argv[2],arvore)==0){
  indice = 2;
  arvorePalavras = cria_arvore();
  }
  if (argc > 2) { // testa se passamos ou não o nome do arquivo texto no terminal, já que 
                  // cada argumento o argc conta, então precisa ser mais igual a 2 no mínimo
    

      in = fopen( argv[1], "r"); // abre o arquivo, localizado no terminal argv, "r" lê o arquivo
    if (in == NULL) {
    printf("Erro ao abrir arquivo\n");
    return 0;
  }

    contador_linha = 0;
    linha = (char *)malloc((TAMANHO + 1) * sizeof(char)); // arranjo a escrita de uma linha 
                                                          //quebrada
    while (in && fgets(linha, TAMANHO, in)) {
    // enquanto in estiver aberto e fgets estiver guardando as strings na linha, continue
      if ((quebra_de_linha = strrchr(linha, '\n'))) //se a função strrchr achar  \n
      *quebra_de_linha = 0;
      // Esta função (strrchr) retorna um ponteiro para a última ocorrência do
      // caractere em str. Se o valor não for encontrado, a função retorna um
      // ponteiro nulo.Ou seja, ele guarda a linha até aparecer \n

      //printf("linha %03d: '%s'\n", contador_linha + 1, linha);

      // fazemos uma copia do endereço que corresponde ao array de chars
      // usado para armazenar cada linha lida do arquivo pois a função 'strsep'
      // modifica o endereço do ponteiro a cada chamada feita a esta função (e
      // não queremos que 'linha' deixe de apontar para o inicio do array).

      copia_ponteiro_linha = linha;
      //copia linha atual para arranjo de linhas
      LinhasCopia[contador_linha] = (char*) malloc(sizeof(char)*(strlen(linha)+1));
      strcpy(LinhasCopia[contador_linha], linha);

      while ((palavra = strsep(&copia_ponteiro_linha, " (),-.?!:/;|\"'[]")) ) {
        
        // strsep quebra as palavras das linhas, por isso tem que ser na
        // cópia do ponteiro linha,se não estraga o original
        // antes de guardar a palavra em algum tipo de estrutura usa./a
        // para implementar o índice, será necessário fazer uma copia
        // da mesma, uma vez que o ponteiro 'palavra' aponta para uma
        // substring dentro da string 'linha', e a cada nova linha lida
        // o conteúdo da linha anterior é sobreescrito.

        if(palavra[0] > 64){
        
        /*deixa toda palavra minuscula
        for(int aux = 0; aux<((strlen(palavra))); aux++){
          if(palavra[aux]<97 || 122<palavra[aux]){
            if(65<=palavra[aux] && palavra[aux]<=90) 
              palavra[aux] = palavra[aux] +32;
          }
        }
        */
          
              WORD elemento;
              WORD_A elemento_a;
        //adicioona na estrutura
          switch (indice){
            case 0:
              printf ("Indice Invalido!\n");
              return 1;
            break;
            
            case 1: //LISTA
              elemento.wordtxt = (char*) malloc(sizeof(char)* (strlen(palavra)+1) );
              strcpy(elemento.wordtxt, palavra);
              elemento.linha = contador_linha + 1;
              insere(listaPalavras, elemento);
            break;
              
            case 2: //ARVORE
              //printf ("!teste");
              elemento_a.wordtxt = (char*) malloc(sizeof(char)* (strlen(palavra)+1) );
              strcpy(elemento_a.wordtxt, palavra);
              elemento_a.linha = contador_linha + 1;
              insere_ord(arvorePalavras, elemento_a);

            break;
          }
        }
      }
      contador_linha++;
    }
    stop = clock();
    printf("Numero de linhas no arquivo: %i\n",contador_linha);
    printf ("Tempo para carregar o arquivo e construir o indice: %.3f ms\n",1000*((double)(stop-start)/CLOCKS_PER_SEC));

    
    //COMANDOS BUSCA E FIM
for (;;) {
    char* command = (char*) malloc (sizeof(char)*51);
    printf("> ");
    command = fgets(command, 50, stdin);
    command [strlen(command) - 1 ] = '\0';
    if(strcasecmp(command,fim) == 0) {
      return 0;}

    int m = 0;
    char* partCommand = (char*) malloc (sizeof(char)*50);
    char** aux = (char**) malloc (sizeof(char)*50);
      while ((partCommand = strsep(&command, " \0\n")) && m<2 ){
        aux[m] = (char*) malloc (sizeof(char)*50);
        strcpy(aux[m], partCommand);
        m++;
      }
    free (command);

  if((strcasecmp(aux[0],busca) != 0 || aux[0] == 0 || aux[1] == 0)){
      indice = indice - 5;
    free(aux);
    }
    //palavra a buscar: aux[1]
  int* busc;
  No_a* noBusc;
    
switch (indice) {    
//LISTA;
    case 1:
    start = clock();
    busc = busca_lista(listaPalavras, aux[1]);
    stop = clock();
    if (busc[0] == -1)
      printf("Palavra '%s' nao encontrada.\n",aux[1]);
    else{
    printf("Existem %i ocorrências da palavra '%s' na(s) seguinte(s) linha(s):\n",busc[0],aux[1]);
    int j = 1;
    while(busc[j]){
      printf("%04i:  %s\n",busc[j], LinhasCopia[busc[j]-1]);
      j++;
        }
    printf ("Tempo de busca: %.3f ms\n",1000*((double)(stop-start)/CLOCKS_PER_SEC));
      }
    break;

  
//ARVORE
    case 2:
    start = clock();
    noBusc = busca_bin_rec(arvorePalavras->raiz, aux[1]);
    stop = clock();
    busc = noBusc->linhas;
        if (noBusc == NULL){
      printf("Palavra '%s' nao encontrada.\n",aux[1]);
      printf ("Tempo de busca: %.3f ms\n",1000*((double)(stop-start)/CLOCKS_PER_SEC));
      }
    else{
    printf("Existem %i ocorrências da palavra '%s' na(s) seguinte(s) linha(s):\n",busc[0],aux[1]);
    int j = 1;
    while(busc[j]){
      printf("%04i:  %s\n",busc[j], LinhasCopia[busc[j]-1]);
      j++;
      }
    printf ("Tempo de busca: %.3f ms\n",1000*((double)(stop-start)/CLOCKS_PER_SEC));
    }
    break;

    default:
      indice = indice + 5;
      printf("Opcao invalida!\n");
    break;
    }
  }
    
  printf("Argumentos insuficientes!\n");
  return 1;
  }
}