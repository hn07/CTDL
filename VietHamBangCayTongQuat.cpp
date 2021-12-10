#include "CayTongQuat.h"
#include "Queuebangmang.h"

void nhapCayTuKey(Tree *T){
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
//void duyetTheoMuc(Tree T){
//	Queue Q;
//	Tree p;
//	makeNullQueue(&Q);
//	DataType I;
//	
//	if(!EmptyTree(T)){
//		enQueue(I,&Q);
//		while(!emptyQueue(Q)){
//			int i = front(Q);
//			printf("%d ", i);
//			//deQueue(&Q);
//			p = Search(front(Q),T);
//			if(LeftChild(p) != NULL){
//				enQueue(LeftChild(p)->Key, &Q);
//		
//			}
//			if(RightChild(p) != NULL){
//				enQueue(RightChild(p)->Key, &Q);
//			}
//			deQueue(&Q);
//		}
//	}
//}


int main(){
	Tree T;
	nhapCayTuKey(&T);
	HeightTree(T);
	
	
}
