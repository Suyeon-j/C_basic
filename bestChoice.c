#include <stdio.h>
#define P 10

int main()
{
	printf("소유금액 > 3,500원\n");

	int cream = 500, shrimp = 700, coke = 400;
	int c_cnt = 0, s_cnt = 0, k_cnt = 0;

	for(c_cnt=1;c_cnt<P;c_cnt++)
		for (s_cnt = 1; s_cnt < P; s_cnt++)
			for (k_cnt = 1; k_cnt < P; k_cnt++) {
				if (cream * c_cnt + shrimp * s_cnt + coke * k_cnt == 3500) {
					printf("크림빵 %d, 새우깡 %d, 콜라 %d개\n", c_cnt, s_cnt, k_cnt);
				}
			}
	printf("어떻게 구입하시겠습니까?\n");
	
}
