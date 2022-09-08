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
	char s[3001],t[3001];
	int s_len, t_len;
	int **dp;

	(void)scanf("%s",s);
	(void)scanf("%s",t);
	s_len = (int)strlen(s);
	t_len = (int)strlen(t);
	dp = (int **)malloc(sizeof(int *) * (s_len + 1));
	rep(i,0,s_len + 1) dp[i] = (int *)malloc(sizeof(int) * (t_len + 1));
	rep(j,0,t_len + 1) dp[0][j] = 0;
	rep(i,0,s_len + 1) dp[i][0] = 0;

	rep(i,1,s_len + 1)
	{
		rep(j,1,t_len + 1)
		{
			if (s[i - 1] == t[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			// printf(" %d",dp[i][j]);
		}
		// printf("\n");
	}
	// printf("%d\n",dp[s_len][t_len]);

	int len = dp[s_len][t_len];
	int i = s_len;
	int j = t_len;
	char *ans = (char *)malloc(len + 1);
	ans[len] = 0;
	while (len > 0)
	{
		if (s[i - 1] == t[j - 1])
		{
			ans[--len] = s[i - 1];
			i--;
			j--;
		}
		else if (dp[i][j] == dp[i][j - 1])
			j--;
		else
			i--;
	}
	printf("%s\n",ans);

	return (0);
}