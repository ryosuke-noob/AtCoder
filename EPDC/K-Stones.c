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
	int *dp;
	int Min;

	(void)scanf("%d %d",&n,&k);
	a = (int *)malloc(sizeof(int)*(n+1));
	rep(i,1,n+1) (void)scanf("%d",&a[i]);
	dp = (int *)malloc(sizeof(int)*(k+1));
	rep(i,0,k+1) dp[i] = 0;

	Min = a[1];
	rep(i,1,k+1)
	{
		if (i < Min) dp[i] = 0;
		else
		{
			rep(j,1,n+1)
			{
				if (i - a[j] < 0) {dp[i] = 0; break;}
				else if (dp[i - a[j]] == 0) {dp[i] = 1; break;}
			}
		}
	}
	
	if (dp[k] == 0) printf("Second");
	else printf("First");

	return (0);
}