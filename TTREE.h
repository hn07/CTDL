#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef int TData;
struct TNode{
	TData Data;
	struct TNode *Left, *Right;
};
typedef struct TNode *TTree;

void makenullTree(TTree *pT){
	*pT = NULL;
}
int emptyTree(TTree T){
	return T==NULL;
}

TTree leftChild(TTree n){
	if (n!=NULL)
	return n->Left;
	else
	return NULL;
}
TTree rightChild(TTree n){
	if(n!= NULL)
	return n->Right;
	else
	return NULL;
}
int isLeaf(TTree n){
	if(n!= NULL){
		return (leftChild(n)==NULL)&& (rightChild(n)==NULL);
	}
		else return 0;
}
void preOrder(TTree T){
	printf("%c ", T->Data);
	if(leftChild(T)!= NULL);
	preOrder(leftChild(T));
	if(rightChild(T)!=NULL){
	preOrder(rightChild(T));
	}
}

void inOrder(TTree T){
	if(leftChild(T)!=NULL)
	inOrder(leftChild(T));
	printf("%c", T->Data);
	if(rightChild(T)!= NULL)
	inOrder(rightChild(T));
}

void posOrder (TTree T){
	if(leftChild(T)!= NULL)
	posOrder(leftChild(T));
	if(rightChild(T)!= NULL)
	posOrder(rightChild(T));
	printf("%c", T->Data);
}

int nb_nodes(TTree T){
	if(emptyTree( T ))
	return 0;
	else 
	return 1 + nb_nodes(leftChild(T))+nb_nodes(rightChild(T));
}

TTree Create2(TData v, TTree l, TTree r){
	TTree N;
	N= (struct TNode*)
	malloc(sizeof (struct TNode));
	N->Data = v;
	N->Left= l;
	N->Right = r;
	return N;
}














