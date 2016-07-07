//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2016 CQU_CST_WuErli. All rights reserved.
//
//#pragma comment(linker, "/STACK:102400000,102400000")
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
#define SI(a) scanf("%d", &a)
#define SII(a,b) scanf("%d%d", &a, &b)
#define SIII(a,b,c) scanf("%d%d%d", &a, &b, &c)
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7f7f7f7f;
const int MOD=1e9+7;
const double eps=1e-10;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int n;
int a[100010];
map<int,int> lch, rch;
map<int,int> par;
set<int> st;

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while(SI(n) == 1) {
		st.clear(); lch.clear(); rch.clear();par.clear();
		for (int i = 1; i <= n; i++) SI(a[i]);
		int root = 0;
		for (int i = 1; i <= n; i++) {
			if (st.size() == 0) {
				root = a[i];
				st.insert(a[i]);
			}
			else {
				set<int>::iterator l, r;
				l = st.begin();
				if (a[i] < *l) {
					lch[*l] = a[i];
					par[a[i]] = *l;
					st.insert(a[i]);
					continue;
				}
				r = --st.end();
				if (a[i] > *r) {
					rch[*r] = a[i];
					par[a[i]] = *r;
					st.insert(a[i]);
					continue;
				}
				l = r = st.lower_bound(a[i]);
				l--;
				if (!rch[*l]) {
					rch[*l] = a[i];
					par[a[i]] = *l;
					st.insert(a[i]);
				}
				else if (!lch[*r]) {
					lch[*r] = a[i];
					par[a[i]] = *r;
					st.insert(a[i]);
				}
			}
		}
		for (int i = 2; i <= n; i++) {
			cout << par[a[i]] << ' ' ;
		}
		cout << endl;
	}
	return 0;
}