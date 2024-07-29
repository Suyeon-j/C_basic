#include <stdio.h>
#define sUb 3
int main()
{
	int i, subs[sUb], sum = 0;
	int* p;
	double avg;
	double* a;

	printf("점수를 3개 입력하세요. ");
	for (i = 0; i < sUb; i++) {
		scanf_s("%d", &subs[i]);
	}
	for (i = 0; i < sUb; i++) {
		p = &subs[i];
		printf("%d번째 과목 점수 : %d > 포인터 주소 : %p\n", i + 1, subs[i], p);
		sum += subs[i];
	}
	p = &sum;
	printf("\n총점: %d > 포인터 주소: %p\n", sum, p);
	avg = sum / 3.0;
	a = &avg;
	printf("평균: %.2f > 포인터 주소: %p\n", avg, a);
}
