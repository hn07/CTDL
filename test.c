#include "QueuebangMang.h"
#include "conio.h"

void nhap(int *No, Queue *Q){
	if(! fullQueue(*Q) ){
		(*No) ++;
		enQueue(*No,Q);
		printf("da tao ra san pham  %d\n ", *No);
	}
	else{
		printf("Kho da day !\n");
	}
}
void nhapkho(int *NO, Queue *Q){
	if(!fullQueue(*Q)){
		(*NO )++;
		enQueue(*NO,Q);
		printf("da nhap vao kho san pham %d\n", *NO);
	}
	else{
		printf("kho ban da day !\nCho suat xuat \n");
	}
}

void xuat(int No, Queue *Q){
	if(!emptyQueue(*Q)){
		printf("xuat san pham thu %d \n",front(*Q) );
		deQueue(Q);
	}
	else{
		printf("het hang\n ");
	}
}
void xuatkho(int NO, Queue *Q){
	if(!emptyQueue(*Q)){
		printf("xuat kho san pham thu %d\n", front(*Q));
		deQueue(Q);
	}
	else{
		printf("het hang ! cho nhap kho\n");
	}
}

int main(){
	Queue Q;
	makeNullQueue(&Q);
	ElementType No = 0;
	ElementType NO =0;
	while(!kbhit()){
		if(rand()%2==1){
		
		//	nhap(&No,&Q);
			nhapkho(&NO,&Q);
		}
		else	xuatkho(NO,&Q);
		sleep(3);
	}

	printf("dung");


	
}



