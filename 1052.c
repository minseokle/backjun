//complete
#include<stdio.h>

int main_1052()
{
	int n, k;
	scanf_s("%d %d", &n, &k);
	for (int i = 0; i < k - 1; i++)
	{
		int j;
		for (j = 1; j < n; j *= 2);
		j = j / 2;
		if (n == j)
		{
			break;
		}
		n -= j;
	}
	if (n == 0)
	{
		printf("0");
	}
	else
	{
		int i;
		for (i = 1; i < n; i *= 2);
		printf("%d", i - n);
	}
	return 0;
}