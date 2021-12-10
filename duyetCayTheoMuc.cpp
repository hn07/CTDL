#include <stdio.h>
#include "CayTongQuat.h"
#include "QueuebangMang.h"
//#include "ReadTree.cpp"

void ReadTree(Tree *T){
int i;
MakeNull_Tree(&*T);
//Nh p s nút c a cây cho n khi s nút nh p vào là h p l
do {
printf("Cay co bao nhieu nut?");
scanf("%d",&(*T).MaxNode);
} while (((*T).MaxNode<1) || ((*T).MaxNode>MAXLENGTH));
printf("Nhap nhan cua nut goc ");
fflush(stdin);
scanf("%c",&(*T).Data[0]);
(*T).Parent[0]=NIL; /* nut goc khong co cha */
for (i=1;i<=(*T).MaxNode-1;i++){
printf("Nhap cha cua nut %d ",i);
scanf("%d",&(*T).Parent[i]);
printf("Nhap nhan cua nut %d ",i);
fflush(stdin);
scanf("%c",&(*T).Data[i]);
}
}

void DuyetTheoMuc(Tree T){
	Queue Q;
	makeNullQueue(&Q);
	enQueue(Root(T), &Q );
	
	while(!emptyQueue(Q)){
		int temp = front(Q);
		printQueue(Q);
		TNode child_temp = LeftMostChild (temp, T);
	
		while(child_temp != EmptyTree(T)){
		enQueue(child_temp, &Q);
		child_temp = RightSibling (child_temp, T);
		}
		
	}
}
int main(){
	Tree T;
	MakeNull_Tree(&T);
	ReadTree(&T);
	DuyetTheoMuc(T);
}










