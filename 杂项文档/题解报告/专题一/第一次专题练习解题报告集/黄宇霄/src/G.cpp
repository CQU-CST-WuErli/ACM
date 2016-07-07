//
//  Created by Running Photon on 2016-05-06
//  Copyright (c) 2015 Running Photon. All rights reserved.
//
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <sstream>
#include <set>
#include <vector>
#include <stack>
#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x,begin())
#define ll long long
#define CLR(x) memset(x, 0, sizeof x)
using namespace std;
const int inf = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 10;
const int maxv = 1e3 + 10;
const double eps = 1e-9;

int n, c;
vector <int> vv;
int num[505];
int vis[5005];
char s[20];
struct Pnt {
    char path[505];
    int mod;
    int size;
    void clear() {
        mod = 0;
        size = 0;
        CLR(path);
    }
    void print() {
        for(int i = 0; i < size; i++) {
            printf("%c", s[path[i]]);
        }
        puts("");
    }
    bool operator< (const Pnt& rhs) const {
        if(size == rhs.size) {
            for(int i = 0; i < size; i++) {
                if(path[i] < rhs.path[i]) return true;
                if(path[i] > rhs.path[i]) return false;
            }
            return false;
        }
        return size < rhs.size;
    }
}ans;
void bfs() {
    queue <Pnt> que;
    Pnt p;
    p.clear();
    ans.clear();
    CLR(vis);
    que.push(p);
    while(que.size()) {
        p = que.front();
        que.pop();

        if(p.mod == 0 && p.size) {
//            p.print();
            if(p < ans || ans.size == 0) {
                memcpy(ans.path, p.path, sizeof p.path);
                ans.size = p.size;
//                ans.print();
            }
            continue;
        }
        if(p.size >= 500) continue;
        if(vis[p.mod]) continue;
        vis[p.mod] = 1;
        for(int i = 0; i < vv.size(); i++) {
            if(p.size == 0 && vv[i] == 0) continue;
            Pnt np;
            np.size = p.size;
            np.mod = (p.mod * c + vv[i]) % n;
            memcpy(np.path, p.path, sizeof p.path);
            np.path[np.size++] = vv[i];
            if(vis[np.mod] && np.mod) continue;
            que.push(np);
        }
    }
}
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
//	ios_base::sync_with_stdio(0);
    int T;
    scanf("%d", &T);

    for(int i = 0; i < 10; i++) s[i] = i + '0';
    s[10] = 'A';
    s[11] = 'B';
    s[12] = 'C';
    s[13] = 'D';
    s[14] = 'E';
    s[15] = 'F';
    while(T--) {
        scanf("%d%d", &n, &c);
        vv.clear();
        int M;
        scanf("%d", &M);
        while(M--) {
            char tmp[2];
            scanf("%s", tmp);
            int r = 0;
            if(isdigit(tmp[0])) {
                r = tmp[0] - '0';
            }
            else {
                r = tmp[0] - 'A' + 10;
            }
            vv.push_back(r);
        }
        sort(ALL(vv));
        if(!n) {
            if(vv[0] == 0)
                puts("0");
            else
                puts("BOMB!!!");
            continue;
        }
        bfs();
        if(!ans.size) puts("BOMB!!!");
        else {
            for(int i = 0; i < ans.size; i++) {
                printf("%c", s[ans.path[i]]);
            }
            puts("");
        }
    }

	return 0;
}
