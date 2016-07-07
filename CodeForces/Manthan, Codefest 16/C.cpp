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

int n,m;
char s[10000+10];
string ts[100010];
int ans[10000+10];
const int maxn=1e6+10;
const int maxv=50;
int have[maxn],fail[maxn];
int nxt[maxn][maxv];
struct ACAutoMaton {
	int cnt,root;
	int ID_cnt;
	map<char,int> ID;
	void init() {
		cnt=ID_cnt=0;
		ID.clear();
		root=newNode();
	}
	int newNode() {
		for (int i=0;i<26;i++) {
			nxt[cnt][i]=-1;
		}
		have[cnt++]=0;
		return cnt-1;
	}
	int getID(char x) {
		return x-'a';
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
	void find(int pos) {
		int now=root;
		for (;pos<n;pos++) {
			int id=getID(s[pos]);
			if (nxt[now][id]==-1) return;
			now=nxt[now][id];
			if (have[now] && !ans[pos]) ans[pos]=have[now];
		}
		return;
	}
}ac;

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (SI(n)==1) {
		scanf("%s",s);
		SI(m);
		rep(i,0,m) ts[i].clear();
		ac.init();
		int idx;
		rep(i,1,m) {
			idx=i;
			char t[1010];
			scanf("%s",t);
			for (int j=0;t[j];j++) ts[i]+=t[j];
			for (int j=0;t[j];j++) if (t[j]>='A' && t[j]<='Z') t[j]+=32;
			int len=strlen(t);
			reverse(t,t+len);
			ac.insert(t,idx);
		}
		CLR(ans);
		rep(i,0,n-1) if (i==0 || ans[i-1]) ac.find(i);
		vector<int> v;
		int cnt=n-1;
		while (cnt>=0) {
			if (ans[cnt]) v.push_back(ans[cnt]);
			cnt-=ts[ans[cnt]].size();
		}
		Rep(i,v.size()-1,0) {
			cout << ts[v[i]] << ' ';
		}
		cout << endl;
	}
	return 0;
}