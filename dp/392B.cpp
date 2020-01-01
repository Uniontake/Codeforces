#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 45;
ll t[3][3];
bool lrc[3];
ll dp[maxn][3][3];
int main()
{
	int n,c;
	for(int i=0;i<3;i++) 
		for(int j=0;j<3;j++) {
			scanf("%I64d",&t[i][j]);
		}
	scanf("%d",&n);
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++) {
		for(int l=0;l<3;l++) {
			for(int r=0;r<3;r++) if(l!=r){
				memset(lrc,0,sizeof(lrc));
				lrc[l] = lrc[r] = 1;
				for(int j=0;j<3;j++) if(!lrc[j]) c = j;
				ll way1 = dp[i-1][l][c] + dp[i-1][c][r]	+ t[l][r];
				ll way2 = 2*dp[i-1][l][r] + dp[i-1][r][l] + t[l][c] + t[c][r];
				dp[i][l][r] = min(way1,way2);
			}
		}
	}
	printf("%I64d\n",dp[n][0][2]);
	return 0;
}