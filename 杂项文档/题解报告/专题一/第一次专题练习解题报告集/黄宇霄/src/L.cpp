//
//  Created by Running Photon on 2016-05-11
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
const int maxn = 5e5 + 10;
const int maxv = 1e3 + 10;
const double eps = 1e-9;

int a[maxn], sa[maxn], rak[maxn], height[maxn];
int wa[maxn], wb[maxn], wv[maxn], c[maxn];

bool cmp(int *r, int a, int b, int l) {
	return r[a] == r[b] && r[a + l] == r[b + l];
}
void CalcSa(int *r, int *sa, int n, int m) {
	int i, j, p, *x = wa, *y = wb;
	for(i = 0; i < m; i++) c[i] = 0;
	for(i = 0; i < n; i++) c[x[i] = r[i]]++;
	for(i = 1; i < m; i++) c[i] += c[i-1];
	for(i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;
	for(j = 1, p = 1; p < n; j *= 2, m = p) {
		for(p = 0, i = n - j; i < n; i++) y[p++] = i;
		for(i = 0; i < n; i++) if(sa[i] >= j) y[p++] = sa[i] - j;
		for(i = 0; i < n; i++) wv[i] = x[y[i]];

		for(i = 0; i < m; i++) c[i] = 0;
		for(i = 0; i < n; i++) c[wv[i]]++;
		for(i = 1; i < m; i++) c[i] += c[i-1];
		for(i = n - 1; i >= 0; i--) sa[--c[wv[i]]] = y[i];
		swap(x, y);
		p = 1; x[sa[0]] = 0;
		for(i = 1; i < n; i++)
			x[sa[i]] = cmp(y, sa[i-1], sa[i], j) ? p-1 : p++;
		if(p >= n) break;
	}
}
void CalcHeight(int *r, int *sa, int n) {
	int i, j, p = 0;
	for(i = 1; i <= n; i++) //防止越界在原数组末尾加上一个最小值
		rak[sa[i]] = i;
	for(i = 0; i < n; i++) {
		j = sa[rak[i] - 1];
		while(r[i+p] == r[j+p]) p++;
		height[rak[i]] = p;
		if(p > 0) p--;
	}
}
char s[maxn];
typedef pair <ll, ll> sta;
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
//	ios_base::sync_with_stdio(0);
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%s", s);
        int n = strlen(s);
        for(int i = 0; i < n; i++) {
            a[i] = s[i] - 'a' + 1;
        }
        a[n] = 0;
        CalcSa(a, sa, n+1, 30);
        CalcHeight(a, sa, n);
        ll res = 0;
        for(ll i = 2; i <= n; i++) {
            res += (i - 1) * i / 2;
            res += i * (i - 1);
        }
        ll sum = 0;
        stack <sta> st;
        st.push(sta(0, 0));
        for(int i = 1; i <= n; i++) {
            while(st.size() > 1 && st.top().first > height[i]) {
                ll r = st.top().second;
                ll hig = st.top().first;
                st.pop();
                ll l = st.top().second;
                sum -= (r - l) * hig;
            }
            sum += height[i] * (i - st.top().second);
            res -= 2 * sum;
            st.push(sta(height[i], i));
        }
        cout << res << endl;
    }

	return 0;
}
