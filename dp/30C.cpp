#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1100;
struct Point {
	ll x,y,t;
	double p;
	bool operator < (const Point& a) const {
		return t < a.t;
	}
};
Point p[maxn];
double dp[maxn];
ll norm(ll x) {
	return x*x;
}
double dist(int i,int j) {
	return norm(p[i].x-p[j].x)+norm(p[i].y-p[j].y);
}
int main()
{
	int n;
	while(~scanf("%d",&n)) {
		for(int i=0;i<n;i++) scanf("%I64d%I64d%I64d%lf",&p[i].x,&p[i].y,&p[i].t,&p[i].p);
		sort(p,p+n);
		memset(dp,0,sizeof(dp));
		double ans = 0;
		// for(int i=0;i<n;i++) printf("%I64d %I64d\n", p[i].x,p[i].t);
		for(int i=0;i<n;i++) {
			dp[i] = p[i].p;
			for(int j=0;j<i;j++) if(dist(i,j) <= norm(p[i].t-p[j].t)){
				dp[i] = max(dp[i],dp[j]+p[i].p);
			}
			ans = max(dp[i],ans);
		}
		// for(int i=0;i<n;i++) printf("%.6f ", dp[i]);printf("\n");
		printf("%.8f\n", ans);
	}
	return 0;
}