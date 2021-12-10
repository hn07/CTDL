#include "CayTimKiemNhiPhan.h"
#include "Queuebangmang.h"

void BST_frombanPhim(Tree *T){
	MakeNullTree(T);
	KeyType X;
	int i,n;
	printf("cay co bao nhieu nut ");
	scanf("%d", &n);
	for (i=1 ;i<= n; i++){
		printf("hay nhap phan tu thu (%d) ", i);
		scanf("%d", &X);
		InsertNode(X, T);
	}
}
void fReadBST( char *fname, Tree *T){
	FILE *f;
	f=fopen(fname,"r");
	if(f!=NULL){
		MakeNullTree(T);
		KeyType X;
		while(!feof(f)){
			fscanf(f,"%d",&X);
			InsertNode(X,T);
		}
		fclose(f);
	}
}

void duyetTheoMuc(Tree T){
	Queue Q;
	Tree p;
	makeNullQueue(&Q);
	KeyType I;
	
	if(!EmptyTree(T)){
		enQueue(T->Key,&Q);
		while(!emptyQueue(Q)){
			int i = front(Q);
			printf("%d ", i);
			//deQueue(&Q);
			p = Search(front(Q),T);
			if(LeftChild(p) != NULL){
				enQueue(LeftChild(p)->Key, &Q);
		
			}
			if(RightChild(p) != NULL){
				enQueue(RightChild(p)->Key, &Q);
			}
			deQueue(&Q);
		}
	}
}
/*
int demSoNutLa(Tree T){
	int k = 0;
	int i,n,a;
	 n = nb_nodes(T);
	if(!EmptyTree(T)){
		for(i = 1; i<n; i++ ){
		if(k = IsLeaf(i)){
			k++;
		}
		}
	}
	
}*/
int soNutLa(Tree T){
	int count = 0;
	if(EmptyTree(T)){
		count = 0;
	}
	else{
		if(IsLeaf(T)){
			return 1;
		}
		else{
		return count = soNutLa(LeftChild(T)) + soNutLa(RightChild(T));
		}
	}
	


}
int countLeaf(Tree T) {
  	if(EmptyTree(T)) 
		return 0;
	else
		if(IsLeaf(T))
			return 1;
		else
			return countLeaf(T->Left) + countLeaf(T->Right);
}
int tinhDoCao(Tree T){
	int h = 0;
	if(EmptyTree(T)){
		h = 0;
		return h;
	}
	else{
		int hL = 1+ tinhDoCao(LeftChild(T));
		int hR = 1+ tinhDoCao(RightChild(T));
		h = max(hR, hL);
	}
	return h;
}
int heighTree(Tree T){
	int a, b;
	if(!T)
		return 0;
	a = heighTree( T->Left);
	b = heighTree( T->Right);
	if(a>b)
		return a+1;
		return b+1;
	
}
int timKhoaX( Tree T){
	KeyType X;
	printf("\nhay nhap vao so nao do ban can tim ");
		scanf("%d", &X);
	if(Search(X,T) != NULL){
		printf(" Co %d luon ", X);
	}
	else
	printf(" khong co %d ban tim so khac di nhe ",X);
}
int duongDiDenKhoaX(KeyType X, Tree T){ 
	if(Search(X,T)!=NULL){
		
		if(T->Key != X){
				printf("%d ",T->Key);
			duongDiDenKhoaX(X,LeftChild(T));
			duongDiDenKhoaX(X,RightChild(T));
		}
		else{
			printf("xong");
		}
	}
	else{
		return 0;
	}
		}
 
	
 int main(){
	//khaibao
	Tree T;
	KeyType X;
	
	//nhapcay
//	BST_frombanPhim(&T);
	fReadBST("avltest.txt",&T);
	//BST_TEXT.txt
	//duyet tien tu
	printf("duyet tien tu ");
	PreOrder(T);
	
	//duyet trung tu
	printf("\nduyet trung tu ");
	InOrder(T);
	//duyet hau tu 
	printf("\nduyet hau tu ");
	PosOrder(T);
	printf("\nduyet theo muc ");
	duyetTheoMuc(T);
	
	printf(" \n%d ",soNutLa(T) );
	printf(" so nut la %d ",countLeaf(T) );
	
	printf("\n tinh do cao %d ", tinhDoCao(T)-1);
	printf("\n tinh do cao %d ", heighTree(T)-1);
	//timKhoaX(T);
	printf("\nhay nhap vao khoa x ");
	scanf("%d", &X);
	duongDiDenKhoaX(X,T);
 
}

