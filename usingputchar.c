#include <stdio.h>
#include <ctype.h>

int main()
{
	int asc, i;
	char ch1[] = { "|   |" }, ch2[] = { "|space|" };
	char ch3[] = { "|   zone|" }, ch4[] = { "| space" }, ch5[] = { "zone |" };

	for (i = 0; ch1[i] != '\0'; i++) {
		asc = toascii(ch1[i]);
		putchar(asc);
	}
	puts("");
	for (i = 0; ch2[i] != '\0'; i++) {
		asc = toascii(ch2[i]);
		putchar(asc);
	}
	puts("");
	puts(ch3);
	for (i = 0; ch4[i] != '\0'; i++) {
		asc = toascii(ch4[i]);
		putchar(asc);
	}
	puts(ch5);

	return 0;
}
