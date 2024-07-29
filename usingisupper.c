#include <stdio.h>
#include <ctype.h>

int main()
{
	int i = 0;
	char str[] = { "SpaceZone" };
	printf("프로그램에서 주어진 문자열\n");
	printf("char str[20] = \"%s\"\n", str);

	//문자열에서 대문자 찾기 > 대문자만 추출
	printf("알파벳 대문자만 추출하여 출력: ");
	while (i < strlen(str))
	{
		if (isupper(str[i]) == 1) {
			printf("%c", str[i]);
		}
		i++;
	}
	printf("\n프로그램을 종료합니다.\n");
}
