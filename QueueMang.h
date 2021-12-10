#include <stdio.h>
#define MaxSize 300

typedef struct{
	int Data[MaxSize];
	int Front , Rear;
}Queue;

void makeNullQueue( Queue *pQ){
	pQ -> Front = pQ->Rear  = 0;
}

int emptyQueue( Queue Q){
	return Q.Front == Q.Rear;
}

int fullQueue(Queue Q){
	return (Q.Rear +1 )% MaxSize == Q.Front;
}

void enQueue(int x, Queue *pQ){
	if(!fullQueue(*pQ)){
		pQ -> Data[pQ -> Rear] = x;
		pQ -> Rear = (pQ->Rear+1) % MaxSize;
	}
}

void deQueue(Queue *pQ, int *pTop){
	if(!emptyQueue(*pQ)){
		(*pTop)= pQ -> Data[ pQ -> Front ];
		pQ -> Front = (pQ -> Front + 1)% MaxSize;
		
	}
}


void printQueue(Queue *pQ){
	while(!emptyQueue(*pQ) ){
		int top;
		deQueue(pQ, &top) ;
		printf("%d\t", top);
	}
	printf("\n");
}











