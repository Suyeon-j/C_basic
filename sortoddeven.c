#include <stdio.h>
#define S 10

int main()
{
	int j = S - 1, k = 0;
	int arr[S], arrp[S];

	printf("숫자 열개를 입력하세요.\n");
	for (int i = 0; i < S; i++) {
		printf("입력: ");
		scanf_s("%d", &arr[i]);
		if (arr[i] % 2 == 0) {
				arrp[j] = arr[i];
				j--;
		}
		else {
				arrp[k] = arr[i];
				k++;
		}
	}
	printf("배열의 요소 출력 > ");
	for (j = 0; j < S; j++)
	printf("%d ", arrp[j]);
	printf("\n");
}
