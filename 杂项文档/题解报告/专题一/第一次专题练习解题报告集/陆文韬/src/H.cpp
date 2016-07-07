//
//  Created by TaoSama on 2016-05-03
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
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, maxd;
char* alpha = "AGCT";
char s[10][10];
int len[10], match[10];

bool dfs(int dep, int lft) {
    if(dep == maxd + 1) return !lft;
    if(lft > maxd - dep + 1) return false;

    vector<pair<int, int> > choice;
    for(int i = 0; i < 4; ++i) {
        int increase = 0;
        for(int j = 1; j <= n; ++j)
            if(match[j] < len[j] && s[j][match[j] + 1] == alpha[i]) ++increase;
        choice.push_back(make_pair(-increase, i));
    }
    sort(choice.begin(), choice.end());

    for(int i = 0; i < choice.size(); ++i) {
        if(!choice[i].first) break;
        int c = alpha[choice[i].second];

        int newLft = 0;
        vector<int> changed;
        for(int j = 1; j <= n; ++j) {
            if(match[j] < len[j] && s[j][match[j] + 1] == c) {
                ++match[j];
                changed.push_back(j);
            }
            newLft = max(newLft, len[j] - match[j]);
        }
        if(dfs(dep + 1, newLft)) return true;
        for(int j = 0; j < changed.size(); ++j)
            --match[changed[j]];
    }
    return false;
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\TaoSama\\Desktop\\in.txt", "r", stdin);
//  freopen("C:\\Users\\TaoSama\\Desktop\\out.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);

    clock_t st = clock();

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        int maxLft = 0;
        for(int i = 1; i <= n; ++i) {
            scanf("%s", s[i] + 1);
            len[i] = strlen(s[i] + 1);
            maxLft = max(maxLft, len[i]);
        }

        for(maxd = maxLft; ; ++maxd) {
            memset(match, 0, sizeof match);
            if(dfs(1, maxLft)) break;
        }
        printf("%d\n", maxd);
    }

#ifdef LOCAL
    printf("Time: %.3f\n", 1.0 * (clock() - st) / CLOCKS_PER_SEC);
#endif
    return 0;
}
