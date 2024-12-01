/*Write a program that calculates the sum of all the elements in array using pointers
(Note: Generate the array via user)*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	printf("Enter the size of array:");
	scanf("%d",&n);
	int* arr = (int*)malloc(n * sizeof(int));
	 if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
	for(int i = 0 ; i < n ;i++){
		printf("Enter the %d element:",i+1);
		scanf("%d",&arr[i]);
	}
	int* ptr = arr;
	int sum = 0;
	for(int i = 0 ; i < n ; i++){
		sum += *ptr ;
		ptr++;
	} 
	printf("sum = %d\n",sum);
	free(arr);
}