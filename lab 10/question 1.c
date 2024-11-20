/*Write a recursive function that takes an array and its size as input and prints all the
elements.*/


#include <stdio.h>
void recursive(int arr[] ,int n, int index);
int main ()
{
	int arr[100],n;
	printf("Enter the size of array:");
	scanf("%d",&n);
	for(int i = 0 ;i < n ;i++)
	
	{
		printf("Enter element %d:",i+1);
		scanf("%d",&arr[i]);
	}
	recursive(arr,n,0);
	return 0;
}

void recursive(int arr[] ,int n, int index)
{
	if(index >= n)
	{
		return ;
	}
	printf("%d ",arr[index]);
	recursive(arr,n,index+1);
	return;
}