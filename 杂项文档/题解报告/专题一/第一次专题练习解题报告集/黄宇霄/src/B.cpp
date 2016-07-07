//
//  Created by Running Photon on 2016-05-02
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
const int maxn = 5e6 + 10;
const int maxv = 1e3 + 10;
const double eps = 1e-9;

//int nxt[maxn];
//int yes[maxn];
//void getNxt(char *t) {
//    nxt[0] = -1;
//    int len = strlen(t);
//    int j = -1, i = 0;
//    while(i <= len) {
//        if(j == -1 || t[i] == t[j]) {
//            nxt[++i] = ++k;
//        }
//        else k = nxt[k];
//    }
//}
//void Find(char *s, char *t, int len2){
//	int len1 = strlen(s);
//	int i = 0, j = 0;
//	while(i < len1 && j < len2){
//		if(j == -1 || s[i] == t[j]) i++, j++;
//		else j = nxt[j];
//		if(j == len2) return true;
//	}
//	return false;
//}
string s, a, b;
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while(T--) {
        cin >> s >> a >> b;
//        cout << s << ' ' << a << ' ' << b << endl;
        int pos = 0;
        while(1) {
            pos = s.find(a, pos);
            if(pos == -1) break;
            s = s.replace(pos, a.size(), b);
//            cout << s << endl;
        }
        cout << s << endl;
    }
	return 0;
}
