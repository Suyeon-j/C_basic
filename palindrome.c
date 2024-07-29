#include <stdio.h>
#include <string.h>
int strlen(char* str);
int main()
{
    int i, len, result = 1;
    char str[100];

    printf("문자열을 입력하세요.: ");
    scanf_s("%s", &str);

    len = strlen(str);

    for (i = 0; i < len; i++) {
        if (str[i] != str[len - i-1]) {
            printf("회문이 아닙니다.");
            return 0;
        }
    }
    printf("회문입니다.");
    return 0;
}

int strlen(char* str) {
    int i = 0;
    while (str[i] != 0) {
        i++;
    }
    return i - 1;
}
