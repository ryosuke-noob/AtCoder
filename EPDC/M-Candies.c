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
	unsigned long long **dp;
	unsigned long long **dp2;

	scanf("%d %d",&n,&k);
	a = (int *)malloc(sizeof(int)*(n+1));
	rep(i,1,n+1) scanf("%d",&a[i]);
	dp = (unsigned long long **)malloc(sizeof(unsigned long long *) * (n+1));
	rep (i,0,n+1) dp[i] = (unsigned long long *)malloc(sizeof(unsigned long long) * (k+1));
	dp2 = (unsigned long long **)malloc(sizeof(unsigned long long *) * (n+1));
	rep (i,0,n+1) dp2[i] = (unsigned long long *)malloc(sizeof(unsigned long long) * (k+1));
	rep(i,0,k+1) {rep(j,0,n+1) {dp[j][i] = 0; dp2[j][i] = 0;} dp2[0][i] = 1;}
	rep(i,0,n+1) {dp[i][0] = 1; dp2[i][0] = 1;}

	rep(i,1,n+1)
	{
		rep(j,1,k+1)
		{
			if (j >= a[i]) dp[i][j] = (dp2[i - 1][j] - dp2[i - 1][j - a[i]] + dp[i - 1][j - a[i]])% 1000000007;
			else dp[i][j] = dp2[i-1][j];
			dp2[i][j] = (dp[i][j] + dp2[i][j - 1]);
		}
	}
	// rep(i,0,n+1) {rep(j,0,k+1) {printf("%2ld ",dp[i][j]);} printf("\n");}
	// printf("\n");
	// rep(i,0,n+1) {rep(j,0,k+1) {printf("%2ld ",dp2[i][j]);} printf("\n");}
	printf("%.0lf\n", (double)dp[n][k]);
	return (0);
}