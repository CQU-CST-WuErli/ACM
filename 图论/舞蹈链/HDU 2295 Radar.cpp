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
#define Lson l,mid,rt<<1
#define Rson mid+1,r,rt<<1|1
#define Root 1,n,1
#define BigInteger bign
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-8;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

double mid;
int n,m,k;
struct P
{
	double x,y;
	P(){}
	P(double x,double y):x(x),y(y){}
	bool operator < (const P& rhs) const {
		return x==rhs.x?y<rhs.y:x<rhs.x;
	}
}city[60],radar[60];

double dis(P& a,P& b){
	double dx=a.x-b.x;
	double dy=a.y-b.y;
	return sqrt(dx*dx+dy*dy);
}
struct DLX {
    const static int maxn=1000010;
    int L[maxn],R[maxn],U[maxn],D[maxn];
    int Row[maxn],Col[maxn];
    int H[maxn],S[maxn];
    int vis[100];
    int ans;
    int size;
    stack<int> Ans;
    void init(int m) {
        for (int i=0;i<=m;i++) {
            U[i]=D[i]=i;
            L[i]=i-1;R[i]=i+1;
            S[i]=0;
        }
        L[0]=m;R[m]=0;
        for (int i=0;i<maxn;i++) H[i]=-1;
        size=m;
        ans=-1;
        while (Ans.size()) Ans.pop();
    }
    void link(int row,int col) {
        size++;
        Col[size]=col;Row[size]=row;
        S[col]++;
        U[size]=U[col];D[size]=col;
        D[U[col]]=size;
        U[col]=size;
        if (H[row]!=-1) {
            R[size]=H[row];
            L[size]=L[H[row]];
            R[L[size]]=size;
            L[R[size]]=size;
        }
        else
            H[row]=L[size]=R[size]=size;
    }
    // exact cover
    void remove(int c) {
        L[R[c]]=L[c];
        R[L[c]]=R[c];
        for (int i=D[c];i!=c;i=D[i]) {
            for (int j=R[i];j!=i;j=R[j]) {
                U[D[j]]=U[j];
                D[U[j]]=D[j];
                S[Col[j]]--;
            }
        }
    }
    void resume(int c) {
        for (int i=U[c];i!=c;i=U[i]) {
            for (int j=L[i];j!=i;j=L[j]) {
                U[D[j]]=j;
                D[U[j]]=j;
                S[Col[j]]++;
            }
        }
        R[L[c]]=c;
        L[R[c]]=c;
    }
    bool dfs(int cnt) {
        if (ans!=-1) return true;
        if (R[0]==0) {
            ans=cnt;
            return true;
        }
        int c=0;
        int Min=INF_INT;
        for (int i=R[0];i!=0;i=R[i]){
            if (Min>S[i]) Min=S[i],c=i;
            // lookln(i);
        }
        remove(c);
        for (int i=D[c];i!=c;i=D[i]) {
            Ans.push(Row[i]);
            for (int j=R[i];j!=i;j=R[j]) {
                remove(Col[j]);
            }
            if (dfs(cnt+1)) return true;
            for (int j=L[i];j!=i;j=L[j]) {
                resume(Col[j]);
            }
            Ans.pop();
        }
        resume(c);
        return false;
    }
    // exact cover ends;
    // multiple cover
    void del(int c) {
        for (int i=D[c];i!=c;i=D[i]) {
            L[R[i]]=L[i];
            R[L[i]]=R[i];
        }
    }
    void rec(int c) {
        for (int i=U[c];i!=c;i=U[i]) {
            L[R[i]]=R[L[i]]=i;
        }
    }
    int h() {
        int ret=0;
        CLR(vis);
        for (int i=R[0];i!=0;i=R[i]) if (!vis[i]) {
            ret++;
            vis[i]=1;
            for (int j=D[i];j!=i;j=D[j])
                for (int k=R[j];k!=j;k=R[k])
                    vis[Col[k]]=1;
        }
        return ret;
    }
    bool DFS(int cnt) {
    	if (cnt>k) return false;
        if (cnt+h()>k) return false;
        if (R[0]==0) {
        	// lookln(mid);
            return true;
        }
        int c=0;
        int Min=INF_INT;
        for (int i=R[0];i!=0;i=R[i])
            if (Min>S[i]) Min=S[i],c=i;
        // lookln(c);
        for (int i=D[c];i!=c;i=D[i]) {
            del(i);
            for (int j=R[i];j!=i;j=R[j]) del(j);
            if (DFS(cnt+1)) return true;
            for (int j=L[i];j!=i;j=L[j]) rec(j);
            rec(i);
        }
        return false;
    }
    // multiple cover ends;
}dlx;


int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int T;SI(T);
    while(T--) {
        SIII(n,m,k);
        rep(i,1,n) scanf("%lf%lf",&city[i].x,&city[i].y);
        rep(i,1,m) scanf("%lf%lf",&radar[i].x,&radar[i].y);
        double L=0.00,R=0.00;
        rep(i,1,m) rep(j,1,n) R=max(R,dis(city[j],radar[i]));
        // lookln(R);
        while (R-L>eps) {
        	mid=(L+R)/2;
        	// lookln(mid);
        	dlx.init(n);
        	rep(i,1,m) rep(j,1,n) {
        		if (dis(radar[i],city[j])<=mid) dlx.link(i,j);
        	}
          	if (dlx.DFS(0)) R=mid;
        	else L=mid;
        	// if (mid==2.5) break;
        }
        printf("%.6lf\n",(L+R)/2);
        // lookln(dlx.size);
    }
	return 0;
}