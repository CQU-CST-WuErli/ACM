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
#define For_UVa if (kase!=1) cout << endl
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define SI(a) scanf("%d",&a)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define rep(flag,start,end) for(int flag=start;flag<=end;flag++)
#define Rep(flag,start,end) for (int flag=start;flag>=end;flag--)
#define Lson l,mid,rt<<1
#define Rson mid+1,r,rt<<1|1
#define Root 1,n,1
#define BigInteger bign
template <typename T> T max(T& a,T& b) {return a>b?a:b;}
template <typename T> T min(T& a,T& b) {return a<b?a:b;}
int gcd(int a,int b) {return b==0?a:gcd(b,a%b);}
long long gcd (long long a,long long b) {return b==0LL?a:gcd(b,a%b);}
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

struct Node {
	Node *ch[2];
	int r; // 优先级
	int v; // 值
	int s; // 节点总数
	Node(int v):v(v) {ch[0]=ch[1]=NULL;r=rand();s=1;}
	bool operator < (const Node& rhs) const {
		return r<rhs.r;
	}
	int cmp(int x) const {
		if (x==v) return -1;
		return x<v?0:1;
	}
	void maintain() {
		s=1;
		if (ch[0]!=NULL) s+=ch[0]->s;
		if (ch[1]!=NULL) s+=ch[1]->s;
	}
};

// 旋转函数
void rotate(Node* &o,int d) {
	Node* k=o->ch[d^1];
	o->ch[d^1]=k->ch[d];
	k->ch[d]=o;
	o->maintain();k->maintain();
	o=k;
} 

// 插入函数
void insert(Node* &o,int x) {
	if (o==NULL) o=new Node(x);
	else {
		int d=(x<o->v?0:1);
		insert(o->ch[d],x);
		if (o->ch[d]->r > o->r) rotate(o,d^1);
	}
	o->maintain();
} 

// 删除函数
void remove(Node* &o,int x) {
	int d=o->cmp(x);
	if (d==-1) {
		Node* u=o;
		if (o->ch[0]!=NULL && o->ch[1]!=NULL) {
			int d2=(o->ch[0]->r > o->ch[1]->r?1:0);
			rotate(o,d2);remove(o->ch[d2],x);
		}
		else {
			if (o->ch[0]==NULL) o=o->ch[1];
			else o=o->ch[0];
			delete u;
		}
	}
	else remove(o->ch[d],x);
	if (o!=NULL) o->maintain();
} 

const int maxc=5e5+10;
const int maxn=2e5+10;
const int maxm=6e5+10;
struct Command {
	char type;
	int x,p;
}commands[maxc];

int n,m,weight[maxn],from[maxm],to[maxm],removed[maxm];

// 并查集相关
 
int par[maxn];
int find(int x) {return par[x]=par[x]==x?x:find(par[x]);}

// 名次树相关
Node* root[maxn]; // Treap

// 第K大的值
int kth(Node* o,int k) {
	if (o==NULL || k<=0 || k>o->s) return 0;
	int s=(o->ch[1]==NULL?0:o->ch[1]->s);
	if (k==s+1) return o->v;
	else if (k<=s) return kth(o->ch[1],k);
	else return kth(o->ch[0],k-s-1); 
} 

// 合并两棵树
void mergeto(Node* &src,Node* &dest) {
	if (src->ch[0]!=NULL) mergeto(src->ch[0],dest);
	if (src->ch[1]!=NULL) mergeto(src->ch[1],dest);
	insert(dest,src->v);
	delete src;
	src=NULL;
} 

// 删除树
void removetree(Node* &x) {
	if (x->ch[0]!=NULL) removetree(x->ch[0]);
	if (x->ch[1]!=NULL) removetree(x->ch[1]);
	delete x;
	x=NULL;
} 

// 主程序相关
void add_edge(int x) {
	int u=find(from[x]),v=find(to[x]);
	if (u!=v) {
		if (root[u]->s < root[v]->s) {
			par[u]=v;
			mergeto(root[u],root[v]);
		} 
		else {
			par[v]=u;
			mergeto(root[v],root[u]);
		}
	}
} 

int query_cnt;
ll query_tot;
void query(int x,int k) {
	query_cnt++;
	query_tot+=kth(root[find(x)],k);
}

void change_weight(int x,int v) {
	int u=find(x);
	remove(root[u],weight[x]);
	insert(root[u],v);
	weight[x]=v;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	int kase=0;
	while (SII(n,m)==2 && (m+n)) {
		rep(i,1,n) scanf("%d",weight+i);
		rep(i,1,m) scanf("%d%d",from+i,to+i);
		CLR(removed);
		// 读命令 
		int c=0;
		while (1) {
			char type;
			int x,p=0,v=0;
			scanf(" %c",&type);
			if (type=='E') break;
			SI(x);
			if (type=='D') removed[x]=1;
			if (type=='Q') SI(p);
			if (type=='C') {
				SI(v);
				p=weight[x];
				weight[x]=v;
			}			
			commands[c++]=(Command){type,x,p};
		} 
		
		// 最终的图
		rep(i,1,n) {
			par[i]=i;
			if (root[i]!=NULL) removetree(root[i]);
			root[i]=new Node(weight[i]);
		} 
		rep(i,1,m) if (!removed[i]) add_edge(i);
		
		// 反向操作
		query_cnt=query_tot=0;
		Rep(i,c-1,0) {
			if (commands[i].type=='D') add_edge(commands[i].x);
			if (commands[i].type=='Q') query(commands[i].x,commands[i].p);
			if (commands[i].type=='C') change_weight(commands[i].x,commands[i].p); 
		} 
		printf("Case %d: %.6lf\n",++kase,query_tot/(double)query_cnt);
	}
	return 0;
}

