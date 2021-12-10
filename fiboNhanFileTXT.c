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
void fibo_onfile(Stack *pS){
  int n,i;
  ElementType x;
  FILE *g;
  g=fopen("fibo.txt","r");
 
  //makeNullList(S);
  printf("nhap vao so luong pt: ");
  fscanf(g,"%d",&n);
  printf("%d \n",n);
  for(i=1;i<=n;i++){
   printf("nhap gia tri a[%d]: ",i);
   fscanf(g,"%d",&x);
   printf("%d\n",x);
  	printf("fibo(%d) = %d\n",x,fibo(x));
  }
   

  fclose(g);
}
int main(){
	Stack S;
	makeNullStack(&S);
	fibo_onfile(&S);
	
}
