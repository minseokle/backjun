//complete
#include<stdio.h>
#include<stdlib.h>
#define min(a,b) ((a<b)?a:b)

typedef struct
{
	int cost[3];
	int lowcost[3];
}home;

int main_1149()
{
	int num;
	scanf_s("%d", &num);
	home* ho = (home*)malloc(sizeof(home) * num);
	for (int i = 0; i < num; i++)
	{
		scanf_s("%d %d %d", &ho[i].cost[0], &ho[i].cost[1], &ho[i].cost[2]);
	}
	for (int i = 0; i < 3; i++)
	{
		ho[0].lowcost[i] = ho[0].cost[i];
	}
	for (int i = 1; i < num; i++)
	{
		ho[i].lowcost[0] = min(ho[i - 1].lowcost[1], ho[i - 1].lowcost[2]) + ho[i].cost[0];
		ho[i].lowcost[1] = min(ho[i - 1].lowcost[2], ho[i - 1].lowcost[0]) + ho[i].cost[1];
		ho[i].lowcost[2] = min(ho[i - 1].lowcost[0], ho[i - 1].lowcost[1]) + ho[i].cost[2];
	}
	printf("%d", min(ho[num - 1].lowcost[0], min(ho[num - 1].lowcost[1], ho[num - 1].lowcost[2])));
	return 0;

}

