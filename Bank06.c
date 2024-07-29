#include <stdio.h>
#include <stdlib.h>
#define MAX 100
void ShowMainMenu();
int ReadInput();
void LogIn();
void Join();
void Print();
void Bank(int);
void ShowBankMenu();
void ReadData();
void WriteData();
enum { LOGIN = 1, JOIN, EXIT, PRINT };

typedef struct Account
{
    char id[10];
    char passwd[10];
    int money;
} Account;

Account* account[MAX];
int numOfAccount = 0;

int main()
{
    int input;
    ReadData();
    do
    {
        ShowMainMenu();
        input = ReadInput();
        switch (input)
        {
        case LOGIN:
            LogIn();
            break;
        case JOIN: // Join
            Join();
            break;
        case EXIT: // Exit
            WriteData();
            return 0;
        case PRINT: // Print
            Print();
            break;
        default:
            printf("\n try again!!!");
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

void LogIn()
{
    char id[10], pwd[10];
    int i;
    printf("Enter ID:");
    scanf_s("%s", id, sizeof(id));
    printf("Enter PWD:");
    scanf_s("%s", pwd, sizeof(pwd));
    for (i = 0; i < numOfAccount; i++)
    {
        //로그인 성공
        if (!strcmp(id, account[i]->id) && !strcmp(pwd, account[i]->passwd))
        {
            printf("LogIn Success!!!\n");
            Bank(i);
            break;
        }

        else if (!strcmp(id, account[i]->id))// && pwd != account[i].passwd)
        {
            printf("Password is wrong!!!\n");
            break;
        }
    }
    if (i == numOfAccount)
        printf("Id is not exist!!!");
}

void Join()
{
    account[numOfAccount] = (Account*)malloc(sizeof(Account));
    printf("Enter ID:");
    scanf_s("%s", account[numOfAccount]->id, sizeof(account[numOfAccount]->id));
    printf("Enter PWD:");
    scanf_s("%s", account[numOfAccount]->passwd, sizeof(account[numOfAccount]->passwd));
    account[numOfAccount++]->money = 1000;
}

void Print()
{
    int i;
    for (i = 0; i < numOfAccount; i++)
    {
        printf("\n=== %d Account ===", i + 1);
        printf("\nID    : %s", account[i]->id);
        printf("\nPWD   : %s", account[i]->passwd);
        printf("\nMoney : %d", account[i]->money);
    }

}

void Bank(int index)
{
    int input, money, i, receiverIndex;
    char id[10];
    enum { DEPOSIT = 1, WITHDRAW, TRANSFER, QUERY, LOGOUT };

    do
    {
        ShowBankMenu();
        input = ReadInput();
        switch (input)
        {
        case DEPOSIT:// 입금
            printf("Enter Money:");
            scanf_s("%d", &money);
            account[index]->money += money;
            printf("%d 이 입금되어 총 잔액은 %d입니다.\n", money, account[index]->money);
            break;
        case WITHDRAW:// 출금
            printf("Enter Money:");
            scanf_s("%d", &money);
            if (money > account[index]->money)
                printf("잔금이 부족하여 출금할 수 없습니다.\n");
            else
            {
                account[index]->money -= money;
                printf("%d 이 출금되어 총 잔액은 %d입니다.\n", money, account[index]->money);
            }
            break;
        case TRANSFER: //송금
            printf("Enter receiver ID:");
            scanf_s("%s", id, sizeof(id));
            printf("Enter Money:");
            scanf_s("%d", &money);
            // 송금자가 존재하지 않습니다.
            for (i = 0; i < numOfAccount; i++)
                if (!strcmp(id, account[i]->id))
                {
                    receiverIndex = i;
                    break;
                }
            if (i == numOfAccount)
                printf("송금자가 존재하지 않습니다.\n");
            else if (money > account[index]->money)
            {
                printf("금액이 부족합니다.\n");
            }
            else
            {
                account[receiverIndex]->money += money;
                account[index]->money -= money;
                printf("%s 회원에게 %d 을 송금하였습니다. 남은 잔액은 %d 입니다.\n",
                    account[receiverIndex]->id, money, account[index]->money);
            }
            break;
        case QUERY: // 조회
            printf("%s 님의 총 잔액은 %d 입니다.\n", account[index]->id, account[index]->money);
            break;
        case LOGOUT:  // LogOut
            return;
        default:
            printf("Try again!!!\n");
        }
    } while (1);
}

void ShowBankMenu()
{
    printf("\n=== Bank Menu ===");
    printf("\n1. Deposit");
    printf("\n2. Withdrawal");
    printf("\n3. Tranfer");
    printf("\n4. Query");
    printf("\n5. LogOut");
    printf("\nChoice >");
}

void ReadData()
{
    int i;//C는 중간에서 변수 선언 불가능함
    FILE* fp;
    fopen_s(&fp, "bank.text", "rt");

    if (fp == NULL) {
        printf("파일 읽기 불가능");
        return;
    }
    fscanf_s(fp, "%d", &numOfAccount);
    for (i = 0; i < numOfAccount; i++) {
        account[i] = (Account*)malloc(sizeof(Account));
        fscanf_s(fp, "%s %s %d", account[i]->id, sizeof(account[i]->id), account[i]->passwd, sizeof(account[i]->passwd), &account[i]->money);
    }
    fclose(fp);
}

void WriteData()
{
    int i;
    FILE* fp;
    fopen_s(&fp, "bank.text", "wt");

    if (fp == NULL) {
        printf("파일 쓰기 불가능");
        return;
    }
    fprintf(fp, "%d\n", numOfAccount);
    for (i = 0; i < numOfAccount; i++) {
        fprintf(fp, "%s %s %d\n", account[i]->id, account[i]->passwd, account[i]->money);
    }
    for (i = 0; i < numOfAccount; i++) {
        free(account[i]);
    }
    fclose(fp);
}
