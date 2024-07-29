#include <stdio.h>
#define ST 2 // 학생수
#define SS 3 // 과목수
#define CL 5 // 과목명 크기

int main()
{
	int i, j, sum;
	float avg;
	int subs[ST][SS];
	char subj[SS][CL] = { "국어","영어","수학" };

	for (i = 0; i < ST; i++)
	{
		sum = 0;
		printf("[%d번째] 학생의 국어, 영어, 수학 점수를 입력하세요.\n", i + 1);
		for (j = 0; j < SS; j++) {
			printf("%s 점수: ", subj[j]);
			scanf_s("%d", &subs[i][j]);
			sum += subs[i][j];
		}
		avg = sum / 3.0;
		printf("> 평균 점수: %.2f\n\n", avg);
	}
}
