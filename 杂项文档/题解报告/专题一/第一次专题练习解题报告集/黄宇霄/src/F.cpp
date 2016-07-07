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
const double eps = 1e-9;

int n;
int idmax, cnt;
int num[1005];
bool dfs(int cur, int step) {
	if(step >= idmax) {
		if(cur == n) return true;
		return false;
	}
	int id = max_element(num, num + cnt) - num;
    int maxx = num[id];
    if(((cur + maxx) << (idmax - step - 1)) < n) return false;
	for(int i = cnt - 1; i >= 0; i--) {
		num[cnt++] = cur + num[i];
		if(dfs(cur + num[i], step + 1)) return true;
		cnt--;
		num[cnt++] = cur - num[i];
		if(dfs(cur - num[i], step + 1)) return true;
		cnt--;
	}
	return false;
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);
	int T;
	scanf("%d", &T);
	while(T--) {
        scanf("%d", &n);
		for(idmax = 0; ; idmax++) {
			CLR(num);
			cnt = 1; num[0] = 1;
			if(dfs(1, 0))
				break;
		}
		cout << idmax << endl;
	}
	return 0;
}
