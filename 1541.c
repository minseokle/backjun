//complate
#include<stdio.h>

int main_1541()
{
	char formula[51];
	scanf_s("%s", formula, 50);
	int num[51] = { 0, };
	int nc = 0;
	for (int i = 0; formula[i] != NULL; i++)
	{
		if (formula[i] <= '9' && formula[i] >= '0')
		{
			num[nc] = num[nc] * 10 + formula[i] - 48;
		}
		else if (formula[i] == '-' || formula[i] == '+')
		{
			nc++;
			num[nc] = formula[i];
			nc++;
		}
	}
	int i = 1;
	int cnt = num[0];
	if (num[i] != 0)
	{
		for (; num[i] != '-' && num[i] != 0; i += 2)
		{
			cnt += num[i + 1];
		}
		i++;
		for (; num[i] != 0; i += 2)
		{
			cnt -= num[i];
		}
	}

	printf("%d", cnt);
	return 0;
}