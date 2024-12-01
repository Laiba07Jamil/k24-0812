/*Write a C Program to Find Largest Number in an array Using Dynamic Memory Allocation. Note:
The array must be dynamically resized and initially the array size will be taken by the user and
then resized by the user
Example arr[5]={1,2,3,4,5}
//After resizing
Arr[7]={1,2,3,4,5,6,7}
Take the same array and resize it.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	int n1;
	printf("Enter the size of array:");
	scanf("%d",&n1);
	int* arr1 = (int*)malloc(n1 * sizeof(int));
	 if (arr1 == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
	for(int i = 0 ; i < n1 ; i++){
		printf("Enter %d element:",i+1);
		scanf("%d",&arr1[i]);
	}
	int n2;
	printf("Enter the new size of array:");
	scanf("%d",&n2);
	arr1 = realloc(arr1 , sizeof(int) * n2 );
	 if (arr1 == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
	for(int i = 0 ; i < n2 ; i++){
		printf("Enter %d element:",i+1);
		scanf("%d",&arr1[i]);
	}
	int* ptr = arr1;
	int max = 0 ;
	for(int i = 0 ; i < n2 ; i++){
		if(max < (*ptr))
		max = (*ptr);
		ptr++ ;
	}
	printf("Largest num = %d\n",max);
	free(arr1);
	return 0 ;
}