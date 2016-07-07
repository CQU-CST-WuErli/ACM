//
//  Created by Running Photon on 2016-04-04
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
const int maxn = 1e5 + 10;
const int maxv = 1e3 + 10;
const double eps = 1e-9;


char s[maxn];
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt","w",stdout);
#endif
//	ios_base::sync_with_stdio(0);
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%s", s);
        int len = strlen(s);
        for(int i = 0; i < len; i++) {
            if(isupper(s[i])) s[i] += 32;
        }
        int ans = 0;
        stack <int> s1, s2;
        for(int i = 0; i < len; i++) {
            if(s[i] == 'a') {
                s1.push(1);
            }
            else if(s[i] == 'c') {
                if(s1.size()) {
                    s1.pop();
                    s2.push(1);
                }
            }
            else if(s[i] == 'm') {
                if(s2.size()) {
                    s2.pop();
                    ans++;
                }
            }
        }
        printf("%d\n", ans);
    }

	return 0;
}
