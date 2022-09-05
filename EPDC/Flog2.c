#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define rep(i,l,r) for(int i=(l);i<(r);i++)
#define max(p,q) ((p)>(q)?(p):(q))
#define min(p,q) ((p)<(q)?(p):(q))

int	main(void)
{
	int n;
	int k;
	int *h;
	int *dp;
	int tmp;

	scanf("%d %d",&n,&k);
	h = (int *)malloc(sizeof(int) * n);
	for(int i=0;i<n;i++)
		scanf("%d",&h[i]);
	dp = (int *)malloc(sizeof(int) * n);

	rep(i,0,n) dp[i] = 0;
	dp[1] = abs(h[1] - h[0]);
	rep(i,2,n)
	{
		rep(j,1,k + 1)
		{
			if (j > i)
				break ;
			tmp = dp[i - j] + abs(h[i] - h[i - j]);
			if (j == 1)
				dp[i] = tmp;
			dp[i] = min(dp[i],tmp);			
		}
	}
	printf("%d\n",dp[n - 1]);
	return (0);
}