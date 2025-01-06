#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **supplies;
    int supplyCount;
} Species;

Species *speciesArray; // Dynamic array of species
char **speciesNames;   // Array to store species names
int speciesCount = 0;

void addSpecies() {
    printf("Enter the number of species to add:\n");
    int count;
    scanf("%d", &count);

    speciesArray = realloc(speciesArray, (speciesCount + count) * sizeof(Species));
    speciesNames = realloc(speciesNames, (speciesCount + count) * sizeof(char *));
    
    for (int i = 0; i < count; i++) {
        speciesArray[speciesCount + i].supplies = NULL;
        speciesArray[speciesCount + i].supplyCount = 0;

        speciesNames[speciesCount + i] = malloc(100 * sizeof(char)); // Allocate memory for species name
        printf("Enter the name of species %d: ", speciesCount + i + 1);
        scanf("%99s", speciesNames[speciesCount + i]);

        // Allocate memory for supplies
        printf("Enter number of supplies for species %d: ", speciesCount + i + 1);
        int supplyCount;
        scanf("%d", &supplyCount);
        speciesArray[speciesCount + i].supplies = calloc(supplyCount, sizeof(char *));
        speciesArray[speciesCount + i].supplyCount = supplyCount;

        for (int j = 0; j < supplyCount; j++) {
            speciesArray[speciesCount + i].supplies[j] = malloc(100 * sizeof(char));
            printf("Enter the name of supply %d for species %d: ", j + 1, speciesCount + i + 1);
            scanf("%99s", speciesArray[speciesCount + i].supplies[j]);

            printf("Enter number of items for supply %d of species %d: ", j + 1, speciesCount + i + 1);
            int itemCount;
            scanf("%d", &itemCount);

            // Allocate memory for items
            char **items = calloc(itemCount, sizeof(char *));
            for (int k = 0; k < itemCount; k++) {
                items[k] = malloc(100 * sizeof(char));
                printf("Enter the name of item %d for supply %d of species %d: ", k + 1, j + 1, speciesCount + i + 1);
                scanf("%99s", items[k]);
            }

            // Print items for the current supply
            printf("Items for supply %s of species %s:\n", speciesArray[speciesCount + i].supplies[j], speciesNames[speciesCount + i]);
            for (int k = 0; k < itemCount; k++) {
                printf("  - %s\n", items[k]);
                free(items[k]);
            }
            free(items);
        }
    }

    speciesCount += count;
}

void displayInventory() {
    printf("Current Inventory:\n");
    for (int i = 0; i < speciesCount; i++) {
        printf("Species %d: %s\n", i + 1, speciesNames[i]); // Display species name
        for (int j = 0; j < speciesArray[i].supplyCount; j++) {
            printf("  Supply: %s\n", speciesArray[i].supplies[j]);
        }
    }
}

void updateSupply() {
    int speciesIndex, supplyIndex;
    printf("Enter species index to update supplies (1-%d): ", speciesCount);
    scanf("%d", &speciesIndex);
     

    if (speciesIndex < 1 || speciesIndex > speciesCount) {
        printf("Invalid species index!\n");
        return;
    }
    speciesIndex--;

    printf("Enter supply index you want to update(1-%d): ", speciesArray[speciesIndex].supplyCount);
    scanf("%d", &supplyIndex);
   

    if (supplyIndex < 1 || supplyIndex > speciesArray[speciesIndex].supplyCount) {
        printf("Invalid supply index entered\n");
        return;
    }
     supplyIndex--; 

    printf("Enter new supply name: ");
    char newSupply[100];
    scanf("%s", newSupply);
    free(speciesArray[speciesIndex].supplies[supplyIndex]);
    speciesArray[speciesIndex].supplies[supplyIndex] =(char*) malloc(100 * sizeof(char));
    strcpy(speciesArray[speciesIndex].supplies[supplyIndex], newSupply);
}

void removeSpecies() {
    int speciesIndex;
    printf("Enter species index you want to remove (from 1 to %d): ", speciesCount);
    scanf("%d", &speciesIndex);
    speciesIndex--; 

    if (speciesIndex < 0 || speciesIndex >= speciesCount) {
        printf("Invalid species index has entered!\n");
        return;
    }
    for (int j = 0; j < speciesArray[speciesIndex].supplyCount; j++) {
        free(speciesArray[speciesIndex].supplies[j]);
}
    free(speciesArray[speciesIndex].supplies);
    free(speciesNames[speciesIndex]); 

    for (int i = speciesIndex; i < speciesCount - 1; i++) 
    {
        speciesArray[i] = speciesArray[i + 1];
        speciesNames[i] = speciesNames[i + 1]; 
    }

    speciesCount--;
    speciesArray = realloc(speciesArray, speciesCount * sizeof(Species));
    speciesNames = realloc(speciesNames, speciesCount * sizeof(char *));
    printf("Species removed successfully.\n");
}



int main() {
    speciesArray = NULL;
    speciesNames = NULL;

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add Species\n");
        printf("2. Display Inventory\n");
        printf("3. Update Supply\n");
        printf("4. Remove Species\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSpecies();
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                updateSupply();
                break;
            case 4:
                removeSpecies();
                break;
            case 5:
               {
    for (int i = 0; i < speciesCount; i++)
     {
        for (int j = 0; j < speciesArray[i].supplyCount; j++) {

            free(speciesArray[i].supplies[j]);}
        free(speciesArray[i].supplies);
         free(speciesNames[i]);
 }
 
    free(speciesArray);
    free(speciesNames); 
}
                break;
            default:
                printf("Invalid choice. Please enter again again.\n");
        }
    } while (choice != 5);

    return 0;
}