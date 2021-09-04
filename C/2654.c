include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Bruno Racobaldo, Alexandre Magno, Rafael Luna

typedef struct{
	char nome[101];
	int poder;
	int kills;
	int deaths;
} GOD;

typedef struct no{
	GOD dados;
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

void inserir_ordenado(LISTA* l, GOD y){
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
	if(atual->dados.poder != y.poder){
	while(atual != NULL && atual->dados.poder > y.poder){
		anterior = atual;
		atual = atual->prox;
		}	
		}
	else if(atual->dados.poder == y.poder && atual->dados.kills != y.kills){
		while(atual != NULL && atual->dados.kills > y.kills){
		anterior = atual;
		atual = atual->prox;
		}
	}
	else if(atual->dados.poder == y.poder && atual->dados.kills == y.kills && atual->dados.deaths != y.deaths){
		while(atual != NULL && atual->dados.deaths < y.deaths){
		anterior = atual;
		atual = atual->prox;
		}
	}
	else if(atual->dados.poder == y.poder && atual->dados.kills == y.kills && atual->dados.deaths == y.deaths){
		if(strcmp(atual->dados.nome, y.nome) < 0){
		anterior = atual;
		atual = atual->prox;
		}
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
	while (aux!=NULL){
		printf("%s", aux->dados.nome);
		aux->prox = NULL;
		aux=aux->prox;
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
	GOD n;
	int casos, i=0;
	
	li = cria_lista();
	
	scanf("%d", &casos);
		while(i!=casos){
			scanf("%s", n.nome);
			scanf("%d %d %d", &n.poder, &n.kills, &n.deaths);
			inserir_ordenado(li, n);
			i++;
			}
		imprime_listase(li);
	return 0;
}
