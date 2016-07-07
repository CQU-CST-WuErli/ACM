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
#include <assert.h>

const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int maxm = 15*15+10;
const int maxn = 15*15+10;
const int maxnode = maxn*maxm;
struct DLX {
    int n,m;
    int L[maxnode],R[maxnode],U[maxnode],D[maxnode];
    int Row[maxnode],Col[maxnode];
    int H[maxnode],S[maxnode];
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
    }
    void link(int row,int col) {
        ++S[Col[++size]=col];
        Row[size]=row;
        D[size]=D[col];
        U[D[col]]=size;
        U[size]=col;
        D[col]=size;
        if(H[row]<0)H[row]=L[size]=R[size]=size;
        else
        {
            R[size]=R[H[row]];
            L[R[H[row]]]=size;
            L[size]=H[row];
            R[H[row]]=size;
        }
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
    int vis[maxn];
    int h() {
        int ret=0;
        for(int c=R[0];c!=0;c=R[c]) vis[c]=true;
        for(int c=R[0];c!=0;c=R[c]) if(vis[c]) {
                ret++;
                vis[c]=false;
                for(int i=D[c];i!=c;i=D[i])
                    for(int j=R[i];j!=i;j=R[j])
                        vis[Col[j]]=false;
        }
        return ret;
    }
    void DFS(int cnt) {
        if (cnt+h()>=ans) return;
        if (R[0]==0) {
            if (cnt<ans) ans=cnt;
            return;
        }
        int c=R[0];
        for (int i=R[0];i!=0;i=R[i])
            if (S[c]>S[i]) c=i;
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

int n,m;
int a[20][20];
int id[20][20];

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while(scanf("%d%d",&n,&m)==2) {
		int cnt=0;memset(id,0,sizeof(id));
	    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) {
	    	scanf("%d",&a[i][j]);
	    	if (a[i][j]==1) id[i][j]=++cnt;
	    }
	    int n1,m1;
	    scanf("%d%d",&n1,&m1);
	    dlx.init(n*m,cnt);
	    int idx=0;
	    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) {
	    	idx++;
	    	for (int s=0;s<n1;s++) for (int t=0;t<m1;t++) if (i+s>=1 && i+s<=n && j+t>=1 && j+t<=m && id[i+s][j+t]) {
	    		dlx.link(idx,id[i+s][j+t]);
	    	}
	    }
	    dlx.ans=INF_INT;
	    dlx.DFS(0);
	    printf("%d\n",dlx.ans);
	}
	return 0;
}