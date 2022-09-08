#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define rep(i,l,r) for(int i=(l);i<(r);i++)
#define max(p,q) ((p)>(q)?(p):(q))
#define min(p,q) ((p)<(q)?(p):(q))


//価値に対する重さの最小値を求める
//価値の最大値= v_max * N_max = 100000
int main(void)
{
	int N, W;
	int max_value;
	int *w, *v;
	double **dp;

	max_value = 100000;
	scanf("%d %d",&N, &W);
	w = (int *)malloc(sizeof(int) * (N + 1));
	v = (int *)malloc(sizeof(int) * (N + 1));
	rep(i,1,N + 1) scanf("%d %d",&w[i],&v[i]);
	dp = (double **)malloc(sizeof(double *) * (N + 1));
	rep(i,0,N + 1) dp[i] = (double *)malloc(sizeof(double) * (max_value + 1));
	rep(i,0,N + 1) rep(j,0,max_value + 1) dp[i][j] = INT_MAX;
	//int型に収まるうちできるだけ大きい数
	//多分Wより大きければなんでもいい
	dp[0][0] = 0;

	rep(i,1,N + 1)
	{
		rep(j,0,max_value + 1)
		{
			if (j - v[i] < 0)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = min(dp[i - 1][j - v[i]] + w[i], dp[i - 1][j]);
			// if (j < 30 + 1)
			// {
			// 	if (dp[i][j] != INT_MAX) printf("%2.0f ",dp[i][j]);
			// 	else printf("-- ");
			// }
		}
		// printf("\n");
	}
	while (dp[N][max_value] > W) max_value--;
	printf("%d\n",max_value);
	return (0);
}