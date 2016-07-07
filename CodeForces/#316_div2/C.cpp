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
#include <ctime>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <functional>
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define MEM(x,a) memset((x),(a),sizeof(x))
#define ALL(x) x.begin(),x.end()
#define AT(i,v) for (auto &i:v)
#define For_UVa if (kase!=1) cout << endl
#define BUG(x) cout << "I am in line" << x << endl
#define lookln(x) cout << #x << "=" << x << endl
#define look(x) cout << #x << "=" << x
#define SI(a) scanf("%d",&a)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int INF=0x3f3f3f3f;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int n,m;
char s[300030];
ll f[300030];

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n >> m){
		CLR(f);
		getchar();
		gets(s+1);
		s[0]='#';
		int flag=0;
		ll sum=0;
		for (int i=1;s[i];i++){
			if (s[i]=='.' && s[i-1]=='.') f[i]=f[i-1]+1;
			if (s[i]=='.' && s[i+1]!='.') sum+=f[i];
		}
		int ls=strlen(s);
		s[ls+1]='#';
//		cout << sum << ;endl;
//		for (int i=1;s[i];i++) cout << f[i] << " ";
		for (int i=1;i<=m;i++){
			int id;
			char c;
			cin >> id >> c;
			if (c=='.') {
				if (s[id]!='.' && s[id-1]=='.' && s[id+1]=='.') sum+=2;
				else if (s[id]!='.' && s[id-1]=='.' && s[id+1]!='.') sum++;
				else if (s[id]!='.' && s[id-1]!='.' && s[id+1]=='.') sum++;
			}
			else if (c!='.'){
				if (s[id]=='.' && s[id+1]!='.' && s[id-1]!='.') sum=sum;
				else if (s[id]=='.' && s[id+1]=='.' && s[id-1]=='.') sum-=2;
				else if (s[id]=='.' && s[id+1]!='.' && s[id-1]=='.') sum--;
				else if (s[id]=='.' && s[id+1]=='.' && s[id-1]!='.') sum--;
			}
			s[id]=c;
			cout << sum << endl;
		}
	}
	return 0;
}


