//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2016 CQU_CST_WuErli. All rights reserved.
//w
#include <stdio.h>
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
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
const int N=1000010*4;

int n,k;

int ans1[1000010*4];
int ans2[1000010*4];

void pushup(int rt) {
	ans1[rt]=max(ans1[rt<<1],ans1[rt<<1|1]);
	ans2[rt]=min(ans2[rt<<1],ans2[rt<<1|1]);
}

void build(int l,int r,int rt) {
	int mid;
	if (l==r) {
		scanf("%d",ans1+rt);
		ans2[rt]=ans1[rt];
		return ;
	}
	mid=(l+r)>>1;
	build(Lson);
	build(Rson);
	pushup(rt);
}

int maxx;
void queryMax(int L,int R,int l,int r,int rt) {
	int mid;
	if (L<=l && r<=R) {
		maxx=max(maxx,ans1[rt]);
		return;
	}
	mid=(l+r)>>1;
	if (L<=mid) queryMax(L,R,Lson);
	if (R>mid) queryMax(L,R,Rson);
	return;
}

int minx;
void queryMin(int L,int R,int l,int r,int rt) {
	int mid;
	if (L<=l && r<=R) {
		minx=min(minx,ans2[rt]);
		return;
	}
	mid=(l+r)>>1;
	if (L<=mid) queryMin(L,R,Lson);
	if (R>mid) queryMin(L,R,Rson);
	return;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int i;
	while(SII(n,k)==2) {
        build(1,n,1);

        for(i=1;i<=n-k+1;i++) {
        	minx=INF_INT;
        	queryMin(i,i+k-1,1,n,1);
        	printf("%d",minx);
        	if (i<n-k+1) printf(" ");
        	else printf("\n");
        }
        for(i=1;i<=n-k+1;i++) {
        	maxx=-INF_INT;
        	queryMax(i,i+k-1,1,n,1);
        	printf("%d",maxx);
        	if (i<n-k+1) printf(" ");
        	else printf("\n");
        }
	}
	return 0;
}