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

ll n;
int m;
ll a[550];
map<ll, ll> mp;

struct Matrix {
	ll mat[4][4];
	void init() {
		CLR(mat);
	}
	Matrix operator * (Matrix rhs) {
		Matrix ret;
		ret.init();
		for (int i = 1; i <= 3; i++) {
			for (int j = 1; j <= 3; j++) {
				for (int k = 1; k <= 3; k++) {
					ret.mat[i][j] = (ret.mat[i][j] + mat[i][k] * rhs.mat[k][j] % MOD) % MOD;
				}
			}
		}
		return ret;
	}
};

int cal(ll x,ll a, ll b, ll c) {
	if (x <= 3) {
		if (x == 1) return a;
		else if (x == 2) return b;
		else if (x == 3) return c;
	}
	int ans = 0;
	Matrix ret;
	ret.init();
	ret.mat[1][2] = ret.mat[2][3] = ret.mat[3][1] = ret.mat[3][2] = ret.mat[3][3] = 1;
	Matrix tmp;
	tmp.init();
	tmp.mat[1][1] = tmp.mat[2][2] = tmp.mat[3][3] = 1;
	x -= 3;
	while(x) {
	    if (x & 1) tmp = tmp * ret;
		ret = ret * ret;
		x >>= 1;
	}
	ans = (tmp.mat[3][1] % MOD * a % MOD + tmp.mat[3][2] % MOD * b % MOD + tmp.mat[3][3] % MOD * c % MOD) % MOD;
	return ans % MOD;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int t; SI(t);
    while(t--) {
        cin >> n >> m;
        for (int i = 1; i <= m; i++)
        	cin >> a[i];
        mp.clear();
        sort(a + 1, a + 1 + m);
        mp[0] = 1;
        mp[1] = 1; mp[2] = 2; mp[3] = 4;
        for (int i = 1; i <= m; i++) {
        	if (a[i] <= 3) {
        		mp[a[i]] = 0;
        	}
        	else break;
        }
        if (mp[1]) mp[1] = mp[0];
        if (mp[2]) mp[2] = mp[1] + mp[0];
        if (mp[3]) mp[3] = mp[1] + mp[2] + mp[0];
       	ll x = 1, y = 2, z = 3;
        for (int i = 1; i <= m; i++) {
        	if (a[i] > 3) {
        		for (ll j = max(4LL, a[i] - 2); j < a[i]; j++) {
        			mp[j] = cal(j - x + 1, mp[x], mp[y], mp[z]);
        		}
        		mp[a[i]] = 0;
        		x = a[i] - 2, y = a[i] - 1, z = a[i];
        	}
        }
        ll ans = cal(n - x + 1, mp[x], mp[y], mp[z]);
        cout << ans << endl;
    }
	return 0;
}