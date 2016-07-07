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
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

int n,m; 
struct P{
	int num;
	int id;
	bool operator < (const P& rhs) const {
		if (num==rhs.num) return id<rhs.id;
		else return num<rhs.num; 
	}
}a[100010];

struct Node {
    Node* ch[2];
    int rank;// 当前节点在序列中的位置 
    int size;// 节点总数 
    int flip;// 旋转标记 
    int val;// 节点的值 
    int v;// 是否需要输出，并且是build时的下标 
	Node() {
		rank=1;
		size=1;
		flip=0;
		ch[0]=ch[1]=NULL;
	}
    int cmp(int x) const {
        if (x==rank) return -1;
        return x<rank? 0 : 1;
    }
    void maintain(){
        size=1;
        rank=1;
        if (ch[0]!=NULL) {
            size+=ch[0]->size;
            rank+=ch[0]->size;
        }
        if (ch[1]!=NULL) {
        	size+=ch[1]->size;
        }
    }
    void pushdown(){
        if (flip) {
            flip=0;
            swap(ch[0],ch[1]);
            if(ch[0]!=NULL) ch[0]->flip^=1;
            if(ch[1]!=NULL) ch[1]->flip^=1;
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
    p->val=a[mid].id;
    p->flip=0;
    p->ch[0]=p->ch[1]=NULL;
    if (mid-1>=l) p->ch[0]=build(l,mid-1);
    if (mid+1<=r) p->ch[1]=build(mid+1,r);
    p->maintain();
    return p;
}

int flag=0;

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

void remove() {
	if (root->ch[0]==NULL) {
		root=root->ch[1];
		root->pushdown();
		root->maintain();
	}
	else {
		splay(root->ch[0],root->ch[0]->size);
		root->ch[0]->ch[1]=root->ch[1];
		root=root->ch[0];
		root->pushdown();
		root->maintain();
	}
}


int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (SI(n)==1 && n) {
		
	}
	return 0;
}

