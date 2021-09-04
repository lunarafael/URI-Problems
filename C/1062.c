#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Alexandre Magno, Bruno Racobaldo, Rafael Luna


typedef struct no{
	int vagao;
	struct no *prox;
} NO;

typedef NO* PILHA;

PILHA* criar_pilha(){
	PILHA *pi = (PILHA*) malloc(sizeof(PILHA));
	if(pi != NULL){
		*pi = NULL;
	}
	return pi;
}

int empilhar(PILHA *p, int c){
	if(p == NULL) return 0;
	NO *novo_no = (NO*) malloc(sizeof(NO));
	if(novo_no == NULL) return 0;
	
	novo_no->vagao = c;
	novo_no->prox = NULL;
	if((*p) == NULL){
		*p = novo_no;
	}else{
		novo_no->prox = *p;
		*p = novo_no;
	}
	return 1;	
}

int desempilhar(PILHA *p){
	NO *topo = *p;
	
	if(topo != NULL){
		*p = topo->prox;
		free(topo);
		 
		 return 1;
	}else{
		return 0;
	}
}

int pilha_vazia(PILHA *p){
	if(p == NULL) return 1;
	if(*p == NULL) return 1;
	return 0;
}


PILHA *p, *p2;
int main(){
	int nveic=1, i, k, incorreto = 0;
	p=criar_pilha();
	p2=criar_pilha();
	
	while(nveic!=0){
	
	scanf("%d", &nveic);
	if(nveic==0) break;
	int input[nveic];
	while(1){
	for(i=nveic;i>0;i--){
		empilhar(p, i);
	}
	
	
	for(k=0;k<nveic;k++){
		scanf("%d", &input[k]);
		if(input[k]==0){
		printf("\n");
		break;
		}
	}
	if(input[k-1]==0){
	free(p);
	p=criar_pilha();
	break;	
	}
	i = 0;
	while((*p) != NULL || ((*p2) != NULL && i<nveic)){
		if((*p)!= NULL && (*p)->vagao == input[i]){
			desempilhar(p);
			i++;
		}
		else if((*p2)!= NULL && (*p2)->vagao == input[i]){
			desempilhar(p2);
			i++;
		}
		else if(!pilha_vazia(p)){
			empilhar(p2, (*p)->vagao);
			desempilhar(p);
		}
		else{
			incorreto++;
			break;
		}
	}
	if(incorreto!=0){
		printf("No\n");
	}
	else{
		printf("Yes\n");
	}
	free(p2);
	free(p);
	p=criar_pilha();
	p2=criar_pilha();
	incorreto = 0;
	}
	}
	return 0;
}
