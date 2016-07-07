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
typedef long long ll;
typedef pair<int ,int> pii;
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a);
const ll inf = 1e18+20;
const int MOD = 1e9 + 7;
ll max1[2000005];
ll max2[2000005];
ll max3[2000005];
ll max4[2000005];
int ans[2000005];
//#define LOCAL
int main()
{
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
	int t;cin >> t;
	int kase = 1;
	while(t--){
		//MEM(max1,0);
		printf("Case #%d: ",kase++);
		int n;cin >> n;
		ll a,b;scanf("%lld%lld",&a,&b);
		for(int i=1;i<=n;i++){
			scanf("%d",&ans[i]);
			max3[i]=a*ans[i]*ans[i];
			max4[i]=b*ans[i];
		}
		ll mmax = -inf;
		for(int i=1;i<=n;i++){
			if(max4[i]>mmax){
				max1[i]=max4[i];
				mmax = max4[i];
			}
			else max1[i]=mmax;
		}
		mmax = -inf;
		for(int i=n;i>=1;i--){
			if(max4[i]>mmax){
				max2[i]=max4[i];
				mmax = max4[i];
			}
			else max2[i]=mmax;
			//cout << max2[i] << endl;
		}
		ll x = -inf;
		for(int i=2;i<=n;i++){
			x = max(x,max1[i-1]+max3[i]);
		}
		for(int i=n-1;i>=1;i--){
			x = max(x,max2[i+1]+max3[i]);
		}
		cout << x << endl;
	}
	return 0;
}
