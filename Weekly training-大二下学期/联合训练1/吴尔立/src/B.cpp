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

char s[5000050], a[5000050], b[5000050];
int vis[5000050];
int nxt[5000050];
char ans[5000050];
int cnt;
void getnxt(char* t) {
	int i = 0, j = -1;
	nxt[0] = -1;
	int len = strlen(t);
	while (i < len) {
		if (j == -1 || t[i] == t[j]) nxt[++i] = ++j;
		else j = nxt[j];
	}
}

void kmp(char* s, char* t) {
	getnxt(t);
	CLR(vis);
	int i = 0, j = 0;
	int len1 = strlen(s);
	int len2 = strlen(t);
	while(i < len1) {
	    if (j == -1 || s[i] == t[j]) ++i, ++j;
	    else j = nxt[j];
	    if (j == len2) {
	    	vis[i - len2] = 1;
	    	j = 0;
	    }
	}
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int t; SI(t);
	while(t--) {
		scanf("%s%s%s", s, a, b);
	    kmp(s, a);
	    int i = 0;
	    cnt = 0;
	    int len = strlen(s);
	    int len1 = strlen(a);
	    int len2 = strlen(b);
	    while(i < len) {
	        if (vis[i]) {
	        	for (int j = 0; j < len2; j++) ans[cnt++] = b[j];
	        	i += len1;
	        }
	        else ans[cnt++] = s[i], i++;
	    }
	   	for (int i = 0; i < cnt; i++) printf("%c", ans[i]);
	   	printf("\n");
	}
	return 0;
}