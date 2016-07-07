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

const int inf = 0x7f7f7f7f;

int n, c, t, m;
bool have[20];
bool vis[5100];
int flag;
struct P {
    string num;
    int mod;
};
string ans;

void bfs() {
    queue<P> q;
    P tmp;
    for (int i = 1; i < 16; i++) {
        if (have[i]) {
            vis[i % n] = true;
            tmp.num = "";
            if (i < 10) tmp.num = i + '0';
            else tmp.num = i + 'A' - 10;
            tmp.mod = i % n;
            q.push(tmp);
        }
    }
    while (q.size()) {
        tmp = q.front(); q.pop();
        if (flag == 1 && (tmp.num.size() > ans.size())) continue;
        if (tmp.mod == 0) {
            if (flag == -1) {
                flag = 1;
                ans = tmp.num;
            }
            else {
                if (ans.size() > tmp.num.size() || (ans.size() == tmp.num.size() && ans > tmp.num))
                    ans = tmp.num;
            }
        }
        P tt;
        for (int i = 0; i < 16; i++) {
            if (have[i]) {
                tt = tmp;
                if (i < 10)
                    tt.num +=  i+'0';
                else
                    tt.num += i+'A'-10;
                tt.mod = (tmp.mod * c + i) % n;
                if ((tt.num.size() <= 500 && !vis[tt.mod]) || tt.mod == 0) {
                    vis[tt.mod] = true;
                    q.push(tt);
                }
            }
        }
    }
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    SI(t);
    while (t--) {
        SIII(n, c, m);
        CLR(have);
        CLR(vis);
        flag = -1;
        ans.clear();
        char tmp[4];
        for (int i=0; i<m; i++) {
            scanf("%s", tmp);
            if (tmp[0] >= '0' && tmp[0] <= '9') have[tmp[0]-'0'] = true;
            else have[tmp[0] - 'A' + 10] = true;
        }
        if (n == 0) {
            if (have[0]) puts("0");
            else puts("BOMB!!!");
        }
        else {
            bfs();
            if (flag == -1) puts("BOMB!!!");
            else cout << ans << endl;
        }
    }
    return 0;
}