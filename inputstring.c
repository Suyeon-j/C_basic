#include <stdio.h>
#include <string.h>

int main() {
	char ch[100], ad[100];
	int i, j, len, cnt = 0;

	printf("문자열을 입력하세요.\n");
	scanf_s("%s", ch, sizeof(ch));
	cnt = strlen(ch);
	//삽입할 위치를 입력하십시오:3
	printf("문자열 길이: %d\n", cnt);
	printf("삽입할 위치를 입력하세요. \n");
	scanf_s("%d", &len);

	printf("삽입할 문자열을 입력하세요.\n");
	scanf_s("%s", ad, sizeof(ad));

	for (i = 0; ad[i]!='\0'; i++) {
		cnt = i;
	}

	for (i = 0; ch[i] != '\0'; i++);
	
	for (; i >= 0; i--) {
		ch[i + len] = ch[i];
	}
	for (i = len - 1, j = 0; ad[j] != '\0'; i++, j++)
		ch[i] = ad[j];

	printf("최종 문자열: %s",ch);
}
