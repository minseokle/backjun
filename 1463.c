//uncomplete
#include<stdio.h>

int main()
{
	int num, cnt = 0;
	scanf_s("%d", &num);
	while (num != 1)
	{
		if (num % 3 == 0)
		{
			num /= 3;
			cnt++;
		}
		else if (num % 3 == 1)
		{
			num -= 1;
			cnt++;
		}
		else if (num > 10 && num % 3 == 2)
		{
			num -= 2;
			cnt += 2;
		}
		else if (num % 2 == 0)
		{
			num /= 2;
		}
		else if (num % 2 == 1 && num > 4)
		{
			num--;
			cnt++;
		}


	}
	printf("%d", cnt);
	return 0;
}