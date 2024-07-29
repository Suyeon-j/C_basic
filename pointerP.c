#include <stdio.h>

int Gob(int* pa, int* pb);
int main()
{
	int a = 10, b = 20;
	Gob(&a, &b);
	printf("주어진 값: a = %d, b = %d\n", a, b);
	printf("반환된 값: a * b = %u\n", Gob(&a, &b));
}
int Gob(int* pa, int* pb)
{
	int a = *pa;
	int b = *pb;
	return a * b;
}
