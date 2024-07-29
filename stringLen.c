#include <stdio.h>
#include <string.h>
int main()
{
	int i;
	char str[30] = " ";
	char* strp;
	
	strp = &str;

	printf("문자열 입력 (30바이트 이내): ");
	scanf_s("%s", str, sizeof(str));
	int len = strlen(str);
	printf("입력한 문자열의 길이: %d바이트\n", len);

	for (i = 0; i < len; i++) {
		printf("*(str + %.2d) : %c\n", i, *(strp + i));
	}
}
