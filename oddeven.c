#include <stdio.h>
int main()
{
	// 홀수 짝수 판별하기
  int num;
	
	printf("Enter number:");
	scanf_s("%d", &num);

	if (num > 0) {
		if (num % 2 == 0)
			printf("짝수 (even number)\n");
		else if (num % 2 == 1)
			printf("홀수 (odd number)\n");
	}

	else if (num == 0) {
		printf("0\n");
	}
	else if (num < 0) {
		printf("음수\n");
	}
	return 0;
}
