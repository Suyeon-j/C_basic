#include <stdio.h>
#define ROW 3
#define COL 3
#define TRUE 1
#define FALSE 0
void printTIC(int a[][COL]);
void initTIC(int a[][COL]);
void readInput(int *, int *);
int checkGame(int, int, int[][COL]);
int turn = 0;
int main()
{
	int tic[ROW][COL];
	int r, c;
	initTIC(tic);
	do {
		printTIC(tic);
		readInput(&r,&c);
		turn++;
	} while (!checkGame(r, c, tic));
	printTIC(tic);
}
void initTIC(int a[][COL]) {
	int i, j;
	for (i = 0; i < ROW; i++)
		for (j = 0; j < COL; j++)
			a[i][j] = -1;
}
void printTIC(int a[][COL]) {
	int i, j;
	//printf("|  --  |  --  |  --  |  \n");
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
			if (a[i][j] == -1)
				printf("       |");
			else if (a[i][j] == 1)
				printf("   O   |");
			else if(a[i][j] == 0)
				printf("   X   |");
		printf("\n");
	}
	//printf("|  --  |  --  |  --  |  \n");
}
void readInput(int *row, int *col)
{
	printf("\n위치를 입력하세요. :  ");
	scanf_s("%d %d", row, col);
	if (*row < 0 || *row>2 || *col < 0 || *col>2)
	{
		do
		{
			printf("\n<입력오류입니다.> \n0~2사이 숫자 두 개를 입력해주세요.\n");
			printf("<패널티로 턴이 넘어갑니다.>\n\n");
		} while (0);
	}
}
int checkGame(int row, int col, int a[][COL])
{
	int i, success = FALSE;
	a[row][col] = turn % 2;
	//가로
	success = TRUE;
	for (i = 0; i < COL; i++)
		if (a[row][i] != a[row][col])
		{
			success = FALSE;
			break;
		}
	if (success) return TRUE;
	//세로
	success = TRUE;
	for (i = 0; i < COL; i++)
		if (a[i][col] != a[row][col])
		{
			success = FALSE;
			break;
		}
	if (success) return TRUE;
	//대각선
	if (row == col)
	{
		success = TRUE;
		for (i = 0; i < ROW; i++)
			if (a[i][i] != a[row][col])
			{
				success = FALSE;
				break;
			}
		if (success) return TRUE;
	}
	return FALSE;
}
