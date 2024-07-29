#include <stdio.h>
int main()
{
	/* 다음 조건에 맞게 369 게임을 출력할 것.
	1. 마지막 숫자를 입력 받을 것
	2. 3, 6, 9가 1번씩 들어갈 경우 짝을 출력할 것.(ex. 13, 16, 19)
	3. 3, 6, 9가 2번씩 들어갈 경우 짝짝을 출력할 것.(ex. 33, 66, 99)
	*/
	int i, num;
	printf("마지막 숫자를 입력하세요 : ");
	scanf_s("%d", &num);
	for (i = 1; i <= num; i++) {
		if (i / 10 == 3 && (i % 10 == 3 || i % 10 == 6 || i % 10 == 9)) printf("짝짝 ");
		else if (i / 10 == 3 || i % 10 == 3 || i % 10 == 6 || i % 10 == 9) printf("짝 ");
		else printf("%d ", i);
	}
	printf("\n");
	return 0;
}
