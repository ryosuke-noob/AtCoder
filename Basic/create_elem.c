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

t_node *create_elem(unsigned long long new_data)
{
	t_node *new = (t_node*)malloc(sizeof(t_node));

	new->data = new_data;
	new->next = 0;
	return (new);
}