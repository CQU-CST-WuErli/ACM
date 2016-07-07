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
const int inf = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
//#define LOCAL
int a[10001];
int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int n;cin >> n;
	int t;cin >> t;
	for(int i=0;i<n-1;i++){
		cin >> a[i];
	}
	sort(a,a+n-1);
	for(int i=0;i<=1000;i++){
		int s = t+i;
		int u = 0;
		for(int j=n-2;j>=0;j--){
			if(s<=a[j]){
				u += a[j]-s+1;
			}
			else break;
		}
		if(u <= i){
			cout <<i << endl;
			break;
		}
	}
	return 0;
}
