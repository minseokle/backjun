//complete
#include<stdio.h>
#include<stdlib.h>

void main_3013()
{
	int n, b, num = 0;
	scanf_s("%d %d", &n, &b);
	int* arr = (int*)malloc(sizeof(int) * n);
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", (arr + i));
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; i + j < n; j += 2)
		{
			int high = 0, low = 0, eq = 0;
			for (int k = i; k <= i + j; k++)
			{
				if (*(arr + k) > b)
				{
					high++;
				}
				else if (*(arr + k) < b)
				{
					low++;
				}
				else
				{
					eq++;
				}
			}
			if (high == low && eq == 1)
			{
				num++;
			}
		}
	}
	printf("%d", num);
	free(arr);
}