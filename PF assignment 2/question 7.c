/*One of the master coders designed a subscript block that stores random characters in a 
multidimensional array. You are asked to design a program that will find a given string in a 
multidimensional array of characters. The search for characters can be present and operational 
from left to right and top to down only. The program should create a 6 x 5 2D array and populate 
it with random alphabet characters. After that, the program should print it in a tabular form as 
shown below. Search the user-entered string in the 2D array, if it is present then add a point to the 
score, if it is not available then subtract one. Print the score at every input. The program stops 
asking and re-populates the 2D array with new random characters when the user enters “END” as 
the string.
[NOTE: After generating random numbers, the last row should have your student ID’s last four 
digits]
E D D F R
A F V A Q
T E B S T
L J G T T
1 2 3 4 Q
Search Str= “FAST”
Output:
FAST is present Score 1
Search Str= “EAT”
EAT is present Score 2
Search Str= “GREAT”
GREAT is not present Score 1*/
#include <stdio.h>

// Function to generate the 6x5 array with random characters
void generate_random_array(char array[6][5], const char student_id_last4[4]) {
    // Fill the first 5 rows with random uppercase letters
    int i,j;
    for ( i = 0; i < 5; i++) {
        for ( j = 0; j < 5; j++) {
            array[i][j] = 'A' + (rand() % 26);  // Random letter from A-Z
        }
    }

    // Fill the last row with student ID's last four digits and a random letter
    for ( j = 0; j < 4; j++) {
        array[5][j] = student_id_last4[j];
    }
    array[5][4] = 'A' + (rand() % 26);  // Random letter
}

// Function to print the 2D array
void print_array(char array[6][5]) {
	int i,j;
    for ( i = 0; i < 6; i++) {
        for (j = 0; j < 5; j++) {
            printf("%c ", array[i][j]);
        }
        printf("\n");
    }
}

// Function to search for a string in the array (left-to-right and top-to-bottom)
int search_string(char array[6][5], char* search_str) {
    int str_len = 0;

    // Calculate the length of the search string manually
    while (search_str[str_len] != '\0') {
        str_len++;
    }
int i,j,k;
    // Row-wise search
    for ( i = 0; i < 6; i++) {
        for ( j = 0; j <= 5 - str_len; j++) {
            int found = 1;  // Assume found until proven otherwise
            for ( k = 0; k < str_len; k++) {
                if (array[i][j + k] != search_str[k]) {
                    found = 0;  // Not found
                    break;
                }
            }
            if (found) {
                return 1;  // Found
            }
        }
    }

    // Column-wise search
    for (j = 0; j < 5; j++) {
        for ( i = 0; i <= 6 - str_len; i++) {
            int found = 1;  // Assume found until proven otherwise
            for ( k = 0; k < str_len; k++) {
                if (array[i + k][j] != search_str[k]) {
                    found = 0;  // Not found
                    break;
                }
            }
            if (found) {
                return 1;  // Found
            }
        }
    }

    return 0;  // Not found
}

int main() {
    char array[6][5];
    char student_id_last4[4] = {'1', '2', '3', '4'}; // Replace with last four digits of student ID
    int score = 0;
    char search_str[20];

    // Generate the initial random array
    generate_random_array(array, student_id_last4);

    while (1) {
        printf("\nArray:\n");
        print_array(array);
int i;
        printf("\nSearch Str= ");
        // Read input string
        for (i = 0; i < 19; i++) {
            search_str[i] = getchar();
            if (search_str[i] == '\n') {
                search_str[i] = '\0';  // Null-terminate the string
                break;
            }
        }

        // Check for "END" input
        if (search_str[0] == 'E' && search_str[1] == 'N' && search_str[2] == 'D' && search_str[3] == '\0') {
            generate_random_array(array, student_id_last4);  // Repopulate array with new characters
            printf("\nArray has been re-populated with new random characters.\n");
            continue;
        }

        // Search for the string
        if (search_string(array, search_str)) {
            score += 1;
            printf("%s is present Score %d\n", search_str, score);
        } else {
            score -= 1;
            printf("%s is not present Score %d\n", search_str, score);
        }
    }

    return 0;
}

