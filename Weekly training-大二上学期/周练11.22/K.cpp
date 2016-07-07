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
template <typename T> T max(T& a,T& b) {return a>b?a:b;}
template <typename T> T min(T& a,T& b) {return a<b?a:b;}
int gcd(int a,int b) {return b==0?a:gcd(b,a%b);}
long long gcd (long long a,long long b) {return b==0LL?a:gcd(b,a%b);}
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=10000007;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=2000;

map<string,int> mp;
int ID;
vector<int> ss,tt;

void process(string &s,vector<int> &vc) {
	vc.clear();
	vc.push_back(INF_INT);
	for (int i=0;i<s.size();i++) {
		if (s[i]>='A' && s[i]<='Z') {
			string tmp;
			tmp+=s[i];
			while (s[i+1]>='0' && s[i+1]<='9') tmp+=s[i+1],i++;
			if (!mp.count(tmp)) {
//				cout << tmp << endl;
				mp[tmp]=ID++;
			}
			vc.push_back(mp[tmp]);
		}
	}
}

ll dp[N][N];
ll sum[N][N];
ll tree[N][N]; 

int lowbit(int x) {
	return x&(-x);
}

void update(int x,int y,ll val) {
	for (int i=x;i<ss.size();i+=lowbit(i)) 
		for (int j=y;j<tt.size();j+=lowbit(j))
			tree[i][j]=(tree[i][j]+val)%MOD;
}

ll query(int x,int y) {
	ll ret=0;
	for (int i=x;i>0;i-=lowbit(i)) 
		for (int j=y;j>0;j-=lowbit(j))
			ret=(ret+tree[i][j])%MOD;
	return ret;
}

ll ksm(int a,int n) {
	if (n==0) return 1;
	ll ans=ksm(a,n/2);
	ans=(ans*ans)%MOD;
	if (n%2) ans=(ans*a)%MOD;
	return ans;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int T_T;
	for (int kase=scanf("%d",&T_T);kase<=T_T;kase++) {
		string s,t;
		cin >> s >> t;
		mp.clear();
		ID=1;
		process(s,ss);process(t,tt);
//		for (int i=1;i<ss.size();i++) cout << ss[i]<< ' ';
//		cout << endl;
//		for (int i=1;i<tt.size();i++) cout << tt[i] << ' ' ;
//		cout << endl;
		CLR(dp);CLR(sum);CLR(tree);
		for (int i=1;i<ss.size();i++) {
			for (int j=1;j<tt.size();j++) {
				if (ss[i]==tt[j]){
					dp[i][j]=(sum[i-1][j-1]+dp[i][j]+1)%MOD;
					update(i,j,dp[i][j]);
				}
				sum[i][j]=query(i,j);
			}
		}
		int Sum=0;
//		cout << ksm(2,10) << endl;
		Sum=(Sum+ksm(2,ss.size()-1))%MOD;
		Sum=(Sum-1+MOD)%MOD;
		Sum=(Sum+ksm(2,tt.size()-1))%MOD;
		Sum=(Sum-1+MOD)%MOD;
//		lookln(Sum);
		int ans=(Sum-sum[ss.size()-1][tt.size()-1]*2+2*MOD)%MOD;
		cout << "Case " << kase << ": " << ans << endl; 
	} 
	return 0;
}

