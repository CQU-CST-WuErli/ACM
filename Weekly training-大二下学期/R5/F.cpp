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
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int n;
char ts[1010][60];
int ans[1010];
char s[2000020];

struct AcAutoMaton
{
	const static int maxn=5e4+10;
    const static int maxv=200;
	int cnt,root;
	int ID_cnt;
	map<char,int> ID;
	int have[maxn],fail[maxn];
	int nxt[maxn][maxv];
	void init() {
		cnt=ID_cnt=0;
		ID.clear();
		root=newNode();
	}
	int newNode() {
		for (int i=0;i<128;i++) {
			nxt[cnt][i]=-1;
		}
		have[cnt++]=0;
		return cnt-1;
	}
	int getID(char c) {
		int ret=(int)c;
		// lookln(ret);
		return ret;
	}
	void insert(char buf[],int pos) {
		int len=strlen(buf);
		int now=root;
		for (int i=0;i<len;i++) {
			int id=getID(buf[i]);
			if (nxt[now][id]==-1) nxt[now][id]=newNode();
			now=nxt[now][id];
		}
		have[now]=pos;
	}
	void build() {
		fail[root]=root;
		queue<int> q;
		for (int i=0;i<128;i++) {
			if (nxt[root][i]==-1) {
				nxt[root][i]=root;
			}
			else {
				fail[nxt[root][i]]=root;
				q.push(nxt[root][i]);
			}
		}
		while (!q.empty()) {
			int u=q.front();q.pop();
			for (int i=0;i<128;i++) {
				int& v=nxt[u][i];
				if (v==-1) {
					v=nxt[fail[u]][i];
				}
				else {
					fail[v]=nxt[fail[u]][i];
					q.push(v);
				}
			}
		}
	}
	void find(char buf[]) {
		int len=strlen(buf);
		int now=root;
		for (int i=0;i<len;i++) {
			int id=getID(buf[i]);
			now=nxt[now][id];
			int tmp=now;
			while (tmp!=root) {
				if (have[tmp]) ans[have[tmp]]++;
				tmp=fail[tmp];
			}
		}
	}
}ac;

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while(SI(n)==1) {
    	ac.init();
        rep(i,1,n) {
        	scanf("%s",ts[i]);
        	ac.insert(ts[i],i);
        }
        ac.build();
        scanf("%s",s);
        CLR(ans);
        ac.find(s);
        rep(i,1,n) if (ans[i]) printf("%s: %d\n",ts[i],ans[i]);
    }
	return 0;
}