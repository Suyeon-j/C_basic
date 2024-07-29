#include <stdio.h>
#include <string.h>
int main()
{
	char str1[20] = { "Have a " };
	char str2[10] = { "good time" };

	printf("주어진 문자열\n");
	printf("char str1[20] = \"%s\"\n", str1);
	printf("char str2[10] = \"%s\"\n", str2);
	
	strcat_s(str1, sizeof(str1), str2);
	printf("결합된 문자열: %s\n", str1);

	printf("문자열에서 'a'검색: %s\n", strchr(str1, 'a'));
	printf("문자열에서 'go'검색: %s\n", strstr(str1, "go"));
	printf("프로그램을 종료합니다.\n");
}
