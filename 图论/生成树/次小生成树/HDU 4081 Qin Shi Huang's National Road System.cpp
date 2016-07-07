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
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

struct P
{
	int x,y;
	int population;
	void read() {
		SIII(x,y,population);
	}
}city[1010];
int n;
double dist[1010][1010];
double F[1010][1010];
int pre[1010],vis[1010];
double d[1010];
int used[1010][1010];
double getd(P& a,P& b) {
	double dx=(a.x-b.x)*1.0;
	double dy=(a.y-b.y)*1.0;
	return sqrt(dx*dx+dy*dy);
}

double prim() {
	double ret=0.0;
	CLR(F);CLR(vis);CLR(used);
	rep(i,1,n) {
		pre[i]=1;
		d[i]=dist[1][i];
	}
	vis[1]=1;
	d[1]=0;
	for (int i=2;i<=n;i++) {
		double mincost=INF_INT*1.0;
		int minid=-1;
		for (int j=1;j<=n;j++) if (!vis[j] && d[j]<mincost) {
			mincost=d[j];
			minid=j;
		}
		ret+=mincost;
		vis[minid]=1;
		used[minid][pre[minid]]=used[pre[minid]][minid]=1;
		for (int j=1;j<=n;j++) {
			if (!vis[j] && d[j]>dist[minid][j]) {
				d[j]=dist[minid][j];
				pre[j]=minid;
			}
			if (vis[j] && j!=minid) {
				F[minid][j]=F[j][minid]=max(F[j][pre[minid]],mincost);
			}
		}
	}
	return ret;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int t;SI(t);
    while(t--) {
        SI(n);
        rep(i,1,n) city[i].read();
        rep(i,1,n) rep(j,1,n) dist[i][j]=getd(city[i],city[j]);
        // for (int i=1;i<=n;i++) {
        // 	for (int j=1;j<=n;j++) cout << dist[i][j] << ' ' ;
        // 	cout << endl;
        // }
        double tmp=prim();
        // for (int i=1;i<=n;i++) {
        // 	for (int j=1;j<=n;j++) printf("%4d ",(int)F[i][j]) ;
        // 	cout << endl;
        // }
        // lookln(tmp);
        double ans=0.0;
        rep(i,1,n) rep(j,1,n) if (i!=j) {
        	if (used[i][j]) {
        		if (ans<(city[i].population+city[j].population)/(tmp-dist[i][j])) {
        			ans=(city[i].population+city[j].population)/(tmp-dist[i][j]);
        			// cout << "1-   " << i << ' ' << j << ' ' << ans << endl;
        		}
        	}
        	else {
        		if (ans<(city[i].population+city[j].population)/(tmp-F[i][j])) {
        			ans=(city[i].population+city[j].population)/(tmp-F[i][j]);
        			// cout << "2-   " << i << ' ' << j << ' ' << ans << endl;
        		}
        	}
        }
        printf("%.2f\n",ans);
    }
	return 0;
}