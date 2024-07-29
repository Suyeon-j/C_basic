#include <stdio.h>

int main()
{
	char* fruit[] = { "Apple","Tomato","Pineapple" };
	int c;

	do
	{
		printf("1. Apple\n");
		printf("2. Tomato\n");
		printf("3. Pineapple\n");
		printf("4. Exit\n");
		printf("선택: ");
		scanf_s(" %d", &c);
		if (c > 4 || c < 1) {
			printf("숫자는 1~4만 허용합니다.");
		}
		else if (c == 4) {
			printf("프로그램을 종료합니다.");
			return 0;
		}
		else
			printf("선택한 과일은 \"%s\"입니다.\n\n", fruit[c-1]);
	} while (1);
}
