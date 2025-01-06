#include<stdio.h>
int main()
{
	int N;
	printf("Enter the number of matchsticks:");
	scanf("%d",&N);
	if( N <= 0 )
	{
		printf("invalid input\n");
		return -1;
	}
	else if( N % 5 == 0){
		printf("-1\n");
	}
	else{
		int res=N % 5;
		printf("%d\n",res);
	}
	return 0;
}