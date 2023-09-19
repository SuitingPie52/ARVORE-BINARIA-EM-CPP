#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// pré-ordem: raiz -> esquerda -> direita
// em-ordem: esquerda -> raiz -> direita (mais útil)
// pós-ordem: esquerda -> direita -> raiz


//////////////////////////////////////////////////////////////
// PROGRAMA QUE IMPLEMENTA AS NAVEGAÇÕES EM ÁRVORE BINÁRIA //
////////////////////////////////////////////////////////////

struct no {
	int numero;
	struct no *esquerda;
	struct no *direita;
	
};



struct no *inserir (struct no * raiz, int numero) { 
	
	if (raiz == NULL) {
	
		raiz = (struct no*) malloc(sizeof(struct no));
		raiz -> numero = numero;
		raiz -> esquerda = NULL;
		raiz -> direita = NULL;
		
	} else {
		
		if ((rand() % 2 == 0)) {
			
			raiz -> esquerda = inserir(raiz -> esquerda, numero); 
			
		} else {
			
			raiz -> direita = inserir(raiz -> direita, numero); 
			
		}
		
	}
	
	return raiz;
	
} 

//////////////////////////////////////////////
// Função que navega a árvore em pré-ordem //
////////////////////////////////////////////

void navegarPreOrdem(struct no *raiz) {
	
	if (raiz != NULL) {
		
		printf("%d\t", raiz -> numero);
		navegarPreOrdem(raiz -> esquerda);
		navegarPreOrdem(raiz -> direita);
	
	}
	
}


/////////////////////////////////////////////
// Função que navega a árvore em em-ordem //
///////////////////////////////////////////

void navegarEmOrdem(struct no *raiz) {
	
	if (raiz != NULL) {
		
		navegarEmOrdem(raiz -> esquerda);
		printf("%d\t", raiz -> numero);
		navegarEmOrdem(raiz -> direita);
	
	}
	
}

/////////////////////////////////////////////
// Função que navega a árvore em pós-ordem //
///////////////////////////////////////////

void navegarPosOrdem(struct no *raiz) {
	
	if (raiz != NULL) {
		
		navegarPosOrdem(raiz -> esquerda);
		navegarPosOrdem(raiz -> direita);
		printf("%d\t", raiz -> numero);
	
	}
	
}

int main () {
	
	struct no *raiz = NULL;
	time_t t;
	
	srand((unsigned) time(&t));
	
	int i =0;
	for (i = 1; i < 10000; i++) {
		
		raiz = inserir(raiz, i);
		
	}
	
	printf("Pre-Ordem:\t");
	navegarPreOrdem(raiz);
	printf("\n================================\nEm-Ordem\t");
	navegarEmOrdem(raiz);
	printf("\n================================\nPos-Ordem\t");
	navegarPosOrdem(raiz);
	
}

