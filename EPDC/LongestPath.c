#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define rep(i,l,r) for(int i=(l);i<(r);i++)
#define max(p,q) ((p)>(q)?(p):(q))
#define min(p,q) ((p)<(q)?(p):(q))

int back(int *x, int *y, int m, int a)
{
	int ret;

	ret = 0;
	rep(i,1,m+1) if (x[i] == a)
	{
		ret = max(ret, back(x,y,m,y[i]) + 1);
		//printf("[%d-%d:%d] ",x[i],y[i],ret);
	}
	return (ret);
}

int main(void)
{
	int n,m,Max = 0;
	int *x,*y;
	// int **dp;

	(void)scanf("%d %d",&n,&m);
	x = (int *)malloc(sizeof(int) * (m + 1));
	y = (int *)malloc(sizeof(int) * (m + 1));
	rep(i,1,m + 1) (void)scanf("%d %d",&x[i], &y[i]);
	// dp = (int **)malloc(sizeof(int *) * (n + 1));
	// rep(i,0,n + 1) dp[i] = (int *)malloc(sizeof(int) * (n + 1));
	
	rep(i,1,m + 1)
	{
		Max = max(Max, back(x,y,m,x[i]));
		//printf("\nhere\n");
	}

	printf("%d\n",Max);

	return (0);
}