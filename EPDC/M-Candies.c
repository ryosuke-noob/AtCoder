#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define rep(i,l,r) for(int i=(l);i<(r);i++)
#define max(p,q) ((p)>(q)?(p):(q))
#define min(p,q) ((p)<(q)?(p):(q))

int main(void)
{
	int n,k;
	int *a;
	long int **dp;

	scanf("%d %d",&n,&k);
	a = (int *)malloc(sizeof(int)*(n+1));
	rep(i,1,n+1) scanf("%d",&a[i]);
	dp = (long int **)malloc(sizeof(long int *) * (n+1));
	rep (i,0,n+1) dp[i] = (long int *)malloc(sizeof(long int) * (k+1));
	rep(i,0,k+1) rep(j,0,n+1) dp[j][i] = 0;
	dp[0][0] = 1;
	rep(i,1,n+1) dp[i][0] = dp[i - 1][0] + 1;
	rep(i,1,k+1) dp[0][i] = dp[0][i - 1];

	rep(i,1,n+1)
	{
		rep(j,1,k+1)
		{
			if (j >= a[i]) dp[i][j] = dp[i - 1][j] - dp[i - 1][j - a[i]];
			else dp[i][j] = dp[i - 1][j] - 0;
			if (i != n || j != k) dp[i][j] += dp[i][j -  1];
		}
	}
	rep(i,0,n+1) {rep(j,0,k+1) {printf("%2ld ",dp[i][j]);} printf("\n");}

	printf("%ld\n",dp[n][k] % (1000000007));
	return (0);
}