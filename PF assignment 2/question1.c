/* Write a c program to find the second smallest element in an array.
Input 5 elements in the array (value must be <9999) :
element - 0 : 0
element - 1 : 9
element - 2 : 4
element - 3 : 6
element - 4 : 5
Expected Output :
The Second smallest element in the array is : 4 */

#include<stdio.h>
int main ()
{
	int small=9999,i;
	int s_small=9999;
	int arr[5];
	for(i=0;i<5;i++)
	{
		printf("Element %d:",i+1);
		scanf("%d",&arr[i]);
	}
	for(i=0;i<5;i++)
	{
		if(arr[i]<small){
			s_small=small;    
			small=arr[i]; //{0,9,4,6,5}              
		}
		else if(arr[i]<s_small && arr[i]!=small){
			s_small=arr[i];
		}
	}
	printf("small=%d second smallest=%d\n",small,s_small);
}