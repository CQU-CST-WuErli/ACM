//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015 CQU_CST_WuErli. All rights reserved.
//
// #include<bits/stdc++.h>
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
#define ALL(x) x.begin(),x.end()
#define AT(i,v) for (auto &i:v)
#define For_UVa if (kase!=1) cout << endl
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define look(x) cout << #x << "=" << x
#define SI(a) scanf("%d",&a)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
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

char s[60];
char t[1001000];

const int maxn=5e5+10;
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
	void insert(char buf[]) {
		int len=strlen(buf);
		int now=root;
		for (int i=0;i<len;i++) {
			int id=getID(buf[i]);
			if (nxt[now][id]==-1) nxt[now][id]=newNode();
			now=nxt[now][id];
		}
		have[now]++;
	}
	void build() {
		fail[root]=root;
		queue<int> q;
		for (int i=0;i<26;i++) {
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
			for (int i=0;i<26;i++) {
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
	int find(char buf[]) {
		int len=strlen(buf);
		int now=root;
		int ret=0;
		for (int i=0;i<len;i++) {
			int id=getID(buf[i]);
			now=nxt[now][id];
			int tmp=now;
			while (tmp!=root) {
				ret+=have[tmp];
				have[tmp]=0;
				tmp=fail[tmp];
			}		
		}
		return ret;
	}
}; 

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif	
	int T_T,n; cin >> T_T;
	while (T_T--) {
		ACAutoMaton HDU2222;
		HDU2222.init();
		cin >> n;
		for (int i=1;i<=n;i++) {
			scanf("%s",s);
			HDU2222.insert(s);			
		}
		scanf("%s",t);
		HDU2222.build();
		cout << HDU2222.find(t) << endl;
	}
	return 0;
}

