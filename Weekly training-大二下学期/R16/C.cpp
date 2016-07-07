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
const int MOD=1e9+7;
const double eps=1e-10;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

struct AcAutoMaton
{
	const static int maxn=1e5+100;
    const static int maxv=30;
	int cnt,root;
	int ID_cnt;
	map<char,int> ID;
	int nxt[maxn][maxv];
	int vis[maxn];
	void init() {
		cnt=ID_cnt=0;
		ID.clear();
		root=newNode();
		CLR(vis);
	}
	int newNode() {
		for (int i=0;i<30;i++) {
			nxt[cnt][i]=-1;
		}
		vis[cnt++]=0;
		return cnt-1;
	}
	int getID(char c) {
		return c-'a';
	}
	void insert(char buf[]) {
		int len=strlen(buf);
		int now=root;
		for (int i=0;i<len;i++) {
			int id=getID(buf[i]);
			if (nxt[now][id]==-1) nxt[now][id]=newNode();
			vis[nxt[now][id]]++;
			now=nxt[now][id];
		}
	}
	int num;
	void find(char buf[]) {
		int len=strlen(buf);
		int now=root;
		for (int i=0;i<len;i++) {
			int id=getID(buf[i]);
			// cout << buf[i] << endl;
			vis[nxt[now][id]]--;
			num++;
			if (vis[nxt[now][id]]==0) return;
			now=nxt[now][id];
		}
	}
}ac;

int n;
char s[10100][100010];

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while(SI(n)==1) {
    	ac.init();
     	rep(i,1,n) {
        	scanf("%s",s[i]);
        	ac.insert(s[i]);
     	}
     	ll ans=0;
     	rep(i,1,n-1) {
     		ac.num=0;
     		ac.find(s[i]);
     		// lookln(ac.num);
     		ans+=ac.num;
     	}
     	printf("%lld.000000\n",ans);
    }
	return 0;
}