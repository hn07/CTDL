#include <stdio.h>
#include "math.h"

int main(){
	int x, y, i;
	printf("tim x,y trong 1675x-367y =23\n");
		for(i=1;i<1000;i++){
			x ++;
			y = ((1675*i-5)/367);
			if(1675*x-367*y==23){
					printf("x= %d		y= %d\n",x, y);
			}
		}		


	
}
