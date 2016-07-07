//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015Äê CQU_CST_WuErli. All rights reserved.
//
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
#include <algorithm>
#include <sstream>
#include <functional>
#define cir(i,a,b)  for (int i=a;i<=b;i++)
#define CIR(j,a,b)  for (int j=a;j>=b;j--)
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define INF 0x3f3f3f3f
#define BUG(x) cout << "I am in line" << x << endl
#define look(x) cout << #x << "= " << x << endl
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=1e5+10;
ll l[N],r[N],sum[N];
ll a[N];
int n;
 

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int kase=1;
	while (cin >> n){
		if (kase!=1) cout << endl; kase++;
		sum[0]=0;
		for (int i=1;i<=n;i++){
			scanf("%lld",a+i);
			sum[i]=sum[i-1]+a[i];
			l[i]=i;
			r[i]=i;
		}
		for (int i=1;i<=n;i++){
			while (l[i]>1 && a[i]<=a[l[i]-1] ) l[i]=l[l[i]-1];
		}
		for (int i=n;i>=1;i--){
			while (r[i]<n && a[i]<=a[r[i]+1]) r[i]=r[r[i]+1];
		}
//		for (int i=1;i<=n;i++)
//			cout << l[i] << "<--" << a[i] << "-->" << r[i] << endl;
		ll ans=0;
		int L=1,R=1;
		int len=0;
		for (int i=1;i<=n;i++){
			ll tmp=sum[r[i]]-sum[l[i]-1];
			if (ans<tmp*a[i]){				
				ans=tmp*a[i];
				len=L-R;
				L=l[i];R=r[i];
			}
			else if (ans==tmp*a[i]){
				if (r[i]-l[i]<len) {
					L=l[i];R=r[i];
				}
			}
		}
		printf("%lld\n",ans);
		printf("%d %d\n",L,R);
	}
	return 0;
}


