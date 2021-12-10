#include <stdio.h>


typedef int keytype;
typedef float othertype;

typedef struct {
	keytype key;
	othertype otherkey;
}recotyped;

void read_data1(char *filenam, recotyped a[], int *n){
	FILE *f;
	f= fopen("Tron2DanhSach.txt","r");
	int i= 0;
	if(f!= NULL){
		while (!feof(f)){
			fscanf(f,"%d", &a[i].key);
				i++;
			
			
		}
		fclose(f);
		*n = i;
		
	}
	else
	printf("file loi ");
}
void read_data2(char *filenam, recotyped a[], int *n){
	FILE *f;
	f= fopen("Tron2DanhSach2.txt","r");
	int i= 0;
	if(f!= NULL){
		while (!feof(f)){
				fscanf(f,"%d", &a[i].key);
				i++;
			
			
		}
		fclose(f);
		*n = i;
		
	}
	else
	printf("file loi ");
}

void Print_data(recotyped a[], int n){
	int i;
	
	for(i= 0 ;i<n; i++){
		printf("%5d",a[i].key);
		
	}
}
void Print_data2(recotyped a[], int n){
	int i;
	
	for(i= 0 ;i<n; i++){
		printf("%3d ",a[i].key);
		printf("\n");
	}
}

void Split (recotyped a[], int n ,recotyped a1[], recotyped a2[], int *k, int *l){
	int i; 
	*k = n/2;
	*l = n- *k;
	// gan ca phan tu cua mang a tu 0 den *k - 1 cho mang a1
	
	for(i = 0; i<*k; i++) {
		a1[i]= a[i];
	}
	
	// gan ca phan tu cua mang a tu *k den n - 1 cho mang a2
	for(i = *k; i<n ;i++){
			a2 [i-*k]= a[i];
	}

}


void Merge(recotyped a1[], recotyped a2[], int k , int l , recotyped a[]){
	int i= 0, j= 0 ,t= 0;
	//khi ca 2 mang a1 a2 con phan tu
	//so sanh mot phan tu cua a1 voi mot phan tu cua a2
	//phan tu cua mang nao nho hon thi gan phan tu cua mang do cho a
	while(j<k && t<l){
		if(a1[j].key< a2[t].key)
		a[i++] = a1[j++];
		else
		a[i++]= a2[t++];
		
	}
	//het mang a2 chi con mang a1
	//gan phan tu cua mang a1 cho a
	while (j<k)
	a[i++]= a1[j++];
	//het mang a1 chi con mang a2
	//gan phan tu cua mang a2 cho a
	while (t<l)
	a[i++]= a2[t++];
	
}

void MegaSort(recotyped a[], int n){
	recotyped a1[n/2], a2[n-n/2];
	int k , l;
	if(n>1){
		Split(a,n,a1,a2,&k,&l);
		MegaSort(a1,k);
		MegaSort(a2,l);
		Merge(a1,a2,k,l,a);
	}
}

int main(){
	recotyped a[ 100 ];
	recotyped b[100];
	int n,m, k,l;
	read_data1("Tron2DanhSach1.txt",a,&n);
	read_data2("Tron2DanhSach2.txt",b,&m);
	printf(" Du lieu dau vao \n");
	Print_data(a,n);
	Print_data(b,m);
	
/*	MegaSort(a,n);
//	MegaSort(b,m);
	printf("\n");
	printf(" sau khi dung ham mergesort\n ");
	
	Print_data(a,n);
//	Print_data(b,m);*/
	return 0;
}




















