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
int mp[550][550];
int vis[550];
vector<int> g[550];
int col[550];
char s[550];

bool dfs(int u,int c) {
    col[u]=c;
    for (int i=0;i<g[u].size();i++) {
        int v=g[u][i];
        if (!col[v]) {
            if (!dfs(v,-c)) return false;
        }
        else if (col[v]==col[u]) return false;
    }
    return true;
}

int main(){
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//  freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int t; SI(t);
    while (t--) {
        SII(n,m);
        CLR(mp);
        rep(i,0,n) g[i].clear();
        rep(i,1,m) {
            int u,v;
            SII(u,v);
            mp[u][v]=mp[v][u]=1;
        }
        CLR(vis);
        rep(i,1,n) rep(j,i+1,n) if (!mp[i][j]) {
            g[i].push_back(j);
            g[j].push_back(i);
            vis[i]=vis[j]=1;
        }
        CLR(col);
        int flag=1;
        rep (i,1,n) if (vis[i] && !col[i]) {
            if (!dfs(i,1)) {
                flag=0;break;
            }
        }
        CLR(col);
        rep(i,1,n) if (vis[i] && !col[i]) {
            if (!dfs(i,-1)) {
                flag=0;break;
            }
        }
        if (!flag) puts("No");
        else {
            rep(i,1,n) {
                if (!vis[i]) s[i]='b';
                else if (col[i]==1) s[i]='a';
                else s[i]='c';
            }
            rep(i,1,n) rep(j,1,n) if (i!=j) {
                if (abs(s[i]-s[j])<=1 && !mp[i][j]) {
                    flag=0;break;
                }
                if (abs(s[i]-s[j])>1 && mp[i][j]) {
                    flag=0;break;
                }
            }
            if (!flag) puts("No");
            else {
                puts("Yes");
            }
        }
    }
    return 0;
}