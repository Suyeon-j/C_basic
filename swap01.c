#include <stdio.h>
void swap1(int x, int y);
void swap2(int* x, int* y);
void swap3(int* x, int* y);
void ToUpper(char arr[], int len);

int main() 
{
	int i, j;
	int* pi, pj;
	int** dpi = &pi;
	char str[10] = "Hello";
	const double PI = 3.141592;
	i = 10; j = 20;
	pi = &i; pj = &j;

	swap1(i, j);
	swap2(&i, &j);
	swap3(pi, pj);

	printf("%p %d", pi, *pi);
	printf("%d %d", i, j);
	scanf_s("%d", &i);

	ToUpper(str, sizeof(str));
	printf("%s", str);
}

void swap1(int x, int y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}

void swap2(int* x, int* y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void swap3(int* x, int* y)
{
	int* temp;
	temp = x;
	x = y;
	y = temp;
}

void ToUpper(char arr[], int len)
{
	int i;
	for (i = 0; i < arr[i] != '\0'; i++) {
		if (arr[i] >= 'a' && arr[i] <= 'z') {
			arr[i] -= 'a' - 'A';
		}
	}
}
