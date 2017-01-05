#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "windows.h"

int position_x,position_y;//飞机位置
int bullet_x,bullet_y;//子弹位置
int enemy_x,enemy_y;//敌机位置
int high,width;//游戏画面尺寸
int score;

void HideCursor()//隐藏光标
{
	CONSOLE_CURSOR_INFO cursor_info = {1, 0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}



void startup()
{
	high = 20;
	width = 30;
	position_x = high / 2;
	position_y = width / 2;
	bullet_x = -2;
	bullet_y = position_y;
	enemy_x = 0;
	enemy_y = position_y;
	score = 0;
}


void show()
{
	system("cls");
	int i,j;
	for (i = 0; i < high; i++)
	{
		for (j = 0;j < width;j++)
		{
			if ((i==position_x)&&(j==position_y))
				printf("*");//输出飞机
			else if ((i == enemy_x)&&(j == enemy_y))
				printf("@");//输出敌机
			else if ((i == bullet_x)&&(j == bullet_y))
				printf("|");//输出子弹
			else
				printf(" ");//输出空格
		}
		printf("\n");
	}
	printf("Score:%d\n",score);
}

void updateWithoutInput()
{
	if (bullet_x>-1)
		bullet_x--;

	if ((bullet_x==enemy_x)&&(bullet_y==enemy_y))
	{
		score++;
		enemy_x = -1;//产生新的敌机
		enemy_y = rand()%width;
		bullet_x = -2;
	}
	if (enemy_x>high)//敌机跑出边界
	{
		enemy_x = -1;
		enemy_y = rand()%width;
	}

	static int speed = 0;
	if (speed<15)
		speed++;
	if (speed == 15)
	{
		enemy_x++;
		speed = 0;
	}	
}

void updateWithInput()
{
	char input;
	if (kbhit())//
	{
		input = getch();//
		if (input == 'a')
			position_y--;
		if (input == 'd')
			position_y++;
		if (input == 'w')
			position_x--;
		if (input == 's')
			position_x++;
		if (input == ' ')
		{
			bullet_x = position_x - 1;
			bullet_y = position_y;
		}
	}
}

int main()
{
	startup();//数据初始化
	while(1)//游戏循环执行
	{
		show();//显示画面
		updateWithoutInput();//与用户输入无关的更新
		updateWithInput();//与用户输入有关的更新
		HideCursor();
	}

	return 0;
}
