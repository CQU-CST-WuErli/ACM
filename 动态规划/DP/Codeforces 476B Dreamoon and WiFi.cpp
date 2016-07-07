//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015 CQU_CST_WuErli. All rights reserved.
//
// #include<bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <sstream>
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define MEM(x,a) memset((x),(a),sizeof(x))
#define ALL(x) x.begin(),x.end()
#define AT(i,v) for (auto &i:v)
#define For_UVa if (kase!=1) cout << endl
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define look(x) cout << #x << "=" << x
#define SI(a) scanf("%d",&a)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define Lson l,mid,rt<<1
#define Rson mid+1,r,rt<<1|1
#define Root 1,n,1
#define BigInteger bign
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

string s,t;


int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> s >> t) {
		int ans=0;
		for (int i=0;i<s.size();i++) {
			if (s[i]=='+') ans++;
			else if (s[i]=='-') ans--;
		}
		int sum=0;
		int tmp=0;
		for (int i=0;i<t.size();i++) {
			if (t[i]=='?') sum++;
			else if (t[i]=='+') tmp++;
			else if (t[i]=='-') tmp--;
		}
		vector<int> temp;
		for (int i=0;i<(1<<sum);i++) {
			int tt=0;
			for (int j=0;j<sum;j++) {
				if (i & 1 << j) tt++;
				else tt--;
			}
			temp.push_back(tt);
		}
//		for (int i=0;i<temp.size();i++) cout << temp[i] << ' ';
//		puts("\ns");
		if (temp.size()==0) {
			if (tmp==ans) {
				cout << "1.000000000000\n";
			}
			else {
				cout << "0.000000000000\n";
			}
		}
		else {
			double x;
			int asd=0;
			for (int i=0;i<temp.size();i++) {
				if (tmp+temp[i]==ans) asd++;
			}
			int tt=temp.size();
			x=1.0*asd/tt*1.0;
			printf("%.12lf\n",x);
		}
	}
	return 0;
}

