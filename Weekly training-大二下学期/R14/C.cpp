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
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7f7f7f7f;
const int MOD=1e9+7;
const double eps=1e-10;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int m;
struct Seg{
	int s,t;
	Seg(int s,int t):s(s),t(t){}
	bool operator < (const Seg& rhs) const {
		return s<rhs.s;
	}
};

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    for (int T_T,kase=SI(T_T);kase<=T_T;kase++) {
    	if (kase!=1) cout << endl;
    	SI(m);
    	int a,b;
    	vector<int> ans;
    	vector<Seg> asd;
    	while(SII(a,b)==2 && !(a==0 && b==0)) {
    		asd.push_back(Seg(a,b));
    	}
    	sort(asd.begin(),asd.end());
    	int flag=0;
    	rep(i,0,asd.size()-1) {
    		if (asd[i].t>=0) {
    			flag=1;break;
    		}
    	}
    	if (!flag || !asd.size()) {
    		cout << 0 << endl;
    		continue;
    	}
    	int l = 0, r = m, tot = 0;
    	while(l < r) {
    		if (tot>=asd.size()) break;
    		int pos = -1;
    		int maxr=-INF_INT;
    		while(asd[tot].s <= l) {
    			if(asd[tot].t > maxr) {
    				maxr = asd[tot].t;
    				pos = tot;
    			}
    			tot++;
    			if (tot>=asd.size()) break;
    		}
    		if(maxr < l) pos = -1;
    		if(pos == -1) break;
    		l = maxr;
    		ans.push_back(pos);
    	}
    	if(!ans.size() || asd[ans.back()].t < m) cout << 0 << endl;
    	else {
    		cout << ans.size() << endl;
    		vector<Seg> tmp;
    		rep(i,0,ans.size()-1) {
    			tmp.push_back(asd[ans[i]]);
    		}
    		sort(tmp.begin(),tmp.end());
    		rep(i,0,tmp.size()-1) {
    			cout << tmp[i].s << ' ' << tmp[i].t << endl;
    		}
    	}

    }
	return 0;
}