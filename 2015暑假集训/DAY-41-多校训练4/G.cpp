#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf  = 0x3f3f3f3f;
const int maxn = 2e4 + 15;

inline int read() {
	char c = getchar();
	while(!isdigit(c)) c = getchar();
	int x = 0;
	while(isdigit(c)) {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x;
}

const int N=300;
double p[N][N];
double dp[10010][N];
int a[10010];
int m;


int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> m) {
		m=m*(m-1)*(m-2)/6;
		for (int i=0;i<m;i++){
			for (int j=0;j<m;j++){
				scanf("%lf",&p[i][j]);
		}
	}
	int n;
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	memset(dp,0,sizeof dp);
	for (int i=0;i<=m;i++) dp[0][i]=1;
		for (int i=1;i<=n;i++){
			for (int j=0;j<m;j++){
				dp[i][j]=max(dp[i][j],dp[i-1][j]*p[j][a[i]]);
				dp[i][a[i]]=max(dp[i][a[i]],dp[i-1][j]*p[j][a[i]]);
			}
		}
		double ans=0.00;
		for (int i=0;i<m;i++) ans=max(ans,dp[n][i]);
		printf("%.6f\n",ans);
	}
	return 0;
}
