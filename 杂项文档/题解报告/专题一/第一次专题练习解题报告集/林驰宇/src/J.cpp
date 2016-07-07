#pragma comment(linker, "/STACK:102400000,102400000")
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<list>
#define LL long long
#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
using namespace std;
const int M = 1e5 + 5;
char s[M * 2];
int p[M * 2], P[M];
int n;
struct trie {
    int ch[M * 100][2];
    int root, L;
    int newnode() {
        ch[L][0] = ch[L][1] = -1;
        return L++;
    }
    void init() {
        L = 0;
        root = newnode();
    }
    void insert(int x) {
        int now = root;
        for(int j = 30; j >= 0; j--) {
            int go = (x & (1 << j)) ? 1 : 0;
            if(ch[now][go] == -1) {
                ch[now][go] = newnode();
                now = ch[now][go];
            } else now = ch[now][go];
        }
    }
    int query(int x) {
        int now = root;
        int ans = 0;
        for(int j = 30; j >= 0; j--) {
            int go = (x & (1 << j)) ? 1 : 0;
            //printf("%d %d %d\n",j,go,ch[now][!go]);
            if(ch[now][!go] != -1) ans |= (1 << j), now = ch[now][!go];
            else now = ch[now][go];
        }
        //printf("ans = %d\n",ans);
        return ans;
    }
} trie;
void manacher() {
    for(int j = n; j >= 0; j--) {
        s[j * 2 + 2] = s[j];
        s[j * 2 + 1] = '#';
    }
    s[0] = '*';
    int id = 0;
    for(int j = 2; j < 2 * n + 1; j++) {
        if(p[id] + id > j) p[j] = min(p[id] + id - j, p[2 * id - j]);
        else p[j] = 1;
        while(s[j - p[j]] == s[j + p[j]]) p[j]++;
        if(p[id] + id < p[j] + j) id = j;
    }
    for(int j = 0; j < 2 * n + 1; j++) {
        if(s[j] != '#' && s[j] != '*') P[j / 2 - 1] = p[j]-1;
    }
}
int _pow(int x, LL y, int mod) {
    int res = 1;
    while(y) {
        if(y & 1) res = 1LL * res * x % mod;
        x = 1LL * x * x % mod;
        y >>= 1;
    }
    return res;
}
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%s", s);
        n = strlen(s);
        manacher();
        int maxx = 0;
        for(int j = 0; j < n; j++) maxx = max(P[j], maxx);
        LL y = 1LL * n * n * n, mod = maxx / 3 * 5 + 1;
        int jd = _pow(maxx, y, mod) + maxx * 4 / 5;

        trie.init();
        int now = 0, fjd = 0;
        trie.insert(0);
        for(int j = 0; j < n; j++) {
            //printf("j = %d P = %d\n",j,P[j]);
            now ^= P[j];
            fjd = max(fjd, trie.query(now));
            trie.insert(now);
        }
        if(jd > fjd) printf("liujc\n");
        else printf("luoxinchen\n");
    }
    return 0;
}
