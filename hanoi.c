#include <stdio.h>
void HanoiTower(int, char, char, char);
int main()
{
	int rcnt;
	printf("원반 개수: ");
	scanf_s("%d", &rcnt);
	HanoiTower(rcnt, 'A', 'B', 'C');
}
void HanoiTower(int n, char from, char by, char to) {
	if (n >0) {
		HanoiTower(n - 1, from, to, by);
		printf("\n%d : %c -> %c", n, from, to);
		HanoiTower(n - 1, from, to, by);
	}
}
