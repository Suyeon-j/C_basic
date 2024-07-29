#include <stdio.h>
#define NNUM 10
int main()
{
	int i, j;
	int gugu[NNUM][NNUM];

	for (i = 2; i <= 9; i++) {
		printf("<%d단 출력>\n", i);
		for (j = 1; j <= 9; j++) {
			gugu[i][j] = i * j;
			printf("%d X %d = %.2d\n", i, j, gugu[i][j]);
		}
		printf("\n");
	}
	return 0;
}
