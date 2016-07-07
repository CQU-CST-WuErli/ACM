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
typedef long long  ll;
using namespace std;

struct Sta
{
	int val,id;
	Sta(int val,int id):val(val),id(id){}
};

const int N=1000010;
int a[N];
int n,k;
int ans[N];

void getmin() {
	deque<Sta> q;
	rep(i,1,k-1) {
		while (q.size() && q[q.size()-1].val>=a[i]) q.pop_back();
		q.push_back(Sta(a[i],i));
	}
	rep(i,k,n) {
		while (q.size() && q.back().val>=a[i]) q.pop_back();
		q.push_back(Sta(a[i],i));
		while (q.size() && q.front().id<=i-k) q.pop_front();
		ans[i-k+1]=q.front().val;
	}
	rep(i,1,n-k+1) {
		printf("%d%c",ans[i],i<n-k+1?' ':'\n');
	}
}

void getmax() {
	deque<Sta> q;
	rep(i,1,k-1) {
		while (q.size() && q.back().val<=a[i]) q.pop_back();
		q.push_back(Sta(a[i],i));
	}
	rep(i,k,n) {
		while (q.size() && q.back().val<=a[i]) q.pop_back();
		q.push_back(Sta(a[i],i));
		while (q.size() && q.front().id<=i-k) q.pop_front();
		ans[i-k+1]=q.front().val;
	}
	rep(i,1,n-k+1) {
		printf("%d%c",ans[i],i<n-k+1?' ':'\n');
	}
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while(SII(n,k)==2) {
        rep(i,1,n) SI(a[i]);
        getmin();
        getmax();
    }
	return 0;
}