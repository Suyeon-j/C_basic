#include <stdio.h>
#define E 100
int main()
{
	int count = 1, sum = 0;

	do
	{
		if (sum > 2500)
			break;
		else
			sum += count;

		count++;
	} 	while (count <= E);
	printf("%d회 반복 후 누적 합계: %d\n", count, sum);
	return 0;
}
