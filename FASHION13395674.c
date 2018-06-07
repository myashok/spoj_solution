#include <stdio.h>
 void quicksort(int x[],int first,int last){
    int pivot,j,temp,i;

     if(first<last){
         pivot=first;
         i=first;
         j=last;

         while(i<j){
             while(x[i]<=x[pivot]&&i<last)
                 i++;
             while(x[j]>x[pivot])
                 j--;
             if(i<j){
                 temp=x[i];
                  x[i]=x[j];
                  x[j]=temp;
             }
         }

         temp=x[pivot];
         x[pivot]=x[j];
         x[j]=temp;
         quicksort(x,first,j-1);
         quicksort(x,j+1,last);

    }
}

int main(void) {
long int i, j, k, l, n, x[100000], y[100000];
	scanf("%ld", &n);
	for (i = 0; i < n; ++i) {
		k = 0;
		scanf("%ld", &l);
		for(j = 0; j < l; ++j)
			scanf("%ld",&x[j]);
		for(j = 0; j < l; ++j)
			scanf("%ld",&y[j]);
			quicksort(x,0,l-1);
			quicksort(y,0,l-1);
		for(j = 0; j < l; ++j)
			k = k + x[j]*y[j];
		printf("%ld\n",k);
	}
	return 0;
}
