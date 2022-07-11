//complete
#include<stdio.h>
#include<stdlib.h>
#define min(a,b) ((a<b)?a:b)

int main()
{
	int num;
	scanf_s("%d", &num);
	if (num == 1)
	{
		printf("0");
		return 0;
	}
	if (num == 2)
	{
		printf("1");
		return 0;
	}
	if (num == 3)
	{
		printf("1");
		return 0;
	}
	int* cnt = (int*)malloc(sizeof(int) * (num + 1));	// 어떤숫자가 1이 될때 까지 걸리는 최소 횟수 저장
	if (cnt == NULL)
		return 0;
	cnt[1] = 0;
	cnt[2] = 1;
	cnt[3] = 1;
	for (int i = 4; i <= num; i++)
	{
		cnt[i] = cnt[i - 1] + 1;					//연산을 한번 하면 연산한 값에 횟수 +1
		if (i % 3 == 0)
		{
			cnt[i] = min(cnt[i / 3] + 1, cnt[i]);	
		}
		if (i % 2 == 0)
		{
			cnt[i] = min(cnt[i / 2] + 1, cnt[i]);
		}
	}
	printf("%d", cnt[num]);
	free(cnt);
	return 0;
}