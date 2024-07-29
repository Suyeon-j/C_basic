#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define R 10
#define C 13
#define NUM 100

void MEMU();
void findH();

int main()
{
    int an;
    do
    {
        MEMU();
        scanf_s("%d", &an);
        switch (an)
        {
        case 1:
            findH();
            break;
        case 2:
            return 0;
        default:
            printf("입력오류입니다. 다시 입력하세요.\n");
            break;
        }
    } while (1);
}

void MEMU() {
    printf("1. 프로그램 실행\n");
    printf("2. 프로그램 종료\n");
    printf("번호를 입력해주세요. ");
}

void findH() {
    int i, j;
    int heart[R][C];

    srand((unsigned)time(NULL));

    // 배열에 난수 할당
    for (i = 0; i < R; i++) {
        for (j = 0; j < C; j++) {
            heart[i][j] = rand() % 100;
        }
    }

    printf("------------------------------------------------------------------\n");

    // 배열 출력
    for (i = 0; i < R; i++) {
        for (j = 0; j < C; j++) {
            if (heart[i][j] < 20) {
                printf("  ♥  ");
            }
            else {
                printf("  *  ");
            }
        }
        printf("\n");
    }

    printf("------------------------------------------------------------------\n");
}
