#include "CayTongQuat.h"
void ReadTree(Tree *T){
int i;
MakeNull_Tree(&*T);
//Nh p s n�t c a c�y cho n khi s n�t nh p v�o l� h p l
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
