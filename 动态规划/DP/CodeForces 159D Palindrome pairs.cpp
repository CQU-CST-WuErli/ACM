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
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define SI(a) scanf("%d",&a)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define rep(flag,start,end) for(int flag=start;flag<=end;flag++)
#define Rep(flag,start,end) for(int flag=start;flag>=end;flag--)
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
const int N=5000;
char s[5000];
char t[5000];
int p[5000];
int a[5000];
int b[5000];

void manacher() {
	t[0]='@';t[1]='#';
	int n=2;
	int tt=strlen(s+1);
	rep(i,1,tt) t[n++]=s[i],t[n++]='#';
	s[n]='\0';
	int mx=0,id=0;
	rep(i,1,n-1) {
		if (mx>i) p[i]=min(mx-i,p[2*id-i]);
		else p[i]=1;
		while (t[i-p[i]]==t[i+p[i]]) p[i]++;
		if (mx<i+p[i]) mx=i+p[i],id=i;
	}
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (scanf("%s",s+1)==1) {
		manacher();
		int len=strlen(t);
		CLR(a);CLR(b);
		for (int i=1;i<len;i++) {
			for (int j=0;j<p[i];j++) a[i+j]++;
		}
		for (int i=1;i<len;i++) {
			for (int j=0;j<p[i];j++) b[i-j]++;
		}
		vector<int> pre,suf;
		for (int i=2;i<len;i+=2) pre.push_back(a[i]),suf.push_back(b[i]);
		for (int i=suf.size()-2;i>=0;i--) suf[i]+=suf[i+1];
		ll ans=0;
		len=strlen(s+1);
		suf.push_back(0);
		for (int i=1;i<=len;i++) ans+=pre[i-1]*suf[i];
		cout << ans << endl;
	}
	return 0;
}