#include <stdio.h>
#include <string.h>
#define MAX 100

int main()

{
	int car[MAX] = { 0 };
	int choice, i, num = 0;

	do
	{
		printf("\n예약을 진행하시겠습니까?(Yes-1/No-2):");
		scanf_s("%d", &choice);

		switch (choice)
		{
		case 1:
			// 현재 예약 상태 보여주기
			printf("자동차 모델 번호: 1	2	3	4	5	6	7	8	9	10\n");
			printf("자동차 예약 현황: ");

			for (i = 0; i < MAX; i++) {
				printf("%d	", car[i]);
			}
			printf("\n");
			// 예약할 번호 입력 받기
			printf("자동차 모델 번호를 입력하세요. \n");
			scanf_s("%d", &num);
			// 가능 여부에 따라서 진행 
			if (num < 1 || num> 10) {
				printf("입력오류입니다. 다시 입력하세요\n");
			}
			// 예약 여부 출력하기
			else {
				if (car[num - 1] == 0) {
					car[num - 1] = 1;
					printf("예약이 완료되었습니다.\n");
					printf("예약 모델: %d", num);
				}
				else {
					printf("해당 모델은 이미 예약 완료 되었습니다.\n");
				}
			}
			break;
		case 2:
			//프로그램 종료
			return 0;
			break;
		default:
			printf("입력이 잘못되었습니다. 다시 입력 바랍니다.");
		}
	} while (1);
}
