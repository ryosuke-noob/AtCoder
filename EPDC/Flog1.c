#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define rep(i,l,r) for(int i=(l);i<(r);i++)
#define max(p,q) ((p)>(q)?(p):(q))
#define min(p,q) ((p)<(q)?(p):(q))

int	main(void)
{
	int	n;
	int *h;
	int *dp;
	int tmp;
	int tmp2;

	scanf("%d",&n);
	h = (int *)malloc(sizeof(int) * n);
	for(int i=0;i<n;i++)
		scanf("%d",&h[i]);
	dp = (int *)malloc(sizeof(int) * n);

	dp[0] = 0;
	dp[1] = abs(h[1] - h[0]);
	rep(i,2,n)
	{
		tmp = dp[i - 1] + abs(h[i] - h[i - 1]);
		tmp2 = dp[i - 2] + abs(h[i] - h[i - 2]);
		dp[i] = min(tmp,tmp2);
	}
	printf("%d\n",dp[n - 1]);
	return (0);
}