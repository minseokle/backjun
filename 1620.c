//uncomplete
#include<stdio.h>
#include<stdlib.h>
#define max(a,b) ((a>b)?a:b)


typedef struct NODE
{
	char name[21];
	int num;
	struct NODE* low;
	struct NODE* high;
}NODE;

NODE* tree_insert(NODE** node, char name[21], int num);
NODE* tree_search(NODE* node, char name[21]);
int tree_hight(NODE* node);
int tree_balance(NODE* node);
void tree_sort(NODE** node);
NODE* tree_LL(NODE* node);
NODE* tree_RR(NODE* node);
NODE* tree_LR(NODE* node);
NODE* tree_RL(NODE* node);

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
		scanf_s("%s", name[i], 21);
		tree_insert(&start, name[i], i + 1);
	}
	char** qu = (char**)malloc(sizeof(char*) * m);
	qu[0] = (char*)malloc(sizeof(char) * m * 21);
	for (int i = 1; i < m; i++)
	{
		qu[i] = qu[i - 1] + 21;
	}
	for (int i = 0; i < m; i++)
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
			printf("%s\n", name[num - 1]);
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
		for (int i = 0; name[i - 1] != NULL; i++)
		{
			(*node)->name[i] = name[i];
		}
		(*node)->num = num;
		(*node)->high = NULL;
		(*node)->low = NULL;
	}
	else
	{
		int i = myStrCmp((*node)->name, name);
		if (i == -1)
		{
			(*node)->high = tree_insert(&(*node)->high, name, num);
			tree_sort(node);
		}
		else if (i == 1)
		{
			(*node)->low = tree_insert(&(*node)->low, name, num);

			tree_sort(node);
		}
		else
		{
			printf("fail");
		}
	}

	return (*node);
}
NODE* tree_search(NODE* node, char name[21])
{
	int j = myStrCmp(node->name, name);
	if (j == 0)
	{
		return node;
	}
	else if (j == -1)
	{
		return tree_search(node->high, name);
	}
	else if (j == 1)
	{
		return tree_search(node->low, name);
	}
	return 0;
}
int tree_hight(NODE* node)
{
	if (node == NULL)
	{
		return 0;
	}
	else
	{
		return max(tree_hight(node->low) + 1, tree_hight(node->high) + 1);
	}
}
int tree_balance(NODE* node)
{
	if (node == NULL)
	{
		return 0;
	}
	return tree_hight(node->high) - tree_hight(node->low);
}

void tree_sort(NODE** node)
{
	int i = tree_balance(*node);
	if (i < -1)
	{
		int j = tree_balance((*node)->low);
		if (j < 0)		//ll
		{
			*node = tree_LL(*node);
		}
		else if (j > 0)	//lr
		{
			*node = tree_LR(*node);
		}
	}
	else if (i > 1)
	{
		int j = tree_balance((*node)->high);
		if (j > 0)		//rr
		{

			*node = tree_RR(*node);

		}
		else if (j < 0)	//rl
		{
			*node = tree_RL(*node);
		}
	}
}
NODE* tree_LL(NODE* node)
{
	NODE* temp = (node->low)->high;
	(node->low)->high = node;
	NODE* nl = node->low;
	node->low = temp;
	return nl;
}

NODE* tree_RR(NODE* node)
{
	NODE* temp = (node->high)->low;
	(node->high)->low = node;
	NODE* nh = node->high;
	node->high = temp;
	return nh;
}

NODE* tree_LR(NODE* node)
{
	NODE* temp = node->low;
	node->low = tree_RR(temp);
	return tree_LL(node);
}
NODE* tree_RL(NODE* node)
{
	NODE* temp = node->high;
	node->high = tree_LL(temp);
	return tree_RR(node);
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

