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
#define BigInteger bign
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

string s;

int nxt[1000100];
set<int>st;

void getnxt(string &t) {
	nxt[0]=-1;
	int i=0,j=-1;
	while (i<t.size()) {
		if (j==-1 || t[i]==t[j]) nxt[++i]=++j;
		else j=nxt[j];
	}
	rep(i,0,s.size()-1) st.insert(nxt[i]);
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> s) {
		st.clear();
		getnxt(s);
		int i=s.size();
		int flag=0;
		while (nxt[i]>0) {
			if (st.count(nxt[i])) {
				flag=1;
				rep(j,0,nxt[i]-1) cout << s[j];
				cout << endl;
				break;
			}
			i=nxt[i];
		}
		if (!flag) puts("Just a legend");
	}
	return 0;
}