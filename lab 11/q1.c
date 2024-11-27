/*Write a program to copy the contents of one file to another. (Create a File with some
dummy data, The data is not required to be formatted)*/

#include <stdio.h>
int main ()
{
	FILE *ptr = fopen("dummy.txt","r");
	if(!ptr)
	{
		printf("Error");
		return 0;
	}
	char str[50];
	while(fgets(str,sizeof(str),ptr)!=NULL)
	{
		printf("%s ",str);
	}
	fclose(ptr);
	
	FILE *file = fopen("content.txt","w");
	if(!file)
	{
		printf("Error");
		return 0;
	}
	fprintf(file,"%s\n",str);
	fclose(file);
}