#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "arvore_binaria_base.h"

Boolean __debug__ = FALSE;
void debug_on() { __debug__ = TRUE; }
void debug_off() { __debug__ = FALSE; }

#define ROWS 20
#define COLS 80

///////////////////////////////////////////////////////////////////////////
Arvore * cria_arvore(){

	Arvore * arvore = (Arvore *) malloc (sizeof(Arvore));
	arvore->raiz = NULL;	
	return arvore;
}


No_a * busca_bin_rec(No_a* no, char* e){

	if(no){
  
		if(strcasecmp(e, no->palavra.wordtxt) == 0) 
      return no;
		
    if(strcasecmp(e, no->palavra.wordtxt) < 0) 
      return busca_bin_rec(no->esq, e);
    else
	    return busca_bin_rec(no->dir, e);
	}
//nao existe
	return NULL;
}

No_a * busca_bin(Arvore * arvore, WORD_A e){

	return busca_bin_rec(arvore->raiz, e.wordtxt);	
}


Boolean insere_ord_rec(No_a * raiz, No_a * novo){

	if(strcasecmp(novo->palavra.wordtxt, raiz->palavra.wordtxt)){

		if(strcasecmp(novo->palavra.wordtxt, raiz->palavra.wordtxt) < 0){

			if(raiz->esq) return insere_ord_rec(raiz->esq, novo);
			else raiz->esq = novo;
		}
		else{
			if(raiz->dir) return insere_ord_rec(raiz->dir, novo);
			else raiz->dir = novo;
		}
	
		return 1;
	}

	return 0;
}

Boolean insere_ord(Arvore * arvore, WORD_A e){
  No_a* wrd = busca_bin(arvore, e);

//ja esta na estrutura
  if(wrd){
    wrd->linhas[0]++;
  int u;
  for(u=1; wrd->linhas[u]; u++){
    if (wrd->linhas[u] == e.linha){
      u = -1;
      break;
    }
  }
  if(u == -1)
    return 0;
  else
    wrd->linhas[u] = e.linha;
    return 0;
  }
//nao esta na arvore
  else{
  
  //cria no
  No_a* novo = (No_a *) malloc(sizeof(No_a));
    novo->palavra.wordtxt = (char*) malloc(sizeof(char)* (strlen(e.wordtxt)) );
    strcpy(novo->palavra.wordtxt, e.wordtxt);
    novo->linhas[0] = 1;
    novo->linhas[1] = e.linha;
    novo->esq = novo->dir = NULL;
  
  if(arvore->raiz) 
    return insere_ord_rec(arvore->raiz,novo);
  arvore->raiz = novo;
    return 1;
  }
}