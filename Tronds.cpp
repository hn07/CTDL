#include "plist.h"
void nhapL1(List *pL1){
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
void nhapL2(List *pL2){
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
void tronDs(List *pL1, List *pL2, int p, int q){
	List L;
	makeNullList(&L);
	if(L1 == NULL){
		L=L2;
	}
	else if(L2 == NULL){
		L=L1;
	}
	else{
		while(p == endList(L2) && q != endList(L2)){
			if(p<=q){
				tail -> next(p);
				tail -> tail->next(p);
				p->next(p);
			}
			else{
				tail -> next(q);
				tail -> tail->next(q);
				q->next(q);
			}
		}
		if(p== endList(L)){
			tail -> q->next;
		}
		else if(q == endList(L)){
			tail -> p->next;
			
		}
	}
	
}














































