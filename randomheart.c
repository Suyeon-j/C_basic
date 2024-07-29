#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
1. 사용자 정의 함수 2개 선언: 메뉴 출력, 하트 찾기
2. 메인 함수에서 정의할 사항: 무한 반복문, switch문, 키보드로 번호 선택
3. 메뉴 출력 사용자 정의 함수: 문자열 출력(1. 프로그램 실행 2. 프로그램 종료)
4. 하트 찾기 사용자 정의 함수: 2차원 배열(10x13), srand(), rand(), time() 함수 사용
5. 하트 구분: 찾은 하트는 ♥, 찾지 못한 하트는 *로 출력
6. 하트 비중: 난수 0~99를 생성하여 20% 비중으로 하트 설정
*/

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
