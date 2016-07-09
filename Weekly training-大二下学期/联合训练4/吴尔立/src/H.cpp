//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2016 CQU_CST_WuErli. All rights reserved.
//
//#pragma comment(linker, "/STACK:102400000,102400000")
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
#define SI(a) scanf("%d", &a)
#define SII(a,b) scanf("%d%d", &a, &b)
#define SIII(a,b,c) scanf("%d%d%d", &a, &b, &c)
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7f7f7f7f;
const int MOD=1e9+7;
const double eps=1e-10;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;


struct SplayTree {
    #define Key_value ch[ch[root][1]][0]
    const static int MAXN = 5001001;
    const static int INF = 0x3f3f3f3f;
    int pre[MAXN], ch[MAXN][2], key[MAXN], size[MAXN];
    int root, tot1;
    int sum[MAXN], rev[MAXN], same[MAXN];
    int lx[MAXN], rx[MAXN], mx[MAXN];//最大子段和相关
    int s[MAXN], tot2;//内存池和容量
    int a[MAXN];//所维护的数组
    int n, q;
    //debug部分**********************************
    void Treavel(int x) {
        if (x) {
            Treavel(ch[x][0]);
            printf("Vertex: %2d: Lson %2d Rson %2d father %2d size = %2d\n", x, ch[x][0], ch[x][1], pre[x], size[x]);
            Treavel(ch[x][1]);
        }
    }
    void debug() {
        printf("root:%d\n", root);
        Treavel(root);
    }
    //以上是debug部分**************************************

    void NewNode(int &r, int father, int k) {
        if(tot2) r = s[tot2--];//取的时候是tot2--,存的时候就是++tot2
        else r = ++tot1;
        pre[r] = father;
        ch[r][0] = ch[r][1] = 0;
        key[r] = k;
        sum[r] = k;
        rev[r] = same[r] = 0;
        lx[r] = rx[r] = mx[r] = k;
        size[r] = 1;
    }
    void Update_Rev(int r) {
        if (!r) return;
        swap(ch[r][0], ch[r][1]);
        swap(lx[r], rx[r]);
        rev[r] ^= 1;
    }
    void Update_Same(int r, int v) {
        if (!r) return;
        key[r] = v;
        sum[r] = v * size[r];
        lx[r] = rx[r] = mx[r] = max(v, v * size[r]);
        same[r] = 1;
    }
    void push_up(int r) {
        int lson = ch[r][0], rson = ch[r][1];
        size[r] = size[lson] + size[rson] + 1;
        sum[r] = sum[lson] + sum[rson] + key[r];
        lx[r] = max(lx[lson], sum[lson] + key[r] + max(0, lx[rson]));
        rx[r] = max(rx[rson], sum[rson] + key[r] + max(0, rx[lson]));
        mx[r] = max(0, rx[lson]) + key[r] + max(0, lx[rson]);
        mx[r] = max(mx[r], max(mx[lson], mx[rson]));
    }
    void push_down(int r) {
        if (same[r]) {
            Update_Same(ch[r][0], key[r]);
            Update_Same(ch[r][1], key[r]);
            same[r] = 0;
        }
        if (rev[r]) {
            Update_Rev(ch[r][0]);
            Update_Rev(ch[r][1]);
            rev[r] = 0;
        }
    }
    void Build(int &x,int l,int r,int father) {
        if(l > r)return;
        int mid = (l + r) >> 1;
        NewNode(x, father, a[mid]);
        Build(ch[x][0], l, mid - 1, x);
        Build(ch[x][1], mid + 1, r, x);
        push_up(x);
    }
    void Init() {
        root = tot1 = tot2 = 0;
        ch[root][0] = ch[root][1] = size[root] = pre[root] = 0;
        same[root] = rev[root] = sum[root] = key[root] = 0;
        lx[root] = rx[root] = mx[root] = -INF;
        NewNode(root, 0, -1);
        NewNode(ch[root][1], root, -1);
        for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
        Build(Key_value, 0, n - 1, ch[root][1]);
        push_up(ch[root][1]);
        push_up(root);
    }
    //旋转,0为左旋，1为右旋
    void Rotate(int x,int kind) {
        int y = pre[x];
        push_down(y);
        push_down(x);
        ch[y][!kind] = ch[x][kind];
        pre[ch[x][kind]] = y;
        if(pre[y])
            ch[pre[y]][ch[pre[y]][1] == y] = x;
        pre[x] = pre[y];
        ch[x][kind] = y;
        pre[y] = x;
        push_up(y);
}
    //Splay调整，将r结点调整到goal下面
    void Splay(int r,int goal) {
        push_down(r);
        while(pre[r] != goal) {
            if(pre[pre[r]] == goal) {
                push_down(pre[r]);
                push_down(r);
                Rotate(r,ch[pre[r]][0] == r);
            }
            else {
                push_down(pre[pre[r]]);
                push_down(pre[r]);
                push_down(r);
                int y = pre[r];
                int kind = ch[pre[y]][0]==y;
                if(ch[y][kind] == r) {
                    Rotate(r,!kind);
                    Rotate(r,kind);
                }
                else {
                    Rotate(y,kind);
                    Rotate(r,kind);
                }
            }
        }
        push_up(r);
        if(goal == 0) root = r;
    }
    int Get_kth(int r, int k) {
        push_down(r);
        int t = size[ch[r][0]] + 1;
        if (t == k) return r;
        if (t > k) return Get_kth(ch[r][0], k);
        else return Get_kth(ch[r][1], k - t);
    }
    // 在第pos个数后面插入tot个数
    void Insert(int pos, int tot) {
        for(int i = 0; i < tot; i++)
            scanf("%d",&a[i]);
        Splay(Get_kth(root, pos + 1), 0);
        Splay(Get_kth(root, pos + 2), root);
        Build(Key_value, 0, tot - 1, ch[root][1]);
        push_up(ch[root][1]);
        push_up(root);
    }
    //删除子树
    void erase(int r) {
        if (!r) return;
        s[++tot2] = r;
        erase(ch[r][0]);
        erase(ch[r][1]);
    }
    //从第pos个数开始连续删除tot个数
    void Delete(int pos, int tot) {
        Splay(Get_kth(root, pos), 0);
        Splay(Get_kth(root, pos + tot + 1), root);
        erase(Key_value);
        pre[Key_value] = 0;
        Key_value = 0;
        push_up(ch[root][1]);
        push_up(root);
    }
    //将从第pos个数开始的连续的tot个数修改为c
    void Make_Same(int pos, int tot, int c) {
        Splay(Get_kth(root, pos), 0);
        Splay(Get_kth(root, pos + tot + 1), root);
        Update_Same(Key_value, c);
        push_up(ch[root][1]);
        push_up(root);
    }
    //将第pos个数开始的连续tot个数进行反转
    void Reverse(int pos, int tot) {
        Splay(Get_kth(root, pos), 0);
        Splay(Get_kth(root, pos + tot + 1), root);
        Update_Rev(Key_value);
        push_up(ch[root][1]);
        push_up(root);
    }
    //得到第pos个数开始的tot个数的和
    int Get_Sum(int pos, int tot) {
        Splay(Get_kth(root, pos), 0);
        Splay(Get_kth(root, pos + tot + 1), root);
        return sum[Key_value];
    }
    //得到第pos个数开始的tot个数中最大的子段和
    int Get_MaxSum(int pos,int tot) {
        Splay(Get_kth(root, pos), 0);
        Splay(Get_kth(root, pos + tot + 1), root);
        return mx[Key_value];
    }
    void InOrder(int r) {
        if (!r) return;
        push_down(r);
        InOrder(ch[r][0]);
        printf("%d ", key[r]);
        InOrder(ch[r][1]);
    }
}T;

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int t; SI(t);
    while(t--) {
        SII(T.n, T.q);
        // cout << T.n << ' ' << T.q << endl;
        T.Init();
        // T.debug();
        for (int i = 1; i <= T.q; i++) {
            int l, r;
            SII(l, r);
            printf("%d\n", T.Get_MaxSum(l, r - l + 1));
        }
    }
    return 0;
}
/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \|     |//  `.
            /  \|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
            佛祖保佑        永无BUG
*/