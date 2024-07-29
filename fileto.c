#include <stdio.h>

int main()
{
	FILE* fp;
	errno_t err, err2;
	char text[80];
	
	err = fopen_s(&fp, "myinfo.txt", "wt");

	if (NULL != fp) {
		fprintf(fp, "이름: 와아아아\n");
		fprintf(fp, "주민번호: 123456-1234567\n");
		fprintf(fp, "전화번호: 010-1111-2222\n");
		fclose(fp);
	}
	else
		printf("파일 열기 실패\n");

	err2 = fopen_s(&fp, "myinfo.txt", "rt");
	if (NULL != fp) {
		while (NULL != fgets(text, sizeof(text), fp)) {
			printf("%s", text);
		}
	}
	else
		printf("파일 열기 실패\n");
	fclose(fp);
}
