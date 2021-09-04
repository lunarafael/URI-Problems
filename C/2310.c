#include <stdio.h>
//Alexandre Magno Pinho Correia de Oliveira, Pedro Henrique Barros de Oliveira Sousa, Rafael Miranda Pinho Luna

int main(){
int numjog, cont;
double ps, pb, pa, s, b, a, s1, b1, a1, ts, tb, ta, ts1, tb1, ta1;
char nome[100];

ts = 0;
tb = 0;
ta = 0;
ts1 = 0;
tb1 = 0;
ta1 = 0;

scanf("%d", &numjog);
cont = 0;

while(cont != numjog){
    scanf("%s", nome);
    
    scanf("%lf%lf%lf", &s, &b, &a);
    
    scanf("%lf%lf%lf", &s1, &b1, &a1);
    
    ts = ts + s;
    tb = tb + b;
    ta = ta + a;
    
    ts1 = ts1+s1;
    tb1 = tb1+b1;
    ta1 = ta1+a1;
    
    cont++;
}

    ps = (ts1/ts)*100;
    pb = (tb1/tb)*100;
    pa = (ta1/ta)*100;
    
    printf("Pontos de Saque: %.2lf %%.\n", ps);
    printf("Pontos de Bloqueio: %.2lf %%.\n", pb);
    printf("Pontos de Ataque: %.2lf %%.\n", pa);
    
    return 0;
}
