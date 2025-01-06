#include <stdio.h>
#include <string.h>
#include <ctype.h>

int anagram(const char *arr, const char *arr2);
int main()
{
    char str[100][100];
    int n;
    printf("Enter the number of codes:\t");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter code %d:\t", i + 1);
        scanf("%s", str[i]);
        for (int j = 0; str[i][j] != '\0'; j++)
        {
            str[i][j] = tolower(str[i][j]);
        }
    }

    int grouped[100] = {0};

    printf("[ ");
    for (int i = 0; i < n; i++)
    {
        if (grouped[i])
        {
            continue;
        }
        printf("[ \'%s\' ", str[i]);
        grouped[i] = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (grouped[j] == 0 && anagram(str[i], str[j]) == 1)
            {
                printf(", \'%s\' ", str[j]);
                grouped[j] = 1;
            }
        }
        printf("]");
        if (i != n-1)
            printf(", ");
    }
    printf(" ]\n");

    return 0;
}

int anagram(const char *arr, const char *arr2)
{
    if (strlen(arr) != strlen(arr2))
    {
        return 0;
    }

    int freq[26] = {0}; // size 26 because we have already converted our strings to lowercase

    // frequency of each character in string 1
    for (int i = 0; arr[i] != '\0'; i++)
    {
        freq[arr[i] - 'a']++;
    }

    // frequency of each character in string 1
    for (int i = 0; arr2[i] != '\0'; i++)
    {
        freq[arr2[i] - 'a']--;
    }

    // Check if all frequencies are zero
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] != 0)
        {
            return 0;
        }
    }
    return 1;
}