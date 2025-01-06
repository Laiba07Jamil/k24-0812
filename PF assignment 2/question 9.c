#include<stdio.h>
void griddisplay(char grid[5][5]);
void playermove(char grid[5][5],int *playerX,int *playerY,char move);
int main ()
{
	char grid[5][5]={{' ', ' ', 'I', 'X', ' '},
	                 {' ', 'X', ' ', ' ', ' '},
					 {'I', ' ', 'X', 'X', ' '},
					 {' ', ' ', ' ', 'I', 'X'},
                     {' ', 'X', ' ', ' ', 'P'}};
    int playerX=4,playerY=4;
    char move;
    while(1){
    griddisplay(grid);
    printf("Enter character to move:\n1.'W' for up\n2.'S' for down\n3.'A' for left\n4.'D' for right\n5.'Q' for quit");
    scanf(" %c",&move);
    if(move=='Q'|| move=='q'){
    	printf("you are quiting\n");
    	return 0;
    	break;
	}
	playermove(grid,&playerX,&playerY,move);
}                    
}

void griddisplay(char grid[5][5])
{
	int i,j;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%c",grid[i][j]);
		}
		printf("\n");
	}
}

void playermove(char grid[5][5],int *playerX,int *playerY,char move)
{
	int newX=*playerX;
	int newY=*playerY;

	switch(move)
	{
		case 'W':
		case 'w':
			newX--;
			break;
		case 'S':
		case 's':
			newX++;
			break;
		case 'A':
		case 'a':
		    newY--;
		    break;
		case 'D':
		case 'd':
			newY++;
			break;
		default:
			printf("Invalid Input\n");
			return;
	}
	
	 if (newX < 0 || newX >= 5 || newY < 0 || newY >= 5) {
        printf("You can't move outside the grid\n");
        return;
    }
    
	if(grid[newX][newY]=='X'){
		printf("You can't move into an obstacle\n");
		return;
	}
	
	if(grid[newX][newY] == 'I')
	{
		printf("You have collected an item\n");
	}
	
	grid[*playerX][*playerY]=' ';
	grid[newX][newY]='P';
	
	*playerX=newX;
	*playerY=newY;

}