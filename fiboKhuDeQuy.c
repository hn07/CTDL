#include "stackmang.h"

int fibo(int n){
	Stack S;
	makeNullStack(&S);
	int fResult=0;
	ElementType temp;
	push(n,&S);
	
	while(!emptyStack(S)){
	temp = top(S);
	pop(&S);
		if(temp==0||temp==1){
			fResult++;
		
		} 
		else{
			
			push(temp-1,&S);
			push(temp-2,&S);
		}
	} 
	return fResult;
}


int main(){

	int k =15;
	printf("fibo(%d) = %d\n",k,fibo(k));
}
