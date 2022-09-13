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
	rep(i,0,n+1) dp[i][0] = 1;

	rep(i,1,n+1)
	{
		rep(j,1,k+1)
		{
			rep(l,0,a[i]+1)
			{
				if (l <= j) dp[i][j] += dp[i - 1][j - l];
			}
		}
	}
	printf("%ld\n",dp[n][k] % (1000000007));
	return (0);
}