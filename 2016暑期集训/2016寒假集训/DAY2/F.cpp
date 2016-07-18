//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015 CQU_CST_WuErli. All rights reserved.
//
// #include<bits/stdc++.h>
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
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define MEM(x,a) memset((x),(a),sizeof(x))
#define For_UVa if (kase!=1) cout << endl
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
template <typename T> T gcd(const T& a,const T& b) {return b==0?a:gcd(b,a%b);}
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int n,m;
int mp[16][16];
int dp[1<<15][16][16];
int ban[1<<15][16][16];
int kind[20];

struct State{
	int state;
	int x,y;
	State(int state,int x,int y):state(state),x(x),y(y){}
};

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (SII(n,m)==2) {
		int sx,sy;
		int cnt=0;
		vector<pair<int,int> > v;
		rep(i,1,n) rep(j,1,m) {
			char c;
			cin >> c;
			if (c=='.') mp[i][j]=-1;
			else if (c=='*') {
				mp[i][j]=-1;
				sx=i;sy=j;
			}
			else if (c=='K') {
				mp[i][j]=cnt;
				kind[cnt++]=1;
				v.push_back(make_pair(i,j));
			}
			else if (c=='B') {
				mp[i][j]=cnt;
				kind[cnt++]=2;
				v.push_back(make_pair(i,j));
			}
			else if (c=='R') {
				mp[i][j]=cnt;
				kind[cnt++]=3;
				v.push_back(make_pair(i,j));
			}
		}
		CLR(ban);MEM(dp,0x3f);
		int tmp[16][16];
		for (int sta=0;sta<1<<cnt;sta++) {
			memcpy(tmp,mp,sizeof(mp));
			for (int i=0;i<v.size();i++) {
				int ti=v[i].first,tj=v[i].second;
				if (!((sta>>mp[ti][tj])&1)) tmp[ti][tj]=-1;
			}
			for (int i=1;i<=n;i++) {
				for (int j=1;j<=m;j++) {
					if (tmp[i][j]==-1) continue;
					if (kind[tmp[i][j]]==1) {		//'K'
						for (int dx=-2;dx<=2;dx++) {
							for (int dy=-2;dy<=2;dy++) {
								if (abs(dx)+abs(dy)==3) {
									int tx=i+dx,ty=j+dy;
									if (tx<1 || ty<1 || tx>n || ty>m) continue;
									ban[sta][tx][ty]=1;
								}
							}
						}
					}
					else if (kind[tmp[i][j]]==2) {
						for (int dx=-1;dx<=1;dx+=2) {
							for (int dy=-1;dy<=1;dy+=2) {
								int tx=i+dx,ty=j+dy;
								while (tx>=1 && tx<=n && ty>=1 && ty<=m) {
									ban[sta][tx][ty]=1;
									if (tmp[tx][ty]!=-1) break;
									tx+=dx;ty+=dy;
								}
							}
						}
					}
					else if (kind[tmp[i][j]]==3) {
						int dx[4]={1,-1,0,0};
						int dy[4]={0,0,1,-1};
						for (int k=0;k<4;k++) {
							int tx=i+dx[k],ty=j+dy[k];
							while (tx>=1 && tx<=n && ty>=1 && ty<=m) {
								ban[sta][tx][ty]=1;
								if (tmp[tx][ty]>=0) break;
								tx+=dx[k];ty+=dy[k];
							}
						}
					}
				}
			}
		}
		// search
		queue<State> q;
		q.push(State((1<<cnt)-1,sx,sy));
		dp[(1<<cnt)-1][sx][sy]=0;
		while (q.size()) {
			State now=q.front();
			q.pop();
			int x=now.x,y=now.y;
//			cout << x << ' ' << y << endl;
			int state=now.state;
//			lookln(state);
			for (int dx=-1;dx<=1;dx++){
				for (int dy=-1;dy<=1;dy++){
					if (dx==0 && dy==0) continue;
					int tx=x+dx,ty=y+dy;
					if (tx<1 || ty<1 || tx>n || ty>m) continue;
					if (ban[state][tx][ty]) continue;
					if (mp[tx][ty]!=-1 && ((state>>mp[tx][ty])&1)) {
						int tt=state&~(1<<mp[tx][ty]);
						if (dp[state][x][y]+1<dp[tt][tx][ty]) {
							dp[tt][tx][ty]=dp[state][x][y]+1;
							q.push(State(tt,tx,ty));
						}
					}
					else {
						if (dp[state][x][y]+1<dp[state][tx][ty]) {
							dp[state][tx][ty]=dp[state][x][y]+1;
							q.push(State(state,tx,ty));
						}
					}
				}
			}
		}
		int ans=INF_INT;
		for (int i=0;i<v.size();i++) ans=min(ans,dp[0][v[i].first][v[i].second]);
		if (ans>=INF_INT) ans=-1;
		if (cnt==0) ans=0;
		cout << ans << endl;
	}
	return 0;
}

