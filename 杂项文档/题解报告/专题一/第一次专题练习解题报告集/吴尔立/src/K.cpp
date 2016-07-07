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
int a[300020];

int work(int m)
{
    int i,j,l;
    i=0; j=1;
    while(i<m && j<m)
    {
        for(l=0;l<m;l++)
            if(a[(i+l)%m]!=a[(j+l)%m]) break;
        if(l>m) break;
        if(a[(i+l)%m] > a[(j+l)%m])
            i=i+l+1;
        else
            j=j+l+1;
        if(i==j) j=i+1;
    }
    if(i<j) return i;
    return j;
}



int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int t; SI(t);
	while(t--) {
	    SI(n);
	    for (int i = 0; i < n; i++) SI(a[i]);
	    int pos = work(n);
		vector<int> ans;
		for (int i = pos; i < n; i++) ans.push_back(a[i]);
		for (int i = 0; i < pos; i++) ans.push_back(a[i]);
		for (int i = 0; i < n; i++) {
			if (i) cout << ' ';
			printf("%d", ans[i]);
		}
		cout << endl;
	}
	return 0;
}