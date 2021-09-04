#include <stdio.h>
//Alexandre Magno Pinho Correia de Oliveira, Pedro Henrique Barros de Oliveira Sousa, Rafael Miranda Pinho Luna

int main(){
 int a, b, testes, conttest, result;
 char caracter;
 
 scanf("%d", &testes);
 
 while(conttest != testes){
	scanf("%d%c%d", &a, &caracter, &b);
	
	if(a==b){
		result = a*b;
		conttest++;
		printf("%d\n", result);
	}
	
	else if(caracter == 'A' || caracter == 'B' || caracter == 'C' || caracter == 'D' || caracter == 'E' || caracter == 'F' || caracter == 'G' || caracter == 'H' || caracter == 'I' || caracter == 'J' || caracter == 'K' || caracter == 'L' || caracter == 'M' || caracter == 'N' || caracter == 'O' || caracter == 'P' || caracter == 'Q' || caracter == 'R' || caracter == 'S' || caracter == 'T' || caracter == 'U' || caracter == 'V' || caracter == 'W' || caracter == 'X' || caracter == 'Y' || caracter == 'Z'){
 	result = b-a;
 		conttest++;
		printf("%d\n", result);
		 }
	else{
		result = a+b;
		conttest++;
		printf("%d\n", result);
	}
	}
 
    return 0;
}
