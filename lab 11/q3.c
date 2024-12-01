#include <stdio.h>
#include <string.h>


int main() {
    char oldWord[20] ;  

    char newWord[20] ;   
    printf("enter the word you want to replace\n");
    scanf(" %s",oldWord);
    printf("enter the word you want to replace with\n");
    scanf(" %s",newWord);
    char content[1000]; 
    char result[1000];  
    int i = 0, j = 0,a=0;       
    int oldWordLen = strlen(oldWord);
    int newWordLen = strlen(newWord);
FILE *file = fopen("file1.txt", "r");
if (!file) {
        printf("Error: Could not open file ");
        return 1;
    }

while((content[a++]=fgetc(file))==EOF)
content[--a]='\0';
    

    while (content[i] != '\0') {
        if (strncmp(&content[i], oldWord, oldWordLen) == 0) {
            strcpy(&result[j], newWord);
            i += oldWordLen; 
            j += newWordLen; 
        } else {
            result[j++] = content[i++];
        }
    }
    result[j] = '\0'; 
    file = fopen("file1.txt", "w");
    if (!file) {
        printf("Error: Could not open file");
        return 1;
    }
    fputs(result, file);
    fclose(file);

    printf("Word replacement completed.\n");
    return 0;
}
