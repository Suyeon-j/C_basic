#include <stdio.h>
void ShowMainMenu();
int ReadInput();
void LogIn(int);
int Join();
void CallBank();
void ShowBankMenu();

int main() {
	int choice, testId=0;
	do {
		ShowMainMenu();
		choice = ReadInput();
		switch (choice)
		{
		case 1:
			LogIn(testId);
			break;
		case 2:
			testId = Join();
			break;
		case 3:
			printf("프로그램을 종료합니다.");
			return 0;
		default:
			printf("입력을 다시 해 주세요.");
		}
	} while (1);
}
void ShowMainMenu(){
	printf("\n ---------MAIN MENU-----------");
	printf("\n 1. 로그인");
	printf("\n 2. 회원가입");
	printf("\n 3. 종료");
}
int ReadInput()
{
	int num;
	printf("\nChoice>");
	scanf_s("%d", &num);
	return num;
}
void LogIn(int joinId)
{
	int id;
	printf("아이디를 입력하세요.: ");
	scanf_s("%d", &id);
	if (id == joinId) {
		printf("로그인 성공");
		CallBank();
	}
	else
		printf("로그인 실패");
}
int Join()
{
	int id, passwd;
	printf("아이디를 입력하세요: ");
	scanf_s("%d", &id);
	return id;
}
void CallBank()
{
	int choice, money = 0, intputMoney;
	do {
		ShowBankMenu();
		choice = ReadInput();
		switch (choice)
		{
		case 1:
			printf("입금액: ");
			scanf_s("%d", &intputMoney);
			money += intputMoney;
			printf("%d원 입금되어 전체 금액은 %d원입니다.",intputMoney, money);
			break;
		case 2:
			printf("출금액: ");
			scanf_s("%d", &intputMoney);
			if (intputMoney > money) {
				printf("출금액이 잔금보다 많습니다.");
			}
			else {
				money -= intputMoney;
				printf("%d원 출금되어 전체 금액은 %d원입니다.", intputMoney, money);
			}
			break;
		case 3:
			printf("전체금액은 %d원입니다.", money);
			break;
		case 4:
			printf("로그아웃되었습니다.\n");
			return;
		default:
			printf("다시 입력해주세요.");
		}
	} while (1);
}
void ShowBankMenu() {
	printf("\n ---------Back MENU-----------");
	printf("\n 1. 입금");
	printf("\n 2. 출금");
	printf("\n 3. 조회");
	printf("\n 4. 로그아웃");
}
