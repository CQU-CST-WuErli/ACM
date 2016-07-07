//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2016 CQU_CST_WuErli. All rights reserved.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <sstream>
#include <assert.h>
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define MEM(x,a) memset((x),(a),sizeof(x))
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define SI(a) scanf("%d",&a)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define rep(flag,start,end) for(int flag=start;flag<=end;flag++)
#define Rep(flag,start,end) for(int flag=start;flag>=end;flag--)
#define Lson l,mid,rt<<1
#define Rson mid+1,r,rt<<1|1
#define Root 1,n,1
#define BigInteger bign
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=1010;

int a[N][N];
int mp[2][N][N];
int n;
int dp[2][N][N];
char pre[2][N][N];
int vis[N][N];

struct Sta
{
	int x,y;
};

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while(SI(n)==1) {
    	CLR(mp);
    	int flag=0;
    	Sta zero;
        rep(i,1,n) rep(j,1,n) {
        	int x;SI(x);
        	a[i][j]=x;
        	int tmp=x;
        	if (x==0) {
        		zero.x=i;zero.y=j;
        		flag=1;
        		continue;
        	}
        	while (tmp%2==0) mp[0][i][j]++,tmp/=2;
        	while (x%5==0) mp[1][i][j]++,x/=5;
        }
        int dir[2][2]={1,0,0,1};
        for (int z=0;z<2;z++) for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) dp[z][i][j]=INF_INT;
        for (int z=0;z<2;z++) {
        	CLR(vis);CLR(pre[z]);
        	queue<Sta> q;
        	vis[1][1]=1;
        	q.push(Sta{1,1});
        	dp[z][1][1]=mp[z][1][1];
        	while (q.size()) {
        		Sta now=q.front();q.pop();
        		for (int i=0;i<2;i++) {
        			int nx=now.x+dir[i][0],ny=now.y+dir[i][1];
        			if (nx<1 || ny<1 || nx>n || ny>n) continue;
        			if (dp[z][nx][ny]>dp[z][now.x][now.y]+mp[z][nx][ny]) {
        				dp[z][nx][ny]=dp[z][now.x][now.y]+mp[z][nx][ny];
        				pre[z][nx][ny]=i==0?'D':'R';
        				if (!vis[nx][ny]) {
        					vis[nx][ny]=1;
        					q.push(Sta{nx,ny});
        				}
        			}
        		}
        	}
        }
        vector<char> ans;
        if (flag && min(dp[0][n][n],dp[1][n][n])>1) {
        	cout << 1 << endl;
        	int aa=zero.x,bb=zero.y;
        	for (int i=1;i<aa;i++) ans.push_back('D');
        	for (int i=1;i<bb;i++) ans.push_back('R');
        	for (int i=aa+1;i<=n;i++) ans.push_back('D');
        	for (int i=bb+1;i<=n;i++) ans.push_back('R');
        	for (int i=0;i<ans.size();i++) cout << ans[i];
        	cout << endl;
        }
        else {
        	cout << min(dp[0][n][n],dp[1][n][n]) << endl;
        	int pos=dp[0][n][n]<dp[1][n][n]?0:1;
        	int nx=n,ny=n;
        	while(1) {
        	    ans.push_back(pre[pos][nx][ny]);
        	    if (pre[pos][nx][ny]=='D') {
        	    	nx--;
        	    }
        	    else ny--;
        	    if (nx==1 && ny==1) break;
        	}
        	reverse(ans.begin(),ans.end());
        	for (int i=0;i<ans.size();i++) cout << ans[i];
        	cout << endl;
        }
    }
	return 0;
}