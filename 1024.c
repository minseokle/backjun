//complete
#include<stdio.h>

int main()
{
	int n, l;
	scanf_s("%d %d", &n, &l);
	if (l <= 100 && l > 0)
	{
		int s = -1, f = 101;
		int ln = l;
		for (int i; ln < 101; ln++)
		{

			if (!(n % ln == 0))
			{
				if (ln % 2 == 0)
				{
					i = n / ln - ln / 2 + 1;
				}
				else
				{
					continue;
				}
			}
			else
			{
				i = n / ln - ln / 2;
			}

			int sum = 0;
			int j;
			for (j = 0; j < ln; j++)
			{
				sum += i + j;
			}
			if (sum == n)
			{
				s = i;
				f = j;
				break;
			}
		}
		if (f > 100 || s < 0 || ln>100)
		{
			printf("%d", -1);
		}
		else
		{
			for (int i = s; i < s + f; i++)
			{
				printf("%d ", i);
			}
		}

	}
	else
	{
		printf("-1");
	}
	return 0;
}