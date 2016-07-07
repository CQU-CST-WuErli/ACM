//=================================splay model================================
// Use removetree() to minimal memory
struct Node {
    Node* ch[2];
    int rank;// 当前节点在序列中的位置
    int s;// 节点总数
    int flip;// 旋转标记
    int add;// 增减标记
    int val;// 节点的值
    int v;  // 原数组中下标
    Node() {
        rank=1;
        s=1;
        flip=0;
        add=0;
        ch[0]=ch[1]=NULL;
    }
    int cmp(int x) const {
        if (x==rank) return -1;
        return x<rank? 0 : 1;
    }
    void maintain(){
        s=1;
        rank=1;
        if (ch[0]!=NULL) {
            s+=ch[0]->s;
            rank+=ch[0]->s;
        }
        if (ch[1]!=NULL) {
            s+=ch[1]->s;
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
            }
            if (ch[1]!=NULL) {
                ch[1]->val+=add;
                ch[1]->add+=add;
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

void change(int pos,int val) {
    Node *left,*mid,*right,*o;
    split(root,pos,left,o);
    split(o,1,mid,right);
    mid->add=0;
    mid->val=val;
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


//================以下用的少=============================//
void insert(int x,int P) {
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

void remove(int x) {
    Node *left,*mid,*right,*o;
    split(root,x,left,o);
    split(o,1,mid,right);
    delete mid;
    root=merge(left,right);
}

void removetree(Node* &o) {
    if (o==NULL) return ;
    if (o->ch[0]!=NULL) removetree(o->ch[0]);
    if (o->ch[1]!=NULL) removetree(o->ch[1]);
    delete o;
    o=NULL;
}