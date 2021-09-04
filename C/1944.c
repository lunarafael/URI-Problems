#include <stdio.h>
#include <stdlib.h>

int main(){
char padrao[4] = {'F', 'A', 'C', 'E'};    
int brindes = 0, num, i = 0, j = 4;
char l1[2], l2[2], l3[2], l4[2];


scanf("%d", &num);
while(i != num){
scanf("%s%s%s%s", l4, l3, l2, l1);

if(l1[0] == padrao[j-4] && l2[0] == padrao[j-3] && l3[0] == padrao[j-2] && l4[0] == padrao[j-1]){
	j = j-4;
    brindes++;
    padrao[0] = 'F';
    padrao[1] = 'A';
    padrao[2] = 'C';
    padrao[3] = 'E';
    }
    
else if(l4[0] == 'E' && l3[0] == 'C' && l2[0] == 'A' && l1[0] == 'F'){
    brindes++;
    padrao[0] = 'F';
    padrao[1] = 'A';
    padrao[2] = 'C';
    padrao[3] = 'E';
}
	
else{
    padrao[j] = l4[0];
    j++;
    padrao[j] = l3[0];
    j++;
    padrao[j] = l2[0];
    j++;
    padrao[j] = l1[0];
    j++;
}
	i++;
}
printf ("%d\n", brindes);

return 0;
}
