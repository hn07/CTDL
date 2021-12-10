#include "CAQueue.h"
void readQueue(Queue *pQ){
	int n, i;
	ElementType X;
	printf("cho biet so luong phan tu can nhap vao ");
	scanf("%d", &n);
	for(i= 1; i<= n; i++){
		printf("nhap phan tu thu  %d ", i);
		scanf("%d", &X);
		enQueue(X,pQ);
	}
}

void printQueue(Queue Q){
	printf("cac phan tu trong hang \n ");
	while(!emptyQueue(Q)){
		printf(" %d ", frontQ(Q));
		deQueue(&Q);
	}
	
}
int main(){
	Queue Q;
	makenullQueue(&Q);
	readQueue(&Q);
	printQueue(Q); 
	return 0;
}
