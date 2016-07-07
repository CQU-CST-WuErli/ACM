//
//  Created by Running Photon on 2016-05-11
//  Copyright (c) 2015 Running Photon. All rights reserved.
//
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <sstream>
#include <set>
#include <vector>
#include <stack>
#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x,begin())
#define ll long long
#define CLR(x) memset(x, 0, sizeof x)
using namespace std;
const int inf = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 10;
const int maxv = 1e3 + 10;
const double eps = 1e-9;

string s[10];
int idmax, n;
string tmp = "AGCT";
bool dfs(int dep, int* top) {
//    for(int i = 0; i < n; i++) {
//        printf("%d ", top[i]);
//    }
//    puts("");
    if(dep == idmax) {
        int flag = 1;
        for(int i = 0; i < n; i++) {
            if(top[i] < s[i].size()) flag = 0;
        }
        return flag;
    }
    for(int i = 0; i < 4; i++) {
        int flag = 0;
        int tmptop[10];
        memcpy(tmptop, top, sizeof tmptop);
//        for(int i = 0; i < n; i++) {
//            printf("%d ", tmptop[i]);
//        }
//        puts("");
        for(int j = 0; j < n; j++) {
            if(top[j] == s[j].size()) continue;
            if(s[j][top[j]] == tmp[i]) {
                tmptop[j]++;
                flag = 1;
            }
        }
        if(flag && dfs(dep+1, tmptop)) return true;
    }
    return false;
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
//	ios_base::sync_with_stdio(0);
    int T; cin >> T;
    while(T--) {
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> s[i];
        for(idmax = 1; ; idmax++) {
            int top[10];
            CLR(top);
//            cout << idmax << endl;
            if(dfs(0, top)) break;
        }
        cout << idmax << endl;
    }

	return 0;
}
