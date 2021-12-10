#include <stdio.h>
#include <conio.h> 

#define Max 500
#ifndef ElementTyep
 typedef int Element; 
 #endif
typedef int Position;

typedef struct{
	Element elment [Max];
	Position Last;
}List;

//KHOI TAO DS RONG
void makeNullList(List *L){
	L->Last=0;
}

//KIEM TRA DS CO RONG HAY KHONG
int emptyList(List L){
	return L.Last==0;
}

//KIEM TRA DS CO FULL HAY KHONG
int full_list(List L){
	return L.Last== Max;
}

//return vi tri dau Ds
Position first(List L){
	return 1;
}

//return vi tri cuoi Ds
Position endList(List L){
	return L.Last+1;
}

//return vi tri tiep the cua P
Position next(Position P, List L){
	if(P<1 || P> L.Last){
		printf(" vi tri %d ", P);
		return -1;
	}
	return P+1;
}

// Return gia tri cua P trong DS
Element retrieve(Position P, List L ){
	if(P<1 || P>L.Last){
		printf("gia tri cua p %d ", P);
		return -1;
		
	}
	return L.elment[P-1];
}
//Chen phan tu x 
void insertList(Element x, Position P, List*L){
	if(full_list(*L)) // L->Last==Max
	printf("List full");
	else if((P<first(*L) || (P> endList(*L))))
	printf("vi tri cua P %d ", P);
	
	else{
		Position Q;	
		for(Q=endList(*L)-1+1;Q>P-1;Q--)
			L-> elment [Q]=L->elment[Q-1];	
		L->elment[P-1]= x;
		L->Last++;
	}
}

void deletList(Position P, List *L){
	if((P<first(*L) || (P> endList(*L))))
	printf("vi tri cua P %d ", P);
	else if (emptyList(*L)){
		printf("list is empty ");
	}
	else {
		Position Q;
		for(Q= P-1; Q<L->Last -1;Q++)
		L-> elment[Q] = L-> elment[ Q+1 ];
		
		L->Last--;
	}
}

Position locate(Element X, List L ){
	Position P;
	int fount =0;
	P = first(L);
	while((P != endList(L)) && (fount == 0 )){
		if (retrieve(P,L)== X) fount = 1;
		else P = next(P,L);
		return P;
		
	}
}

void printList(List L){
	Position P = first(L );
	while (P != endList(L)){
		printf("%d", retrieve(P,L));
		P = next(P,L);
	}
	printf("\n");
}

void readList(List *pL){
   int i,N;
    int X;
    makeNullList (pL);
    scanf("%d",&N);
    for(i=1; i<=N; i++) { 
    scanf("%d",&X);
    insertList(X,endList(*pL), pL) ;
}
}

void copy (List  L, List  &A)
{
A.Last=L.Last;
for (int i=0; i<L.Last; i++)
A.elment[i]=L.elment[i];
}
void copyEvenNumbers (List L1, List *pL2){
    makeNullList (&*pL2);
    pL2->Last=L1.Last;
    for (int i=1; i<L1.Last; i++){
        if(i%2==0){
            insertList (L1.elment [i], pL2->Last-1, pL2);
            // pL2->Elements[i]=L1.Elements[i];
        }
    }
   
}
void insertSet(int x, List *pL){
     for (int i = pL->Last; i > 0; i--){
        pL->elment[i] = pL->elment[i-1];
        pL->elment[i] = x;
        pL->Last++;
     }
    
}
void normalize(List *pL){
    int p = first(*pL);
    while( p != pL->Last-1){
    	int q = p+1;
    	if(pL->elment[p]==pL->elment[q]){
    		deletList(p,pL);
			}
		else q = next(q,*pL);
    	}
    p = next(p,*pL);
}


