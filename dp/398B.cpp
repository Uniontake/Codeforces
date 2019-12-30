/**
 * 题意：
 * 给出n和m，表示在一个n*n的平面上有n*n个方格，
 * 其中有m块已经涂色。现在随机选中一块进行涂色（如果已经涂色跳过，也消耗时间），
 * 消耗1个步骤。终止条件为每行每列都有至少有一块瓷砖被涂色。问说涂成满意的情况需要时间的期望。
 *
 * 题解：
 * 设dp[i][j] 表示还剩下i行和j列没有被画（dp[0][0] = 0）
 * 对于任意dp[i][j] = 1 + k: 1表示无论如何都要花费的期望时间，k表示已经求得状态的期望*概率
 * k = dp[i-1][j-1]*i/n*j/n + dp[i-1][j]*i/n*(n-j)/n + dp[i][j-1]*(n-i)/n*j/n + dp[i][j]*(n-i)/n*(n-j)/n
 * 主要是等式两边都有dp[i][j],所以需要将其化简
**/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3+10;
int row[maxn],col[maxn];
double dp[maxn][maxn];
int main()
{
	int n,c;
	while(~scanf("%d%d",&n,&c)) {
		memset(row,0,sizeof(row));
		memset(col,0,sizeof(col));
		for(int i=0,u,v;i<c;i++) {
			scanf("%d%d",&u,&v);
			row[u]=1,col[v]=1;
		}
		int num_row = 0,num_col = 0;
		for(int i=1;i<=n;i++) {
			if(row[i]) num_row++;
			if(col[i]) num_col++;
		}
		memset(dp,0,sizeof(dp));
		for(int i=1;i<n;i++) dp[i][0] = dp[i-1][0] + 1.0*n/i;
		for(int i=1;i<n;i++) dp[0][i] = dp[0][i-1] + 1.0*n/i;
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				dp[i][j] = n*n;
				dp[i][j] += dp[i-1][j-1]*i*j;
				dp[i][j] += dp[i-1][j]*i*(n-j);
				dp[i][j] += dp[i][j-1]*j*(n-i);
				dp[i][j] /= (n*n - (n-i)*(n-j));
			}
		}
		printf("%.6f\n", dp[n-num_row][n-num_col]);
	}
	return 0;
}