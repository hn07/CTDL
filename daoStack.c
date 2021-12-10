#include "stackmang.h"
#include "QueuebangMang.h"
void nhapStack(Stack *pS){
  	int n,i;
    ElementType x;
 
  printf("nhap vao so luong pt: ");
  scanf("%d",&n);
  for(i=1;i<=n;i++){
   printf("nhap gia tri a[%d]: ",i);
   scanf("%d",&x);
   push(x,&*pS);
  }
}

void daoStack(Stack *S, Queue Q){
	makeNullQueue( &Q);
	
	while(!emptyStack(*S)){
		int temp = top(*S);
		enQueue( temp, &Q);
		pop( S );
	}
	while(!emptyQueue( Q )){
		push(front(Q),S);
		deQueue(&Q);
	}
	
}
void daoQueue(Stack S, Queue *Q){
	makeNullStack(&S);
	while(!emptyQueue(*Q) ){
		int temp = front(*Q) ;
		push(temp,&S);
		deQueue(Q);
	}
	while(!emptyStack(S)){
		enQueue( top(S),&*Q);
		pop( &S );
	}

}

/*void  nhapStack(Stack *pS){
	int n, i;
	ElementType X;
	MakeNull_Stack(pS);
	printf("co bao nhieu so nguyen ?"); scanf("%d", &n);
	for(i=0; i<n; i++) {
		printf("nhap so thu %d: ", i+1); scanf("%d", &X);
		Push(X,pS);
	}
}

void daoStack(Stack *pS){
	Queue Q;
	
    
	makeNullQueue(&Q);
	while(!Empty_Stack(*pS)) {
		enQueue(Top(*pS), &Q);
		Pop(pS);
	}
	while(!emptyQueue(Q)){
		Push(front(Q),pS);
		deQueue(&Q);
	}
}
*/
int main(){
	Stack S;
	makeNullStack(&S);
	Queue Q;
	
	printf("hay nhap vao mang ");
	nhapStack(&S);
	printStack(S);
	daoStack(&S,Q);
	printf("sau khi dung ham daoStack ");
	printStack(S);
}
