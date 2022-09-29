#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define rep(i,l,r) for(int i=(l);i<(r);i++)
#define max(p,q) ((p)>(q)?(p):(q))
#define min(p,q) ((p)<(q)?(p):(q))

unsigned long long f(int l, int r, unsigned long long **dp, int *a)
{
	if (dp[l][r]) return dp[l][r];
	if (l==r) return 0;
	unsigned long long fans = LLONG_MAX;
	rep(m,l,r) fans = min(fans, f(l,m,dp,a)+f(m+1,r,dp,a));
	dp[l][r] += fans;
	rep(i,l,r+1) dp[l][r] += a[i];
	return dp[l][r];
}

int main(void)
{
	int n;
	int *a;
	unsigned long long **dp;
	unsigned long long ans = 0;

	if(scanf("%d",&n) != 1) return 0;
	a = (int*)malloc(sizeof(int)*(n+1));
	rep(i,1,n+1) if(scanf("%d",&a[i]) != 1) return 0;
	dp = (unsigned long long**)malloc(sizeof(unsigned long long*)*(n+1));
	rep(i,0,n+1) dp[i] = (unsigned long long*)malloc(sizeof(unsigned long long)*(n+1));
	rep(i,0,n+1) rep(j,0,n+1) dp[i][j] = 0;

	ans = f(1,n,dp,a);

	printf("%I64lld\n",ans);
	return (0);
}