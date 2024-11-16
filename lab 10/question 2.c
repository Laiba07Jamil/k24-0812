#include <stdio.h>
#include <math.h>

typedef struct points{
	int x;
	int y;
}points;

int calculate(points point1 , points point2);
void rect_bound(points point1 , points pointA, points pointB, points pointC, points pointD);

int main()
{
	points point1,point2;
	points pointA,pointB,pointC,pointD;
	 
	printf("Enter x1 and y1 of point1:");
	scanf("%d %d",&point1.x,&point1.y);
	printf("Enter x2 and y2 of point2:");
	scanf("%d %d",&point2.x,&point2.y);
	int distance=calculate(point1 , point2);
	printf("Distance=%d\n",distance);
	printf("Enter boundaries of rectangle :");
	
	printf("Enter the coordinates of top-left corner:");
	scanf("%d %d",&pointA.x,&pointA.y);
	
	printf("Enter the coordinates of top-right corner:");
	scanf("%d %d",&pointB.x,&pointB.y);
	
	printf("Enter the coordinates of bottom-right corner:");
	scanf("%d %d",&pointC.x,&pointC.y);

	printf("Enter the coordinates of bottom-left corner:");
	scanf("%d %d",&pointD.x,&pointD.y);
	rect_bound(point1 ,pointA,pointB,pointC,pointD);
	return 0;
	
}

int calculate(points point1 , points point2)
{
	int distance;
	distance = sqrt( ((point2.x-point1.x)*(point2.x-point1.x)) + ((point2.y-point1.y)*(point2.y-point1.y)) );
	return distance;
}

void rect_bound(points point1 , points pointA, points pointB, points pointC, points pointD)
{
	if ((point1.x >= pointC.x && point1.x >= pointD.x ) && (point1.y >= pointC.y && point1.y >= pointD.y))
	{
		if ((point1.x <= pointA.x && point1.x <= pointB.x ) && (point1.y <= pointA.y && point1.y <= pointB.y))
		{
			printf("The point (%d,%d) lies within specific rectangular boundary\n",point1.x,point1.y);
		}
		else{
	     	printf("The point (%d,%d) doesnot lies within specific rectangular boundary\n",point1.x,point1.y);
		}
	}
	else{
		printf("The point (%d,%d) doesnot lies within specific rectangular boundary\n",point1.x,point1.y);
	}
}