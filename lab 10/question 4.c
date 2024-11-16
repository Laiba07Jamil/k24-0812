#include <stdio.h>
#include <string.h>
typedef struct book{
	char title[20];
	char author[20];
	int publication_year;
	float price;
}book;

void display(book Books[],int size);
void search_title(book Books[] , int size , char searchtitle[]);
void search_author(book Books[] , int size , char searchauthor[]);

int main()
{
	int size;
	printf("Enter the num of books:");
	scanf("%d",&size);
	book Books[size];
	int i;
	for(i = 0 ; i < size ; i++ )
	{
		printf("Enter title of book %d:",i+1);
		scanf(" %[^\n]s",Books[i].title);
		printf("Enter author's name of book %d:",i+1);
		scanf(" %[^\n]s",Books[i].author);
		printf("Enter publication year of book %d:",i+1);
		scanf("%d",&Books[i].publication_year);
		printf("Enter the price of book %d:",i+1);
		scanf("%f",&Books[i].price);
		printf("\n");
	}
	int choice;
	do{
		printf("What do u want to do?\n1.Display all books\n2.Search book by title\n3.search book by author\n4.Exit\n");
		scanf("%d",&choice);
		printf("\n");
		switch(choice)
		{
			case 1:
				printf("Displaying all books:");
				display(Books,size);
				break;
			case 2:
				printf("Searching book by title\n");
				char searchtitle[20];
				printf("Enter the title to search:");
				scanf(" %[^\n]s",searchtitle);
				search_title(Books , size ,searchtitle);
				printf("\n");
				break;
			case 3:
				printf("Searching book by author\n");
				char searchauthor[20];
				printf("Enter author's name to search:");
				scanf(" %[^\n]s",searchauthor);
				search_author(Books , size , searchauthor);
				printf("\n");
				break;
			case 4:
				printf("Thank you for coming\n");
				break;
			default:
				printf("Invalid input");
		}
		
	}
	while(choice!=4);
	printf("\n");
	
}

void display(book Books[],int size)
{
	int i;
	for(i = 0 ; i < size ; i++)
	{
	    printf("Tilte of book %d=%s\n",i+1,Books[i].title);
	    printf("Author's name of book %d=%s\n",i+1,Books[i].author);
	    printf("Publication year of book %d=%d\n",i+1,Books[i].publication_year);
	    printf("Price of book %d=%.2f\n",i+1,Books[i].price);
	    printf("\n");
	}
}

void search_title(book Books[] , int size , char searchtitle[])
{
	int i,found=0;
	for(i = 0 ; i < size ; i++)
	{
		if(strcmp(Books[i].title,searchtitle)==0)            //if two strings match it would return value 0
		{
			found=1;
		}
	}
	if(found==1)
	printf("%s book is available",searchtitle);
	else{
		printf("%s book is not avaiable",searchtitle);
	}
}

void search_author(book Books[] , int size , char searchauthor[])
{
	int i,found=0;
	for(i = 0 ;i < size ; i++)
	{
		if(strcmp(Books[i].author,searchauthor)==0)
		{
			found=1;
		}
	}
	if(found==1)
	{
		printf("%s auhtor's name book is available",searchauthor);
	}
	else 
	{
		printf("%s author's name book us not available",searchauthor);
	}
}







