#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define rep(i,l,r) for(int i=(l);i<(r);i++)
#define max(p,q) ((p)>(q)?(p):(q))
#define min(p,q) ((p)<(q)?(p):(q))
#define MOD 1000000007

int main(void)
{
	int n,k;
	int *a;
	unsigned long long **dp;
	unsigned long long *cum;

	if (scanf("%d %d",&n,&k) != 2) return 1;
	a = (int *)malloc(sizeof(int)*(n+1));
	for(int i = 1;i < n+1;i++) if (scanf("%d",&a[i]) != 1) return 1;
	dp = (unsigned long long **)malloc(sizeof(unsigned long long *) * (n+1));
	for(int i = 0;i < n+1;i++) dp[i] = (unsigned long long *)malloc(sizeof(unsigned long long) * (k+2));
	cum = (unsigned long long *)malloc(sizeof(unsigned long long) * (k+2));
	rep(i,0,k+1) {rep(j,0,n+1) dp[j][i] = 0;}
	rep(i,0,n+1) {dp[i][0] = 1;}

	for(int i = 1;i < n+1;i++)
	{
		cum[0] = 0;
		rep(j,1,k+1+1) cum[j] = (cum[j-1]+dp[i-1][j-1])%MOD;
		rep(j,0,k+1) dp[i][j] = (cum[j+1]-cum[max(0,j-a[i])]+MOD)%MOD;
	}
	printf("%I64d\n", dp[n][k]);
	return (0);
}