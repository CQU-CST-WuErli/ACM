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

const int N = 100010;
struct Edge
{
	int v;
	char c;
	Edge(int v,char c):v(v),c(c){}
};

vector<Edge> g[N];
int n, m;
vector<int> s,t;

int vis[N];

bool dfs(int u, char c) {
	for (int i = 0; i < g[u].size(); i++) {
		int v = g[u][i].v;
		char cor = g[u][i].c;
		if (!vis[v]) {
			vis[v] = cor == c ? vis[u] : 3 - vis[u];
			if (vis[v] == 1) s.push_back(v);
			else t.push_back(v);
			if (!dfs(v, c)) return false;
		}
		else {
			int tmp = cor == c ? vis[u] : 3 - vis[u];
			if (tmp != vis[v]) return false;
		}
	}
	return true;
}

vector<int> solve(char c) {
	vector<int> ans;
	CLR(vis);
	for (int i = 1; i <= n; i++) if (!vis[i]) {
		s.clear();t.clear();
		vis[i] = 1;
		s.push_back(i);
		if (!dfs(i, c)) {
			ans.clear();
			for (int j = 1; j <= n + 1; j++) {
				ans.push_back(-1);
			}
			return ans;
		}
		if (t.size() < s.size())
			ans.insert(ans.end(), t.begin(), t.end());
		else ans.insert(ans.end(), s.begin(), s.end());
	}
	return ans;
}

void print(vector<int>& v) {
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++) {
		if (i) printf(" ");
		printf("%d", v[i]);
	}
	printf("\n");
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while(SII(n,m)==2) {
    	for (int i = 1; i <= n; i++) g[i].clear();
        for (int i = 1; i <= m; i++) {
        	int u,v;
        	char c;
        	scanf("%d %d %c",&u,&v,&c);
        	// cout << u << ' ' << v << ' ' << c << endl;
        	g[u].push_back(Edge(v,c));
        	g[v].push_back(Edge(u,c));
        }
        // BUG;
        vector<int> ans1 = solve('B');
        vector<int> ans2 = solve('R');
        // print(ans1);
        // print(ans2);
    	if (min((int)ans1.size(), (int)ans2.size()) > n) puts("-1");
    	else {
    		if (ans1.size() < ans2.size()) print(ans1);
    		else print(ans2);
    	}
    }
	return 0;
}