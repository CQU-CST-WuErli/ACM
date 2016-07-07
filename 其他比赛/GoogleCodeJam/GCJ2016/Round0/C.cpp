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
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <sstream>
#include <ctime>
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

const int N=1e6+12;
vector<ll> prime;
int isprime[N];

void getPrime() {
	CLR(isprime);
	for (ll i=2;i<=(ll)(1e3);i++) if (!isprime[i]) {
		for (ll j=i*i;j<=(ll)(1e6);j+=i) isprime[j]=1;
	}
	for (int i=2;i<=(1e6);i++) if (!isprime[i]) prime.push_back(i);
}

int n,m;

ll gao(ll sta,ll base) {
	ll ret=0;
	ll cnt=1;
	ll x=sta;
	while(x) {
	    if (x%2==1) ret+=cnt;
	    cnt*=base;
	    x/=2;
	}
	return ret;
}

long long mult_mod(long long a,long long b,long long c)
{
	a %= c;
	b %= c;
	long long ret = 0;
	long long tmp = a;
	while(b)
	{
		if(b & 1)
		{
			ret += tmp;
			if(ret > c)ret -= c;//鐩存帴鍙栨ā鎱㈠緢澶?
		}
		tmp <<= 1;
		if(tmp > c)tmp -= c;
		b >>= 1;
	}
	return ret;
}
long long pow_mod(long long a,long long n,long long mod)
{
	long long ret = 1;
	long long temp = a%mod;
	while(n)
	{
		if(n & 1)ret = mult_mod(ret,temp,mod);
			temp = mult_mod(temp,temp,mod);
		n >>= 1;
	}
	return ret;
}
bool check(long long a,long long n,long long x,long long t)
{
	long long ret = pow_mod(a,x,n);
	long long last = ret;
	for(int i = 1;i <= t;i++)
	{
		ret = mult_mod(ret,ret,n);
		if(ret == 1 && last != 1 && last != n-1)return true;//鍚堟暟
		last = ret;
	}
	if(ret != 1)return true;
	else return false;
}
bool Miller_Rabin(long long n)
{
	if( n < 2)return false;
	if( n == 2)return true;
	if( (n&1) == 0)return false;//鍋舵暟
	long long x = n - 1;
	long long t = 0;
	while( (x&1)==0 ){x >>= 1; t++;}
	srand(time(NULL));/* *************** */
	for(int i = 0;i < 10;i++)
	{
		long long a = rand()%(n-1) + 1;
		if( check(a,n,x,t) )
		return false;
	}
	return true;
}
bool judge(ll sta) {
	ll tmp;
	for (int i=2;i<=10;i++) {
		tmp=gao(sta,(ll)i);
		if (tmp<=(ll)(1e6)) {
			if (!isprime[tmp]) return false;
		}
		else {
			if (Miller_Rabin(tmp)) return false;
		}
	}
	return true;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
#endif
    getPrime();
    for (int T_T,kase=SI(T_T);kase<=T_T;kase++) {
    	SII(n,m);
    	ll st=1;
    	st|=(1<<(n-1));
    	int num=0;
    	vector<ll> ans;
    	for (ll i=st;i<(1<<n);i++) {
    		if ((i&1)==0) continue;
    		if (judge(i)) {
    			num++;
    			ans.push_back(i);
    		}
    		if (num>=m) break;
    	}
    	printf("Case #%d:\n", kase);
    	for (int i=0;i<ans.size();i++) {
    		string s;
    		ll tmp=ans[i];
    		// cout << ans[i] << ' ';
    		while(tmp) {
    		    if (tmp%2==1) s+='1';
    		    else s+='0';
    		    tmp/=2;
    		}
    		reverse(s.begin(),s.end());
    		cout << s << ' ';
    		for (int j=2;j<=10;j++) {
    			ll tt=gao(ans[i],j);
    			for (int k=0;k<prime.size();k++) {
    				if (tt%prime[k]==0) {
    					printf("%lld", prime[k]);
    					break;
    				}
    			}
    			if (j<10) printf(" ");
    			else printf("\n");
    		}
    	}
    }
	return 0;
}