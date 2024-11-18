/*Write a recursive function bubbleSort that takes an array and its size. It performs the
bubble sort algorithm by repeatedly comparing adjacent elements and swapping them if
they are in the wrong order.*/


#include <stdio.h>

void bubblesort(int arr[] , int size);
int main ()
{
	int size;
	printf("Enter the size of array:");
	scanf("%d",&size);
	int arr[size];
	for(int i = 0 ; i < size ; i++)
	{
		printf("Enter %d element",i+1);
		scanf("%d",&arr[i]);
	}
	bubblesort(arr , size);
	for(int i = 0 ; i < size ; i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}

void bubblesort(int arr[] , int size)
{
    if (size == 1)
    {
        return;
    }
    else {
        for(int i=0 ;i<size -1 ;i++)
        {
            if(arr[i] > arr[i+1])
            {
                int temp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = temp;
            }
        }
    }
    bubblesort(arr, size-1);
}
	