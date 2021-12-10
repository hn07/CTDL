#include "stackmang.h"

void duaVaoNganXep(int n, Stack *S){
	while(n!= 0){
		int  i;
		i = n % 2;
		push(i,S);
		n = n / 2;
	}
}
int xuat(Stack *pS ){
	while(!emptyStack(*pS)){
		top(*pS);
		printStack(*pS);
		return 0;
	}
}


int main(){
	Stack S;
	makeNullStack(&S);
	int n;
	printf("hay nhap vao mot so can chuyen nhi Phan ");
	scanf("%d", &n);
	duaVaoNganXep(n, &S);
	xuat(&S);
}
