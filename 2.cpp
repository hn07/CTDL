#include "Nham.h"
void nhapDSTT(AVLTree *AVL){
  int n,i;
  KeyType  x;
  FILE *g;
  g=fopen("avltest.txt","r");
  printf("nhap vao so luong pt: ");
  fscanf(g,"%d",&n);
  printf("%d \n",n);
  for(i=1;i<=n;i++){
   printf("nhap gia tri a[%d]: ",i);
   fscanf(g,"%d",&x);
   printf("%d\n",x);
   AVLNode *root=NULL;
   insertNodeA (root,x);
  }
  fclose(g);
}

int main(){
	AVLNode *root;
	root = insertNode(root, 20);
	root = insertNode(root, 24);
	root = insertNode(root, 15);
	root = insertNode(root, 19);
	root = insertNode(root, 2);
	root = insertNode(root, 29);

	Tree T;
	KeyType X;
	//fRead("avltest.txt",&T); 
	//nhapDSTT(&T);

	printf("key  bal  hight\n");
	printf("in cay theo thu tu NLR \n");
	PreOrderavl(root);
//	preOrder(T);
//	printf("in cay theo thu tu LNR \n");
//	inOrder(T);
//	printf("in cay theo thu tu RLN \n");
//	PosOrder(*T);
//	printf("in cay theo level\n");
//	levelOrder(*T);
//	duyetTheoMuc(node);
  

			
}
