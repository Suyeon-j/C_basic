#include <stdio.h>
#define MAX 25

//employee 구조체 정의  > 문자열 ＇종업원 이름', '주민등록번호’ 정수 '급여정보＇>  완료
typedef struct employee
{
    char name[10];
    char pnum[15];
    int pay;
}employee;

int main()
{
    employee Employee[3];
        //세명의 정보를 프로그램 사용자로부터 입력 받아서 배열에 저장한 후
    int i;
    //배열에 저장된 데이터를 순서대로 출력
    for (i = 0; i < 3; i++) {
        printf("%d 번째 종업원 이름 > ", i + 1);
        scanf_s("%s", Employee[i].name, sizeof(Employee[i].name));
        printf("종업원 주민등록번호 > ");
        scanf_s("%s", Employee[i].pnum, sizeof(Employee[i].pnum));
        printf("종업원 급여 > ");
        scanf_s("%d",&Employee[i].pay);
        printf("\n");
    }

    for (i = 0; i < 3; i++)
    {
        printf(" > %d번째 종업원\n", i + 1);
        printf("\t이름  > %s\n", Employee[i].name);
        printf("\t주민등록번호  > %s\n", Employee[i].pnum);
        printf("\t급여  > %d\n", Employee[i].pay);
        printf("\n");
    }
}
