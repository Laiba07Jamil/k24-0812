#include <stdio.h>
void reverse(char arr[]);

int main() {
    int i;
    char arr[50];
    
        printf("Enter string :");
        scanf(" %[^\n]",&arr);
        reverse(arr);
      
      
        
}
void reverse(char arr[])
{
	int i=0,size=0;
	while(arr[i]!='\0')
	{
		size++;
		i++;
	}
        for(int i=0;i<size/2;i++)
        {
		char temp=arr[i];
		arr[i]=arr[size-i-1];
		arr[size-i-1]=temp;
		  

	}
	printf("Reversed string %s:",arr);
}