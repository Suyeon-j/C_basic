#include <stdio.h>
#define DT 5
double dSum(double a[], int end);

int main()
{
	double list[DT] = { 12.3, 35.8, 57.29, 96.53, 28.37 };
	int i;
	double sumArr;
	sumArr = dSum(list, DT);
	printf("배열 요소 합: %.2f\n", sumArr);
}

double dSum(double sUm[], int end)
{
	int i;
	double sumArr = 0;
	for (i = 0; i < end; i++)
	{
		sumArr += sUm[i];
	}
	return sumArr;
}
