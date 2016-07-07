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

int n, k;
int a[300010];
int sum[300010];
int start;

int search(int l, int r) {
	int ret;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if ((mid - start + 1) - (sum[mid] - sum[start - 1]) <= k) l = mid + 1, ret = mid;
		else r = mid - 1;
	}
	return ret;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while(SII(n,k) == 2) {

	    for (int i = 1; i <= n; i++) SI(a[i]);
	    if (k == 0) {
	    	int ans = 0;
	    	int tmp = 0;
	    	for (int i = 1; i <= n; i++) {
	    		if (a[i] == 0) {
	    			ans = max(ans, tmp);
	    			tmp = 0;
	    		}
	    		else tmp++;
	    	}
	    	ans = max(ans, tmp);
	    	cout << ans << endl;
			for (int i = 1; i <= n; i++) {
				cout << a[i];
				if (i < n) cout << ' ';
				else cout << endl;
			}
			continue;
		}
	    CLR(sum);
		for (int i = 1; i <= n; i++) {
			if (a[i] == 1) sum[i] = sum[i - 1] + 1;
			else sum[i] = sum[i - 1];
		}
		int l, r;
		int ans = 0;
		for (start = 1; start <= n; start++) {
			int end = search(start, n);
			int tmp = end - start + 1;
			if (ans < tmp) {
				ans = tmp;
				l = start;
				r = end;
			}
		}
		cout << ans << endl;
		for (int i = 1; i <= n; i++) {
			if (i >= l && i <= r) cout << 1;
			else cout << a[i];
			if (i < n) cout << ' ';
			else cout << endl;
		}
	}
	return 0;
}