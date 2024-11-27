/*Define a structure Company with fields name, year_established, and an array
departments containing the names of up to 5 departments. Write a program to display
company details including all departments.*/

#include <stdio.h>

typedef struct{
	char name[20];
	int year_established;
	char* departments[5];
}Company;

int main()
{
	Company companies;
	companies.departments[0]="Finance";
	companies.departments[1]="Marketing";
	companies.departments[2]="Science";
	companies.departments[3]="Software";
	companies.departments[4]="IT";
	printf("Enter the name of company:");
	scanf("%[^\n]s",companies.name);
	printf("Enter the year :");
	scanf("%d",&companies.year_established);
	printf("\nCompany details\n");
	printf("Name=%s\n",companies.name);
	printf("Year=%d\n",companies.year_established);
	for(int i= 0 ; i < 5 ; i++)
	{
		printf("Departments=%s\n",companies.departments[i]);
	}
}                           