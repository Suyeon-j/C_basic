#include <stdio.h>
int main()
{
	int num, cnt=0,i,sum=0;

	printf("숫자 입력: ");
	scanf_s("%d",&num);

	for (i = 2; i <= num; i++) {
		if (num % i == 0) {
			break;
		}
	}
	if (i==num) {
		printf("소수입니다.");
	}
	else {
		printf("소수가 아닙니다.");
	}

	return 0;
}
