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
	int h,w;
	char **a, dummy;
	int **dp;

	scanf("%d %d",&h,&w);
	scanf("%c",&dummy);
	a = (char **)malloc(sizeof(char *) * (h + 1));
	rep(i,1,h+1) a[i] = (char *)malloc(sizeof(char) * (w + 2));
	rep(i,1,h+1) rep(j,1,w+2) scanf("%c",&a[i][j]);//改行まで読み込んでいる
	dp = (int **)malloc(sizeof(int *) * (h + 1));
	rep(i,0,h+1) dp[i] = (int *)malloc(sizeof(int) * (w + 1));
	rep(i,0,h+1) dp[i][0] = 0;
	rep(j,0,w+1) dp[0][j] = 0;
	// rep(i,1,h+1) rep(j,1,w+1) printf("%c",a[i][j]);

	dp[1][1] = 1;
	rep(i,1,h+1)
	{
		rep(j,1,w+1)
		{
			// printf("[%c ",a[i][j]);
			if (a[i][j] == '#')
				dp[i][j] = 0;
			else if (i != 1 || j != 1)
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
			// printf("%d] ",dp[i][j]);
		}
	}
	printf("%d\n",dp[h][w]);

	return (0);
}