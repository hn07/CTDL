#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BALANCE 0
#define LEFT 1
#define RIGHT 2
typedef int KeyType;

typedef struct AVLNode{	
   	KeyType key;
    int bal;
    int height;
    struct AVLNode *Left;
    struct AVLNode *Right;
}AVLNode;

typedef AVLNode *AVLTree;

void MakeNullTree(AVLTree *T){ 
			(*T)=NULL; 
}
//tim gia tri lon nhat cua 2 so
int find_max(int a, int b) {
  return (a > b) ? a : b;
}
//Ham tao nut co khoa x, chieu cao =0, con trai va con phai NULL

AVLNode* create_node(KeyType key) {
  AVLNode* new_node = (AVLNode* )
    malloc(sizeof(AVLNode));
  new_node->key = key;
  new_node->Left = NULL;
  new_node->Right = NULL;
  new_node->height = 1;
  return (new_node);
}

int height(AVLNode *node){
if (node == NULL)
    return 0;
  return node->height;
}


AVLNode *rotateLeft(AVLNode *x){
	AVLNode *y = x->Right ;
	AVLNode *T2 = y->Left ;
	y->Left  = x;
	x->Right  = T2;
	x->height = find_max(height(x->Left ), height(x->Right )) + 1;
	y->height = find_max(height(y->Left ), height(y->Right )) + 1;
  return y;
}

AVLNode *rotateRight(AVLNode *y){
	AVLNode *x = y->Left;
	AVLNode *T2 = x->Right ;
	x->Right  = y;
	y->Left  = T2;
	y->height  = find_max(height(y->Left ), height(y->Right )) + 1;
	x->height = find_max(height(x->Left ), height(x->Right )) + 1;
  return x;
}

AVLNode* rotateLeftRight(AVLNode *Node){
	AVLNode* T1 = Node->Left;
	AVLNode* T2 = T1->Right;
	Node ->Left = T2->Right;
	T2->Right = Node ;
	T1->Right = T2->Left;
	T2->Left = T1;
	switch(T2->bal)
	{
	case LEFT: Node->bal = RIGHT;
		T1->bal = BALANCE;break;
	case BALANCE:Node->bal = BALANCE;
		T1->bal = BALANCE;break;
	case RIGHT: Node->bal = BALANCE;
		T1->bal = LEFT ;break;
	}
	T2->bal = BALANCE;
	Node= T2;
}

AVLNode* rotateRightLeft(AVLNode *Node){
	AVLNode* T1 = Node->Right;
	AVLNode* T2 = T1->Left;
	Node->Right = T2->Left;
	T2->Left = Node ;
	T1->Left = T2->Right;
	T2->Right = T1;
	switch(T2->bal)
	{
	case RIGHT: Node->bal = LEFT;
		T1->bal = BALANCE;break;
	case BALANCE:Node->bal = BALANCE;
		T1->bal = BALANCE;break;
	case LEFT: Node->bal = BALANCE;
		T1->bal = RIGHT ;break;
	}
	T2->bal = BALANCE;
	Node= T2;
}

AVLNode* createNode(int data)
{
	AVLNode* p;
	p = new AVLNode;
	if(p==NULL) return NULL;
	p->key=data;
	p->Left=NULL;
	p->Right=NULL;
	p->bal=0;
	return p;
}
//Hhe so can bang
int balanceLeft(AVLNode *Nod) {
  if (Nod == NULL)
    return 0;
  return height(Nod->Left ) - height(Nod->Right );
}
AVLNode *insertNode(AVLNode *node, KeyType key ){
	//Tim vi tri thich hop de them nut
  if (node == NULL)
    return (create_node(key));
  if (key< node->key)
    node->Left  = insertNode(node->Left , key);
  else if (key > node->key)
    node->Right  = insertNode(node->Right , key);
  else
    return node;
    
  //cap nhat he so can bang va can ban cay
  node->height = 1 + find_max(height(node->Left ),
               height(node->Right ));
  int balance  = balanceLeft(node);
  if (balance > 1 && key < node->Left ->key)
    return rotateRight(node);
  if (balance < -1 && key > node->Right ->key)
    return rotateLeft(node);
  if (balance > 1 && key > node->Left->key) {
    node->Left  = rotateLeft(node->Left );
    return rotateRight(node);
  }
  if (balance < -1 && key < node->Right ->key) {
    node->Right  = rotateLeft (node->Right );
    return rotateLeft (node);
  }
  return node;
}

void preOrder(AVLNode *T){
if(T != NULL){
	printf("%d %d %d \n", T->key, T->bal , T->height);
	preOrder(T->Left );
	preOrder(T->Right);
	}	
}

void inOrder(AVLNode *T){
if(T != NULL){	
	inOrder(T->Left );
	printf("%d %d %d \n", T->key, T->bal , T->height);
	inOrder (T->Right);
	}	
}

void PosOrder(AVLNode *T){
if(T != NULL){
	PosOrder (T->Right);
	PosOrder (T->Left );
	printf("%d   %d   %d \n", T->key, T->bal , T->height);
	}	
}

void  levelOrder(AVLTree root){
	
}
int main(){
	AVLNode *root = NULL;
	root = insertNode(root, 20);
	root = insertNode(root, 24);
	root = insertNode(root, 15);
	root = insertNode(root, 21);
	root = insertNode(root, 19);
	root = insertNode(root, 2);
	root = insertNode(root, 29);
	printf("in cay theo thu tu NLR \n");
	preOrder(root);
	printf("in cay theo thu tu LNR \n");
	inOrder(root);
	printf("in cay theo thu tu RLN \n");
	PosOrder(root);
	
			
}
