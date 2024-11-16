#include <stdio.h>
#include <string.h>

typedef struct travelpackage{
	char name[50];
	char destination[50];
	char duration[20];
	float cost;
	int no_of_seats;
}travelpackage;

void display(travelpackage package[], int size);
void booking(travelpackage package[], int size, char packagename[] , int seats);

int main()
{
    travelpackage package[3];
    int i=0;
    
    strcpy(package[i].name,"Beach Paradise");
    strcpy(package[i].destination,"Hawaii");
    strcpy(package[i].duration,"1 day");
    package[i].cost = 1200.00;
    package[i].no_of_seats =5;
    i++;
    
    strcpy(package[i].name,"Adventure Mountain");
    strcpy(package[i].destination,"Swiss");
    strcpy(package[i].duration,"3 day");
    package[i].cost = 2000.00;
    package[i].no_of_seats =4;
    i++;
    
    strcpy(package[i].name,"City Lights");
    strcpy(package[i].destination,"Newyork");
    strcpy(package[i].duration,"5 day");
    package[i].cost = 5500.00;
    package[i].no_of_seats =6;
    i++;
    
    int choice,seats;
    char packagename[20];
    do
    {
    	printf("Enter your choice\n1.Dispaly Packages\n2.Book package\n3.Exit\n");
    	scanf("%d",&choice);
    	
    	switch (choice)
    	{
    		case 1:
    			printf("Displaying All Package\n");
    			display(package,3);
    			break;
    		case 2:
    			printf("Booking Package\n");
    			printf("Enter your packgae:");
    			scanf(" %[^\n]s",packagename);
    			printf("Enter the number of seats:");
    			scanf("%d",&seats);
    			booking(package,3,packagename ,seats);
    			break;
    		case 3:
    			printf("Thank you for coming:");
    			break;
    		default:
    			printf("Invalid input");
		}
	}
	while(choice!=3);
}

void display(travelpackage package[], int size)
{
	int i;
	for(i = 0;i <size ; i++)
	{
		printf("Name:%s\n",package[i].name);
		printf("Destination:%s\n",package[i].destination);
		printf("Duration:%s\n",package[i].duration);
		printf("Cost:%f\n",package[i].cost);
		printf("Seats:%d\n",package[i].no_of_seats);
		printf("\n");
	}
}

void booking(travelpackage package[], int size, char packagename[] , int seats)
{
	int i,flag=0;
	for(i =0; i<size;i++)
	{
	    if (strcmp(package[i].name,packagename)==0)
	    {
	    	flag=1;
	    	if(package[i].no_of_seats >= seats)
	    	{
	    		package[i].no_of_seats -= seats;
				printf("Booking confirmed\n");
			}
			else
			{	
				printf("seats not available\n");
			}
			break;
		}
	}
	if(!flag)
	{
		printf("Package not available");
	}
}






