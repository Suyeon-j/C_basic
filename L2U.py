#include <stdio.h>
int main() 
{
  char M;

	printf("Enter Character:");
	scanf_s("%c", &M, sizeof(M)); // 문자 하나 입력 받기

	if (M >= 'A' && M <= 'Z') {
		printf("%c\n",M);
	}
	else if (M >= 'a' && M <= 'z') {
		printf("%c\n", M - ('a' - 'A')); // 소문자 -> 대문자 (lowercase -> uppercase)
	}
	else {
		printf("알파벳이 아님\n"); // 나머지 -> 알파벳 아님 출력
	}
}
