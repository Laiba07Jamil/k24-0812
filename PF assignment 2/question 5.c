#include<stdio.h>
void horizontalhistogram(int arr[],int n);
void verticalhistogram(int arr[],int n);
int main()
{
	int n;
	int i;
	printf("Enter the size:");
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
	{
		printf("Enter the element %d:",i+1);
		scanf("%d",&arr[i]);
	}
	horizontalhistogram(arr,n);
	verticalhistogram(arr,n);
	return 0;
	
}

void horizontalhistogram(int arr[],int n)
{
	printf("Horizontal histogram\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<arr[i];j++)
		{
			printf("* ");
		}
	printf("\n");
	}
}

void verticalhistogram(int arr[],int n)
{
	int max=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]>max){
			max=arr[i];
		}
	}
	printf("Vertical histogram\n");
	for(int i=max;i>0;i--)
	{
		for(int j=0;j<n;j++)
		{
			if(arr[j]>=i)
			{
				printf("*");
			}
			else{
				printf(" ");
			}	
		}
		printf("\n"); 
	}
	for(int i=0;i<n;i++)
	{
		printf("%d",arr[i]);
	}
}