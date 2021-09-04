#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

typedef struct{
	int topo;
	int dados[MAX];
} Pilha;

Pilha* criarPilha(){
	Pilha *p;
	p = (Pilha*)malloc(sizeof(Pilha));
	if(p != NULL){
		p->topo = 0;
	}
	return p;
}

void destruirPilha(Pilha* p){
	free(p);
}

int estahVaziaPilha(Pilha* p){
	if(p == NULL) return -1;
	else return p->topo == 0;
}

int estaCheiaPilha(Pilha* p){
	if(p == NULL) return -1;
	else return p->topo == MAX;
}

int empilhar(Pilha* p, int c){
	if(p==NULL) return 0;
	if(estaCheiaPilha(p)) return 0;
	p->dados[p->topo] = c;
	p->topo++;
	return 1;
}

int desempilhar(Pilha *p) { 
	int temp;
	if(p != NULL || !estahVaziaPilha(p)){	
		p->topo--;  // Reduz o topo para retirar
		temp = p->dados[p->topo];
		return temp;
	}else{
		return temp;
	}
}

void imprimirDadosPilha(Pilha* p){
	int i;
	if(p != NULL){
		if(!estahVaziaPilha(p)){
			for(i=p->topo-1; i>=0; i--){
				printf("%d", p->dados[i]);
			}
		}else{
			printf("Pilha esta vazia!\n");
		}
	}else{
		printf("Pilha nao foi criada!\n");
	}
}

void copiarpilha(Pilha *pi1, Pilha *pi2){
	while(!estahVaziaPilha(pi1)){
		empilhar(pi2, desempilhar(pi1));	
	}
}


int main(){
	int val, cont, quantdescarte = 0, cartatemp, cont2=1, cont3=0;	
	int descarte[49];
	
	Pilha *p1, *p2;
	p1 = criarPilha();
	p2 = criarPilha();
	
	scanf("%d", &val);
	while(val != 0){
		cont = val;
		while(cont >= 1){
			empilhar(p1, cont);
			cont--;
		}
		while(cont2 < val){
		descarte[quantdescarte] = desempilhar(p1);
		quantdescarte++;
		cartatemp = desempilhar(p1);
		
		copiarpilha(p1, p2);
		empilhar(p2, cartatemp);
		copiarpilha(p2, p1);
		cont2++;
		}
		printf("Discarded cards: ");
		while(cont3 != val-1){
			if(cont3 != val-2){
		printf("%d", descarte[cont3]);
		printf(", ");
		cont3++;
			}
			else{
				printf("%d", descarte[cont3]);
				cont3++;
			}
		}
		printf("\nRemaining card: ");
		imprimirDadosPilha(p1);
		printf("\n");
		desempilhar(p1);
		quantdescarte = 0;
		cont2 = 1;
		cont3 = 0;
		scanf("%d", &val);
	}
	return 0;
}
