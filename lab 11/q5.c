#include <stdio.h>
#include <string.h>

struct Date{
	char day[10];
	char month[10];
	int year;
};

struct Events{
	char event_name[20];
	struct Date dates;
	char location[20];
};

int main()
{
	struct Events events;
	strcpy(events.event_name,"PROCOM");
	strcpy(events.dates.day,"Thursday");
	strcpy(events.dates.month,"August");
	events.dates.year = 2007 ;
	strcpy(events.location,"Bahria Town");
	
	printf("Event name = %s\n",events.event_name);
	printf("Event day = %s\n",events.dates.day);
	printf("Event month = %s\n",events.dates.month);
	printf("Event year = %d\n",events.dates.year);
	printf("Event Location = %s\n",events.location);
}