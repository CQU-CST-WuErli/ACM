//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2016 CQU_CST_WuErli. All rights reserved.
//
#include <iostream>
#include <cstdio>

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
typedef long long  ll;
using namespace std;

int x1,x2,y1,y2;
int abs(int x) {
	return x<0?-x:x;
}

int get(int x1) {
	int tmp1=(abs((x1+y1)))%2;
	int tmp2=abs((x1+y2))%2;
	int ret;
	if (tmp1==0 && tmp2==0) ret=(y2-y1)/2+1;
	else if (tmp1==1 && tmp2==0) ret=(y2-y1+1)/2;
	else if (tmp1==0 && tmp2==1) ret=(y2-y1+1)/2;
	else if (tmp1==1 && tmp2==1) ret=(y2-y1)/2;
	return ret;
}



int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int t;SI(t);
	while(t--) {
		SII(x1,y1);
	    SII(x2,y2);
	    ll ans=0LL;
	   	if (x1==x2) {
	   		ans+=1LL*get(x1);
	   	}
	   	else {
	   		ans+=1LL*get(x1)+1LL*get(x1+1);
	   		// lookln(get(x1,y1,y2));lookln(get(x1+1,y1,y2));
	   		int len=x2-x1+1;
	   		ans=ans*1LL*(len/2)+(len%2?1LL*get(x1):0LL);
	   	}
	   	cout << ans << endl;
	}
	return 0;
}