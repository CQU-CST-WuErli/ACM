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

priority_queue<int> q[2];
int num[110];
vector<int> pile[110];
int n,m;
int R;
int wolffy,happy;

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	SI(R);
	wolffy=happy=0;
	while(R--) {
	    SII(n,m);
	    rep(i,1,m) pile[i].clear();
	    rep(i,1,m) SI(num[i]);
	    rep(i,1,m) rep(j,1,num[i]) {
	    	int x;SI(x);
	    	pile[i].push_back(x);
	    }
	    while(q[0].size()) q[0].pop();
	    while(q[1].size()) q[1].pop();
	    char op;
	    int id;
	    getchar();
	    rep(i,1,n) {
	    	cin >> op;
	    	int now=(i+1)%2;
	    	int vs=i%2;
	    	// cout << op << endl;
	    	if (op=='T') {
	    		SI(id);
	    		// cout << "pile[" << id << "].size()=" << pile[id].size() << endl;
	    		rep(j,0,pile[id].size()-1) q[now].push(pile[id][j]);
	    		pile[id].clear();
	    		// cout << "q[" << now << "].size()=" << q[now].size() << endl;
	    	}
	    	else if (op=='C') {
	    		int pnow=q[now].top();
	    		int pvs=q[vs].top();
	    		int win=-1;
	    		if (pnow>pvs) win=now;
	    		else if (pnow<pvs) win=vs;
	    		if (win!=-1) {
	    			while(q[(win+1)%2].size()) {
	    				int tmp=q[(win+1)%2].top();
	    			    q[win].push(tmp);
	    			    q[(win+1)%2].pop();
	    			}
	    		}
	    	}
	    	else if (op=='L') {
	    		if (q[now].size()) q[now].pop();
	    	}
	    	else if (op=='A') {
	    		SI(id);
	    		int tmp=q[now].top();q[now].pop();
	    		tmp+=id;
	    		q[now].push(tmp);
	    	}
	    	else if (op=='E') {
	    		SI(id);
	    		int tmp=q[now].top();q[now].pop();
	    		tmp=id;
	    		q[now].push(tmp);
	    	}
	    }
	    if (q[0].size()>=q[1].size()) wolffy++;
	    else happy++;
	    printf("%d:%d\n",q[0].size(),q[1].size());
	}
	if (wolffy>happy) puts("Hahaha...I win!!");
	else puts("I will be back!!");
	return 0;
}