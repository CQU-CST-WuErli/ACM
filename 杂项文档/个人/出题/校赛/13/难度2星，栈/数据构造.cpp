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
const int maxn = 1e6 + 10;
const int maxv = 1e3 + 10;
const double eps = 1e-9;

int main() {
#ifdef LOCAL
//	freopen("in.txt", "r", stdin);
	freopen("in.txt","w",stdout);
#endif
//	ios_base::sync_with_stdio(0);
    int cnt = 0; srand(time(NULL));
    int tmp[9] = {97,97,97,99,99,99,109,109,109};
    /// 97 99 109
    puts("1682");
    do {
        cnt++;
        for(int i = 0; i < 9; i++) {
            printf("%c", tmp[i]);
        }
        puts("");
    } while(next_permutation(tmp, tmp + 9));
    for(int i = 0; i < 33333; i++) {
        printf("a");
    }
    for(int i = 0; i < 33333; i++) {
        printf("c");
    }
    for(int i = 0; i < 33333; i++) {
        printf("m");
    }
    puts("");
    for(int i = 0; i < 100000; i++) {
        int t = rand() % 26;
        printf("%c", t + 'A');
    }
    printf("%d\n", cnt);
	return 0;
}
