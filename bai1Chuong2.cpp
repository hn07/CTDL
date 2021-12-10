#include"dsList.h"
#include "stackmang.h"

void nhap(List *L){
	int n,i;
	ElementType x;
	printf("ds co bao nhieu phan tu ");
	scanf("%d", &n);
	for(i= 1;i<=n ; i++){
		printf("hay nhap phan tu thu %d ",i);
		scanf("%d",&x);
		insertList(x,endList(*L),L);
		}
	delete_duplicate(L);
}

void nhapTheoThuTu(List *L){
	int n,i;
	ElementType x;
	printf("ds co bao nhieu phan tu ");
	scanf("%d", &n);
	for(i= 1;i<=n ; i++){
		printf("hay nhap phan tu thu %d ",i);
		scanf("%d",&x);
		Position p = locate(x,*L);
		insertList(x,p,L);
		}
	
}
void nhapDSTT(List *L){
  int n,i;
  ElementType x;
  FILE *g;
  g=fopen("file.txt","r");
 
  makeNullList(L);
  printf("nhap vao so luong pt: ");
  fscanf(g,"%d",&n);
  printf("%d \n",n);
  for(i=1;i<=n;i++){
   printf("nhap gia tri a[%d]: ",i);
   fscanf(g,"%d",&x);
   printf("%d\n",x);
   Position p = locate(x,*L);
   insertList(x,p,L);
  }
  fclose(g);
}
void nhapNguoc(Stack *S){
	int n,i;
	ElementType x;
	printf("ds co bao nhieu phan tu ");
	scanf("%d", &n);
	for(i= 1;i<=n ; i++){
		printf("hay nhap phan tu thu %d ",i);
		scanf("%d",&x);
		push(x,S);
		}
	
}
void inra(List L){
	Position P;
		P = first(L);
		while(P != endList(L)){
			printf("%d ", retrieve(P,L));
			P = next(P,L);
		}
		printf("\n");
}
void themPhanTu(List *L){
	 ElementType X;
	 printf("them phan tu can them 2 lan ");
	 scanf("%d ", &X);
	 Position p =  locate(X,*L);
	 insertList(X,p, L);
	 printList(*L);

	
}
void xoaPhanTu(List *L){
	 ElementType X;
	 printf("hap nhap tu can xoa ");
	 scanf("%d ", &X);
	 Position p = retrieve(X,*L);
	 	deleteList(p,L);
		printList(*L);

	 
}

int main(){
	List L;
	//Stack S;
	makeNullList(&L);
	//makeNullStack(&S);
	nhap(&L);	
	//nhapTheoThuTu(&L);
	printList(L);
//	nhapDSTT(&L);
//	printList(L);
//	themPhanTu(&L);
//	xoaPhanTu(&L);

	
//	inra(L);
//	nhapNguoc(&S);
//	printStack(S);
	
	
	
	
}
