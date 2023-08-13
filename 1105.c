//complete
#include<stdio.h>

int main_1105()
{
	int l, r;
	int el[11] = { 0, }, er[11] = { 0, };
	scanf_s("%d %d", &l, &r);
	int rl = l, rr = r;
	int ll = 0, lr = 0;
	while (rl > 0)
	{
		el[10 - ll] = rl % 10;
		rl /= 10;
		ll++;
	}
	while (rr > 0)
	{
		er[10 - lr] = rr % 10;
		rr /= 10;
		lr++;
	}
	if (ll == lr)
	{
		int ncnt = 0;
		int i;
		for (i = 0; el[i] == er[i]; i++)
		{
			if (el[i] == 8)
			{
				ncnt++;
			}
		}
		printf("%d", ncnt);
	}
	else
	{
		printf("0");
	}
	return 0;
}