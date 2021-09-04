#include <stdio.h>
#include <string.h>
int main(){
    int N, i, met_palavra, g, tam, j, tamtotal, cont_met;
    char palavras[102], y[102];
    //Alexandre Magno Pinho Correia de Oliveira, Pedro Henrique Barros de Oliveira Sousa, Rafael Miranda Pinho Luna
    scanf("%d", &N);
    for(i=1;i <= N;i++){
        scanf("%s", &palavras);
        
        tamtotal = strlen(palavras);
        met_palavra = tamtotal / 2;
        cont_met = 0;
        
        for(g=met_palavra - 1;g>= 0;g--){ 
        
         y[cont_met] = palavras[g];
            cont_met++;
            
        }
        cont_met = met_palavra;
        for(j = tamtotal - 1;j >= met_palavra; j--){
            y[cont_met] = palavras[j];    
            cont_met++;
            
        }
        
        y[tamtotal] = '\0';
        printf("%s\n", y);        
    
 	}
	 }   
