#include <stdio.h>
#include <string.h>
#define MAX 100
void ShowMainMenu();
int ReadInput();
void Join();
void Print();
void LogIn();
void Bank(int a);
void ShowBankMenu();
int resultid, resultpwd;

struct Account
{
	//int id;
	char id[10];
	//int passwd;
	char passwd[9];
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
	printf("Enter ID: ");
	scanf_s("%s", account[numOfAccount].id, sizeof(account[numOfAccount].id));

	printf("Enter PWD: ");
	scanf_s("%s", account[numOfAccount].passwd, sizeof(account[numOfAccount].passwd));

	account[numOfAccount++].money = 1000;
}
void Print()
{
	int i;
	for (i = 0; i < numOfAccount; i++) {
		printf("\n=== %d Account ===", i + 1);
		printf("\nID : %s", account[i].id);
		printf("\nPWD : %s", account[i].passwd);
		printf("\nMoney : %d\n", account[i].money);
	}
}
void LogIn()
{
	char id[10], pwd[9];
	int i;

	printf("Enter ID: ");
	scanf_s("%s", id, sizeof(account[numOfAccount].id));
	printf("Enter PWD: ");
	scanf_s("%s", pwd, sizeof(account[numOfAccount].passwd));

	for (i = 0; i < numOfAccount; i++) {
		resultid = strcmp(account[i].id, id);
		resultpwd= strcmp(account[i].passwd, pwd);

		if (resultid == 0 && resultpwd == 0) {
				printf("로그인 성공!\n");
				Bank(i);
				break;
			}
			else if (resultid == 0) {
				printf("비밀번호를 잘못 입력했습니다.\n");
				break;
			}
	}
	if (i == numOfAccount)
		printf("아이디가 존재하지않습니다.");
}
void Bank(int a)
{
	int input, money, i;
	char id[10];
	do {
		ShowBankMenu();
		input = ReadInput();
		switch (input)
		{
		case 1:
			printf("입금할 금액을 입력하세요. > ");
			scanf_s("%d", &money);
			account[a].money += money;
			printf("%d원이 입금되어 총 잔액은 %d입니다.\n", money, account[a].money);
			break;
		case 2:
			printf("출금할 금액을 입력하세요. > ");
			scanf_s("%d", &money);
			if (money > account[a].money) {
				printf("잔금 부족으로 출금할 수 없습니다.\n");
			}
			else {
				account[a].money -= money;
				printf("%d원이 출금되어 총 잔액은 %d입니다.\n", money, account[a].money);
			}
			break;
		case 3:
			printf("받으실 분의 아이디를 입력하세요. > ");
			scanf_s("%s", id, sizeof(account[numOfAccount].id));
			printf("송금할 금액을 입력하세요. > ");
			scanf_s("%d", &money);
			for (i = 0; i < numOfAccount; i++) {
				resultid = strcmp(account[i].id, id);

				if (resultid == 0) {
					if (money > account[a].money) {
						printf("잔금 부족으로 송금할 수 없습니다.\n");
						break;
					}
					else {
						account[a].money -= money;
						account[i].money += money;
						printf("%s 회원에게 %d원을 송금하여 총 잔액은 %d입니다.\n", id, money, account[a].money);
						break;
					}
				}
			}
			if (i == numOfAccount)
				printf("송금자가 존재하지않습니다.\n");
			break;
		case 4:
			printf("%s님의 총 잔액은 %d원입니다.\n", account[a].id, account[a].money);
			break;
		case 5:
			return;
			break;
		default:
			printf("\nTry again\n");
		}
	} while (1);
}
void ShowBankMenu()
{
	printf("\n=== Bank Menu ===");
	printf("\n1. Deposit");
	printf("\n2. Withdrawal");
	printf("\n3. Transfer");
	printf("\n4. Query");
	printf("\n5. Logout");
	printf("\nChoice > ");
}
