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


int a[maxn];
int main() {
#ifdef LOCAL
//	freopen("in.txt", "r", stdin);
	freopen("in.txt","w",stdout);
#endif
//	ios_base::sync_with_stdio(0);
    puts("200");
    srand(time(NULL));
    int n;
    for(int T = 1; T <= 199; T++) {
        n = rand() % 50 + 105;
        printf("%d  1000002\n", n);
        for(int i = 2; i <= n; i++) {
            printf("%d\n", rand() % (i - 1) + 1);
        }
    }
    puts("100000 100000008");
    for(int i = 2; i <= 100000; i++) {
        printf("%d\n", rand() % (i - 1) + 1);
    }
	return 0;
}
