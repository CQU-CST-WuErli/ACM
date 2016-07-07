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

int main(){
#ifdef LOCAL
//	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	string s;
	while (cin >> s) {
		int flag=0;
		int ans=0;
		for (int i=0;i<s.size();i++) if (s[i]=='0') {
			flag=1;break;
		}
		if (flag) {
			cout << "YES\n" << 0 << endl;
			continue;
		}	
			
		for (int i=0;i<s.size();i++) if (s[i]=='8') {
			flag=1;break;
		}
		if (flag) {
			cout << "YES\n8\n";
			continue;
		} 
		
		if (s.size()>=2) {
				for (int i=0;i<s.size()-1;i++) {
			for (int j=i+1;j<s.size();j++) {
				int tmp=(s[i]-'0')*10+(s[j]-'0');
				if (tmp%8==0) {
					ans=tmp;
					flag=1;break;
				}
			}
			if (flag) break;
		}
		if (flag) {
			cout <<"YES\n" << ans << endl;
			continue;
		}
		}
		
		if (s.size()>=3) {
			for (int i=0;i<s.size()-2;i++) {
			for (int j=i+1;j<s.size()-1;j++) {
				for (int k=j+1;k<s.size();k++) {
					int tmp=(s[i]-'0')*100+(s[j]-'0')*10+s[k]-'0';
					if (tmp%8==0) {
						ans=tmp;
						flag=1;
						break;
					}
				}
				if (flag) break;
			}
			if (flag) break;
		}
		}
		
		if (flag) cout << "YES\n" << ans << endl;
		else cout << "NO\n";
	} 
	return 0;
}

