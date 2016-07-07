//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015年 CQU_CST_WuErli. All rights reserved.
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
const int N=300;
int n,T;
int t[N];
int have_train[N][N][2];
int dp[N][N];

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int kase=1;
	while (cin >> n && n){
		cin >> T;
		for (int i=1;i<n;i++) cin >> t[i];
		int m1,m2;
		CLR(have_train);
		cin >> m1;
		for (int i=0;i<m1;i++){
			int t1;
			cin >> t1;
			for (int j=1;j<n;j++){
				if (t1<=T) {
					have_train[t1][j][0]=1;
					t1+=t[j];
				}
				else break;
			}
		}
		cin >> m2;
		for (int i=0;i<m2;i++){
			int t2;
			cin >> t2;
			for (int j=n;j>1;j--){
				if (t2<=T){
					have_train[t2][j][1]=1;
					t2+=t[j-1];
				}
				else break;
			}
		}
		for (int i=1;i<=n-1;i++) dp[T][i]=INF;
		dp[T][n]=0;
		for (int i=T-1;i>=0;i--){
			for (int j=1;j<=n;j++){
				dp[i][j]=dp[i+1][j]+1; // 原地等待 
				if (i+t[j]<=T && have_train[i][j][0] && j<n)
					dp[i][j]=min(dp[i][j],dp[i+t[j]][j+1]);
				if (j>1 && i+t[j-1]<=T && have_train[i][j][1]) 
					dp[i][j]=min(dp[i][j],dp[i+t[j-1]][j-1]);
			}
		} 
		cout << "Case Number " << kase++ << ": " ;
		if (dp[0][1]>=INF) cout << "impossible\n";
		else cout << dp[0][1] << endl;
	}
	return 0;
}


