//
//  Created by TaoSama on 2016-05-01
//  Copyright (c) 2016 TaoSama. All rights reserved.
//
#pragma comment(linker, "/STACK:102400000,102400000")
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
#include <set>
#include <vector>

using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 5e7 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

string s, a, b;
int n, m;
vector<int> nxt;

void getNxt() {
    nxt = vector<int>(a.size() + 1);
    nxt[0] = -1;
    for(int i = 0, j = -1; i < a.size();) {
        if(j == -1 || a[i] == a[j]) nxt[++i] = ++j;
        else j = nxt[j];
    }
}

string kmp() {
    string ans;
    for(int i = 0, j = 0; i < s.size();) {
        if(j == -1 || s[i] == a[j]) {
            ans += s[i];
            ++i, ++j;
        } else j = nxt[j];
        if(j == a.size()) {
            while(j--) ans.erase(ans.size() - 1, 1);
            ans += b;
            j = 0;
        }
    }
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) {
        cin >> s >> a >> b;
        getNxt();
        cout << kmp() << '\n';
    }
    return 0;
}
