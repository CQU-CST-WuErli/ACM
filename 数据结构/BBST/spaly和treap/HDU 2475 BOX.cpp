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
#define Rep(flag,start,end) for(int flag=start;flag>=end;flag--)
#define Lson l,mid,rt<<1
#define Rson mid+1,r,rt<<1|1
#define Root 1,n,1
#define BigInteger bign
#define null NULL
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

const int N=5e5+100;
int n,m;
vector<int> g[N];
int dfs_clock;
int seq[N<<1];
int a[N];

struct Node {
	Node *ch[2];
	int l[2],r[2];
	int size,val,sum;
	int invert,same,flip;
	int cmp(int k) const {
		int d=k-ch[0]->size;
		if (d==1) return -1;
		return d<=0?0:1;
	}
	void modifyflip() {
		swap(l[0],r[0]);
		swap(l[1],r[1]);
		flip^=1;
	}
	void modifysame(int c) {
		same=c;
		val=c;
		sum=size*c;
		l[0]=r[0]=c>0?0:size*c;
		l[1]=r[1]=c>0?size*c:0;
		invert=0;
	}
	void modifyinvert() {
		l[0]*=-1;l[1]*=-1;
		r[0]*=-1;r[1]*=-1;
		sum*=-1;val*=-1;
		swap(l[0],l[1]);
		swap(r[0],r[1]);
		invert^=1;
	}
	void pushdown() {
		if (same) {
			ch[0]->modifysame(same);
			ch[1]->modifysame(same);
			same=0;
		}
		if (invert) {
			ch[0]->modifyinvert();
			ch[1]->modifyinvert();
			invert^=1;
		}
		if (flip) {
			swap(ch[0],ch[1]);
			ch[0]->modifyflip();
			ch[1]->modifyflip();
			flip^=1;
		} 
	}
	void maintain() {
		size=1;
		size+=ch[0]->size+ch[1]->size;
		sum=ch[0]->sum+val+ch[1]->sum;
		l[0]=min(ch[0]->l[0],ch[0]->sum+val+ch[1]->l[0]);
		l[1]=max(ch[0]->l[1],ch[0]->sum+val+ch[1]->l[1]);
		r[0]=min(ch[1]->r[0],ch[1]->sum+val+ch[0]->r[0]);
		r[1]=max(ch[1]->r[1],ch[1]->sum+val+ch[0]->r[1]);
	}
};

Node *null=new Node();
Node* root[N];
int cnt;

void rotate(Node* &o,int d) {
	Node *k=o->ch[d^1];
	o->ch[d^1]=k->ch[d];
	k->ch[d]=o;
	o->maintain();
	k->maintain();
	o=k;
}

void splay(Node* &o,int k) {
	o->pushdown();
	o->maintain();
	int d=o->cmp(k);
	if (d==1) k-=o->ch[0]->size+1;
	if (d!=-1) {
		Node *p=o->ch[d];
		p->pushdown();
		int d2=p->cmp(k);
		int k2=d2==0?k:k-p->ch[0]->size-1;
		if (d2!=-1) {
			splay(p->ch[d2],k2);
			if (d2==d) {
				rotate(o,d^1); 
			}
			else {
				rotate(o->ch[d],d);
			}
		}
		rotate(o,d^1);
	} 
}

void split(Node *o,int k,Node* &left,Node* &right) {
	splay(o,k);
	left=o;
	right=o->ch[1];
	o->ch[1]=null;
	left->maintain();
} 

Node* merge(Node* a,Node* b) {
	splay(a,a->size);
	a->ch[1]=b;
	a->maintain();
	return a;
}

Node* build(int s) {
	if (!s) return null;
	Node *L=build(s/2);
	Node *o=new Node();
	o->val=a[cnt];
	cnt++;
	o->same=o->flip=o->invert=0;
	o->ch[0]=L;
	o->ch[1]=build(s-s/2-1);
	o->maintain();
	return o;
}

void init(int s) {
	null->ch[0]=null->ch[1]=NULL;
	null->size=0;
	null->sum=0;
	cnt=0;
	root=build(s);
}

void InOrder(Node *o) {
	if (o==NULL) return;
	o->pushdown();
	InOrder(o->ch[0]);
	if (o->val) printf("%c",o->val>0?'(':')');
	InOrder(o->ch[1]);
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (SI(n)==1) {
		rep(i,1,n) g[i].clear()
		rep(i,1,n) {
			scanf("%d",a+i);
			if (a[i]!=0) {
				g[a[i]].push_back(i);
				g[i].push_back(a[i]);
			}
		}
		
	}
	return 0;
}

