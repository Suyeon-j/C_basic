//두 변수를 대상으로 저장된 값을 서로 바꿔주는 함수를 정의 후 호출

#include <stdio.h>
void SwapPoint(struct Point* a, struct Point* b);

typedef struct point
{
	int xpos;
	int ypos;
} Point;
int main() {
	Point pos1={2, 4};
	Point pos2 = { 5, 7 };
	printf("변환 전 > %d %d\n", pos1.xpos, pos1.ypos);
	printf("변환 전 > %d %d\n", pos2.xpos, pos2.ypos);
	SwapPoint(&pos1, &pos2);
//이 두 구조체변수를 대상으로, 혹은 두 구조체 변수의 주소 값을 대상으로 SwapPoint라는 이름의 함수를 호출하면 pos1의 xpos, ypos에는 각각 5와 7이
//그리고 pos2의 xpos, ypos에는 각각 2와 4가 저장되어야한다.
}

void SwapPoint(Point* a, Point* b) {
	struct point swap;
	swap = *a;
	*a = *b;
	*b = swap;

	printf("변환 후 > %d %d\n", a->xpos, a->ypos);
	printf("변환 후 > %d %d\n", b->xpos, b->ypos);

}
