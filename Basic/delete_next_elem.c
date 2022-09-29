#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define rep(i,l,r) for(int i=(l);i<(r);i++)
#define max(p,q) ((p)>(q)?(p):(q))
#define min(p,q) ((p)<(q)?(p):(q))

typedef struct s_node
{
	unsigned long long data;
	struct s_node *next;
} t_node;

void delete_next_elem(t_node *pre_obj)
{
	t_node *obj;

	obj = pre_obj->next;
	pre_obj->next = obj->next;
	free(obj);
}