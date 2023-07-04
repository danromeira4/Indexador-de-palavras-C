#include "lista_ligada.c"

#define TAMANHO 1000

int main(int argc, char **argv) { /*argc conta quantos parametros foram passados no terminal
                                    argv é uma matriz que guarda as palavras passadas no 
                                    terminal*/

//cria lista ligada e arranjo copia das linhas
ListaLigada * listaPalavras = cria_lista();
char** LinhasCopia = (char**) malloc (sizeof(char*)*TAMANHO);

  
  FILE *in;  // está guardando o endereço de memória de um arquivo qualquer
  char *linha; //ponteiro utilizado para manipular as linhas
  char *copia_ponteiro_linha; // ponteiro utilizado para manipular as linhas com segurança
  char *quebra_de_linha;     //guardará as quebras de linhas na função strrchr
  char *palavra;  //guardará as palavras cortadas no final          
  int contador_linha; // vai contar as linhas, trabalhará em conjunto com strrchr

  if (argc >= 2) { // testa se passamos ou não o nome do arquivo texto no terminal, já que 
                  // cada argumento o argc conta, então precisa ser mais igual a 2 no mínimo
    in = fopen( argv[1], "r"); // abre o arquivo, localizado no terminal argv, "r" lê o arquivo

    printf(">>>>> Carregando arquivo...\n");

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

      printf("linha %03d: '%s'\n", contador_linha + 1, linha);

      // fazemos uma copia do endereço que corresponde ao array de chars
      // usado para armazenar cada linha lida do arquivo pois a função 'strsep'
      // modifica o endereço do ponteiro a cada chamada feita a esta função (e
      // não queremos que 'linha' deixe de apontar para o inicio do array).

      copia_ponteiro_linha = linha;
      //copia linha atual para arranjo de linhas
      strcpy(LinhasCopia[(contador_linha)-1], linha);
      while ((palavra = strsep(&copia_ponteiro_linha, " "))) {
        
        // strsep quebra as palavras das linhas, por isso tem que ser na
        // cópia do ponteiro linha,se não estraga o original
        // antes de guardar a palavra em algum tipo de estrutura usada
        // para implementar o índice, será necessário fazer uma copia
        // da mesma, uma vez que o ponteiro 'palavra' aponta para uma
        // substring dentro da string 'linha', e a cada nova linha lida
        // o conteúdo da linha anterior é sobreescrito.


        
        printf("\t\t'%s'\n", palavra);

        //for(int aux = 0; palavra[aux]!='\0'; aux++)
        //if (65<=palavra[aux] && palavra[aux]<=90) palavra[aux] = palavra[aux]i]+32;
        
        WORD elemento;
          strcpy(elemento.wordtxt, palavra);
          elemento.linha = contador_linha;
        //adicioona na lista(palavra, contador_linha)
        insere(listaPalavras, elemento);
      }

      contador_linha++;
    }

    printf(">>>>> Arquivo carregado!\n");
    
  
    return 0;
  }

  return 1;
}