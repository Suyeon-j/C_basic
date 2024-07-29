#include <stdio.h>

int main()
{
	int i, arr[] = { 23,10,15,92,88 };
	int* max;
	max = (int*)arr[0];

	for (i = 0; i < 5; i++) {
		if (arr[i] > max)
			max = &arr[i];
		printf("%d번째 배열 요소: %d\n", i + 1, arr[i]);
	}
	printf("5개 숫자 중 에서 최댓값은 %d입니다.\n", *max);
}
