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
#define BigInteger bign
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int mod;
int a,b,n,m;
struct Matrix {
	int mat[2][2];
}initM,ansM;

Matrix multi(Matrix& a,Matrix& b) {
	Matrix ret;
	rep(i,0,1) rep(j,0,1) {
		ret.mat[i][j]=0;
		rep(k,0,1) ret.mat[i][j]+=(a.mat[i][k]*b.mat[k][j])%mod;
		ret.mat[i][j]=ret.mat[i][j]%mod;
	}
	return ret;
}

void calc(int n) {
	ansM.mat[0][0]=1;
	ansM.mat[0][1]=0;
	ansM.mat[1][0]=0;
	ansM.mat[1][1]=1;
	initM.mat[0][0]=0;
	initM.mat[0][1]=1;
	initM.mat[1][0]=1;
	initM.mat[1][1]=1;
	while (n) {
		if (n&1) ansM=multi(initM,ansM);
		initM=multi(initM,initM);
		n>>=1;
	}

}


int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    for (int T_T,kase=SI(T_T);kase<=T_T;kase++) {
    	SII(a,b);

    	SII(n,m);
    	mod=1;
    	rep(i,1,m) mod*=10;
    	cout << "Case " << kase << ": ";
    	if (n==0) cout << a%mod;
    	else if (n==1) cout << b%mod;
    	else if (n==2) cout << (a+b)%mod;
    	else {
    		calc(n-1);
    		cout << ((ansM.mat[1][0]*a)%mod+(ansM.mat[1][1]*b)%mod)%mod << endl;
    	}
    }
	return 0;
}