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

int a[7],b[7];
int kase;
int vis[8888888];

struct Sta
{
	int a,b,c,d,e,f;
	int step;
}st,ed;

int get(Sta& tt) {
	int ret=0;
	ret+=tt.a;
	ret+=tt.b*10;
	ret+=tt.c*100;
	ret+=tt.d*1000;
	ret+=tt.e*10000;
	ret+=tt.f*100000;
	return ret;
}

Sta gao(Sta& now,int op) {
	Sta ret;
	if (op==1) {
		ret.a=now.c;
		ret.b=now.d;
		ret.c=now.b;
		ret.d=now.a;
		ret.e=now.e;
		ret.f=now.f;
	}
	else if (op==2) {
		ret.a=now.d;
		ret.b=now.c;
		ret.c=now.a;
		ret.d=now.b;
		ret.e=now.e;
		ret.f=now.f;
	}
	else if (op==3) {
		ret.a=now.f;
		ret.b=now.e;
		ret.c=now.c;
		ret.d=now.d;
		ret.e=now.a;
		ret.f=now.b;
	}
	else if (op==4) {
		ret.a=now.e;
		ret.b=now.f;
		ret.c=now.c;
		ret.d=now.d;
		ret.e=now.b;
		ret.f=now.a;
	}
	return ret;
}

int bfs() {
	Sta now;
	st.step=0;
	queue<Sta> q;
	vis[get(st)]=kase;
	q.push(st);
	// cout << get(st) << '\n' << get(ed) << endl;
	while(q.size()) {
	    now=q.front();q.pop();
	    if (get(now)==get(ed)) return now.step;
	    for (int i=1;i<=4;i++) {
	    	Sta tmp=gao(now,i);
	    	int tt=get(tmp);
	    	if (vis[tt]!=kase) {
	    		vis[tt]=kase;
	    		tmp.step=now.step+1;
	    		q.push(tmp);
	    	}
	    }
	}
	return -1;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    CLR(vis);
    kase=0;
	while(~SI(st.a)) {
		kase++;
		scanf("%d%d%d%d%d",&st.b,&st.c,&st.d,&st.e,&st.f);
		scanf("%d%d%d%d%d%d",&ed.a,&ed.b,&ed.c,&ed.d,&ed.e,&ed.f);
		int ans=bfs();
		cout << ans << endl;
	}
	return 0;
}