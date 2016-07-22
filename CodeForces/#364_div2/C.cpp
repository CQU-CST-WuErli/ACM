//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2016 CQU_CST_WuErli. All rights reserved.
//
//#pragma comment(linker, "/STACK:102400000,102400000")
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
#include <bitset>
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
char s[100010];

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while (SI(n) == 1) {
    	scanf("%s", s + 1);
		set<char> st;
		for (int i = 1; s[i]; i++)
			st.insert(s[i]);
		int num = st.size();
		map<char, int> mp;
		int ans = INF_INT;
		int l = 1, r = 1;
		while (1) {
			while (mp.size() < num && r <= n) {
				if (mp.find(s[r]) == mp.end()) mp.insert(make_pair(s[r], 1));
				else mp[s[r]]++;
				r++;
			}
			ans = min(ans, r - l);
			// lookln(ans);
			while (l <= r && l <= n && mp.size() >= num) {
				if (mp.find(s[l]) != mp.end()) {
					mp[s[l]]--;
					if (mp[s[l]] == 0) mp.erase(s[l]);
					l++;
				}
			}
			ans = min(ans, r - l + 1);
			if (r > n) break;
		}
		cout << ans << endl;
    }
	return 0;
}