//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015Äê CQU_CST_WuErli. All rights reserved.
//
// #include<bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <ctime>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <sstream>
#include <functional>
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define MEM(x,a) memset((x),(a),sizeof(x))
#define ALL(x) x.begin(),x.end()
#define At(i,v) for (auto &i:v)
#define for_uva if (kase!=1) cout << endl
#define BUG(x) cout << "I am in line" << x << endl
#define look(x) cout << #x << "= " << x << endl
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define INF 0x3f3f3f3f
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

string s, t;
int nxt[1005];
int l[1005], r[1005];
//l[i]:= record the position of the original string of the i's length
//r[i]:= similar to l[i]

void getNxt() {
    nxt[0] = -1;
    int i = 0, j = -1;
    while(i < t.size()) {
        if(j == -1 || t[i] == t[j])
            nxt[++i] = ++j;
        else j = nxt[j];
    }
}

void match(int *l) {
    int i = 0, j = 0;
    while(i < s.size()) {
        if(j == -1 || s[i] == t[j]) {
            ++i, ++j;
            l[j] = min(l[j], i);
        } else j = nxt[j];
        if(j == t.size()) j = nxt[j];
    }
}

int main() {
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while(cin >> s) {
        int k; cin >> k;
        int ans = 0;
        while(k--) {
            cin >> t;
            if(t.size() == 1) continue;
            MEM(l,0x3f);
            MEM(r,0x3f);
            l[0] = r[0] = 0;
            getNxt(); match(l);
            reverse(ALL(s));
            reverse(ALL(t));
            getNxt(); match(r);
            for(int i = 1; i <= t.size(); ++i) {
                if(l[i] + r[t.size() - i] <= s.size()) {
                    ++ans;
                    break;
                }
            }
            reverse(ALL(s));
        }
        cout << ans << '\n';
    }
    return 0;
}
