#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

int main()
{
	int i,j;
	int x = 5;
	int y= 10;
	char input;
	int isFire = 0;

	int ny = 5;//一个靶子
	int isKilled = 0;

	while(1){
		system("cls");

		if (!isKilled)//输出靶子
		{
			for (j = 0;j<ny;j++)
				printf(" ");
			printf("+\n");
		}

		if (isFire == 0)
		{
			for(i=0;i<x;i++)
				printf("\n");
		}
		else
		{
			for(i=0;i<x;i++)
			{
				for (j=0;j<y;j++)
					printf(" ");
				printf("  |\n");

			}
			if (y + 2 == ny)
				isKilled = 1;
			isFire = 0;
		}

		for (j = 0; j < y; j++)
		{
			printf(" ");
		}
		printf("  *\n");
		for (j = 0; j < y; j++)
		{
			printf(" ");
		}
		printf("*****\n");
		for (j = 0; j < y; j++)
		{
			printf(" ");
		}
		printf(" * * \n");

		if (kbhit())
		{
			input = getch();
			if(input == 'a')
				y--;
			if (input == 'd')
				y++;
			if(input == 'w')
				x--;
			if(input == 's')
				x++;
			if (input == ' ')
				isFire = 1;
		}
		
	}

	return 0;
}