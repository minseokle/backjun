//complete
#include<stdio.h>
#include<stdlib.h>



int main_1012()
{
	int x[4] = { 1,0,-1,0 };
	int y[4] = { 0,1,0,-1 };
	int num;
	scanf_s("%d", &num);
	int* cnt = (int*)malloc(sizeof(int) * num);
	for (int c = 0; c < num; c++)
	{
		cnt[c] = 0;
		int der = 0;
		int n, m, bn;
		scanf_s("%d %d %d", &m, &n, &bn);
		int** arr;
		arr = (int**)malloc(sizeof(int*) * n);
		arr[0] = (int*)malloc(sizeof(int) * n * m);
		for (int i = 1; i < n; i++) {
			arr[i] = arr[i - 1] + m;
		}
		int** arr1;
		arr1 = (int**)malloc(sizeof(int*) * n);
		arr1[0] = (int*)malloc(sizeof(int) * n * m);
		for (int i = 1; i < n; i++) {
			arr1[i] = arr1[i - 1] + m;
		}
		int** arr2;
		arr2 = (int**)malloc(sizeof(int*) * n);
		arr2[0] = (int*)malloc(sizeof(int) * n * m);
		for (int i = 1; i < n; i++) {
			arr2[i] = arr2[i - 1] + m;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				arr[i][j] = 0;
				arr1[i][j] = 0;
				arr2[i][j] = 0;
			}
		}
		for (int k = 0; k < bn; k++)
		{
			int i, j;
			scanf_s("%d %d", &j, &i);
			arr[i][j] = 1;
		}

		for (int k = 0; k < n; k++)
		{
			for (int l = 0; l < m; l++)
			{
				if (arr[k][l] == 1)
				{
					arr[k][l] = 2;
					cnt[c]++;
					int check[100] = { 00,0, };
					check[0] = k * 100 + l;
					int checknum = 0;
					do
					{
						int j = check[0] % 100;
						int i = (check[0] - j) / 100;
						for (int k = 0; k < checknum; k++)
						{
							check[k] = check[k + 1];
						}
						check[checknum] = 0;
						checknum--;
						for (der = 0; der < 4; der++)
						{
							int si = i + y[der];
							int sj = j + x[der];
							if (si >= 0 && si < n && sj >= 0 && sj < m)
							{
								if (arr[si][sj] == 1)
								{
									arr[si][sj] = 2;
									checknum++;
									check[checknum] = si * 100 + sj;
								}
							}
						}
					} while (check[0] != 0);
				}
			}
		}
		free(arr[0]);
		free(arr);
		free(arr1[0]);
		free(arr1);
		free(arr2[0]);
		free(arr2);
	}
	for (int c = 0; c < num; c++)
	{
		printf("%d\n", cnt[c]);
	}
	free(cnt);
	return 0;

}