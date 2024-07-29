#include <stdio.h>
#include <ctype.h>
#define TRUE 1
#define FALSE 0
int atoiU(char a[]);
int main()
{
	char str[20];
	int num;
	printf("숫자를 입력하세요: ");
	gets_s(&str, sizeof(str));

	num = atoiU(str);

	printf("%d\n", num);

	return 0;
}
int atoiU(char a[])
{
	int i = 0, re = 0;
	while (a[i] != 0)
		{
		re = re * 10 + (a[i] - '0');
		i++;
	}
	return re;
}
