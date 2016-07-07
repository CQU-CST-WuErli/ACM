//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015Äê CQU_CST_WuErli. All rights reserved.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <ctime>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <sstream>
#include <functional>
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define MEM(x,a) memset((x),(a),sizeof(x))
#define ALL(x) x.begin(),x.end()
#define at(i,v) for (auto &i:v)
#define for_uva if (kase!=1) cout << endl
#define BUG(x) cout << "I am in line" << x << endl
#define look(x) cout << #x << "= " << x << endl
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define INF 0x3f3f3f3f
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int n,m;
int mp[20][200];
int path[20][200];
int dp[20][200];


int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> m >> n){
		CLR(mp);CLR(path);CLR(dp);
		for (int i=1;i<=m;i++){
			for (int j=1;j<=n;j++){
				cin >> mp[i][j];
			}
		}
		int start=0,ans=INF;
		for (int j=n;j>=1;j--){
			for (int i=1;i<=m;i++){
				if (j==n) dp[i][j]=mp[i][j];
				else {
					dp[i][j]=INF;
					int dir[3]={i-1,i,i+1};
					if (i-1==0) dir[0]=m;
					if (i+1==m+1) dir[2]=1;
					sort(dir,dir+3);
					for (int k=0;k<3;k++){
						int tmp=mp[i][j]+dp[dir[k]][j+1];
						if (tmp<dp[i][j]){
							dp[i][j]=tmp;
							path[i][j]=dir[k];
						}
					}
				}
				if (j==1) {
					if (dp[i][j]<ans) {
						ans=dp[i][j];start=i;
					}
				}
			}
		}
		cout << start;
		for (int i=path[start][1],j=2;j<=n;i=path[i][j],j++){
			cout << ' ' << i;   // iÊÇÐÐºÅ 
		}
		cout << endl << ans << endl;
	}
	return 0;
}


