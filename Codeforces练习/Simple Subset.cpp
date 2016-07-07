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

int n;
int a[1010];
int link[1010][1010];

int isprime[2000010];
void init() {
	CLR(isprime);
	for (int i = 2; i <= 2000000; i++) if (!isprime[i]) {
		for (int j = i + i; j <= 2000000; j += i) isprime[j] = 1;
	}
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    init();
    while(SI(n)==1) {
        int ones = 0;
        int tmp = 0;
    	for (int i = 1; i <= n; i++) {
            SI(a[i]);
            if (a[i] == 1) ones++;
        }
        vector<int> v;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) if (i != j && a[i] > 1 && a[j] > 1) {
                if (!isprime[a[i] + a[j]]) {
                    tmp = 2;
                    v.push_back(a[i]);
                    v.push_back(a[j]);
                    break;
                }
            }
        }
        int tt = ones;
        vector<int> vv;
        for (int i = 1; i <= n; i++) if (a[i] != 1) {
            if (!isprime[a[i] + 1]) {
                tt++;
                vv.push_back(a[i]);
                break;
            }
        }
        if (tmp >= tt) {
            if (tmp == 0) {
                cout << 1 << endl;
                cout << a[1] << endl;
            }
            else {
                cout << tmp << endl;
                if (v.size()) cout << v[0] << ' ' << v[1] << endl;
            }
        }
        else {
            cout << tt << endl;
            for (int i = 1; i <= ones; i++) cout << 1 << ' ';
            if (vv.size()) cout << vv[0] << endl;
        }
    }
	return 0;
}