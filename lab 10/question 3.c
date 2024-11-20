#include <stdio.h>

#define max_temp 45
int compare(float [] , int ,int);

int main ()
{
	int size;
	printf("Enter the num of temperatures:");
	scanf("%d",&size);
	float temp[size];
	for(int i = 0 ; i < size ; i++)
	{
		printf("Enter element %d:",i+1);
		scanf("%f",&temp[i]);
	}
	int count=compare(temp , size , 0);
	printf("count=%d",count);
	return 0;
}

int compare(float temp[] , int size ,int index)
{
	static int count=0;
	if(index >= size)
	{
		return ;
	}
	else
	{
		if(temp[index] > max_temp)
		{
			count++;
		}
		compare(temp , size , index+1);
	}
	return count;
}