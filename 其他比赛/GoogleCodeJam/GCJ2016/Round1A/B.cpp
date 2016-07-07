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
#include <cassert>
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


int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("B-large-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    for (int T_T,kase=SI(T_T);kase<=T_T;kase++) {
    	int n;cin >> n;
    	map<int,int> mp;
    	for (int i=1;i<=2*n-1;i++)
    		for (int j=1;j<=n;j++) {
    			int x;
    			cin >> x;
    			mp[x]++;
    		}
    	set<int> st;
    	for (map<int,int>::iterator it=mp.begin();it!=mp.end();it++) {
    		if (it->second%2==1) st.insert(it->first);
    	}
    	printf("Case #%d: ", kase);
    	vector<int> v;
    	for (set<int>::iterator it=st.begin();it!=st.end();it++) v.push_back(*it);
    	for (int i=0;i<v.size();i++) {
    		if (i) cout << ' ';
    		cout << v[i];
    	}
    	cout << endl;
    }
	return 0;
}