#include <stdio.h>
 
int main() {
int A, B, C, D, dif;
 
scanf("%d %d %d %d", &A, &B, &C, &D);

A = A*B;
C = C*D;
dif = A-C;
printf("DIFERENCA = %d\n", dif);
    return 0;
}
