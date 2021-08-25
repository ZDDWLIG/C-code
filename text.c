#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void menu()
{
	printf("*********************\n");
	printf("*****   1.play  *****\n");
	printf("*****   0.exit  *****\n");
	printf("*********************\n");

}
void game()
{
	char ret;
	char arr[ROW][COL] = { 0 };
	Initboard(arr, ROW, COL);
	Displayboard(arr, ROW, COL);
	while (1)
	{
		Playermove(arr, ROW, COL);
		Displayboard(arr, ROW, COL);
		ret = Iswin(arr,ROW,COL);
		if (ret != 'C')
		{
			break;
		}
		Computermove(arr, ROW, COL);
		Displayboard(arr, ROW, COL);
		ret = Iswin(arr,ROW,COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("��ϲ����Ӯ��!\n");
	}
	else if (ret == '#')
	{
		printf("���ź���������\n");
	}
	else
	{
		printf("ƽ��");
	}
}
void text()
{
	int input = 0;
	do
	{
		menu();
		printf("��ѡ�� 1 �� 0\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("�����忪ʼ\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
		}
	} while (input);
}
int main()
{
	srand((unsigned int)time(0));
	text();
	return 0;
}