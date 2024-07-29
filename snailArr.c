#include <stdio.h>
#define S 100

int main()
{
	int n, i, j, x = 0, y = -1, swit = 1;
	int arr[S][S] = { 0 };

	printf("배열의 크기를 입력하세요. > ");
	scanf_s("%d", &n);
	printf("\n<%d X %d 달팽이 배열>\n", n, n);
	i = n;

	int a = 1;
	while (i != 0) {
		for (j = 0; j < i; j++) {
			y += swit;
			arr[x][y] = a;
			a++;
		}

		i--;

		for (j = 0; j < i; j++) {
			x += swit;
			arr[x][y] = a;
			a++;
		}
		swit *= -1;
	}

	for (x = 0; x < n; x++) {
		for (y = 0; y < n; y++) {
			printf("%5d", arr[x][y]);
		}
		printf("\n");
	}
}
