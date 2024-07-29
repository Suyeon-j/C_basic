#include <stdio.h>
#define MAX 100
void ShowMainMenu();
int ReadInput();
void Join();
void Print();
void LogIn();

struct Account
{
	int id;
	int passwd;
	int money;
};

struct Account account[MAX];
int numOfAccount = 0;
int main()
{
	int input;
	do
	{
		ShowMainMenu();
		input = ReadInput();
		switch (input)
		{
		case 1:
			LogIn();
			break;
		case 2:
			Join();
			break;
		case 3:
			return 0;
			break;
		case 4:
			Print();
			break;
		default:
			printf("\nTry again\n");
			break;
		}
	} while (1);
}
void ShowMainMenu()
{
	printf("\n=== Main Menu ===");
	printf("\n1. Login");
	printf("\n2. Join");
	printf("\n3. Exit");
	printf("\n4. Print");
	printf("\nChoice > ");
}
int ReadInput()
{
	int input;
	scanf_s("%d", &input);
	return input;
}
void Join()
{
	int id, pwd;
	struct Account temp;
	printf("Enter ID: ");
	scanf_s("%d", &id);
	printf("Enter PWD: ");
	scanf_s("%d", &pwd);

	temp.id = id;
	temp.passwd = pwd;
	temp.money = 1000;

	account[numOfAccount++] = temp;
}
void Print()
{
	int i;
	for (i = 0; i < numOfAccount; i++) {
		printf("\n=== %d Account ===", i + 1);
		printf("\nID : %d", account[i].id);
		printf("\nPWD : %d", account[i].passwd);
		printf("\nMoney : %d", account[i].money);
	}
}
void LogIn()
{
	int id, pwd, i;

	printf("Enter ID: ");
	scanf_s("%d", &id);
	printf("Enter PWD: ");
	scanf_s("%d", &pwd);
	
	for (i = 0; i < numOfAccount; i++) {
		if (id == account[i].id && pwd == account[i].passwd) {
			printf("로그인 성공!\n");
		}
		else
			printf("로그인 실패 다시 입력하세요.\n");
	}
}
