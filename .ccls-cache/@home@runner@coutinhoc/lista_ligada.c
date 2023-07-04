#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>

#include "lista_ligada.h"

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

/*
int busca(ListaLigada * lista, WORD e){

	int i = 0;
	No * p = lista->primeiro;

	while(p && p->valor < e){

		p = p->proximo;
		i++;
	}
	return p ? (p->valor == e ? i : -1) : -1;
}
*/

Boolean insere(ListaLigada * lista, WORD e){

	No * p;
	No * anterior;
	No * novo = (No *) malloc(sizeof(No));

	novo->valor = e;

	anterior = NULL;
	p = lista->primeiro;

	while(p){
    
 			
		anterior = p;
		p = p->proximo;
	}
	
	novo->proximo = p;
		
	if(anterior) anterior->proximo = novo;
	else lista->primeiro = novo;

	return TRUE;
}


/*Boolean remove_WORD(ListaLigada * lista, WORD e){

	int i;
	int indice = busca(lista, e);
	No * p;
	No * tmp;

	if(indice >= 0) {

		if(indice == 0){

			tmp = lista->primeiro;
			lista->primeiro = tmp->proximo;
			free(tmp);
		}
		else{

			i = 0;
			p = lista->primeiro;

			while(p){

				if(i == indice - 1) break;

				i++;
				p = p->proximo;
			}
			
			tmp = p->proximo;
			p->proximo = p->proximo->proximo;
			free(tmp);
		}
		
		return TRUE;
	}

	return FALSE;
}*/
