/*Write a program that ask the user to enter the total 'N' no of characters in user's name {First
Name + Last Name} to create a dynamic array of characters. After create a dynamic array of
that 'N' no of characters using malloc or calloc function. Finally copy your full name in it that has
already been taken from the user before
Dynamic Array = "Muhib Ahmed"; */

#include <stdio.h>
#include <stdlib.h>

int main(){
	int N;
	printf("Enter the total number of characters in your name {First name + Last name} including space:");
	scanf("%d",&N);
	char* dynamicarray = (char*)calloc(N+1 , sizeof(char));
	 if (dynamicarray == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
	printf("Enter your full name:");
	scanf(" %[^\n]s",dynamicarray);
	printf("Your full name is: %s\n",dynamicarray);
	free(dynamicarray);
	return 0;
}