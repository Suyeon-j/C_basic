#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int pid;
    int i, j;

    pid = fork();

    if(pid < 0) {
        printf("Error\n");
        exit(-1);
    } else if (pid == 0) {
        printf("\n--- 자식 프로세스 ---\n");
        printf("< 1부터 10까지 합 출력 >\n");

        int sum;

        for(i = 10; i <= 100; i += 10) {
            for(j = 1; j <= i; j++) {
                sum += j;
            }
            printf("자식) %d부터 %d까지 합: %d\n", i - 9, i, sum);
            sum = 0;
            sleep(1);
        }
        prnitf("--- 자식 프로세스 종료 ----\n");
        exit(0);
    } else {
        printf("\n--- 자식 프로세스 ---\n");
        printf("< 1과 100 사이 짝수 홀수 합 출력 >\n");
        
        int esum, osum;

        printf("계산중...\n");

        for(i = 1; i <= 100; i++) {
            if(i % 2 == 0) esum += i;
            else osum += i;
        }
        sleep(1);
        printf("부모) 1부터 %d사이 짝수 합: %d\n", i, esum);
        printf("부모) 1부터 %d사이 홀수 합: %d\n", i, osum);
        printf("---부모 프로세스 종료 ---\n\n");
        exit(0);
    }
}
