#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main()
{
    char frase[101], temporario[101], maiorpal[101]; 
    int mpal= 0,  quantpal[101], l, u, k, carac, i;
    
    //Alexandre Magno Pinho Correia de Oliveira, Pedro Henrique Barros de Oliveira Sousa, Rafael Miranda Pinho Luna
    while(1){
        gets(frase);
        if(frase[0] == '0'){
            break;
        }
        l=0;
        k=0;
        u=0;
        carac= 0;
        while(frase[l]){
            
            while(1){
                if(frase[l] == ' ' || frase[l] == '\0'){
                    break;
                }
                temporario[k++] = frase[l++];
                carac++;
                
            }
            
            temporario[k] = '\0';
            quantpal[u++] = carac;
            
            if(carac >= mpal){
                mpal = carac;
             strcpy(maiorpal, temporario);
                
            }            
            
            if(frase[l] == ' '){
                l++;
            }
            
            k=0;
            carac=0;
                
        }
        for(i=0; i < u; i++ ){
            if(i!=0){
            printf("-");
            }
            printf("%d", quantpal[i]);
            
        }
            printf("\n");
        
        
    }
        printf("\n");
        printf("The biggest word: %s\n", maiorpal);
    return 0;

}