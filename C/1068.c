#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 10001

typedef struct{
	int topo;
	char dados[MAX];
} Pilha;

Pilha* criarPilha(){
		Pilha *p;
		p = (Pilha*)malloc(sizeof(Pilha));
		if(p != NULL){
			p->topo = 0;
		}
	return p;
}

int estaCheiaPilha(Pilha* p){
	if(p == NULL) return -1;
	else return p->topo == MAX;
}

int estahVaziaPilha(Pilha* p){
	if(p == NULL) return -1;
	else return p->topo == 0;
}



int empilhar(Pilha* p, char k){
	if(p==NULL) return 0;
	if(estaCheiaPilha(p)) return 0;
	p->dados[p->topo] = k;
	p->topo++;
	return 1;
}

int desempilhar(Pilha *p) { 
	char t;
	if(p != NULL || !estahVaziaPilha(p)){	
		p->topo--;
		t = p->dados[p->topo];
		return t;
	}else{
		return t;
	}
}

Pilha *p1;
int main(){
int cont = 0;
int wrong = 0, x = 0;
	p1 = criarPilha(p1);
	while(scanf(" %[^\n]s", p1->dados)!= EOF){	
	while(p1->dados[cont] != '\0'){
			if(p1->dados[cont] == ')' && estahVaziaPilha(p1))
			{
				x = 1;
				break;
			}
			else if(p1->dados[cont] == ')'){
				p1->dados[cont] = 'x';	
				desempilhar(p1);				
				}
			else if(p1->dados[cont] == '('){
				empilhar(p1, p1->dados[cont]);
				}
			cont++;	
			}
	if(x == 1){
		printf("incorrect\n");
		wrong = 1;
		x = 1;
	}
	else if(!estahVaziaPilha(p1) && x!= 1){
		printf("incorrect\n");
		wrong = 1;
	}
	else{
		cont = 0;
		while(p1->dados[cont] != '\0'){
		if(p1->dados[cont] == ')'){
		printf("incorrect\n");
		wrong = 1;
		}
		cont++;
	}
	if(p1->dados[cont] == '\0' && estahVaziaPilha(p1) && wrong == 0){
		printf("correct\n");
		}
	}
	cont = 0;
	wrong = 0;
	x = 0;
	free(p1);
	p1 = criarPilha(p1);
	}
	return 0;
}
