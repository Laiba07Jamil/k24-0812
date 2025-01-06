#include <stdio.h>

struct Employee {
	char employeecode [20];
	char employeename [20];
	int dateofjoining ;        //assuming only year
};

void employee_input(struct Employee emp[] ,int n);
int calculate_tenure(struct Employee emp[] , int n ,int curr_year);

int main ()
{
	struct Employee emp[4];
	int curr_year;
	employee_input(emp,4);
	printf("Enter the current year:");   //assuming only year
	scanf("%d",&curr_year);
	printf("\n");
	printf("Displaying the details of employee\n");
	calculate_tenure(emp,4,curr_year);
	
}

void employee_input(struct Employee emp[] ,int n)
{
	int i;
	for(i = 0 ; i < n ; i++)
	{
		printf("Enter the code of employee %d:",i+1);
		scanf("%s",emp[i].employeecode);
		printf("Enter the name of Employee %d:",i+1);
		scanf(" %[^\n]s",&emp[i].employeename);
		printf("Enter the year of joinig of employee %d:",i+1);
		scanf("%d",&emp[i].dateofjoining);
		printf("\n");
	}
}

int calculate_tenure(struct Employee emp[] , int n ,int curr_year)
{
	int i,tenure;
	int count=0;
	for(i = 0; i < n ; i++)
	{
		tenure = curr_year - emp[i].dateofjoining;
		
		if(tenure > 3)
		{
			printf("Employee code=%s\n",emp[i].employeecode);
			printf("Emplyee name=%s\n",emp[i].employeename);
			printf("date of joining=%d\n",emp[i].dateofjoining);
			printf("Tenure=%d\n",tenure);
			count++;
		}
		printf("\n");
	}
	printf("The number of employees who have passed more than 3 years are %d\n",count);
	
	
}