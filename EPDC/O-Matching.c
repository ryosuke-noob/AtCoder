#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define INF ((1LL<<62)-(1LL<<31)) /*オーバーフローしない程度に大きい数*/
#define MOD 1000000007
#define rep(i,l,r) for(int i=(l);i<(r);i++)
#define max(p,q) ((p)>(q)?(p):(q))
#define min(p,q) ((p)<(q)?(p):(q))
#define bit(n,k) ((n>>k)&1) /*nのk bit目が1かどうか*/

int main(void)
{
	int n,ans;
	int **a;
	int **dp;

	if (scanf("%d",&n) != 1) return 1;
	a = (int **)malloc(sizeof(int *) * (n));
	rep(i,0,n) a[i] = (int *)malloc(sizeof(int) * (n));
	rep(i,0,n) rep(j,0,n) if (scanf("%d",&a[i][j]) != 1) return 1;
	dp = (int **)malloc(sizeof(int *) * (n+1));
	rep(i,0,n+1) dp[i] = (int *)malloc(sizeof(int) * (1<<n));

	// dp[0][0] = 1;
	// rep(i,0,n) rep(s,0,1<<n) if(dp[i][s])
	// {
	// 	rep(j,0,n) if(bit(s,j)==0 && a[i][j]==1)
	// 	{
	// 		dp[i+1][s^(1<<j)] = (dp[i][s^(1<<j)]+dp[i][s])%MOD;
	// 	}
	// 	printf("%d ",dp[i][s]);
	// 	if (s == (1<<n)-1) printf("\n");
	// }
	rep(i,0,n) rep(j,0,1<<n) dp[i][j]=1;
	dp[0][0] = 1;
	rep(i,0,n)rep(S,0,1<<n)if(dp[i][S]){
		rep(j,0,n)if(bit(S,j)==0&&a[i][j]==1){
			dp[i+1][S^(1<<j)]=(dp[i][S^(1<<j)]+dp[i][S])%MOD;
		}
	}
	ans=dp[n][(1<<n)-1];
	printf("%d\n",ans);

	return (0);
}
