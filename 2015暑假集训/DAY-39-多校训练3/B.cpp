/********************************************
Author         :Crystal
Created Time   :
File Name      :
********************************************/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <cctype>
using namespace std;
typedef unsigned long long ll;
typedef pair<int ,int> pii;
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a);
const int inf = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
//#define LOCAL
int dp[20][20];
int isprime(ll ans){
	if (ans==1) return 0;
	for(ll i=2;i*i<=ans;i++){
		if(ans%i==0) return 0;
	}
	return 1;
}
ll quick_pow(ll a, ll b){
	if (b==0) return 1;
	ll d=quick_pow(a,b/2);
	ll ret=d*d;
	if (b%2) ret*=a;
	return ret;
}
int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int b,n;
	while (cin >> b >> n){
		ll sum=0;
		for (int i=0;i<=n-1;i++){
			sum+=quick_pow(b,i);
		}
		if (isprime(sum)) cout << "YES\n";
		else cout << "NO\n";
	}	
	return 0;
}

