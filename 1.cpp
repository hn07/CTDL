#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "QueuebangMang.h"
#include "CayTimKiemNhiPhan.h"


#define BALANCE 0
#define LEFT 1
#define RIGHT 2
typedef int KeyType;

typedef struct AVLNode{	
   	KeyType key;
    int bal;
    int height;
    int heightA;
    struct AVLNode *Left;
    struct AVLNode *Right;
}AVLNode;

typedef AVLNode *AVLTree;

void MakeNullavl(AVLTree *T){ 
			(*T)=NULL; 
}
int EmptyAVL(AVLTree AVL){
	return AVL==NULL;
}
AVLTree  LeftChild(AVLTree  n){ 	
		if (n!=NULL) return n->Left;
		else return NULL; 
} 
// xac dinh con phai
AVLTree RightChild(AVLTree  n){	
		if (n!=NULL) return n->Right;
 		else return NULL;
}
int  bal(AVLTree  n){
		if(LeftChild(n)!=NULL && RightChild(n)== NULL )
		return 1 ;
		else if(LeftChild(n)==NULL && RightChild(n) != NULL)
		return 2 ;			
	else return 0;
	} 

//tim gia tri lon nhat cua 2 so
int find_max(int a, int b) {
  return (a > b) ? a : b;
}
//Ham tao nut co khoa x, chieu cao =0, con trai va con phai NULL

AVLNode* create_node(KeyType key) {
  AVLNode* new_node = (AVLNode* ) malloc(sizeof(AVLNode));
  new_node->key = key;
  new_node->Left = NULL;
  new_node->Right = NULL;
  new_node->height = 1;
  return (new_node);
}

int height(AVLNode *T){
if (T == NULL)
        return 0;
    else {
	int a, b;
	if(!T)
		return 0;
	a = height ( T->Left);
	b = height ( T->Right);
	if(a>b)
		return a+1;
		return b+1;
	
    }
}
//int bal(AVLNode *root){
//if (root == NULL)
//        return 0;
//    else {
//       
//        int lbal = bal(root->Left );
//        int rbal = bal(root->Right  );
// 
//        if (lbal = rbal)
//            return BALANCE;
//        else if(lbal > rbal )
//            return LEFT ;
//        else return RIGHT ;
//       
//	
//    }
//}

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
	case LEFT: Node->bal = LEFT;
		T1->bal = LEFT;break;
	case BALANCE:Node->bal = BALANCE;
		T1->bal = BALANCE;break;
	case RIGHT: Node->bal = RIGHT;
		T1->bal = RIGHT ;break;
	}
	T2->bal = BALANCE;
	Node = T2;
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
	case RIGHT: Node->bal = RIGHT;
		T1->bal = RIGHT;break;
	case BALANCE:Node->bal = BALANCE;
		T1->bal = BALANCE;break;
	case LEFT: Node->bal = LEFT;
		T1->bal = LEFT ;break;
	}
	T2->bal = BALANCE;
	Node= T2;
}


//Hhe so can bang
int balanceLeft(AVLNode *bal) {
  if (bal == NULL)
    return 0;
  return height(bal ->Left ) - height(bal ->Right );
}
AVLTree insertNode(AVLTree *node, KeyType key ){
	//Tim vi tri thich hop de them nut
  if ((*node) == NULL)
    return (create_node(key));
  if (key< (*node)->key)
     (*node)->Left  = insertNode( &(*node)->Left , key);
  else if (key >  (*node)->key)
     (*node)->Right  = insertNode( &(*node)->Right , key);
  else
    return  (*node);
    
  //cap nhat he so can bang va can ban cay
   (*node)->height = 1 + find_max(height( (*node)->Left ),
               height( (*node)->Right ));
  int balance  = balanceLeft( (*node));
  if (balance > 1 && key <  (*node)->Left ->key)
    return rotateRight( (*node));
  if (balance < -1 && key >  (*node)->Right ->key)
    return rotateLeft( (*node));
  if (balance > 1 && key >  (*node)->Left->key) {
     (*node)->Left  = rotateLeft( (*node)->Left );
    return rotateRight( (*node));
  }
  if (balance < -1 && key <  (*node)->Right ->key) {
     (*node)->Right  = rotateLeft ( (*node)->Right );
    return rotateLeft ( (*node));
  }
  return  (*node);
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
	printf("%d \n", T->key);
	}	
}


int printCurrentLevel(AVLNode *root, int level)
{
    if (root == NULL)
        return 0;
    if (level == 1)
        printf("(%d %d %d) -- ", root->key, bal(root), root->height);
    else if (level > 1) {
        printCurrentLevel(root->Left , level - 1);
        printCurrentLevel(root->Right , level - 1);
    }
}
void  levelOrder(AVLNode *node){
 int h = height(node);
    int i;
    for (i = 0; i <= h; i++)
        printCurrentLevel(node, i);
}

void fRead( char *fname, AVLTree *T){
	FILE *f;
	f=fopen(fname,"r");
	if(f!=NULL){
		MakeNullavl(T);
		KeyType X;
		while(!feof(f)){
			fscanf(f,"%d",&X);
			 (*T) = insertNode(T,X);
		}
		fclose(f);
	}
}
AVLTree  Search(KeyType x,AVLTree T){
	if (T == NULL) 
		return NULL;
 	else if (T->key == x) 
		return T;
 	else if (T->key < x)        
      	return Search(x,T->Right);	
  	else 
		 return Search(x,T->Left);
 }
void duyetTheoMuc(AVLTree T){
	Queue Q;
	AVLTree  p;
	makeNullQueue(&Q);
	KeyType I;
	
	if(!EmptyAVL (T)){
		enQueue(T->key,&Q);
		while(!emptyQueue(Q)){
			int i = front(Q);
			printf("%d ", i);
			//deQueue(&Q);
			p = Search(i,T);
			if(LeftChild(p) != NULL){
				enQueue(LeftChild (p)->key, &Q);
			}
			if(RightChild(p) != NULL){
				enQueue(RightChild (p)->key, &Q);
			}
			deQueue(&Q);
		}
	}
}
AVLTree  LeftChildavl(AVLTree  n){ 	
		if (n!=NULL) return n->Left;
		else return NULL; 
} 
// xac dinh con phai
AVLTree RightChildavl(AVLTree  n){	
		if (n!=NULL) return n->Right;
 		else return NULL;
}
void PreOrderavl(AVLTree T){ 
	printf("%d ",T->key);
  	if (LeftChildavl (T)!=NULL)   
  		PreOrderavl (LeftChildavl (T));
  	if(RightChildavl (T)!=NULL)
    	PreOrderavl (RightChildavl (T));
 }
 
 
 
 
 int heightA(struct AVLNode *N){
  if (N == NULL)
    return 0;
  return N->heightA ;
}

int max(int a, int b){
  return (a > b) ? a : b;
}
struct AVLNode *rightRotate(struct AVLNode *y){
  struct AVLNode *x = y->Left ;
  struct AVLNode *T2 = x->Right ;

  x->Right  = y;
  y->Left  = T2;

  y->heightA = max(heightA (y->Left ), heightA(y->Right )) + 1;
  x->heightA = max(height (x->Left), heightA(x->Right )) + 1;

  return x;
}
struct AVLNode *leftRotate(struct AVLNode *x){
  struct AVLNode *y = x->Right  ;
  struct AVLNode *T2 = y->Left;

  y->Left = x;
  x->Right = T2;

  x->heightA  = max(heightA (x->Left ), heightA (x->Right )) + 1;
  y->heightA = max(heightA (y->Left ), heightA (y->Right )) + 1;

  return y;
}
struct AVLNode *newNode(KeyType  key){
 	struct AVLNode *node = (struct AVLNode *)
    malloc(sizeof(struct AVLNode));
  node->key = key;
  node->Left = NULL;
  node->Right = NULL;
  node->heightA = 1;
  return (node);
}
 int getBalance(struct AVLNode *N){
  if (N == NULL)
    return 0;
  return heightA(N->Left) - heightA(N->Right);
}
 // Insert node
struct AVLNode *insertNodeA(struct AVLNode *node, KeyType key){
  // Find the correct position to insertNode the node and insertNode it
  if (node == NULL)
    return (newNode(key));

  if (key < node->key)
    node->Left = insertNodeA(node->Left , key);
  else if (key > node->key)
    node->Right  = insertNodeA(node->Right , key);
  else
    return node;

  // Update the balance factor of each node and
  // Balance the tree
  node->heightA = 1 + max(heightA(node->Left ),
               heightA(node->Right ));

  int balance = getBalance(node);
  if (balance > 1 && key < node->Left ->key)
    return rightRotate(node);

  if (balance < -1 && key > node->Right ->key)
    return leftRotate(node);

  if (balance > 1 && key > node->Left ->key) {
    node->Left  = leftRotate(node->Left );
    return rightRotate(node);
  }

  if (balance < -1 && key < node->Right ->key) {
    node->Right  = rightRotate(node->Right );
    return leftRotate(node);
  }

  return node;
}
void printPreOrder(struct AVLNode  *root){
  if (root != NULL) {
    printf("%d ", root->key);
    printPreOrder(root->Left);
    printPreOrder(root->Right);
  }
}

AVLTree insertNodeAB(KeyType X, AVLTree  *T ){

	static int added=0;    
  	if((*T) == NULL)
  	{
    	(*T)      = (AVLNode *)malloc(sizeof(AVLNode ));
    	(*T)->key = X;
    	(*T)->Left = NULL;
    	(*T)->Right = NULL;
    	added =1;
  	}
  	else
		if((*T)->key == X){
			printf("Da ton tai khoa %d \n",X);
			added= -1;
		}	
		else
		if( (*T)->key > X)
		{
			insertNodeAB(X,&(*T)->Left);
			
		}
			
		else{
			insertNodeAB(X,&(*T)->Right);
			
		}
			
  //cap nhat he so can bang va can ban cay
  (*T)->height = 1 + find_max(height((*T)->Left ),
               height((*T)->Right ));
  int balance  = balanceLeft((*T));
  if (balance > 1 && X < (*T)->Left ->key)
    return rotateRight((*T));
  if (balance < -1 && X> (*T)->Right ->key)
    return rotateLeft((*T));
  if (balance > 1 && X > (*T)->Left->key) {
    (*T)->Left  = rotateLeft((*T)->Left );
    return rotateRight((*T));
  }
  if (balance < -1 && X < (*T)->Right ->key) {
    (*T)->Right  = rotateLeft ((*T)->Right );
    return rotateLeft ((*T));
  }
  return (*T);
}
void Read( char *fname,AVLTree  *T){
	FILE *f;
	f=fopen(fname,"r");
	if(f!=NULL){
		MakeNullavl(T);
		KeyType X;
		while(!feof(f)){
			fscanf(f,"%d",&X);
			(*T) = insertNode(T,X);
		}
		fclose(f);
	}
}

int main(){
	AVLTree  root = NULL;

//root = insertNode(root, 2);
//root = insertNode(root, 1);
//root = insertNode(root, 7);
//root = insertNode(root, 4);
//root = insertNode(root, 5);
//root = insertNode(root, 3);
//root = insertNode(root, 8);
	AVLTree  T;
	MakeNullavl(&T);
	KeyType X;
	
	//nhapcay
//	BST_frombanPhim(&T);
	Read("TEEN.TXT",&T);
//	fRead("TEEN.TXT",&T);

  printPreOrder(T);
  printf("\n");
  duyetTheoMuc(T);
   printf("\n");
  levelOrder(T);
  printf("\n");

}




