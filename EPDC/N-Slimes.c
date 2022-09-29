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

void input_data(t_node *link, int *a, int size)
{
	t_node *tmp;

	tmp = link;
	rep(i,1,size+1)
	{
		t_node *new = (t_node*)malloc(sizeof(t_node));
		new->data = a[i];
		new->next = 0;
		tmp->next = new;
		tmp = new;
	}
}

t_node *create_elem(unsigned long long new_data)
{
	t_node *new = (t_node*)malloc(sizeof(t_node));

	new->data = new_data;
	new->next = 0;
	return (new);
}

void delete_next_elem(t_node *pre_obj)
{
	t_node *obj;

	obj = pre_obj->next;
	pre_obj->next = obj->next;
	free(obj);
}

int main(void)
{
	int n;
	int *a;
	unsigned long long Min;
	unsigned long long ans = 0;
	t_node *link, *dp_link;
	t_node *tmp, *tmp2;

	if(scanf("%d",&n) != 1) return 0;
	a = (int*)malloc(sizeof(int)*(n+1));
	rep(i,1,n+1) if(scanf("%d",&a[i]) != 1) return 0;
	link = (t_node*)malloc(sizeof(t_node));
	input_data(link,a,n);

	while (link->next->next != 0)
	{
		Min = LLONG_MAX;
		//calculate min
		tmp = link->next;
		while (tmp != 0 && tmp->next != 0)
		{
			Min = min(Min, tmp->data + tmp->next->data);
			tmp = tmp->next;
		}

		//find min
		tmp = link;
		while (tmp != 0 && tmp->next != 0)
		{
			if (Min == tmp->data + tmp->next->data)
			{
				tmp->data = Min;
				ans += Min;
				delete_next_elem(tmp);
				break ;
			}
			tmp = tmp->next;
		}

		// tmp = link->next;
		// while(tmp != 0)
		// {
		// 	printf("%I64d ",tmp->data);
		// 	tmp = tmp->next;
		// }
		// printf("\n%I64d\n",Min);
	}

	// tmp = link->next;
	// while(tmp != 0)
	// {
	// 	printf("%I64d ",tmp->data);
	// 	tmp = tmp->next;
	// }
	// printf("\n%I64d\n",Min);
	printf("%I64lld\n",ans);

	return (0);
}