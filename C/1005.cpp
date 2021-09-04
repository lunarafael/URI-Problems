#include <stdio.h>
 
int main() {
double A, B, nf;
 
scanf("%lf %lf", &A, &B);

 A = A*3.5;
 B = B*7.5;
 nf = (A+B)/11;
 
 printf("MEDIA = %.5lf\n", nf);
    return 0;
}
