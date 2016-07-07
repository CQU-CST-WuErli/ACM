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
#include <assert.h>
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

char s[90];
int maze[10][10];
int ans[10][10];
struct P{
    int i,j,val;
    P(int i,int j,int val):i(i),j(j),val(val){}
    P(){}
} Hash[81*9+10];
int id[10][10];
stack<int> Ans;

const int maxm = 1100;
const int maxn = 1100*4;
const int maxnode = maxn * maxm;
struct DLX {
    int n,m;
    int L[maxnode],R[maxnode],U[maxnode],D[maxnode];
    int Row[maxnode],Col[maxnode];
    int H[maxnode],S[maxnode];
    int vis[maxn];
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
        // lookln(cnt);
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
}dlx;


int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (scanf("%s",s)!=EOF) {
		// puts(s);
		if (s[0]=='e') break;
        while (Ans.size()) Ans.pop();
		int idx=0;
        int cnt=0;
		rep(i,1,9) rep(j,1,9) {
			if (s[idx]!='.') maze[i][j]=s[idx]-'0';
			else cnt++,maze[i][j]=0;
			idx++;
		}
        idx=0;
        for (int i=1;i<=9;i+=3) for (int j=1;j<=9;j+=3) {
            idx++;
            for (int x=0;x<3;x++) for (int y=0;y<3;y++) id[i+x][j+y]=idx;
        }
        // rep(i,1,9) {
        //     rep(j,1,9) cout << id[i][j] << ' ';
        //     cout << endl;
        // }
		dlx.init(81-cnt+9*cnt,4*9*9);
		idx=1;
		//X=INT（（N-1）/9）+1；Y=（（N-1） Mod 9）+1；N=（X-1）×9+Y
		//X=INT（（N-81-1）/9）+1；Y=（（N-81-1） Mod 9）+1；N=（X-1）×9+Y+81
		//X=INT（（N-162-1）/9）+1；Y=（（N-162-1） Mod 9）+1；N=（X-1）×9+Y+162
		//X=INT（（N-243-1）/9）+1；Y=（（N-243-1） Mod 9）+1；N=（X-1）×9+Y+243
        /*
        1、每个格子只能填一个数字
        2、每行1-9的这9个数字都得填一遍
        3、每列1-9的这9个数字都得填一遍
        4、每宫1-9的这9个数字都得填一遍
        */
		rep(i,1,9) rep(j,1,9) {
			if (maze[i][j]==0) {
                rep(z,1,9) {
                    dlx.link(idx,(i-1)*9+j);
                    dlx.link(idx,(i-1)*9+z+81);
                    dlx.link(idx,(j-1)*9+z+162);
                    dlx.link(idx,(id[i][j]-1)*9+z+243);
                    Hash[idx++]=P(i,j,z);
                }
			}
			else {
                int num=maze[i][j];
                dlx.link(idx,(i-1)*9+j);
                dlx.link(idx,(i-1)*9+num+81);
                dlx.link(idx,(j-1)*9+num+162);
                dlx.link(idx,(id[i][j]-1)*9+num+243);
                Hash[idx++]=P(i,j,num);
			}
		}
        dlx.dfs(0);
        // lookln(Ans.size());
        while (Ans.size()) {
            int x=Ans.top();Ans.pop();
            int i=Hash[x].i,j=Hash[x].j,val=Hash[x].val;
            ans[i][j]=val;
        }
        // rep(i,1,9) {
        //     rep(j,1,9) cout << ans[i][j] << ' ';
        //     cout << endl;
        // }
	    rep(i,1,9) rep(j,1,9) cout << ans[i][j];
        cout << endl;
    }
	return 0;
}