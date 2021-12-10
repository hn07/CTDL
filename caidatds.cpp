#include<stdio.h>
#define MAX_LENGTH 300
/*typedef struct{
	int mssv;
	char ho_ten [25];
	float diem ;
	
}sinh_vien;*/
typedef int Element_Type;
typedef int Position;
typedef struct{
	Element_Type Element[MAX_LENGTH];
	Position Last;
}List;

void make_null_list(List *L){
	L->Last=0;
	}

int emptylist(List L){
	return L.Last == 0;
	
	}

Position first(List L){
return 1;
	}
	
Position end_last (List L){
	return L.Last+1;
}

Position next_p (Position P,List L){
	return P+1;
}

Position previous(Position P, List L){
	return P-1;//VI TRI TRUOC P
}

Element_Type retrieve (Position P , List L){
	return L.Element[P-1];//XAC DINH GIA TRI TAI VI TRI P
}

/*Position Locate(Element_Type X, List L){
	Position P =1;
	int Found = 0;
	while(P<= L.Last && !Found)
	if(L.Element[P-1]== X)
	Found =1;
	else P++;
return P;
}*/

Position Locate(Element_Type X, List L){
	Position P = first(L);
	Position E = end_last(L);
	int Found = 0;
	while(P!= E && !Found)
	if(retrieve(P,L)== X)
	Found =1;
	else P = next_p(P,L);
return P;
}

void insert_list(Element_Type X, Position P, List *L){
	if(L->Last == MAX_LENGTH)
		printf("danh ds day ");
	else if(P<1 || P>L->Last+1)
	printf("Vi tri khong hop le ");
	else{
		Position Q;
		for(Q == L->Last ; Q >= P; Q--)
			L->Element[Q] = L->Element[Q-1];
			L->Last++;
			L->Element[P-1] =X;
			
	}
}

void delete_list(Position P ,List *L ){
	if(L->Last==0)
		printf("danh ds rong ");
	else if(P<1 || P>L->Last)
	printf("vi tri khong hop le ");
	else{
		Position Q;
		for(Q= P;Q<L->Last-1; Q--)
		  L->Element[Q-1]=L->Element[Q];
		L->Last--;
		
	}
}
	
