#include <stdio.h>
#include <string.h>
int main(){
    int N, g, tam_palavra;
    char palavras[26], obi[4] = {'O','B','I','\0'}, uri[4] = {'U','R','I','\0'}, palavras1[4];
    //Alexandre Magno Pinho Correia de Oliveira, Pedro Henrique Barros de Oliveira Sousa, Rafael Miranda Pinho Luna
    scanf("%d", &N);
    for(g=1;g<=N;g++){
    scanf("%s", palavras);

    tam_palavra = strlen(palavras);

    if(tam_palavra == 3){
        if(palavras[0] == 'O' && palavras[1] == 'B'){
            strcpy(palavras,obi);
        }
        if(palavras[0] == 'U' && palavras[1] == 'R'){
            strcpy(palavras,uri);
        }
        printf("%s", palavras);
        printf(" ");
    }else{
        printf("%s", palavras);
        printf(" ");
    }
    }
    printf("\n");

    return 0;
}
