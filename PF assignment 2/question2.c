/* A popular beverage company is looking to optimize their marketing campaigns by understanding
the frequency of characters used in their promotional slogans. They believe that analyzing these
patterns can help them tailor their messaging to specific demographics and improve brand recall.
You've been tasked with creating a C code function to analyze the character frequency in a list of
slogans provided by the marketing team. This analysis will help identify the most common letters
used in their slogans, which can inform future marketing strategies.
Input:
slogans = ["buy now", "save big", "limited offer"]
Expected Output:
? For "buy now": {'b': 1, 'u': 1, 'y': 1, ' ': 1, 'n': 1, 'o': 1, 'w': 1}
? For "save big": {'s': 1, 'a': 1, 'v': 1, 'e': 1, ' ': 1, 'b': 1, 'i': 1, 'g': 1}
? For "limited offer": {'l': 1, 'i': 1, 'm': 1, 't': 1, 'e': 2, 'd': 1, ' ': 1, 'o': 1, 'f': 1, 'r': 1} */

#include<stdio.h>
int main()
{
	int i,num;

	printf("Enter the number of slogans:");
	scanf("%d",&num);
	char slogan[num][100];
	for( i=0;i<num;i++)
	{
		printf("enter slogan %d:",i+1);
		scanf(" %[^\n]",slogan[i]);
	}
	for( i=0;i<num;i++)
	{
		int freq[256]={0};
		char *slo = slogan[i];
		for(int  j=0; slo[j]!='\0';j++)
		{
			freq[(unsigned char)slo[j]]++;
		}

		printf("For \"%s\": {",slogan[i]);
		int flag=0;
		for(int j=0;j<256;j++)
		{
			if(freq[j]>0){
				if(flag){
					printf(", ");
				}
			printf("'%c':'%d'",j,freq[j]);
			flag=0;
			}
		}
		printf("}\n");
	}
}
