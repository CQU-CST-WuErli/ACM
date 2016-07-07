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
#define For_UVa if (kase!=1) cout << endl
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define SI(a) scanf("%d",&a)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define rep(flag,start,end) for(int flag=start;flag<=end;flag++)
#define Rep(flag,start,end) for (int flag=start;flag>=end;flag--)
#define Lson l,mid,rt<<1
#define Rson mid+1,r,rt<<1|1
#define Root 1,n,1
#define BigInteger bign
template <typename T> T max(T& a,T& b) {return a>b?a:b;}
template <typename T> T min(T& a,T& b) {return a<b?a:b;}
int gcd(int a,int b) {return b==0?a:gcd(b,a%b);}
long long gcd (long long a,long long b) {return b==0LL?a:gcd(b,a%b);}
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=1e5+100;

vector<int> prime;
int isprime[N];
int n;
void getPrime() {
	CLR(isprime);
	prime.clear();
	for (int i=2;i<N;i++) if (!isprime[i]) {
		for (int j=i+i;j<N;j+=i) isprime[j]=1;
	}
	for (int i=2;i<N;i++) if (!isprime[i]) prime.push_back(i);	
}

vector<int> fac;
vector<int> num;
void FTA(int n) {
	fac.clear();
	num.clear();
	for (int i=0;i<prime.size();i++) {
		int p=prime[i];
		if (p>n) break;
		if (n%p==0) {
			int tot=0;
			while (n%p==0) n/=p,tot++;
			fac.push_back(p);
			num.push_back(tot);
		}
	}
	if (n>1) fac.push_back(n),num.push_back(1);
}

set<int> st;
vector<int> ans;

void dfs(int cur,int n,long long tmp){
	if(cur>=n)
		return;
	dfs(cur+1,n,tmp);
	for(int i=1;i<=num[cur];i++){
		tmp*=fac[cur];
		if(st.count(tmp)==0){
			st.insert(tmp);
			ans.push_back(tmp);
			dfs(cur+1,n,tmp);
		}
	}
}

void work(int n) {
	st.clear();
	ans.clear();
	FTA(n);
	dfs(0,fac.size(),1);
	sort(ans.begin(),ans.end());
}

ll sum[N];

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	getPrime();
	while (cin >> n) {
		work(n);
//		for (int i=0;i<ans.size();i++) cout << ans[i] << endl;
		int from=0,to=0;
		int ss=1;
		for (int i=0;i<ans.size();i++) {
			ll tt=ans[i];
			int pos=i;
			for (int j=i+1;j<ans.size();j++) if (ans[j]==ans[pos]+1) {
				tt*=ans[j];
				if (n%tt) break;
				else {
					pos=j;
					if (j-i+1>ss) {
//						cout << i << ' ' << j << endl;
						ss=j-i+1;
						from=i,to=j;
					}
				}
			}
		}
		cout << ss << endl;
		for (int i=from;i<=to;i++) {
			if (i!=from) cout << '*';
			cout << ans[i];
		}
		cout << endl;
	}
	return 0;
}

