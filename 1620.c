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
	int* seq = (int*)malloc(sizeof(int) * n);
	int index[26] = { 0, };
	for (int i = 0; i < n; i++)
	{
		scanf_s("%s", name[i], 20);
		int al;
		if (name[i][0] <= 'z' && name[i][0] >= 'a')
		{
			al = name[i][0] - 'a';
		}
		if (name[i][0] <= 'Z' && name[i][0] >= 'A')
		{
			al = name[i][0] - 'A';
		}
		for (int j = al+1; j < 26; j++)
		{
			index[j]++;
		}
		for (int j = n - 1; j >= index[al + 1]; j--)
		{
			seq[j] = seq[j - 1];
		}
		seq[index[al + 1] - 1] = i;
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
			int al;
			if (qu[0] <= 'z' && qu[0] >= 'a')
			{
				al = qu[0] - 'a';
			}
			if (qu[0] <= 'Z' && qu[0] >= 'A')
			{
				al = qu[0] - 'A';
			}
			while (num == -1)
			{
				int k;
				for (k = 0; qu[k] != NULL || name[seq[index[al] + j]][k] != NULL; k++)
				{
					if (qu[k] != name[seq[index[al] + j]][k])
					{
						break;
					}
				}
				if (qu[k] == NULL)
				{
					num = seq[index[al] + j];
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
	free(seq);
	return 0;
}