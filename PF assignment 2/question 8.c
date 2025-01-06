#include<stdio.h>
int BinaryToDecimal(int number);
int DecimalToBinary(int number);
void DecimalToHexadecimal(int number);
void HexadecimalToDecimal(char hexadecimal[]);
void BinaryToHexadecimal(int number);
void HexadecimalToBinary(char hexadecimal[]);
void displaymenu();

int main ()
{
	int choice,number;
	char hexadecimal[20];
	displaymenu();
	printf("Enter your choice:");
	scanf("%d",&choice);
	while(1)
	{
		switch(choice)
		{
			case 1:
				printf("Enter a binary number:");
				scanf("%d",&number);
				printf("Decimal:%d\n",BinaryToDecimal(number));
				break;
			case 2:
				printf("Enter a decimal number:");
				scanf("%d",&number);
				printf("Decimal:%d\n",DecimalToBinary(number));
				break;
			case 3:
				printf("Enter a decimal number:");
				scanf("%d",&number);
				DecimalToHexadecimal(number);
				break;
			case 4:
				printf("Enter the hexadecimal string:");
				scanf("%s",hexadecimal);
				HexadecimalToDecimal(hexadecimal);
				break;
			case 5:
				printf("Enter a binary number:");
				scanf("%d",&number);
				BinaryToHexadecimal(number);
				break;
			case 6:
				printf("Enter the hexadecimal string:");
				scanf("%s",hexadecimal);
				HexadecimalToBinary(hexadecimal);
				break;
			case 7:
				printf("Exiting\n");
				return 0;
			default:
				printf("Invalid Inputs\n");
			}
				
		}
	}

void displaymenu()
{
	printf("\nNumerical conversion System\n");
	printf("1.Binary to decimal\n");
	printf("2.decimal to binary\n");
	printf("3.Decimal to hexadecimal\n");
	printf("4.Hexadecimal to Decimal\n");
	printf("5.Binary to hexadecimal\n");
	printf("6.Hexadecimal to binary\n");
	printf("7.Exit\n");
}

int BinaryToDecimal(int number)
{
	int remainder,base=1,decimal=0;
	while(number>0)
	{
		remainder=number%10;
		decimal=decimal+(remainder*base);
		base=base*2;
		number /= 10;
	}
	return decimal;
}

int DecimalToBinary(int number)
{
	int rem,binary=0,base=10;
	while(number>0)
	{
		rem=number%2;
		binary =binary+(rem*base); 
		base *= 10;
		number /= 2;
	}
	return binary;
}

void DecimalToHexadecimal(int number)
{
	char hex[20],remainder;
	int i=0;
	while(number>0)
	{
		remainder=number%16;
		if(remainder <'10'){
			hex[i++]=remainder +'0';
		}
		else{
			hex[i++]=remainder-10+'A';
	
		}
		number /= 16;
	}
//	for(int j=i-1;j>=0;j--)
//	{
	printf("Hexadecimal\n");
	printf("%s",hex);	
	}


void HexadecimalToDecimal(char hexadecimal[])
{
	int decimal=0;
	for(int i=0;hexadecimal[i]!='\0';i++)
	{
		if(hexadecimal[i]>='0'&& hexadecimal[i]<='9'){
		decimal =decimal+hexadecimal[i]-'0';}
		else if(hexadecimal[i]>='A'&& hexadecimal[i]<='F'){
		decimal += hexadecimal[i]-'A'+ 10;}
	}
}

void BinaryToHexadecimal(int number)
{
	int decimal;
	BinaryToDecimal(number);
	DecimalToHexadecimal(decimal);
}

void HexadecimalToBinary(char hexadecimal[])
{
	int decimal;
	HexadecimalToDecimal(hexadecimal);
    printf("Binary:%d",DecimalToBinary(decimal));
}

