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

int n, k;
int a[100010];

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while (SII(n, k) == 2) {
    	for (int i = 1; i <= n; i++)
    		SI(a[i]);
    	map<int, int> mp1, mp2;
    	for (int i = 1; i < k; i++) {
    		if (mp1.find(a[i]) == mp1.end() && mp2.find(a[i]) == mp2.end())
    			mp1.insert(make_pair(a[i], 1));
    		else if (mp1.find(a[i]) != mp1.end()) {
    			mp1.erase(a[i]);
    			mp2.insert(make_pair(a[i], 2));
    		}
    		else if (mp2.find(a[i]) != mp2.end()) {
    			mp2[a[i]]++;
    		}
    	}
    	for (int i = k; i <= n; i++) {
    		if (mp1.find(a[i]) == mp1.end() && mp2.find(a[i]) == mp2.end())
    			mp1.insert(make_pair(a[i], 1));
    		else if (mp1.find(a[i]) != mp1.end()) {
    			mp1.erase(a[i]);
    			mp2.insert(make_pair(a[i], 2));
    		}
    		else if (mp2.find(a[i]) != mp2.end()) {
    			mp2[a[i]]++;
    		}
    		if (!mp1.size()) puts("Nothing");
    		else {
    			auto it = mp1.end();
    			it--;
    			printf("%d\n", *it);
    		}
    		int pre = a[i - k + 1];
    		if (mp1.find(pre) != mp1.end()) mp1.erase(pre);
    		else if (mp2.find(pre) != mp2.end()) {
    			if (--mp2[pre] == 1) {
    				mp2.erase(pre);
    				mp1.insert(make_pair(pre, 1));
    			}
    		}
    	}
    }
	return 0;
}