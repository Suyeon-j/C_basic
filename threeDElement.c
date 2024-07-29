#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define P 2
#define R 3
#define C 5
#define NUM 99

void four();

int main()
{
    char an;

    do {
        four();
        printf("\n프로그램을 다시 시작하시겠습니까? (Y / N) ");
        scanf_s("%c", &an);
        while (getchar() != '\n');

        if (an == 'Y' || an == 'y') {
            continue;
        }
        else if (an == 'N' || an == 'n') {
            return 0;
        }
        else
        {
            printf("입력 오류입니다. 다시 입력하세요.\n");
        }
    } while (1);
}

void four()
{
    int list[P][R][C];
    int i, j, cnt;

    srand((unsigned)time(NULL));

    for (i = 0; i < P; i++) {
        printf("[%d면] 출력\n", i + 1);
        for (j = 0; j < R; j++) {
            printf("<%d행 출력> ", j + 1);
            for (cnt = 0; cnt < C; cnt++) {
                printf("%d ", rand() % NUM);
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("프로그램 수행 완료\n");
}
