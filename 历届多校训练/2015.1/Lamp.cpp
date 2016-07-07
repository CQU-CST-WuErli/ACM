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
#define SI(a) scanf("%d", &a)
#define SII(a,b) scanf("%d%d", &a, &b)
#define SIII(a,b,c) scanf("%d%d%d", &a, &b, &c)
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7f7f7f7f;
const int MOD=1e9+7;
const double eps=1e-10;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int n, m;

const int maxm = 1010;
const int maxn = 1010;
const int maxnode = maxn * maxm;
struct DLX {
    int n,m;
    int L[maxnode],R[maxnode],U[maxnode],D[maxnode];
    int Row[maxnode],Col[maxnode];
    int H[maxnode],S[maxnode];
    int vis[maxnode];
    int ans;    //  need update
    int size;
    void init(int _n,int _m) {
        n=_n,m=_m;
        for (int i=0;i<=m;i++) {
            U[i]=D[i]=i;
            L[i]=i-1;R[i]=i+1;
            S[i]=0;
        }
        L[0]=m;R[m]=0;
        for (int i=1;i<=n;i++) H[i]=-1;
        size=m;
    	CLR(vis);
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
        int c=R[0];
        for (int i=R[0];i!=0;i=R[i]){
            if (S[c]>S[i]) c=i;
        }
        remove(c);
        for (int i=D[c];i!=c;i=D[i]) {
            for (int j=R[i];j!=i;j=R[j]) {
                remove(Col[j]);
            }
            if (dfs(cnt+1)) return true;
            for (int j=L[i];j!=i;j=L[j]) {
                resume(Col[j]);
            }
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
    bool DFS(int cnt) {
    	if (R[0] == 0) return true;
        int c=R[0];
        for (int i=R[0];i!=0;i=R[i])
            if (S[c]>S[i]) c=i;
        for (int i=D[c];i!=c;i=D[i]) {
        	if (Row[i] > n/2 && vis[Row[i] - n/2]) continue;
        	if (Row[i] <= n/2 && vis[Row[i] + n/2]) continue;
        	vis[Row[i]] = 1;
            del(i);
            for (int j=R[i];j!=i;j=R[j]) del(j);
            if (DFS(cnt + 1)) return true;
            for (int j=L[i];j!=i;j=L[j]) rec(j);
            rec(i);
        	vis[Row[i]] = 0;
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
	while(SII(n, m) == 2) {
		dlx.init(m * 2, n);
		for (int i = 1; i <= n; i++) {
			int x;SI(x);
			while(x--) {
				int id;
				char str[10];
				scanf("%d%s", &id, str);
				if (str[0] == 'O' && str[1] == 'N')
					dlx.link(id, i);
				else dlx.link(id + m, i);
			}
		}
		if (!dlx.DFS(0)) puts("-1");
		else {
			for (int i = 1; i <= m; i++) {
				if (dlx.vis[i]) printf("ON");
				else printf("OFF");
				if (i < m) printf(" ");
				else printf("\n");
			}
		}
	}
	return 0;
}