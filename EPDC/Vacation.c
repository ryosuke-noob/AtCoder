#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define rep(i,l,r) for(int i=(l);i<(r);i++)
#define max(p,q) ((p)>(q)?(p):(q))
#define min(p,q) ((p)<(q)?(p):(q))

int main(void)
{
	int n;
	int *a,*b,*c;
	int **dp;

	scanf("%d",&n);
	a = (int *)malloc(sizeof(int) * n);
	b = (int *)malloc(sizeof(int) * n);
	c = (int *)malloc(sizeof(int) * n);
	rep(i,0,n) scanf("%d %d %d",&a[i],&b[i],&c[i]);
	dp = (int **)malloc(sizeof(int *) * n);
	rep(i,0,n) dp[i] = (int *)malloc(sizeof(int) * 3);
	rep(i,0,n) rep(j,0,3) dp[i][j] = 0;
	dp[0][0] = a[0];
	dp[0][1] = b[0];
	dp[0][2] = c[0];
	rep(i,1,n)
	{
		dp[i][0] = max(dp[i - 1][1],dp[i - 1][2]) + a[i];
		dp[i][1] = max(dp[i - 1][0],dp[i - 1][2]) + b[i];
		dp[i][2] = max(dp[i - 1][0],dp[i - 1][1]) + c[i];
	}
	int ans;
	ans = max(dp[n - 1][0],max(dp[n - 1][1],dp[n - 1][2]));
	printf("%d\n", ans);
	return (0);
}