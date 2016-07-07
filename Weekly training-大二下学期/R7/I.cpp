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
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int n;
int a[110],b[110],c[110];

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
   	int kase=1;
    while(SI(n)==1 && n) {
        rep(i,0,n-1) SIII(a[i],b[i],c[i]);
        int ti;
        int tt=-1;
        rep(i,0,500000) {
            int tmp=0;
            rep(j,0,n-1) {
                ti=a[j]+b[j];
                if((i+c[j]-1)%ti<a[j]) tmp++;
                else tmp--;
            }
            if(tmp>0) {
            	tt=i;
            	break;
            }
        }
        cout << "Case " << kase++ << ": ";
        if(tt==-1) puts("-1");
        else {
            int ans=-1;
            rep(i,0,n-1) {
                ti=a[i]+b[i];
                if((tt+c[i]-1)%ti>=a[i]) ans=max(ans,ti-(tt+c[i]-1)%ti);
            }
            cout << tt+ans+1 << endl;
        }
    }
	return 0;
}