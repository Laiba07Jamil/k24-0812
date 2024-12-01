/*Using Task. 4, resize that dynamic array of character and append the array with your studentId.
That student id must be taken input from the user.
DynamicArray = "Muhib Ahmed" // Before
DynamicArray = "K241234Muhib Ahmed" // After the text append*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	
	char* temp = (char*)calloc(N+1 , sizeof(char));
	 if (temp == NULL) {
        printf("Memory allocation failed\n");
        free(dynamicarray);
        return 1;
    }
    strcpy(temp,dynamicarray);
	int size;
	printf("Enter the number of elements in your student ID:");
	scanf("%d",&size);
	dynamicarray = realloc(dynamicarray , ((N + 1)+(size+1)) * sizeof(char));
	 if (dynamicarray == NULL) {
        printf("Memory reallocation failed\n");
        free(temp);
        return 1;
    }
    
    char id[10];
	printf("Enter your student ID:");
	scanf("%s",id);
	strcpy(dynamicarray,id);
	dynamicarray[size] = ' ';
	for(int i = 0 ; i < N ; i++){
		dynamicarray[i+size+1] = temp[i];
	}
	 dynamicarray[size + 1 + N] = '\0';
	printf("Your name with ID = %s\n",dynamicarray);
	free(dynamicarray);
	free(temp);
	return 0;
}