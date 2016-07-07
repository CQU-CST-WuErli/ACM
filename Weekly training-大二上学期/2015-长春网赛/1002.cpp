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
#define ALL(x) x.begin(),x.end()
#define AT(i,v) for (auto &i:v)
#define For_UVa if (kase!=1) cout << endl
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define look(x) cout << #x << "=" << x
#define SI(a) scanf("%d",&a)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define BigInteger bign
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;
const int N=2e4;
int p,m;
ll val[N];
vector<int> g[N];
int par[N],rnk[N];
int deg[N];
ll sum[N];
int num[N];
int vis[N];
void init(){
    for (int i=0;i<=p;i++) g[i].clear();
    for (int i=0;i<=p;i++) {
        par[i]=i;
        rnk[i]=0; 
    }
    CLR(deg);
    CLR(sum);
    CLR(rnk);
    CLR(num);
}
int find(int x)
{
    int r=x;
   while (par[r]!=r)
   r=par[r];
   int i=x; int j;
   while(i!=r)
   {
       j=par[i];
       par[i]=r;
       i=j;
   }
   return r;
}
void dfs(int u){
    num[par[u]]--;
    sum[par[u]]-=val[u];
    vis[u]=1;
//    lookln(u);
    for (int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if (v==u || vis[v]) continue;
        deg[v]--;
        if (deg[v]<=1) dfs(v);
    }
}
//#define LOCAL
int main(){
#ifdef LOCAL
    freopen("in.txt","r",stdin);
//    freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int _;
    int t;cin >> t;
    while (t--){
        scanf("%d%d",&p,&m);
        init();
        for (int i=1;i<=p;i++)scanf("%I64d",val+i);
        for (int i=1;i<=m;i++) {
            int u,v;
            scanf("%d%d",&u,&v);
        //    cout <<u<<v;
//            if (u==v) continue;
            g[u].push_back(v);
            g[v].push_back(u);
            int f1 = find(u);
            int f2 = find(v);
            if(f1!=f2){
                par[f2]=f1;
            }
            deg[u]++;deg[v]++;
        }
        set<int> st;
        for (int i=1;i<=p;i++){
            int x = find(i);
            num[x]++;
            sum[x]+=val[i];
            st.insert(par[i]);
        }
        //for (int i:st) cout << i << endl;
        CLR(vis);
        for (int i=1;i<=p;i++){
            if (deg[i]==1 && !vis[i]) dfs(i);
        }
        ll ans=0;
        for (set<int>::iterator it=st.begin();it!=st.end();it++) {
            if (num[*it]%2 && num[*it]>1) {
                ans+=sum[*it];
            }
        }        
        cout << ans << endl;
    }
    return 0;
}
