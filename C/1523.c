#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10001

typedef struct{
    int entrada;
    int saida;
} Veiculos;

typedef struct{
	int topo;
	Veiculos dados[MAX];
} Pilha;

Pilha* criarPilha(){
		Pilha *p;
		p = (Pilha*)malloc(sizeof(Pilha));
		if(p != NULL){
			p->topo = 0;
		}
	return p;
}

int estahVaziaPilha(Pilha* p){
	if(p == NULL) return -1;
	else return p->topo == 0;
}

int estaCheiaPilha(Pilha* p){
	if(p == NULL) return -1;
	else return p->topo == MAX;
}

int empilhar(Pilha* p, Veiculos v){
	if(p==NULL) return 0;
	if(estaCheiaPilha(p)) return 0;
	p->dados[p->topo] =v;
	p->topo++;
	return 1;
}

Veiculos desempilhar(Pilha *p) { 
	Veiculos temp;
	if(p != NULL || !estahVaziaPilha(p)){	
		p->topo--;
		temp = p->dados[p->topo];
		return temp;
	}else{
		return temp;
	}
}

Veiculos v;
Pilha *p1;
int main(){
	int quantve, quantva, nvagas, nve, topof, valido=1;
	
	p1 = criarPilha();
	scanf("%d %d", &quantve, &quantva);
	while(quantve != 0 && quantva != 0){
	nvagas = quantva;
	nve = quantve;
	while(nve != 0){
		scanf("%d %d", &p1->dados[p1->topo].entrada, &p1->dados[p1->topo].saida);
		nvagas = quantva;
		p1->topo++;
		topof = p1->topo-1;
		if(quantva>quantve){
		while(topof != 0){
			if(topof==0){
				break;
			}
			if(p1->dados[topof-1].saida > p1->dados[p1->topo-1].entrada && p1->dados[topof-1].saida <= p1->dados[p1->topo-1].saida){
			valido = 0;	
			}
			topof--;
		}
		}
		else{
		while(topof != 0){
			if(topof==0){
				break;
			}
			if(p1->dados[p1->topo-1].entrada < p1->dados[topof-1].saida){
			 nvagas--;
			}
			if(p1->dados[topof-1].saida > p1->dados[p1->topo-1].entrada && p1->dados[topof-1].saida <= p1->dados[p1->topo-1].saida){
			valido = 0;	
			}
			if(nvagas==0){
			valido = 0;	
			}
			topof--;
			}
		}
			nve--;
	}
	if(valido==1){
		printf("Sim\n");
	}
	else{
		printf("Nao\n");
	}
	valido = 1;
	nve=0;
	nvagas=0;
	scanf("%d %d", &quantve, &quantva);
	free(p1);
	p1 = criarPilha();
	}

	
	return 0;
}
