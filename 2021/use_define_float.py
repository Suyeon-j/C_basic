#include <stdio.h>
#define MAX 100
int main()
{
	// define, float 사용해보기
  // 도전문제 #03
	int a = 7, b = 3;
	float result;

	result = (float)a / b; // a앞에 캐스트 연산자 사용
	printf("a=7, b=3일 때 a/b=%f\n",result);
	return 0;
}
