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
const int MOD=10007;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int n,R;

struct Point
{
	int x,y;
	Point(){}
	void read() {
		SII(x,y);
	}
}p[330];
int g[330][330];

struct Matrix
{
	int mat[330][330];
	void init() {
		memset(mat,0,sizeof mat);
	}
	int inv(int a,int m) {// 逆元
    	if(a == 1)return 1;
    	return inv(m%a,m)*(m-m/a)%m;
	}
	int det(int n) {
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
				mat[i][j]=(mat[i][j]+MOD)%MOD;
		int ret=1;
		for (int i=0;i<n;i++) {
			for (int j=i;j<n;j++) if (mat[i][j]!=0){
				for (int k=i;k<n;k++)
					swap(mat[i][k],mat[j][k]);
				if (i!=j)
					ret=(-ret+MOD)%MOD;
				break;
			}
			if (mat[i][i]==0) {
				ret=-1;
				break;
			}
			for (int j=i+1;j<n;j++) {
				int mut=(mat[i][j]*inv(mat[i][i],MOD))%MOD;
				for (int k=i;k<n;k++)
					mat[j][k]=(mat[j][k]-(mat[i][k]*mut)%MOD+MOD)%MOD;
			}
			ret=(ret*mat[i][i])%MOD;;
		}
		return ret;
	}
	void print(int n) {
		for (int i=0;i<n;i++) {
			for (int j=0;j<n;j++) cout << mat[i][j] << ' ' ;
				cout << endl;
		}
	}
};

int dis(int i,int j) {
	int dx=p[i].x-p[j].x;
	int dy=p[i].y-p[j].y;
	return dx*dx+dy*dy;
}

bool check(int i,int j) {
	if (dis(i,j)>R*R) return false;
	for (int k=0;k<n;k++) if (k!=i && k!=j) {
		int dx1=p[i].x-p[j].x;
		int dy1=p[i].y-p[j].y;
		int dx2=p[i].x-p[k].x;
		int dy2=p[i].y-p[k].y;
		if (dx1*dy2==dx2*dy1 && (dis(i,k)<dis(i,j))) return false;
	}
	return true;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int t;SI(t);
    while(t--) {
        SII(n,R);
        rep(i,0,n-1) p[i].read();
        CLR(g);
        for (int i=0;i<n;i++)
        	for (int j=i+1;j<n;j++)
        		if (check(i,j)) g[i][j]=g[j][i]=1;
        Matrix ret;
        ret.init();
        for (int i=0;i<n;i++)
        	for (int j=0;j<n;j++)
        		if (i!=j && g[i][j]) {
                    ret.mat[i][j]=-1;
                    ret.mat[i][i]++;
                }
        // ret.print(n);
        printf("%d\n", ret.det(n-1));
    }
	return 0;
}