#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void chg();
char keepg;
char str[30];

int main()
{
    
    chg(); 
    do {
        printf("프로그램을 계속 수행할까요? (Y/N) ");
        keepg = _getche();
        printf("\n\n");

        if (keepg == 'Y' || keepg == 'y') {
            chg();
        }
        else if (keepg == 'N' || keepg == 'n') {
            printf("프로그램을 종료합니다.\n");
            return 0;
        }
        else {
            printf("알파벳 입력 오류!\n");
            printf("알파벳을 다시 입력하세요\n");
        }
    } while (1);
}

void chg() {
    printf("문자열 30바이트 이내로 입력: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    printf("입력 문자열: ");
    puts(str);

    int str1 = atoi(str);
    printf("문자열 > 정수형으로 변환: %d\n\n", str1);
}
