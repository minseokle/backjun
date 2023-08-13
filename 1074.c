//complete
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int sq(int a, int b);
int squ(int a, int b);

int main_1074()
{
	int n, r, c;
	int arr1[2][2] = { 0,1,2,3 };
	scanf_s("%d %d %d", &n, &r, &c);
	int size = 1;
	size = squ(2, n);
	int num = 0;
	for (int k = 1; k <= n; k++)
	{
		num += arr1[r % 2][c % 2] * sq(4, k - 1);
		r -= r % 2;
		c -= c % 2;
		r /= 2;
		c /= 2;

	}
	printf("%d", num);
	return 0;
}
int sq(int a, int b)
{
	int result = 1;
	for (int i = 0; i < b; i++)
	{
		result *= a;
	}
	return result;
}
int squ(int a, int b)
{
	int result = a;
	if (b == 0)
	{
		return 1;
	}
	for (int i = 1; i < b; i++)
	{
		result *= result;
	}
	return result;
}