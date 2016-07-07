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
const double eps=1e-8;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

struct P
{
	double x,y,z;
	int id,cap;
	P(){}
	void read() {
		scanf("%d%d",&id,&cap);
		scanf("%lf%lf%lf",&x,&y,&z);
	}
	void print() {
		cout << "id=" << id << " cap=" << cap;
		cout << " x=" << x << " y=" << y << " z=" << z << endl;
	}
}send[220],recive[220];
int n;
int t;
struct Sta
{
	double dis;
	int cap,id;
	Sta(double dis,int cap,int id):dis(dis),cap(cap),id(id){}
	bool operator < (const Sta& rhs) const {
		if (dis==rhs.dis) return cap>rhs.cap;
		else return dis<rhs.dis;
	}
	void print() {
		cout << "id=" << id << " cap=" << cap << " dis=" << dis << endl;
	}
};
vector<Sta> pri[220];

double dis(P& a,P& b) {
	double dx=a.x-b.x;
	double dy=a.y-b.y;
	double dz=a.z-b.z;
	return dx*dx+dy*dy+dz*dz;
}

int pref[220][220],order[220][220],nxt[220];
int future_husband[220],future_wife[220];
queue<int> q;
void engage(int man,int woman) {
	int m=future_husband[woman];
	if (m) {
		future_wife[m]=0;
		q.push(m);
	}
	future_wife[man]=woman;
	future_husband[woman]=man;
}

void GalShapley() {
	// man judge woman
	rep(i,1,n) pri[i].clear();
	rep(i,1,n) rep(j,1,n) {
      	double d=dis(send[i],recive[j]);
     	pri[i].push_back(Sta(d,recive[j].cap,j));
    }
    rep(i,1,n) sort(pri[i].begin(),pri[i].end());
	rep(i,1,n) {
		rep(j,0,pri[i].size()-1) pref[i][j+1]=pri[i][j].id;
		future_wife[i]=0;
		nxt[i]=1;
		q.push(i);
	}
	// woman judge man
	rep(i,1,n) pri[i].clear();
	rep(i,1,n) rep(j,1,n) {
		double d=dis(recive[i],send[j]);

		pri[i].push_back(Sta(d,send[j].cap,j));
	}
	rep(i,1,n) sort(pri[i].begin(),pri[i].end());
	rep(i,1,n) {
		rep(j,0,pri[i].size()-1) order[i][pri[i][j].id]=j+1;
		future_husband[i]=0;
	}
	while(q.size()) {
	    int man=q.front();q.pop();
	    int woman=pref[man][nxt[man]++];
	    if (!future_husband[woman]) engage(man,woman);
	    else if (order[woman][man]<order[woman][future_husband[woman]])
	    	engage(man,woman);
	    else q.push(man);
	}
	while(q.size()) q.pop();
	for (int i=1;i<=n;i++) printf("%d %d\n",i,future_wife[i]);
	puts("");
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    SI(t);
    while(t--) {
        SI(n);
        rep(i,1,n) send[i].read();
        rep(i,1,n) recive[i].read();
        GalShapley();
    }
	return 0;
}