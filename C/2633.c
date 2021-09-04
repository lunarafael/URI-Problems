#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Bruno Racobaldo, Alexandre Magno, Rafael Luna

typedef struct{
	char nome[21];
	int validade;
} CARNE;

typedef struct no{
	CARNE dados;
	struct no *prox;
} NO;

typedef NO* LISTA;
LISTA *li;

LISTA* cria_lista(){
	LISTA *li = (LISTA*) malloc(sizeof(LISTA));
	if(li != NULL)
		*li = NULL;
	return li;
}

int listase_vazia(LISTA *l){
	if(l==NULL) return 1;
	if((*l)==NULL) return 1;
	return 0;
}

void inserir_ordenado(LISTA* l, CARNE y){
	NO *aux = (NO*) malloc(sizeof(NO));
	if(l == NULL){
		printf("Lista vazia\n");
	}
	aux->dados = y;
	if(listase_vazia(l)){
		aux->prox = (*l);
		*l = aux;
	}
	else{
	NO *anterior, *atual = *l;
	while(atual != NULL && atual->dados.validade < y.validade){
		anterior = atual;
		atual = atual->prox;
		}	
		if(atual == *l){
			aux->prox = (*l);
			*l = aux;
		}
		else{
			aux->prox = anterior->prox;
			anterior->prox = aux;
		}
	}
}

void imprime_listase(LISTA *l){
	NO *aux = *l;
	int j = 0;
	while (aux!=NULL){
		if(j==0){
		printf("%s", aux->dados.nome);
		aux=aux->prox;
		j++;
		}
		else{
		printf(" %s", aux->dados.nome);
		aux=aux->prox;
		}
	}
	printf("\n");
}


void destruir_listase(LISTA *l){
	NO *atu = *l;
	while (atu!=NULL){
		*l=atu->prox;
		free(atu);
		atu=*l;
	}
	free(l);
}

int main(){
	CARNE n;
	int casos, i=0;
	
	li = cria_lista();
	
	while(scanf("%d", &casos) != EOF){
		while(i!=casos){
			scanf("%s", n.nome);
			scanf("%d", &n.validade);
			inserir_ordenado(li, n);
			i++;
			}
		imprime_listase(li);
		destruir_listase(li);
		li = cria_lista();
		i = 0;
	}
	return 0;
}


