#include <stdio.h>
int main()
{
	// multiplicationTable01
  int dan, cnt, result;

	for (dan = 2; dan <= 5; dan++) {
		printf("%d단 \n", dan);
		for (cnt = 1; cnt <= 9; cnt++) {
			result = dan * cnt;
			printf("%d X %d = %d\n", dan, cnt, result);
		}
	}
	return 0;
}
