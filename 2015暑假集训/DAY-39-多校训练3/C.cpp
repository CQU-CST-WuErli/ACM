/********************************************
Author         :Crystal
Created Time   :
File Name      :
********************************************/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <cctype>
using namespace std;
typedef long long ll;
typedef pair<int ,int> pii;
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a);
const int inf = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
//#define LOCAL
struct node{
	int cost;
	int pi;
	int a[15][2];
}p[55];
ll dp[55][100005];
int main()
{
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	int nmin = 0;
	int n,w;
	while(cin >> n >> w){
		for(int i=1;i<=n;i++){
		cin >> p[i].cost;
		cin >> p[i].pi;
		for(int j=1;j<=p[i].pi;j++){
			cin >> p[i].a[j][0] >> p[i].a[j][1];
		}
		}
		MEM(dp,-1);
		MEM(dp[0],0);
		for(int i=1;i<=n;i++){
			for(int k=p[i].cost;k<=w;k++)
				dp[i][k]=dp[i-1][k-p[i].cost];
			for(int j=1;j<=p[i].pi;j++)
				for(int k=w;k>=p[i].a[j][0];k--){
					if(dp[i][k-p[i].a[j][0]]!=-1)
						dp[i][k]=max(dp[i][k],dp[i][k-p[i].a[j][0]]+p[i].a[j][1]);
				}
			for(int j=0;j<=w;j++)
				dp[i][j]=max(dp[i][j],dp[i-1][j]);
		}
		cout << dp[n][w] << endl;
	}
	return 0;
}
