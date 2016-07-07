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
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=2e5+100;

int n,m;
int a[N];

struct Node {
    Node* ch[2];
    int rank;// 当前节点在序列中的位置
    int s;// 节点总数
    int flip;// 旋转标记
    int add;// 增减标记
    int val;// 节点的值
    int v;  // 原数组中下标
    int maxv;
    Node() {
        rank=1;
        s=1;
        flip=0;
        add=0;
        maxv=0;
        ch[0]=ch[1]=NULL;
    }
    int cmp(int x) const {
        if (x==rank) return -1;
        return x<rank? 0 : 1;
    }
    void maintain(){
        s=1;
        rank=1;
        maxv=val;
        if (ch[0]!=NULL) {
            s+=ch[0]->s;
            rank+=ch[0]->s;
            maxv=max(maxv,ch[0]->maxv);
        }
        if (ch[1]!=NULL) {
            s+=ch[1]->s;
            maxv=max(maxv,ch[1]->maxv);
        }
    }
    void pushdown(){
        if (flip) {
            flip=0;
            if(ch[0]!=NULL) {
                ch[0]->flip^=1;
                swap(ch[0]->ch[0],ch[0]->ch[1]);
            }
            if(ch[1]!=NULL) {
                ch[1]->flip^=1;
                swap(ch[1]->ch[0],ch[1]->ch[1]);
            }
        }
        if (add) {
            if (ch[0]!=NULL) {
                ch[0]->val+=add;
                ch[0]->add+=add;
                ch[0]->maxv+=add;
            }
            if (ch[1]!=NULL) {
                ch[1]->val+=add;
                ch[1]->add+=add;
                ch[1]->maxv+=add;
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
    p->val=a[mid];
    p->v=mid;
    p->s=r-l+1;
    p->rank=mid-l+1;
    p->flip=0;
    p->add=0;
    p->maxv=a[mid];
    p->ch[0]=p->ch[1]=NULL;
    if (mid-1>=l) p->ch[0]=build(l,mid-1);
    if (mid+1<=r) p->ch[1]=build(mid+1,r);
    p->maintain();
    return p;
}

int flag;

void InOrder(Node* o) {
    o->pushdown();
    o->maintain();
    if (o->ch[0]!=NULL) InOrder(o->ch[0]);
    if (o->v) {
        printf("%d ",o->val);
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
    splay(left, left->s);
    left->ch[1]=right;
    left->maintain();
    return left;
}

void update(int l,int r,int val) {
    Node *left,*mid,*right,*o;
    split(root,l,left,o);
    split(o,r-l+1,mid,right);
    mid->add+=val;
    mid->val+=val;
    mid->pushdown();
    mid->maintain();
    root=merge(merge(left,mid),right);
}

void reverse(int l,int r) {
    Node *left,*mid,*right,*o;
    split(root,l,left,o);
    split(o,r-l+1,mid,right);
    mid->flip^=1;
    mid->pushdown();mid->maintain();
    root=merge(merge(left,mid),right);
}

void change(int pos,int val) {
    Node *left,*mid,*right,*o;
    split(root,pos,left,o);
    split(o,1,mid,right);
    mid->add=0;
    mid->val=val;
    mid->maxv=val;
    mid->pushdown();
    mid->maintain();
    root=merge(merge(left,mid),right);
}

int query(int l,int r) {
    int ret;
    Node *left,*mid,*right,*o;
    split(root,l,left,o);
    split(o,r-l+1,mid,right);
    mid->pushdown();
    mid->maintain();
    ret=mid->maxv;
    root=merge(merge(left,mid),right);
    return ret;
}

void removetree(Node* &o) {
    if (o==NULL) return ;
    if (o->ch[0]!=NULL) removetree(o->ch[0]);
    if (o->ch[1]!=NULL) removetree(o->ch[1]);
    delete o;
    o=NULL;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    while (SII(n,m)==2) {
        rep(i,1,n) SI(a[i]);
        a[0]=0;
        root=build(0,n);
        // InOrder(root);
        // cout << endl;
        // cout << query(2,4) << endl;
        // change(3,666);
        // InOrder(root);
        // cout << endl;
        // cout << query(2,4) << endl;
        char op;
        int A,B;
        while (m--) {
            cin >> op >> A >> B;
            if (op=='Q') {
                cout << query(A,B) << endl;
            }
            if (op=='U') {
                change(A,B);
            }
        }
        removetree(root);
    }
    return 0;
}