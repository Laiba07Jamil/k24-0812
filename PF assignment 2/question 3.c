#include<stdio.h>
#include<string.h>
int check_char(char words[] , int n);
int main ()
{
	char word[100][100];
	int i,n;
	int removed;
	printf("Enter the number of words:");
	scanf("%d",&n);
	for(i = 0 ;i < n; i++)
	{
		printf("Enter string %d:",i+1);
		scanf("%s",word[i]);
	}
	printf("[");
	for(i = 0 ; i < n ; i++)
	{
	    int size=strlen(word[i]);
	    removed=check_char(word[i],n);
	    removed += removed;
	    if(i != n-1)
	    printf(", ");
	}
	printf("]\n");
	printf("Total removed characters %d",removed);
	
}

int check_char(char word[] , int n)
{
	char arr[n];
	int count=0,j=0;
	for(int i = 0 ; word[i] != '\0' ; i++)
	{
		if(i == 0 || (word[i] != word[i -1]))
		{
			arr[j]=word[i];
			j++;
		}
		else{
			count++;
		}
	}
	
	printf(" \"%s\"",arr);
	return count;
}