#include <stdio.h>
#include <stdlib.h>
#define rep(i,l,r) for(int i=(l);i<(r);i++)
#define max(p,q) ((p)>(q)?(p):(q))
 
int back(int *x, int *y, int m, int a, int *dp, int *flag)
{
	if (flag[a]) return (dp[a]);
	flag[a] = 1;
	rep(i,1,m+1) if (x[i] == a)
	{
		dp[a] = max(dp[a], back(x,y,m,y[i],dp,flag) + 1);
	}
	return (dp[a]);
}
 
int main(void)
{
	int n,m,Max = 0;
	int *x,*y;
	int *dp, *flag;

	(void)scanf("%d %d",&n,&m);
	x = (int *)malloc(sizeof(int) * (m + 1));
	y = (int *)malloc(sizeof(int) * (m + 1));
	rep(i,1,m + 1) (void)scanf("%d %d",&x[i], &y[i]);
	dp = (int *)malloc(sizeof(int) * (n + 1));
	flag = (int *)malloc(sizeof(int) * (n + 1));
	rep(i,1,n+1) {dp[i] = 0; flag[i] = 0;}
 
	rep(i,1,m+1) Max = max(Max, back(x,y,m,x[i],dp,flag));

	printf("%d\n",Max);
 
	return (0);
}
