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

const int N=50010*3;
int pnt[N],head[N],nxt[N];
ll c[N];
int vis[N];
int cnt;
int counter[N];
ll ans;
int n;

void addedge(int u,int v,int w){
	c[cnt]=w;pnt[cnt]=v;nxt[cnt]=head[u];head[u]=cnt++;
}

void init(){
	cnt=0;ans=0;
	OFF(head);OFF(nxt);CLR(vis);
	for (int i=0;i<=n;i++) counter[i]=1;
	for (int i=0;i<n;i++){
		int a,b,w;
		scanf("%d%d%d",&a,&b,&w);
		addedge(a,b,w); 
		addedge(b,a,w);
	}
}

void dfs(int u){
	vis[u]=1;
	for (int i=head[u];~i;i=nxt[i]){
		int v=pnt[i];
		if (vis[v]) continue;
		dfs(v);
		counter[u]+=counter[v];
		ans+=c[i]*abs(n-2*counter[v]);
	}
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n){
		init();
		dfs(1);
		if (ans==0) cout << "0\n";
		else 
			printf("%lld00000000\n",ans);
	}
	return 0;
}


