#include <stdio.h>
int main()
{
	float nint, * nintp;

	printf("소수 셋째 자리까지 실수 입력하세요.  ________\b\b\b\b\b\b\b\b");
	scanf_s("%f", &nint);

	nintp = &nint;
	printf("포인터의 현재 주소값: %p\n",nintp);
	printf("포인터의 현재 데이터값: %.3f\n\n\n", nint);

	(*nintp)++;
	printf("포인터의 증감 후( (*nintp)++ ) 주소값: %p\n", nintp);
	printf("포인터의 증감 후( (*nintp)++ ) 데이터값: %.3f\n", nint);
