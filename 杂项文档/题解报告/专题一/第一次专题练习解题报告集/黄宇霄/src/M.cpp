//
//  Created by Running Photon on 2016-05-05
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

int T;
char s[maxv];
double ra[maxv];
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
//	ios_base::sync_with_stdio(0);
    scanf("%d", &T);
    ra['B'] = 0;
    ra['K'] = 1;
    ra['M'] = 2;
    ra['G'] = 3;
    ra['T'] = 4;
    ra['P'] = 5;
    ra['E'] = 6;
    ra['Z'] = 7;
    ra['Y'] = 8;
    int cas = 0;
    while(T--) {
        double p = 1000.0 / 1024;
        double res = 1;
        scanf("%s", s);
        for(int i = 0; s[i]; i++) {
            if(s[i] == '[') {
                res = 1.0 - res * pow(p, ra[s[i+1]]);
                break;
            }
        }
        printf("Case #%d: %.2f%\n", ++cas, res * 100);
    }

	return 0;
}
