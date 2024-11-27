/*Define a structure Employee with fields name, id, salary, and a nested structure Address
(fields: city and zip_code). Write a program to input details for multiple employees,
store them in a file, and read them back to display.*/

#include <stdio.h>

struct Address{
	char city[20];
	char zip_code[20];
};

struct Employee{
	char name[20];
	int id;
	float salary;
	struct Address _address_;
};

int main()
{
	FILE *file=fopen("file.txt","w");
	if(file==NULL)
	{
		printf("Invalid file doesnot exist\n");
		return 0;
	}
	struct Employee employees[5];
	for (int i = 0 ; i < 5 ; i++)
	{
		printf("Enter the name of employee%d:",i+1);
		scanf(" %[^\n]s",employees[i].name);
		printf("Enter the id:");
		scanf("%d",&employees[i].id);
		printf("Enter the salary:");
		scanf("%f",&employees[i].salary);
		printf("Enter the city:");
		scanf(" %[^\n]s",employees[i]._address_.city);
		printf("Enter the zip code:");
		scanf(" %[^\n]s",employees[i]._address_.zip_code);
		printf("\n");
	}
	
	for(int i = 0 ; i < 5 ; i++)
	{
		fprintf(file,"Name = %s\n",employees[i].name);
		fprintf(file,"ID = %d\n",employees[i].id);
		fprintf(file,"Salary = %.3f\n",employees[i].salary);
		fprintf(file,"City = %s\n",employees[i]._address_.city);
		fprintf(file,"Zip code = %s\n",employees[i]._address_.zip_code);
	}
	fclose(file);
	
     file=fopen("file.txt","r");
	if(!file)
	{
		printf("Invalid file doesnot exist\n");
		return 0;
	}
	char buffer[100];
	while(fgets(buffer,100,file)!=NULL)
	{
		printf("%s \n",buffer);
	}
	fclose(file);
	return 0;
}