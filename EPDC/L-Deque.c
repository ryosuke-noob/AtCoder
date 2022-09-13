#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#define rep(i,l,r) for(int i=(l);i<(r);i++)
#define max(p,q) ((p)>(q)?(p):(q))
#define min(p,q) ((p)<(q)?(p):(q))

void myswap(double *a, double *b)
{
	double tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

double f(int l, int r, int **flag, double **dp, int *a)
{
	if (flag[l][r]) return dp[l][r];
	flag[l][r]=1;
	if (l==r) return (dp[l][r] = a[l]);
	return (dp[l][r] = max(a[l] - f(l+1,r,flag,dp,a), a[r] - f(l,r-1,flag,dp,a)));
}

int main(void)
{
	int n;
	int *a;
	int **flag;
	double **dp;
	double ret;

	scanf("%d",&n);
	a = (int *)malloc(sizeof(int) * (n+1));
	rep(i,1,n+1) scanf("%d",&a[i]);
	flag = (int **)malloc(sizeof(int *) * (n+1));
	dp = (double **)malloc(sizeof(double *) * (n+1));
	rep(i,0,n+1)
	{
		flag[i] = (int *)malloc(sizeof(int) * (n+1));
		dp[i] = (double *)malloc(sizeof(double) * (n+1));
		rep(j,0,n+1) {flag[i][j]=0;}
	}

	ret = f(1,n,flag,dp,a);
	printf("%0.lf\n",ret);

	return (0);
}