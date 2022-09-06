#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define rep(i,l,r) for(int i=(l);i<(r);i++)
#define max(p,q) ((p)>(q)?(p):(q))
#define min(p,q) ((p)<(q)?(p):(q))

int main(void)
{
	int N, W;
	int *w, *v;
	double **dp;

	scanf("%d %d",&N, &W);
	w = (int *)malloc(sizeof(int) * (N + 1));
	v = (int *)malloc(sizeof(int) * (N + 1));
	rep(i,1,N + 1) scanf("%d %d",&w[i],&v[i]);
	dp = (double **)malloc(sizeof(double *) * (N + 1));
	rep(i,0,N + 1) dp[i] = (double *)malloc(sizeof(double) * (W + 1));
	rep(i,0,N + 1) rep(j,0,W + 1) dp[i][j] = 0;

	rep(i,1,N + 1)
	{
		rep(j,1,W + 1)
		{
			if (j - w[i] < 0)
			{
				dp[i][j] = dp[i - 1][j];
				continue ;
			}
			dp[i][j] = max(dp[i - 1][j - w[i]] + v[i], dp[i - 1][j]);
		}
	}
	printf("%.0f\n",dp[N][W]);
	return (0);
}