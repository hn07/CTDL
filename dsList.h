#include <stdio.h>
#include <conio.h>
#include <math.h>
//#ifndef MaxLength
#define MaxLength 500
//#endif
#ifndef ElementType
	typedef int ElementType;  // define type of elements
#endif


typedef int Position; 
typedef struct {
	ElementType Elements[MaxLength];  //store elements of list
	Position Last; //store the current length of list
} List;

// List initialization
void makeNullList(List *L) { 
	L->Last=0; 
}

//Check list is empty or not
int emptyList(List L){
	return L.Last==0;
}

// Check l? is full or not?
int Full_List(List L)
	{
			return L.Last==MaxLength;
	} 

// return the first position of list
Position first(List L){
	return 1;
}

// return the lastest position of list
Position endList(List L){
	return L.Last+1;
}


// return the next position of position P
Position next(Position P, List L){
	if (P<1 || P>L.Last){
		printf("The position %d is out of list",P);
		return -1;
	}
	return P+1;
}

// Return the value of elements[P] of list
ElementType retrieve(Position P,List L){
	if (P<1 || P>L.Last){
		printf("The position %d is out of list", P);
		return -1;
	}
	return L.Elements[P-1];
}

void insertList(ElementType X, Position P, List *L){
	if (Full_List(*L))   //(L->Last==MaxLength)
		printf("List is full");
	else if ((P<first(*L)) || (P>endList(*L))) 
		printf("The position %d is illegal", P);
	else{
		Position Q;	
		for(Q=endList(*L)-1+1;Q>P-1;Q--)
			L->Elements[Q]=L->Elements[Q-1];	
		L->Elements[P-1]=X;
		L->Last++;
	}
}

void deleteList(Position P,List *L){
	if ((P<first(*L)) || (P>=endList(*L)))
		printf("The position %d is illegal", P);
	else if (emptyList(*L))
		printf("List is empty");
	else{
		Position Q;
		for(Q=P-1;Q<L->Last-1;Q++)
		L->Elements[Q]=L->Elements[Q+1];
		
		L->Last--;
	}
}
//xoa gia tri trung lap
void delete_duplicate(List *L){
	Position p,q; //ki?u v? trí c?a các ph?n t? trong danh sách
	p=first(*L); //v? trí ph?n t? d?u tiên trong danh sách
	while (p!=endList(*L))
	{ q=next(p,*L); //v? trí ph?n t? d?ng ngay sau ph?n t? p
	while (q!=endList(*L))
	{
	if (retrieve(p,*L) == retrieve(q,*L))
	deleteList(q,L); // xoa ph?n t?
	else
	q=next(q,*L);
	}
	p=next(p,*L);
}
	
}

Position locate(ElementType X, List L){
  Position P;
	int Found = 0;
	P = first(L); 
	while ((P != endList(L)) && (Found == 0))
		if (retrieve(P,L) >= X) Found = 1;
		else P = next(P, L);
	return P;
} 

//tim mot phan tu trong ds
Position myLocate(ElementType x, int i, List L){
Position p= first(L);
int count =0;
while (next(p,L)!= NULL && count < i){
if (retrieve(p,L)== x)
count++;
if (count<i)
p=next(p,L);
}
return p;
}

void printList(List L){
	Position P= first(L);
	while (P != endList(L)){
		printf("%d ", retrieve(P,L));
		P=next(P,L);
	}
	printf("\n");
	
}
void swap(int x, int y) {
    int swapInt;

    swapInt = x;
    x = y;
    y = swapInt;
} 
void sort(List *L){
Position p,q;
	 p = first(*L);
	while (p!=endList(*L)){ 
	 q=next(p,*L);
	 while (q!=endList(*L)){
	 if (retrieve(p,*L) > retrieve(q,*L))
	swap(p,q);
	 q=next(q,*L);
}
	 p=next(p,*L); 
}
}

void bubble_sort(int n, List *L) {
int i,j;
for(i= 0; i<= n-2; i++)
for(j=n-1;j>=i+1; j--)
if (retrieve(i,*L) < retrieve(j,*L))
swap(i,j);
}






