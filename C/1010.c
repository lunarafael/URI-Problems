#include <stdio.h>

int main(){
int l=1, r=1, s;
	
while(l!=0 && r!=0){
	scanf("%d", &l);
	scanf("%d", &r);
	
	s = l + r;
	if(s==0){
		break;
	}
	printf("%d\n", s);
	s = 0;	
	}
	return 0;
}
