#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validateEmail(char *email){
    int atCount = 0;
    int dotAfterat = 0;
    int len = strlen(email);
    
        
    if (email[0] == '@' || email[len - 1] == '@' ) {
        return 0;
    }
        
    for(int i = 0; i < len; i++){
        if(email[i] == ' ')
        return 0;
        if(email[i] == '@'){
            atCount++;

              for(int j = i + 1; j < len; j++){
                if(email[j] =='.'){
                dotAfterat++ ;
            }
              }
        }
    }
    if (atCount == 1 && dotAfterat >= 1) 
        return 1;
    
    return 0;

}

int main(){
    char *email;
    int maxLength = 100; 
    
    email = (char *)malloc(maxLength * sizeof(char));
    
    if(email == NULL){
        printf("Memory allocation failed!\n");
        return 1;
    }
    printf("Enter email address:");
    scanf("%s", email);
    
    if (validateEmail(email)){
        printf("Valid Email");
    }
    else {
        printf("Invalid Email\n");
    }
    
    free(email);
    
    return 0;
}