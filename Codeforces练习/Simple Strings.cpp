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

string s;
int l[200010], r[200010];

char getNext(char c) {
	char ret = c;
	if (ret == 'z') ret = 'a';
	else ret++;
	return ret;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while(cin >> s) {
	    int flag = 0;
	    for (int i = 1; i < s.size(); i++) {
	    	if (s[i] == s[i-1]) {
	    		flag = 1;break;
	    	}
	    }
	    if (flag == 0) {
	    	cout << s << endl;
	    	continue;
	    }
	    l[0] = 0;
	    for (int i = 1; i < s.size(); i++) {
	    	if (s[i] == s[i - 1]) l[i] = l[i - 1];
	    	else l[i]  = i;
	    }
	    r[s.size() - 1] = s.size() - 1;
	    for (int i = s.size() - 2; i >= 0; i--) {
	    	if (s[i] == s[i + 1]) r[i] = r[i + 1];
	    	else r[i] = i;
	    }
	    // for (int i = 0; i < s.size(); i++) {
	    	// cout << l[i] << ' ' << r[i] << endl;
	    // }
	    int pos = 0;
	    while(pos < s.size()) {
	    	// lookln(pos);
	    	int len = r[pos] - l[pos] + 1;
	    	if (len > 1) {
	    		if (len % 2 == 0) {
	    			int i;
	    			for (i = pos + 1; i <= r[pos]; i += 2) {
	    				s[i] = getNext(s[i]);
	    			}
	    			i -= 2;
	    			while(i < s.size() - 1 && s[i] == s[i + 1]) {
	    			    s[i] = getNext(s[i]);
	    			}
	    		}
	    		else {
	    			for (int i = pos + 1; i <= r[pos]; i += 2)
	    				s[i] = getNext(s[i]);
	    		}
	    	}
	    	pos = r[pos] + 1;
	    }
	    cout << s << endl;
	}
	return 0;
}