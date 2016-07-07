//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2016 CQU_CST_WuErli. All rights reserved.
//
#include <bits/stdc++.h>
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
#define SI(a) scanf("%d",&a)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define rep(flag,start,end) for(int flag=start;flag<=end;flag++)
#define Rep(flag,start,end) for(int flag=start;flag>=end;flag--)
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7f7f7f7f;
const int MOD=1e9+7;
const double eps=1e-10;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int n;
vector<int> v1,v2;

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while(SI(n)==1) {
		if (n==1) {
			int x;SI(x);
			puts("Yes");
			continue;
		}
		else if (n==2) {
			int a,b;
			SII(a,b);
			puts(a<=b?"Yes":"No");
			continue;
		}
		v1.clear();v2.clear();
		rep(i,1,n) {
			int x;SI(x);
			if (i%2) v1.push_back(x);
			else v2.push_back(x);
		}
		sort(v1.begin(),v1.end());
		sort(v2.begin(),v2.end());
		vector<int> ans;
		int cnt1=0,cnt2=0;
		while (cnt1<v1.size() && cnt2<v2.size()) {
			if (cnt1<v1.size()) ans.push_back(v1[cnt1]),cnt1++;
			if (cnt2<v2.size()) ans.push_back(v2[cnt2]),cnt2++;
		}
		int flag=1;
		for (int i=0;i<ans.size()-2;i++) if (ans[i]>ans[i+1]) {
			flag=0;break;
		}
		puts(flag?"Yes":"No");
	}
	return 0;
}