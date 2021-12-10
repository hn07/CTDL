#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <Math.h>
//#ifndef MaxLength
#define MaxLength 500
//#endif

typedef struct{
	int MNV;
	char HoTen[25];
	float namsinh;
	char chucVu[25];
}nhanVien;
#ifndef ElementType
	typedef nhanVien ElementType;  // define type of elements
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
int equal( ElementType X, ElementType Y){
	return X.MNV== Y.MNV && X.chucVu == Y.chucVu && X.namsinh == Y.namsinh && strcmp(X.HoTen,Y.HoTen) == 0;
}

Position LocateNv(ElementType X, List L){
	int Found = 0 ;
	Position P = first(L), E = endList(L);
	while(P!= E && !Found){
		if(equal(retrieve(P, L),X)) Found =1;
		else P = next(P, L) ;
		return P;
	}
}

void printList(List L){
	Position P= first(L), E = endList(L);
	ElementType X;
	int stt = 1;
	printf("stt  msnv  ho va ten   nam sinh    chuc vu \n");
	while (P != E){
		printf("%d  %d  %s  %d\n ", stt++, X.MNV,X.HoTen,X.namsinh);
		P=next(P,L);
	}
	printf("\n");
	
}

void readList(List *L){
int i, n;
ElementType x;
printf("danh sach co bao nhieu sinh vien ")	;
scanf("%d", &n);
for(i=1; i<= n; i++){
	printf("nhap phan tu thu %d \n",i);
	printf("ma so nhan vien  ");
	scanf("%d ",&x.MNV);
	fflush(stdin);
	printf("HO VA TEN "); gets(x.HoTen);
	printf("nam sinh "); scanf("%d",&x.namsinh);
//	printf("chuc vu \n"); gets(x.chucVu);
	insertList(x, endList(*L), L);
}
}
void replace(ElementType X, Position P, List *L){
	insertList(X,P,L);
	deleteList(next(P, *L), L);
}

void swap(Position P, Position Q, List *L){
	ElementType X = retrieve(P, *L);
	ElementType Y = retrieve(Q, *L);
	replace(X, Q, L);
	replace(Y, P, L);
}

void sortT(List *L){
	Position P = first(*L), E = endList(*L), Q;
	while (P != E){
		Q=next(P,*L);
		while(Q!=E){
			if(retrieve(P, *L).MNV>retrieve(Q,*L).MNV)
				 swap(P,Q,L);
			Q = next(Q,*L);
		}
		P = next(P, *L);
	}
}

int main(){
	List L;
	makeNullList(&L);
	readList(&L);
	printList(L);
	//sortT(&L);
	printList(L);
	return 0;
}



