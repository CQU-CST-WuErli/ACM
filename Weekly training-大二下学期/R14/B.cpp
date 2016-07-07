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

int a[555];
int lis[555],lds[555];

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int n;
	while(SI(n)==1 && n) {
		rep(i,1,n) SI(a[i]);
		Rep(i,n,1) {
			lis[i]=lds[i]=1;
			Rep(j,n,i+1) {
				if (a[i]>=a[j]) lds[i]=max(lds[i],lds[j]+1);
				if (a[i]<=a[j]) lis[i]=max(lis[i],lis[j]+1);
			}
		}
		int ans=0;
		rep(i,1,n) {
			ans=max(ans,max(lis[i],lds[i]));
			rep(j,i+1,n) {
				if (a[j]<a[i]) ans=max(ans,lis[i]+lds[j]);
				if (a[j]>a[i]) ans=max(ans,lds[i]+lis[j]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}