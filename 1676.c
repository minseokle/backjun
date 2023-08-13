#include<stdio.h>

int main_1676()
{
	int num;
	scanf_s("%d", &num);
	int c5 = 0;
	for (int i = 1; i <= num; i++)
	{
		for (int j = i; j % 5 == 0; j /= 5)
			c5++;
	}
	printf("%d", c5);
	return 0;
}