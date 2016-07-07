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

#define lson rt<<1
#define rson rt<<1|1

const int N= 100005;
const int INF = 1e9 + 7;

struct Node {
    int l, r;
    long long jj, jo, oj, oo;
    int mid() { return (l + r) >> 1; }
}sum[N << 2];
long long val[N];
int n, m;

void push_up(int rt) {
    sum[rt].jj = max(sum[lson].jj, max(sum[rson].jj, max(sum[lson].jj + sum[rson].oj, sum[lson].jo + sum[rson].jj)));
    sum[rt].oo = max(sum[lson].oo, max(sum[rson].oo, max(sum[lson].oo + sum[rson].jo, sum[lson].oj + sum[rson].oo)));
    sum[rt].jo = max(sum[lson].jo, max(sum[rson].jo, max(sum[lson].jj + sum[rson].oo, sum[lson].jo + sum[rson].jo)));
    sum[rt].oj = max(sum[lson].oj, max(sum[rson].oj, max(sum[lson].oo + sum[rson].jj, sum[lson].oj + sum[rson].oj)));
}

void build(int l, int r, int rt) {
    sum[rt].l = l, sum[rt].r = r;
    sum[rt].jj = sum[rt].jo = sum[rt].oj = sum[rt].oo = -INF;
    if(l == r) {
        if(l & 1) sum[rt].jj =  val[l];
        else sum[rt].oo = val[l];
        return;
    }
    build(l, sum[rt].mid(), lson);
    build(sum[rt].mid() + 1, r, rson);
    push_up(rt);
}
void update(int o, ll v, int rt) {
    if(sum[rt].l == sum[rt].r) {
        if(o & 1) {
            sum[rt].jj = v;
            sum[rt].oo = sum[rt].oj = sum[rt].jo = -INF;
        }
        else {
            sum[rt].oo = v;
            sum[rt].jj = sum[rt].oj = sum[rt].jo = -INF;
        }
        return;
    }
    if(o <= sum[rt].mid()) update(o, v, lson);
    else update(o, v, rson);
    push_up(rt);
}
Node query(int L, int R, int rt) {
    if(L <= sum[rt].l && sum[rt].r <= R) {
    	return sum[rt];
    }
    if(R <= sum[rt].mid()) return query(L, R, lson);
    else if(L > sum[rt].mid()) return query(L, R, rson);
    else {
      	Node ls = query(L, R, lson);
        Node rs = query(L, R, rson);
        Node ret;
        ret.jj = max(ls.jj, max(rs.jj, max(ls.jj + rs.oj, ls.jo + rs.jj)));
        ret.oo = max(ls.oo, max(rs.oo, max(ls.oo + rs.jo, ls.oj + rs.oo)));
        ret.jo = max(ls.jo, max(rs.jo, max(ls.jj + rs.oo, ls.jo + rs.jo)));
        ret.oj = max(ls.oj, max(rs.oj, max(ls.oo + rs.jj, ls.oj + rs.oj)));
        return ret;
    }
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","rt",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int t;
    SI(t);
    int op, x, y;
    while(t--) {
        Node s;
        SII(n, m);
        for(int i = 1; i <= n; i++) scanf("%lld", &val[i]);
        build(1, n, 1);
        while(m--) {
        	SIII(op, x, y);
            if(op == 0) {
                s = query(x, y, 1);
                printf("%lld\n", max(s.jj, max(s.oo, max(s.oj, s.jo))));
            }
            else update(x, y, 1);
        }
    }
    return 0;
}