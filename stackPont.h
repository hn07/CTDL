#include "stackPont.h"
typedef List Stack;

void makeNullStack(Stack *pS){
	makeNullList(pS);
}
int emptyStack(Stack S){ 
	return emptyList(S);
}

void push(ElementType X, Stack *pS){
		insertList (X, first (*pS), pS);
}

void pop (Stack *pS){	
	deleteList (first (*pS), pS);
}
ElementType top (Stack S){	
	retrieve(first (S), S);
}
void printStack(Stack S){
	while (!emptyStack(S)){
		printf("%d ",top(S));
		pop(&S);
	}	
}



