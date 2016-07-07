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
int k,n,m;
double sum;
double dp[25][55][25][105];
int c[100];
int v[100];
void print(double s,int cnt,int cost,int pre){
	if(cnt<=0)return;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k;j++){
			if(dp[cnt][i][j][cost]==s && i!=pre){
				if(j>=1)print(s-1.5*v[i],cnt-j-1,cost-(j+1)*c[i],i);
				else print(s-v[i],cnt-1,cost-c[i],i);
				for(int p=0;p<=j;p++){
					printf("%d ",i);
				}
				return;
			}
		}
	}
	return;
}
int main()
{
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	int kase = 1;
	while(cin >> k >> n >> m && (k+n+m)){
		CLR(dp);
		for(int i=1;i<=n;i++){
			scanf("%d%d",&c[i],&v[i]);
		}
		for(int i=1;i<=n;i++){
			dp[1][i][0][c[i]]=v[i];
		}
		for(int i=2;i<=k;i++){
			for(int j=1;j<=n;j++){
				for(int s=m;s>=c[j];s--){
					for(int cnt = 1;cnt <= k;cnt++){
						if(cnt==1 && dp[i-1][j][cnt-1][s-c[j]])dp[i][j][cnt][s]=max(dp[i][j][cnt][s],dp[i-1][j][cnt-1][s-c[j]]+v[j]*1.0/2);
						else dp[i][j][cnt][s]=max(dp[i][j][cnt][s],dp[i-1][j][cnt-1][s-c[j]]);
					//	printf("%d %d %d %d %lf\n",i,j,cnt,s,dp[i][j][cnt][s]);
					}
					for(int t=1;t<=n;t++){
						if(j!=t){
							for(int cnt = 0;cnt <= k;cnt++){
								if(dp[i-1][t][cnt][s-c[j]])dp[i][j][0][s]=max(dp[i][j][0][s],dp[i-1][t][cnt][s-c[j]]+v[j]);
							}
						}
						//printf("%d %d %d %d %lf\n",i,j,0,s,dp[i][j][0][s]);
					}
				}
			}
		}
		sum = 0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=m;j++){
				for(int cnt=0;cnt <= k;cnt++){
					sum = max(sum,dp[k][i][cnt][j]);
				}
			}
		}
		int cost = inf;
		for(int j=0;j<=m;j++){
			for(int i=1;i<=n;i++){
				for(int cnt=0;cnt<=k;cnt++){
					if(dp[k][i][cnt][j]==sum){
						cost = min(cost,j);
					}
				}
			}
		}
		printf("%.1lf\n",sum);
		if(sum!=0.0)print(sum,k,cost,-1);
		printf("\n");
	}
	return 0;
}







