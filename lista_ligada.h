#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "lista_ligada_base.h"

ListaLigada * cria_lista(){

	ListaLigada * lista =  (ListaLigada *) malloc (sizeof(ListaLigada));
	lista->primeiro = NULL;
	
	return lista;
}

void destroi_lista(ListaLigada * lista){

	No * p = lista->primeiro;
	No * tmp;

	while(p){
		
		tmp = p;
		p = p->proximo;
		free(tmp);
	}

	free(lista);
}

//tem q fazer ainda, acho melhor n usar strcasecmp pode dar problema se tiver 
//string de tamanho diferente

int* busca_lista(ListaLigada * lista, char* palavra){
  int* ocorrencias = (int*) malloc (sizeof(int)*1000);
	int i = 0;
  int aux = 1;
	int temp;
  No * p = lista->primeiro;
  ocorrencias[0] = 0;

	while(p && p->valor.wordtxt[0] < (palavra[0]+1)){
    if (strcasecmp(p->valor.wordtxt, palavra) == 0){
      ocorrencias[0]++;
      temp = 1;
      while(temp!=-1 && ocorrencias[temp]){
        if (ocorrencias[temp] == p->valor.linha){
          temp = -1;
          break;
          }
        temp++;
      }
      if(temp!=-1){
        ocorrencias[aux] = p->valor.linha;
        aux++;
        }
      }
		p = p->proximo;
		i++;
	}
if(ocorrencias[1]) 
  return ocorrencias;
else{
  ocorrencias [0] = -1;
  return ocorrencias;
  }
  
}



Boolean insere(ListaLigada * lista, WORD e){

	No * p;
	No * anterior;
	No * novo = (No *) malloc(sizeof(No));

	novo->valor = e;

	anterior = NULL;
	p = lista->primeiro;

	while(p){

		if(e.wordtxt[0] < p->valor.wordtxt[0]) break;
 			
		anterior = p;
		p = p->proximo;
	}
	
	novo->proximo = p;
		
	if(anterior) anterior->proximo = novo;
	else lista->primeiro = novo;

	return TRUE;
}


void imprime(ListaLigada * lista){

	No * p;

	printf("Lista:");

	for(p = lista->primeiro; p; p = p->proximo){

		printf(" %s  /  %i\n", p->valor.wordtxt, p->valor.linha);
    
	}

	printf("\n");
}