#include <stdio.h>
void quicksort(long int x[], long long int first, long long int last);
int main(void) {
	// your code goes here
	long long int n, i, j, k, l, no,sum=0, count;
	long int arr[1000000];
	scanf("%lld", &n);
	for (i = 0; i < n; ++i) {
		sum = 0;
		count = 0;
		scanf("%lld %lld",&no, &k);
		for (j = 0; j < k; ++j) 
			scanf("%ld", &arr[j]);
			quicksort(arr,0,k-1);
	//	for (j = 0; j < k; ++j) 
	//		printf("%ld ", arr[j]);
		for (j = k-1; j >= 0; --j) {
			sum = sum + arr[j];
			if (no <= sum )
				break;
				count++;
			}
			if(j == -1)
				printf("Scenario #%lld:\nimpossible\n",i+1);
			else
				printf("Scenario #%lld:\n%lld\n", i+1, ++count);
		}
	
	return 0;
}
 void quicksort(long int x[],long long int first,long long int last){
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