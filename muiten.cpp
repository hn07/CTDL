#include<stdio.h>

struct node{
	int data;
	node *next;
};
typedef node *List;
typedef int songuyen;

void ListRong(List &L){
	L = NULL;
	}

void addList(List &L, int x){
	
	node *q = new node;
	q -> data = x;
	q -> next = NULL;
	if(L == NULL){
		L = q;
	}
	else{
		node *p = new node;
		p = L;
		while (p -> next != NULL ){
		p = p -> next;
		
		}
		p->next = q;
		
	}
}
void duyet(List L){
	while (L != NULL){
	printf("%d ", L->data )	;
	L = L->next;
	}
}

int main(){
	/*node a;
	a.data =4;
	printf("%d", a);
	node *b = new node;
	b->data =3;
	printf("\n%d", b->data);
	*/
	List L;
	ListRong(L);
	addList(L, 1);
	addList(L, 5);
	addList(L, 1);
	addList(L, 54);
	duyet(L);
	
	}
