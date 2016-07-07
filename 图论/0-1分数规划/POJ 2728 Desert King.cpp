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
const double eps=1e-9;
typedef long long  ll;
using namespace std;

struct P
{
	double x,y,z;
	P(){}
	void read() {
		scanf("%lf%lf%lf",&x,&y,&z);
	}
}vill[1010];
int n;
double dist[1010][1010],cost[1010][1010];
double getd(P& a,P& b) {
	double dx=a.x-b.x;
	double dy=a.y-b.y;
	return sqrt(dx*dx+dy*dy);
}

int pre[1010];
double dis[1010];
int vis[1010];
double prim(double ratio) {
	double totcost=0,totdis=0;
	double sum=0;
	rep(i,1,n) pre[i]=1;
	dis[1]=0;
	CLR(vis);
	vis[1]=1;
	rep(i,2,n) dis[i]=cost[1][i]-dist[1][i]*ratio;
	int minId;
	rep(i,2,n) {
		double mincost=1.0*INF_INT;
		rep(j,2,n) {
			if (!vis[j] && dis[j]<mincost) {
				mincost=dis[j];
				minId=j;
			}
		}
		vis[minId]=1;
		sum+=mincost;
		totcost+=cost[pre[minId]][minId];
		totdis+=dist[pre[minId]][minId];
		rep(j,1,n) {
			if (!vis[j] && dis[j]>cost[minId][j]-dist[minId][j]*ratio) {
				dis[j]=cost[minId][j]-dist[minId][j]*ratio;
				pre[j]=minId;
			}
		}
	}
	return totcost/totdis;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while(SI(n)==1 && n) {
        rep(i,1,n) vill[i].read();
        rep(i,1,n) rep(j,1,n) {
        	dist[i][j]=getd(vill[i],vill[j]);
        	cost[i][j]=abs(vill[i].z-vill[j].z);
        }
        double l=1.0,ans;
        do {
        	ans=l;
        	l=prim(ans);
        }while(fabs(l-ans)>eps);
        printf("%.3f\n",l);
    }
	return 0;
}