#include "stackmang.h"
int th(int k,int n){
	Stack K,N;
	makeNullStack(&K); makeNullStack(&N);
	int cResult=0;
	push(k,&K); push(n,&N);
	ElementType tempk,tempn;
	while(!emptyStack(K)){
		tempk=top(K); tempn=top(N);
		pop(&K); pop(&N);
		if(tempk==0||tempn==tempk){
			cResult++;
		}
		else{
			push(tempk-1,&K); push(tempn-1,&N);
			push(tempk,&K); push(tempn-1,&N);
		}
	}
	return cResult;
}
void tohop_onfile(Stack *pK , Stack *pN){
  int n,i;
  ElementType x;
  ElementType y;
  FILE *g;
  g=fopen("tohop.txt","r");
 
  //makeNullList(S);
  printf("nhap vao so luong pt: ");
  fscanf(g,"%d",&n);
  printf("%d \n",n);
  for(i=1;i<=n;i++){
   printf("nhap gia tri a[%d]: ",i);
   fscanf(g,"%d",&x);
   fscanf(g,"%d",&y);
   printf("%d ",x);
   printf("%d\n",y);
  	printf("th(%d %d) = %d\n",x,y,th(x,y));
  }
   

  fclose(g);
}
int main(){
	int k, n;
	k=2;
	n=10;
	printf("th(%d, %d) = %d test kq \n",k, n, th(k,n));

	Stack K,N;
	makeNullStack(&K);
	makeNullStack(&N);
	tohop_onfile(&K,&N);
}
