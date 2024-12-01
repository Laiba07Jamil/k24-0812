#include <stdio.h>
#include <string.h>

int main() {
    int freq[100] = {0};
    char word[1000]; 
    char ch;
    char temp[1000];
    int a=0;
    int i = 0;

    FILE *ptr = fopen("file1.txt", "r");
    if (!ptr) {
        printf("Error: Could not open file ");
        return 1;
    }
   while ((ch = fgetc(ptr)) != EOF) {
        word[i++] = ch;
    }
    word[i] = '\0'; 

    fclose(ptr);

    int length = strlen(word);
    for (int j = 0; j < length; j++) {
        ch = word[j];
        if (freq[j] == 0) { 
        
        temp[a++]=ch;
            freq[j]++;
            for (i = j + 1; i < length; i++) {
                if (word[i] == ch) { 
                    freq[j]++;
                    freq[i] = 1;
                }
            }
        }
    }
    temp[a]='\0';
    int L=strlen(temp);

    for (int j = 0; j < L; j++) {
        if (freq[j] > 0) {
            printf("'%c': %d\n", temp[j], freq[j]);
        }
    }

    return 0;
}
