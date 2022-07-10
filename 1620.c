//uncomplete
#include<stdio.h>
#include<stdlib.h>


typedef struct NODE
{
	char name[21];
	int num;
	struct NODE* low;
	struct NODE* high;
}NODE;

NODE* tree_insert(NODE** node, char name[21], int num);
NODE* tree_search(NODE* node, char name[21]);

int myStrCmp(const char* str1, const char* str2);

int main()
{
	int n, m;
	scanf_s("%d %d", &n, &m);
	NODE* start = NULL;
	char** name = (char**)malloc(sizeof(char*) * n);
	name[0] = (char*)malloc(sizeof(char) * n * 21);
	for (int i = 1; i < n; i++)
	{
		name[i] = name[i - 1] + 21;
	}
	for (int i = 0; i < n; i++)
	{
		scanf_s("%s", name[i],21);
		tree_insert(&start, name[i],i+1);
	}
	char** qu = (char**)malloc(sizeof(char*) * m);
	qu[0] = (char*)malloc(sizeof(char) * m * 21);
	for (int i = 1; i < m; i++)
	{
		qu[i] = qu[i - 1] + 21;
	}
	for (int i = 0; i < m; i++ )
	{
		scanf_s("%s", qu[i], 21);
	}
	for (int i = 0; i < m; i++)
	{
		if (qu[i][0] >= '0' && qu[i][0] <= '9')
		{
			int num = 0;
			for (int j = 0; qu[i][j] != NULL; j++)
			{
				num = num * 10 + qu[i][j] - 48;
			}
			printf("%s\n", name[num-1]);
		}
		else
		{
			NODE* ans = tree_search(start, qu[i]);
			printf("%d\n", ans->num);
		}
	}
}

NODE* tree_insert(NODE** node, char name[21], int num)
{
	if (*node == NULL)
	{
		*node = (NODE*)malloc(sizeof(NODE));
		for (int i = 0; name[i-1]!=NULL; i++)
		{
			(*node)->name[i] = name[i];
		}
		(*node)->num = num;
		(*node)->high = NULL;
		(*node)->low = NULL;
	}
	else if (myStrCmp((*node)->name, name) == -1)
	{
		(*node)->high = tree_insert(&(*node)->high, name,num);
	}
	else if (myStrCmp((*node)->name, name) == 1)
	{
		(*node)->low = tree_insert(&(*node)->low, name,num);
	}
	else
	{
		printf("fail");
	}
	return (*node);
}
NODE* tree_search(NODE* node, char name[21])
{
	if (myStrCmp(node->name, name) == 0)
	{
		return node;
	}
	else if (myStrCmp(node->name, name) == -1)
	{
		return tree_search(node->high, name);
	}
	else if (myStrCmp(node->name, name) == 1)
	{
		return tree_search(node->low, name);
	}
	return 0;
}

int myStrCmp(const char* str1, const char* str2)
{
	for (int i = 0; !(str1[i] == NULL && str2[i] == NULL); i++)
	{
		if (str1[i] < str2[i])
		{
			return -1;
		}
		else if (str1[i] > str2[i])
		{
			return 1;
		}
	}
	return 0;
}

