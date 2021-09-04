#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Bruno Racobaldo, Alexandre Magno, Rafael Luna

typedef struct{
	char nome[101];
	int peso;
	int idade;
	float altura;
	int cont;
} RENA;

typedef struct no{
	RENA dados;
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

int inserir_ordenado(LISTA* l, RENA y){
    if(l==NULL)return 0;
    NO *novo_no = (NO*)malloc(sizeof(NO));
    if(novo_no==NULL)return 0;
    novo_no->dados = y;
    novo_no->prox = NULL;
    if((*l)==NULL)
        *l = novo_no;
    else{
        NO *aux = *l;
        NO *ant = NULL;
        while(aux != NULL && aux->dados.peso > novo_no->dados.peso){
            ant = aux;
            aux = aux->prox;
        }
    	if(aux != NULL && aux->dados.peso == novo_no->dados.peso){
    	NO *c2 = ant;
    	while(aux != NULL && aux->dados.peso == novo_no->dados.peso && aux->dados.idade < novo_no->dados.idade){
            c2 = aux;
            aux = aux->prox;
        }
        if(aux != NULL && aux->dados.idade == novo_no->dados.idade){
        NO *c3 = c2;
        while(aux != NULL && aux->dados.peso == novo_no->dados.peso && aux->dados.idade == novo_no->dados.idade && aux->dados.altura < novo_no->dados.altura){
            c3 = aux;
            aux = aux->prox;
        }
		if(aux != NULL && aux->dados.altura == novo_no->dados.altura){
		NO *c4 = c3;
		while(aux != NULL && aux->dados.peso == novo_no->dados.peso && aux->dados.idade == novo_no->dados.idade && aux->dados.altura == novo_no->dados.altura && strcmp(aux->dados.nome, novo_no->dados.nome)<0){
            c4 = aux;
            aux = aux->prox;
        }
        if(c4==NULL)
            *l = novo_no;
        else{
            c4->prox = novo_no;
        }
        novo_no->prox = aux;
        return 1;
		}
		if(c3==NULL)
            *l = novo_no;
        else{
            c3->prox = novo_no;
        }
        novo_no->prox = aux;
        return 1;
		}
		if(c2==NULL)
            *l = novo_no;
        else{
            c2->prox = novo_no;
        }
        novo_no->prox = aux;
        return 1;
		}
        if(ant==NULL)
            *l = novo_no;
        else{
            ant->prox = novo_no;
        }
        novo_no->prox = aux;
    }
    return 1;    
}

void imprime_listase(LISTA *l, int nmain){
	NO *aux = *l;
	int h = 1;
	while (aux!=NULL){
		printf("%d - %s\n", h, aux->dados.nome);
		aux=aux->prox;
		h++;
		nmain--;
		if(nmain == 0){
		break;
		}
		}
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
	RENA n;
	int casos, nrena, npass, i=0, k=0, w=1;
	li = cria_lista();
	
	scanf("%d", &casos);
		while(i!=casos){
		scanf("%d %d", &nrena, &npass);
			while(nrena!=k){
			scanf("%s", n.nome);
			scanf("%d %d %f", &n.peso, &n.idade, &n.altura);
			inserir_ordenado(li, n);
			k++;
			}
			i++;
			printf("CENARIO {%d}\n", w);
			w++;
			imprime_listase(li, npass);
			destruir_listase(li);
			li = cria_lista();
			k = 0;
			}
	return 0;
}