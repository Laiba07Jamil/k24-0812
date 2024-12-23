
#include <stdio.h>
#include <stdlib.h>

struct Employee{
	int* ratings;
	int totalscore;
};

void inputEmployees(int** ratings , int numEmployee , int numperiods);
void displayperformance(int** ratings , int numEmployee , int numperiods);
int findEmployeeOfTheYear(int** ratings , int numEmployee , int numperiods);
int findHighestRatedPeriod(int** raings , int numEmployee , int numperiods);
int findWorstPerformingEmployee(int** ratings , int numEmployee , int numperiods);

int main ()
{
	int numEmployee;
	int numperiods;
	printf("Enter the number of Employees:");
	scanf("%d",&numEmployee);
	printf("Enter the number of periods:");
	scanf("%d",&numperiods);
	
	int** ratings = (int**)malloc(numEmployee * sizeof(int*));
	for(int i = 0 ; i < numEmployee ; i++)
	{
		ratings[i] = (int*)malloc(numperiods * sizeof(int));
	}
	
	printf("\n");
     inputEmployees(ratings , numEmployee , numperiods);
     printf("\nDisplaying Performance\n");
     displayperformance(ratings , numEmployee , numperiods);
     int EOTY = findEmployeeOfTheYear(ratings , numEmployee , numperiods);
     printf("\nThe Employee of the year is employee %d:",EOTY+1);
     int HRP = findHighestRatedPeriod(ratings , numEmployee , numperiods);
     printf("\nThe Highest Rated Period is period no %d:",HRP+1);
     int WPE = findWorstPerformingEmployee(ratings ,numEmployee ,numperiods);
	 printf("\nThe Worst Emplyee of the year is employee %d:",WPE+1);
	 
	 for(int i = 0 ; i < numEmployee ; i++)
	 {
	 	free(ratings[i]);
	 }
	 free(ratings);
	return 0;
}

void inputEmployees(int** ratings , int numEmployee , int numperiods)
{
	for(int i = 0 ; i < numEmployee ; i++)
	{
		printf("Enter the ratings for %d employee\n\n",i+1);
		for( int j = 0 ; j < numperiods ; j++)
		{
			do{
			printf("Enter rating for period %d between (1-10):",j+1);
			scanf("%d",&ratings[i][j]);
			if(ratings[i][j] < 1 || ratings[i][j] > 10 )
			{
				printf("Inavlid Input Plz Enter again.\n");
			}
		}
		while(ratings[i][j] < 1 || ratings[i][j] > 10);
		}
		printf("\n");
	}
	
}

void displayperformance(int** ratings , int numEmployee , int numperiods)
{
	for(int i = 0 ; i < numEmployee ; i++)
	{
		printf("[");
		for(int j = 0 ; j < numperiods ; j++)
		{
			printf("%d ",ratings[i][j]);
		}
		printf("]\n");
	}
}

int findEmployeeOfTheYear(int** ratings , int numEmployee , int numperiods)
{
	float average = 0.0;
	float maxavg = 0.0;
	int maxindex=0;
	for(int i = 0 ; i < numEmployee ; i++)
	{
	    int sum=0;
		for(int j = 0 ; j < numperiods ; j++)
		{
			sum += ratings[i][j];
		}
			average = (float)sum / numperiods;
		if(average  > maxavg)
		maxavg = average;
		maxindex = i;
	}
	return maxindex;
}

int findHighestRatedPeriod(int** ratings , int numEmployee , int numperiods)
{
	float average;
	float maxavg = 0.0;
	int maxindex = 0;
	for(int j = 0 ; j < numperiods ; j++)
	{
	    int sum =0;
		for(int i = 0 ; i < numEmployee ; i++)
		{
			sum += ratings[i][j];
		}
		average =(float)sum / numEmployee ;
		if( average > maxavg )
		{
			maxavg = average;
			maxindex = j;
		}
	}
	return maxindex;
}

int findWorstPerformingEmployee(int** ratings , int numEmployee , int numperiods)
{
    float average;
    float minavg = 10.0; 
    int index= 0;
    for(int i = 0 ; i < numEmployee ; i++)
    {
        int sum=0;
    	for(int j = 0; j < numperiods ; j++)
    	{
    		sum += ratings[i][j];
		}
		average =(float)sum / numperiods;
		if(average < minavg)
		{
			minavg = average;
			index = i;
		}
	}
	return index;
}