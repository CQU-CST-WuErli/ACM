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

string s;

int vis[10010][2];

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while(cin >> s) {
        int sz = 0;
        set<string> st;
        CLR(vis);
        vis[s.size()][0] = vis[s.size()][1] = 1;
        for (int i = s.size() - 1; i > 4; i--) {
            if (vis[i + 2][0]) {
                string a = s.substr(i, 2);
                string b = s.substr(i + 2, 2);
                if (a != b) {
                    st.insert(a);
                    vis[i][0] = 1;
                }
            }
            if (vis[i + 2][1]) {
                st.insert(s.substr(i, 2));
                vis[i][0] = 1;
            }
            if (vis[i + 3][0]) {
                st.insert(s.substr(i, 3));
                vis[i][1] = 1;
            }
            if (vis[i + 3][1]) {
                string a = s.substr(i, 3);
                string b = s.substr(i + 3, 3);
                if (a != b) {
                    st.insert(s.substr(i, 3));
                    vis[i][1] = 1;
                }
            }
        }
        cout << st.size() << endl;
        for (auto x : st) cout << x << endl;
    }
	return 0;
}