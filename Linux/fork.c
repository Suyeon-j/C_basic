#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	int pid;
	int i;
	pid = fork();

	if (pid < 0) {
		printf("Error\n");
		exit(-1);
	}
	else if (pid == 0) {
		printf("Chlid\n");
		for (i = 1; i < 100; i += 2) {
			printf("C %d\n", i);
			sleep(1);
		}
		exit(0);
	}
	else {
		print("Parent\n");
		for (i = 0; i < 100; i += 2) {
			printf("P %d\n", i);
			sleep(1);
		}
		exit(0);
	}
}
