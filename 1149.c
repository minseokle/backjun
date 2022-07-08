//uncomplete
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	scanf_s("%d", &n);
	int** cos = (int**)malloc(sizeof(int*) * 3);
	cos[0] = (int*)malloc(sizeof(int) * 3 * n);
	for (int i = 1; i < 3; i++)
	{
		cos[i] = cos[i - 1] + n;
	}
	int** lowcos = (int**)malloc(sizeof(int*) * 2);
	lowcos[0] = (int*)malloc(sizeof(int) * 2 * n);
	for (int i = 1; i < 2; i++)
	{
		cos[i] = cos[i - 1] + n;
	}
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d %d %d", &cos[0][i], &cos[1][i], &cos[2][i]);
		lowcos[0][i] = cos[0][i];
		lowcos[1][i] = 0;
		for (int j = 1; j < n; j++)
		{
			if (lowcos[0][i] > cos[j][i])
			{
				lowcos[0][i] = cos[j][i];
				lowcos[1][i] = j;
			}
		}
	}
	if (lowcos[1][0] == lowcos[1][1])
	{
		switch (lowcos[1][0])
		{
		case 1:

		}
	}
	for (int i = 1; i < n - 2; i++)
	{
		if (lowcos[1][i] == lowcos[1][i + 1])
		{

		}
	}
}