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
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int ,int> pii;
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a);
#define pi acos(-1.0)
#define maxn 40000
#define maxv 100005
const int inf = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int mp[maxv];
int dp[maxv];
int a[maxv];
int main()
{
	for(int i=2;i<=1e5;i++){
		if(!mp[i]){
			for(int j=i;j<=1e5;j+=i){
				mp[j] = i;
			}
		}
	}
	int n;
	while(cin >> n){
		MEM(dp,0);
		for(int i=1;i<=n;i++)cin >> a[i];
		int nmax = 0;
		for(int i=1;i<=n;i++){
			int x = 0;
			for(int j=a[i];j>1;j/=mp[j]){
				x = max(x,dp[mp[j]]);
			}
			for(int j=a[i];j>1;j/=mp[j]){
				dp[mp[j]] = max(dp[mp[j]],x+1);
			}
			nmax = max(x+1,nmax); 
		}
		printf("%d\n",nmax);
	}
	return 0;
}
