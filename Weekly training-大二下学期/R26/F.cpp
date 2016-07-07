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

int n;

int work(string& pat)  //最大表示法
{
	int i = 0, j = 1, k = 0;
	int len = pat.size();
    while(i < len && j < len && k < len) {
    	int t = pat[(i+k)%len] - pat[(j+k)%len];
       	if(!t) k++;
      	else {
      		if(t>0) j = j+k+1;
        	else i = i+k+1;
            if(i == j) j++;
            k = 0 ;
        }
    }
    return i<j?i:j;
}

int nxt[20020];

void getnxt(string &t) {
    nxt[0]=-1;
    int i=0,j=-1;
    while (i<t.size()) {
        if (j==-1 || t[i]==t[j]) nxt[++i]=++j;
        else j=nxt[j];
    }
}

int len;

int kmp(string& s, string& t) {
	getnxt(t);
	int i = 0, j = 0;
	int ret = INF_INT;
	while(i < s.size()) {
	    if (j == -1 || s[i] == t[j]) i++, j++;
	    else j = nxt[j];
	    if (j == t.size()) {
	    	int tmp = i - n;
	    	if (tmp >= n) tmp = n - 1;
	    	else tmp = n - 1 - tmp;
	    	ret = min(ret, tmp);
	    	j = nxt[j];
	    }
	}
	return ret;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int t; SI(t);
	while(t--) {
		string s;
		SI(n);
		cin >> s;
		int pos1 = work(s);
		string ans1;
		ans1 += s.substr(pos1, s.size());
		ans1 += s.substr(0, pos1);
		// cout << tmp << endl;
		string t = s;
		reverse(t.begin(), t.end());
		int pos2 = work(t);
		string ans2;
		ans2 += t.substr(pos2, t.size());
		ans2 += t.substr(0, pos2);
		t += t;
		pos2 = kmp(t, ans2);
		if (ans1 > ans2) cout << pos1 + 1 << ' ' << 0 << endl;
		else if (ans1 < ans2) cout << pos2 + 1 << ' ' << 1 << endl;
		else if (ans1 == ans2) {
			if (pos1 < pos2) cout << pos1 + 1 << ' ' << 0 << endl;
			else if (pos1 > pos2) cout << pos2 + 1 << ' ' << 1 << endl;
			else if (pos1 == pos2) cout << pos1 + 1 << ' ' << 0 << endl;
		}
	}
	return 0;
}