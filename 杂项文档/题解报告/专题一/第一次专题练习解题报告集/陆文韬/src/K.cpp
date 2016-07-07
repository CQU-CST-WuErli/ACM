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
const int N = 6e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, s[N];

int get(bool isMax = false) {
    int i = 0, j = 1;
    while(i < n && j < n) {
        int k = 0;
        while(k < n && s[i + k] == s[j + k]) ++k;
        if(k == n) break;
        if((s[i + k] <= s[j + k]) ^ isMax) j += k + 1;
        else i += k + 1;
        j += i == j;
    }
    return min(i, j);
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) scanf("%d", s + i);
        //remember to double the string....
        for(int i = 0, j = n; i < n; ++i, ++j) s[j] = s[i];
        int one = get();
        for(int i = 0; i < n; ++i) {
            int p = one + i;
            if(p >= n) p -= n;
            printf("%d%c", s[p], " \n"[i == n - 1]);
        }
    }
    return 0;
}
