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
template <typename T> T max(T& a,T& b) {return a>b?a:b;}
template <typename T> T min(T& a,T& b) {return a<b?a:b;}
int gcd(int a,int b) {return b==0?a:gcd(b,a%b);}
long long gcd (long long a,long long b) {return b==0LL?a:gcd(b,a%b);}
const int MAX_L=2005;// For BigInteger
const int INF_INT=999999999;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

inline int read() {
    char c = getchar();
    while(!isdigit(c)) c = getchar();
    int x = 0;
    while(isdigit(c)) {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}

int n,m;
int a[200000];

struct Node {
    Node* ch[2];
    int rank;// 当前节点在序列中的位置
    int size;// 节点总数
    int flip;// 旋转标记
    int add;// 增减标记
    int minv;// 最小值
    int val;// 节点的值
    int v;// 是否需要输出，并且是build时的下标
	Node() {
		rank=1;
		size=1;
		flip=0;
		add=0;
		ch[0]=ch[1]=NULL;
	}
    int cmp(int x) const {
        if (x==rank) return -1;
        return x<rank? 0 : 1;
    }
    void maintain(){
        size=1;
        rank=1;
        minv=val;
        if (ch[0]!=NULL) {
            size+=ch[0]->size;
            rank+=ch[0]->size;
            minv=min(minv,ch[0]->minv);
        }
        if (ch[1]!=NULL) {
        	size+=ch[1]->size;
        	minv=min(minv,ch[1]->minv);
        }
    }
    void pushdown(){
        if (flip) {
            flip=0;
            swap(ch[0],ch[1]);
            if(ch[0]!=NULL) ch[0]->flip^=1;
            if(ch[1]!=NULL) ch[1]->flip^=1;
        }
        if (add) {
        	val+=add;
        	if (ch[0]!=NULL) {
        		ch[0]->add+=add;
        		ch[0]->minv+=add;
        	}
        	if (ch[1]!=NULL) {
        		ch[1]->add+=add;
        		ch[1]->minv+=add;
        	}
        	add=0;
        }
    }
};

Node* root=NULL;

void rotate(Node* &o,int d) {
    Node* k = o->ch[d^1];
    o->ch[d^1] = k->ch[d];
    k->ch[d] = o;
    o->maintain();
    k->maintain();
    o=k;
}

void splay(Node* &o,int k) {
	if (o==NULL) return;
    //correct
    o->pushdown();
    o->maintain();
    int d= o->cmp(k);
    if (d==1) k -= o->rank;
    if (d!=-1) {
        Node* p = o->ch[d];
        p->pushdown();
        p->maintain();
        int d2 = p->cmp(k);
        int k2 = (d2==0 ? k : k-p->rank);
        if (d2!=-1) {
            splay(p->ch[d2],k2);
            if (d==d2) rotate(o,d^1);
            else rotate(o->ch[d], d);
        }
        rotate(o,d^1);
    }
}

Node* build(int l,int r) {
    Node* p;
    int mid=(l+r)>>1;
    p=new Node();
    p->size=r-l+1;
    p->rank=mid-l+1;
    p->v=mid;
    p->val=a[mid];
    p->flip=0;
    p->minv=a[mid];
    p->add=0;
    p->ch[0]=p->ch[1]=NULL;
    if (mid-1>=l) p->ch[0]=build(l,mid-1);
    if (mid+1<=r) p->ch[1]=build(mid+1,r);
    p->maintain();
    return p;
}

int flag;

void InOrder(Node* o) {
//	BUG;
    o->pushdown();
    o->maintain();
//    cout << o->val << endl;
    if (o->ch[0]!=NULL) InOrder(o->ch[0]);
    if (o->v) {
    	if (flag) printf(" ");flag++;
    	printf("%d",o->val);
    }
    if (o->ch[1]!=NULL) InOrder(o->ch[1]);
}

// 分裂
void split(Node* o,int k,Node* &left,Node* &right) {
    splay(o,k);
    left=o;
    right=o->ch[1];
    o->ch[1]=NULL;
    left->maintain();
}

// 合并
Node* merge(Node* left,Node* right) {
    splay(left, left->size);
    left->ch[1]=right;
    left->maintain();
    return left;
}

// 更新节点
void update(int l,int r,int val) {
	Node *left,*mid,*right,*o;
	split(root,l,left,o);
	split(o,r-l+1,mid,right);
	mid->add+=val;
	mid->pushdown();
	mid->maintain();
	root=merge(merge(left,mid),right);
}

// 反转区间
void reverse(int l,int r) {
	Node *left,*mid,*right,*o;
	split(root,l,left,o);
	split(o,r-l+1,mid,right);
	mid->flip^=1;
	mid->pushdown();mid->maintain();
	root=merge(merge(left,mid),right);
}

// 轮转区间
void revolve(int l,int r,int T) {
	int len=r-l+1;
	T%=len;
	Node *left,*mid,*right,*o;
	split(root,l,left,o);
	split(o,r-l+1,mid,right);
	Node *tl,*tr;
	split(mid,len-T,tl,tr);
	mid=merge(tr,tl);
	mid->pushdown();mid->maintain();
	root=merge(merge(left,mid),right);
}

// 插入节点
void insert(int x,int P) {
//	BUG;
	if (x==0) {
		Node *tmp=new Node();
		tmp->val=x;
		tmp->v=1;
		tmp->maintain();
		root=merge(tmp,root);
	}
	else {
		Node *left,*mid,*right;
		split(root,x+1,left,right);
		mid=new Node();
		mid->val=P;
		mid->v=1;
		mid->maintain();
		root=merge(merge(left,mid),right);
	}
}

// 删除节点
void remove(int x) {
	Node *left,*mid,*right,*o;
	split(root,x,left,o);
	split(o,1,mid,right);
	delete mid;
	root=merge(left,right);
}

// 查询
int query(int l,int r) {
	Node *left,*mid,*right,*o;
	split(root,l,left,o);
	split(o,r-l+1,mid,right);
	int ret=mid->minv;
	root=merge(merge(left,mid),right);
	return ret;
}

// 删除树
void removetree(Node* &o) {
	if (o==NULL) return ;
	if (o->ch[0]!=NULL) removetree(o->ch[0]);
	if (o->ch[1]!=NULL) removetree(o->ch[1]);
	delete o;
	o=NULL;
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n) {
		rep(i,1,n) a[i]=read();
		a[0]=INF_INT;
		root=build(0,n);
		m=read();
//		lookln(m);
		while (m--) {
			char op[20];
			scanf("%s",op+1);
//			puts(op+1);
			int x,y,T,P,D;
			if (op[1]=='A') {
				x=read();y=read();D=read();
				if (x>y) swap(x,y);
				update(x,y,D);
			}
			else if (op[1]=='R' && op[4]=='E') {
				x=read();y=read();
				if (x==y) continue;
				if (x>y) swap(x,y);
				reverse(x,y);
			}
			else if (op[1]=='R' && op[4]=='O') {
				x=read();y=read();T=read();
				if (x==y) continue;
				if (x>y) swap(x,y);
				int len=(y-x+1);
				T=(T%len+len)%len;
				if (T==0) continue;
				revolve(x,y,T);
			}
			else if (op[1]=='I') {
				x=read();P=read();
				insert(x,P);
			}
			else if (op[1]=='D') {
				x=read();
				remove(x);
			}
			else if (op[1]=='M') {
				x=read();y=read();
				if (x>y) swap(x,y);
//				BUG;
				printf("%d\n",query(x,y));
			}
		}
		removetree(root);
//		InOrder(root);
//		BUG;
	}
	return 0;
}

