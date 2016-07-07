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

int Min[110],Max[110];
int n,s;

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n >> s ) {
		if ((s==0 && n!=1) || n*9<s) {
			cout << "-1 -1\n";
			continue;
		} 
		int tmp=s-1;
		Max[1]=Min[1]=1;
		for (int i=2;i<=n;i++) {
			Min[i]=Max[i]=0;
		}
		for (int i=n;i>=1;i--) {
			if (tmp>=9-Min[i]) {
				tmp-=9-Min[i];
				Min[i]=9;
			}
			else {
				Min[i]+=tmp;
				break;
			}
		}
		tmp=s-1;
		for (int i=1;i<=n;i++) {
			if (tmp>=9-Max[i]) {
				tmp-=9-Max[i];
				Max[i]=9;
			}
			else {
				Max[i]+=tmp;
				break;
			}
		}
		for (int i=1;i<=n;i++) cout << Min[i];
		cout << ' ';
		for (int i=1;i<=n;i++) cout << Max[i];
		cout << endl;
	}
	return 0;
}

