#include "QueuebangMang.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void sanXuat(int *No,Queue *Q){
	if(!fullQueue(*Q)){
		(*No)++;
		enQueue(*No,Q);
		printf("Da tao ra san pham thu %d\n",*No);
	}
	else printf("Kho day ngung san xuat\n");
}

void tieuThu(int No,Queue *Q){
	if(!emptyQueue(*Q)){
		printf("Tieu thu san pham %d\n",front(*Q));
		deQueue(Q);
	}
	else printf("Het hang\n");	
}

void SXvaTT(){
	Queue Q;
	makeNullQueue(&Q);
	ElementType No=0;
	int n;
	int rand();
	while(!kbhit()){
		n=rand()%2;
		if(n==1) sanXuat(&No,&Q);
		else tieuThu(No,&Q);
	}
	printf("Dung!!");
}
int main(){
	//SXvaTT();
	Queue Q;
	makeNullQueue(&Q);
	ElementType No=0;
	while(!kbhit()){
	
		if(rand()%2==1) sanXuat(&No,&Q);
		else tieuThu(No,&Q);
		sleep(2);
	}
	printf("Dung!!");
}

























