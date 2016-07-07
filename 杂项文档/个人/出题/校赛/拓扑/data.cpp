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
#include <ctime>
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

const int N=1e5+100;

int a[N];
int n,m;

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    // freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    freopen("4.in","w",stdout);
#endif

    srand(time(NULL));
    int T1=rand()%20+1,T2=rand()%15+1;
    printf("%d\n", T1+T2);
    for (int i=1;i<=100000;i++) a[i]=i;
    for (int i=1;i<=T1;i++) {
    	n=rand()%99996+4;
    	m=rand()%n+2*n;
    	printf("%d %d\n", n,m);
    	for (int j=1;j<=m;j++) {
    		int u=rand()%n+1;
    		while(u==1) u=rand()%n+1;
    		int v=rand()%u+1;
    		while(v==u) v=rand()%u+1;
    		printf("%d %d\n", a[u],a[v]);
    	}
    	puts("");
    }
    // no solution
    for (int i=1;i<=T2;i++) {
    	int n=rand()%99995+5;
    	int m=rand()%n+4*n;
    	printf("%d %d\n", n,m);
    	for (int j=1;j<=m;j++) {
    		int u=rand()%n+1;
    		int v=rand()%n+1;
    		while(v==u) v=rand()%n+1;
    		printf("%d %d\n", a[u],a[v]);
    	}
    	puts("");
    }
	return 0;
}