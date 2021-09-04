#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 52

typedef struct{
	char letras[2501];
} Palavra;

Palavra criarpalavra(char* letras){
	Palavra p;
	strcpy(p.letras, letras);
}

typedef struct{
	int cont;
	Palavra dados[MAX];
} Lista;

Lista* criarLista(){
	Lista *l;
	l = (Lista*)malloc(sizeof(Lista));
	if(l != NULL){
		l->cont = 0;
	}
	return l;
}

int tamanhoLista(Lista* l){
	if(l == NULL) return -1;
	else return l->cont;		
}

void imprimirPalavra(Palavra p){
	printf("%s", p.letras);
}

int estahVaziaLista(Lista* l){
	if(l == NULL) return -1;
	else return l->cont == 0;
}

int estaCheiaLista(Lista* l){
	if(l == NULL) return -1;
	else return l->cont == MAX;
}



int inserirOrdenado(Lista* l, Palavra p){
	int i, posicao, valor;
	if(l==NULL) return 0;
	if(estaCheiaLista(l)) return 0;
	if(estahVaziaLista(l)) 
		posicao = 0;
	else{
		for(i=l->cont-1; i>=0 && (strlen(l->dados[i].letras) < strlen(p.letras)); i--){
			l->dados[i+1] = l->dados[i];
		}
		posicao = i+1;
	}
	l->dados[posicao] = p;
	l->cont++;
	return 1;
}


void imprimirDadosLista(Lista* l){
	int i;
	if(l != NULL){
		if(!estahVaziaLista(l)){
			for(i=0; i<l->cont; i++){
				if(i>0){
					printf(" ");
				}
				imprimirPalavra(l->dados[i]);
			}
		}
	}
}
Lista *li;
void iniciar(){
	li = criarLista();	
}

Palavra p;
int main(){
	int casos;

scanf(" %d", &casos);	
while(casos != 0){
	iniciar();
	scanf(" %[^\n]s", &p.letras);
	char * tok = strtok(p.letras, " ");
		while(tok != NULL){
		strcpy(p.letras, tok);
		inserirOrdenado(li, p);
		tok= strtok(NULL, " ");
   	}
	imprimirDadosLista(li);
	printf("\n");
	free(li);
   	casos--;
}	
	return 0;
}
