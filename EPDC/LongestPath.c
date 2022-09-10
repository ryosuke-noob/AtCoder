#include <stdio.h>
#include <stdlib.h>
#define rep(i,l,r) for(int i=(l);i<(r);i++)
#define max(p,q) ((p)>(q)?(p):(q))

typedef struct s_link
{
	struct s_link *next;
	int to_num;
} t_link;

//link要素追加
void create_elm(t_link *link, int x, int y)
{
	t_link *new;

	new = (t_link *)malloc(sizeof(t_link));
	new->to_num = y;
	new->next = link[x].next;
	link[x].next = new;	
}

//各link(1~n)から始まる最長経路を計算
int max_path(t_link *link, int *dp, int i)
{
	t_link *tmp;

	if (dp[i] != 0)
		return (dp[i]);
	tmp = link[i].next;
	while (tmp != 0)
	{
		dp[i] = max(dp[i], max_path(link, dp, tmp->to_num) + 1);
		tmp = tmp->next;
	}
	return (dp[i]);
}

int main(void)
{
	int n, m, Max;
	int *x, *y;
	t_link *link;
	int *dp;

	(void)scanf("%d %d",&n,&m);
	x = (int *)malloc(sizeof(int) * (m + 1));
	y = (int *)malloc(sizeof(int) * (m + 1));
	rep(i,1,m + 1) (void)scanf("%d %d",&x[i], &y[i]);
	link = (t_link *)malloc(sizeof(t_link) * (n + 1));
	dp = (int *)malloc(sizeof(int) * (n + 1));
	rep(i,1,n+1) {dp[i] = 0; link[i].next = 0;}

	rep(i,1,m+1) create_elm(link, x[i], y[i]);

	Max = 0;
	rep(i,1,n+1)
		Max = max(Max, max_path(link,dp,i));

	printf("%d\n",Max);

	return (0);
}
