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
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-6;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=2e4;
const int M=1010;

int n,m;

int pnt[N],nxt[N],head[M],cnt;
double w[N],val[M];
void add_edge(int u,int v,double c) {
	pnt[cnt]=v;nxt[cnt]=head[u];w[cnt]=c;head[u]=cnt++;
}


double d[M];
int vis[M],counter[M];
bool spfa(double mid) {
	queue<int> q;
	rep(i,1,n) {
		vis[i]=counter[i]=1;
		q.push(i);
		d[i]=0;
	}
	while(q.size()) {
	    int x=q.front();q.pop();
	    vis[x]=0;
	    for (int i=head[x];~i;i=nxt[i]) {
	    	int v=pnt[i];
	    	double tmp=val[x]-mid*w[i];
	    	if (d[v]<d[x]+tmp) {
	    		d[v]=d[x]+tmp;
	    		if (!vis[v]) {
	    			vis[v]=1;
	    			counter[v]++;
	    			q.push(v);
	    			if (counter[v]>n) return true;
	    		}
	    	}
	    }
	}
	return false;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while(SII(n,m)==2) {
    	OFF(head);cnt=0;
        rep(i,1,n) scanf("%lf",val+i);
        rep(i,1,m) {
        	int u,v;
        	double cost;
        	SII(u,v);
        	scanf("%lf",&cost);
        	add_edge(u,v,cost);
        	// cout << u << ' ' << v << ' ' << cost << endl;
        }
        double L=0.0,R=1000.0;
        while(R-L>=eps) {
            double mid=(L+R)/2.0;
            // cout << L << ' ' << R << endl;
            if (spfa(mid)) L=mid;
            else R=mid;
        }
        printf("%.2f\n",(L+R)/2.0);
    }
	return 0;
}
