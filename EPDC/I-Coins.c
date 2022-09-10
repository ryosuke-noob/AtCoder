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
	int n;
	double *p;
	double **dp;
	double ans;

	scanf("%d",&n);
	p = (double *)malloc(sizeof(double) * (n + 1));
	rep(i,1,n+1) scanf("%lf",&p[i]);
	dp = (double **)malloc(sizeof(double *) * (n + 1));
	rep(i,0,n+1) dp[i] = (double *)malloc(sizeof(double) * (n + 1));
	rep(i,0,n+1) {dp[i][0] = 0; dp[0][i] = 0;}
	dp[0][0] = 1;
	rep(i,1,n+1)
	{
		dp[i][0] = dp[i - 1][0] * (1 - p[i]);
		rep(j,1,n+1)
		{
			dp[i][j] = dp[i - 1][j] * (1 - p[i]) + dp[i - 1][j - 1] * p[i];
		}
	}

	ans = 0;
	rep(i,(n+1)/2,n+1) {ans += dp[n][i];}
	printf("%.10g\n",ans); 
	//.10で桁指定 %gで実数の最適表示
	return (0);
}