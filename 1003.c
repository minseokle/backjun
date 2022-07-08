//complete
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	scanf_s("%d", &n);
	int* num = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &num[i]);
	}
	for (int i = 0; i < n; i++)
	{
		int* pi = (int*)malloc(sizeof(int) * (num[i] + 1));
		pi[num[i]] = 1;
		pi[num[i] - 1] = 0;
		for (int j = num[i]; j > 1; j--)
		{
			pi[j - 2] = pi[j];
			pi[j - 1] += pi[j];
		}
		printf("%d %d\n", pi[0], pi[1]);
		free(pi);
	}
	free(num);
	return 0;

}