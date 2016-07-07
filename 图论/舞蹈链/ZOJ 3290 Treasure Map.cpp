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

int n,m,p;

struct DLX {
    const static int maxn=500010;
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
        OFF(H);
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
        // look(size);
        // look(Col[size]);look(Row[size]);look(S[col]);
        // look(U[size]);look(D[size]);look(L[size]);lookln(R[size]);
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
    void dfs(int cnt) {
        // lookln(cnt);
        // 这个剪枝没啥用- -
        // if (ans!=-1 && ans<=cnt) return;
        if (R[0]==0) {
            if (ans==-1) ans=cnt;
            else ans=min(ans,cnt);
            return;
        }
        int c=0;
        int Min=INF_INT;
        for (int i=R[0];i!=0;i=R[i]){
        	// lookln(S[i]);
            if (Min>S[i]) Min=S[i],c=i;
            // lookln(i);
        }
        // lookln(c);
        remove(c);
        // BUG;
        for (int i=D[c];i!=c;i=D[i]) {
        	// lookln(D[c]);
            for (int j=R[i];j!=i;j=R[j]) {
            	// lookln(Col[j]);
                remove(Col[j]);
            }
            // BUG;
           	dfs(cnt+1);
            for (int j=L[i];j!=i;j=L[j]) {
                resume(Col[j]);
            }
        }
        resume(c);
        return;
    }
    // exact cover ends;
    // multiple cover
    void del(int c) {
        for (int i=D[c];i!=c;i=D[i]) {
            // cout << i << ' ';
            L[R[i]]=L[i];
            R[L[i]]=R[i];
        }
        // cout << endl;
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
    void DFS(int cnt) {
        if (cnt+h()>=ans) return;
        if (R[0]==0) {
            ans=min(ans,cnt);
            return;
        }
        int c=0;
        int Min=INF_INT;
        for (int i=R[0];i!=0;i=R[i])
            if (Min>S[i]) Min=S[i],c=i;
        // lookln(c);
        for (int i=D[c];i!=c;i=D[i]) {
            del(i);
            for (int j=R[i];j!=i;j=R[j]) del(j);
            DFS(cnt+1);
            for (int j=L[i];j!=i;j=L[j]) rec(j);
            rec(i);
        }
        return;
    }
    // multiple cover ends;
}dlx;

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int T;
    SI(T);
    while(T--) {
        SIII(n,m,p);
        dlx.init(n*m);
        // 0-n  1~n+1    0-m  n+1+1~n+m+2
        rep(z,1,p) {
            int X1,X2,Y1,Y2;
            SII(X1,Y1);
            SII(X2,Y2);
           	rep(i,X1+1,X2) rep(j,Y1+1,Y2) {
           		int id=(i-1)*m+j;
           		// cout << z << ' ' << id << endl;
           		dlx.link(z,id);
           	}
        }
        dlx.dfs(0);
        cout << dlx.ans << endl;
    }
	return 0;
}