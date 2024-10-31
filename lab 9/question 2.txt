#include<stdio.h>
int swap(int *a,int *b);
int main ()
{
	int a,b;
	printf("Enter the number 1:");
	scanf("%d",&a);
	printf("Enter the number 2:");
	scanf("%d",&b);
	swap(&a,&b);
	printf("%d %d ",a,b);
	return 0;
}

int swap(int *a,int *b)
{
	int temp=0;
	temp=*a;
	*a=*b;
	*b=temp;
	
}