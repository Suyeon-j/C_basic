#include <stdio.h>
void ShowMainMenu();
int ReadInput();
void LogIn();
void Join();
void CallBank();
void ShowBankMenu();
int id, passwd;

int main() {
	int choice, testId = 0;
	do {
		ShowMainMenu();
		choice = ReadInput();
		switch (choice)
		{
		case 1:
			LogIn();
			break;
		case 2:
			Join();
			break;
		case 3:
			printf("프로그램을 종료합니다.");
			return 0;
		default:
			printf("입력을 다시 해 주세요.");
		}
	} while (1);
}
void ShowMainMenu() {
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
void LogIn()
{
	int tid, tpasswd;
	printf("아이디를 입력하세요.: ");
	scanf_s("%d", &tid);
	printf("비밀번호를 입력하세요.: ");
	scanf_s("%d", &tpasswd);
	if (tid == id && tpasswd == passwd) {
		printf("로그인 성공");
		CallBank();
	}
	else
		printf("로그인 실패");
}
void Join()
{
	static int cnt = 0;
	cnt++;
	printf("아이디를 입력하세요: ");
	scanf_s("%d", &id);
	printf("비밀번호를 입력하세요: ");
	scanf_s("%d", &passwd);
	printf("당신은 %d번째 회원입니다.", cnt);
	return;
}
void CallBank()
{
	int choice, intputMoney;
	static int money = 0;
	do {
		ShowBankMenu();
		choice = ReadInput();
		switch (choice)
		{
		case 1:
			printf("입금액: ");
			scanf_s("%d", &intputMoney);
			money += intputMoney;
			printf("%d원 입금되어 전체 금액은 %d원입니다.", intputMoney, money);
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
