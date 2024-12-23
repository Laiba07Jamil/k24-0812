#include <stdio.h>

struct Player{
	int ballscores[12];
	char playername [20];
	int totalscore;
};

void playgame(struct Player *player);
int validatescore(int score);
void findwinner(struct Player player1 , struct Player player2);
void displaymatchscoreboard(struct Player player1 , struct Player player2);


int main ()
{
	struct Player player1,player2;
	player1.totalscore = 0;
	player2.totalscore = 0;
	
	printf("Enter the name of player 1:");
	scanf(" %[^\n]s",player1.playername);
	printf("Enter the name of player 2:");
	scanf(" %[^\n]s",player2.playername);
	printf("\n %s's turn\n",player1.playername);
	playgame(&player1);
	printf("\n %s's turn\n",player2.playername);
	playgame(&player2);
	findwinner(player1 , player2);
	printf("\n");
	displaymatchscoreboard(player1 , player2);
}

void playgame(struct Player *player)
{
	int i,score;
	for(i = 0 ; i < 12 ; i++)
	{
		printf("Enter the score for ball %d:",i+1);
		scanf("%d",&score);
		
	   if(validatescore(score))
	 	{
			player->ballscores[i] = score;
			player->totalscore += score;
		}
		else{
			printf("Invalid score\n");
			player->ballscores[i] = 0;
		}
		
	}
		
	}


int validatescore(int score)
{
	return (score >= 0) && (score <= 6);
	
}


void findwinner(struct Player player1 , struct Player player2)
{
	if(player1.totalscore > player2.totalscore)
	{
		printf("\n%s won\n",player1.playername);
	}
	else if(player1.totalscore == player2.totalscore)
	{
		printf("Game tied\n");
	}
	else{
		printf("\n%s won \n",player2.playername);
	}
}


void displaymatchscoreboard(struct Player player1 , struct Player player2)
{
	int i;
	int sum1=0,sum2=0;
	printf("\nPLayer 1 performance\n");
	for(i = 0 ; i < 12 ; i++)
	{
		printf("%dth ball score = %d\n",i+1,player1.ballscores[i]);
		sum1 += player1.ballscores[i];
	}
	printf("Average score=%.2f\n",(float) sum1/12);
	printf("Total score of player 1=%d\n",player1.totalscore);
	
	printf("\nPlayer 2 performance\n");
	for(i = 0 ; i < 12 ; i++)
	{
		printf("%dth ball score = %d\n",i+1,player2.ballscores[i]);
		sum2 += player2.ballscores[i];
	}
	printf("Average score=%.2f\n",(float)sum2/12);
	printf("Total score of player 1=%d\n",player2.totalscore);
}

