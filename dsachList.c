#include "Plist.h"
#include <math.h>

void nhapDS1(List *pL){
  int n,i;
  ElementType x;
 
  //makeNullList(pL);
  printf("nhap vao so luong pt: ");
  scanf("%d",&n);
  for(i=1;i<=n;i++){
   printf("nhap gia tri a[%d]: ",i);
   scanf("%d",&x);
   insertList(x,endList(*pL),pL);
  }
}

void nhapDSfile(List *pL){
  int n,i;
  ElementType x;
  FILE *g;
  g=fopen("file.txt","r");
 
  makeNullList(pL);
  printf("nhap vao so luong pt: ");
  fscanf(g,"%d",&n);
  printf("%d \n",n);
  for(i=1;i<=n;i++){
   printf("nhap gia tri a[%d]: ",i);
   fscanf(g,"%d",&x);
   printf("%d\n",x);
   insertList(x,endList(*pL),pL);
  }
  fclose(g);
}

int main(){
	List L1;
	makeNullList(&L1);
//	nhapDS1(&L1);
	nhapDSfile(&L1);

	
	
	
	
	
	
	
	
	
	
// truoc sort()
	printList(L1);

// sau sort()
//	sort(&L1);
//	printList(L1);

}

