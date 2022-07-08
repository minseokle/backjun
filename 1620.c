//uncomplete
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n, m;
	scanf_s("%d %d", &n, &m);
	char** name = (char**)malloc(sizeof(char*) * n);
	name[0] = (char*)malloc(sizeof(char) * n * 21);
	for (int i = 1; i < n; i++)
	{
		name[i] = name[i - 1] + 21;
	}
	for (int i = 0; i < n; i++)
	{
		scanf_s("%s", name[i], 20);
	}
	int** asw = (int**)malloc(sizeof(int*) * m);
	asw[0] = (int*)malloc(sizeof(int) * m * 2);
	for (int i = 1; i < m; i++)
	{
		asw[i] = asw[i - 1] + 2;
	}
	for (int i = 0; i < m; i++)
	{
		char qu[21];
		scanf_s("%s", qu, 20);
		if (qu[0] <= '9' && qu[0] >= '0')
		{
			asw[i][0] = 0;
			int num = 0;
			for (int j = 0; qu[j] != NULL; j++)
			{
				num = num * 10 + qu[j] - 48;
			}
			asw[i][1] = num - 1;
		}
		else
		{
			asw[i][0] = 1;
			int num = -1;
			int j = 0;
			while (num == -1)
			{
				int k;
				for (k = 0; qu[k] != NULL || name[j][k] != NULL; k++)
				{
					if (qu[k] != name[j][k])
					{
						break;
					}
				}
				if (qu[k] == NULL)
				{
					num = j;
				}
				j++;
			}
			asw[i][1] = num + 1;
		}

	}
	for (int i = 0; i < m; i++)
	{
		if (asw[i][0] == 0)
		{
			printf("%s\n", name[asw[i][1]]);
		}
		else
		{
			printf("%d\n", asw[i][1]);
		}
	}
	free(name[0]);
	free(name);
	free(asw[0]);
	free(asw);
	return 0;
}