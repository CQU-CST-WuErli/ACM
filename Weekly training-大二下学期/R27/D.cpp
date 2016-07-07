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

int n;
int digit[20];

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while(SI(n) == 1) {
		int cnt = 0;
		CLR(digit);
	    while(n) {
	    	digit[cnt++] = n % 3;
	    	n /= 3;
	    }
	    vector<int> l, r;
	    int pos = 0;
	    int tt = 1;
	    while(1) {
	        if (pos >= cnt && digit[pos] == 0) break;
	        if (digit[pos] == 1) r.push_back(tt);
	        else if (digit[pos] == 2) {
	        	digit[pos + 1] ++;
	        	l.push_back(tt);
	        }
	       	else if (digit[pos] == 3) digit[pos + 1]++;
	        pos++;
	        tt *= 3;
	    }
	    cout << l.size();
	    for (int i = 0; i < l.size(); i++) cout << ' ' << l[i];
	    cout << endl;
	    cout << r.size();
	    for (int i = 0; i < r.size(); i++) cout << ' ' << r[i];
	    cout << endl;
	}
	return 0;
}