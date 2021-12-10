#include <stdio.h>
#define MaxLength 300
typedef int ElementType;
typedef struct {
	ElementType Element[MaxLength];
	int Front, Rear;
	
}Queue;

void makenullQueue(Queue *pQ){
	pQ->Front = -1;
	pQ->Rear  = -1;
}

int emptyQueue(Queue Q){
	return Q.Front == -1;
}

int fullQueue(Queue Q){
	return (Q.Rear - (Q.Front-1))%MaxLength == 0;
}

ElementType frontQ(Queue Q){
	return Q.Element[Q.Front];
}

void deQueue(Queue *pQ){
	if(pQ -> Front == pQ ->Rear)
	makenullQueue(pQ);
	else
	pQ -> Front = (pQ->Front+1)%MaxLength ;
}

void enQueue(ElementType X, Queue *pQ){
	if(fullQueue(*pQ))
	printf("hang day \n");
	else{
	
	if(emptyQueue(*pQ) ) pQ->Front = 0;
	pQ -> Rear = (pQ ->Rear +1) % MaxLength ;
	pQ -> Element[pQ->Rear]=X;
}
}






















