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
struct node {
    int a, b, c;
    bool operator != (const node& x) const {
        return !(x.a == a && x.b == b && x.c == c);
    }
};
node step[505][5005];
pair<int, char>A[20];
int n, c, m;
queue<node>Q;
void dfs(node& a) {
    //printf("len = %d mod = %d insert = %c\n",a.a,a.b,A[a.c].second);
    if(a.a == 0) return;
    node &b = step[a.a][a.b];
    dfs(step[a.a][a.b]);
    printf("%c", A[b.c].second);
}
void bfs() {
    while(!Q.empty()) Q.pop();
    memset(step, -1, sizeof(step));
    //printf("%d %d %d\n",step[1][1].a,step[1][1].b,step[1][1].c);
    step[0][0] = (node) {0, 0, 0};
    Q.push(step[0][0]);
    node now;
    while(!Q.empty()) {
        now = Q.front(); Q.pop();
        if(now.a > 500) break;
        //printf("111\n");
        if(now.a != 0 && now.b == 0) break;
        for(int j = 1; j <= m; j++) {
            if(now.a == 0 && A[j].first == 0) continue;
            int len = now.a + 1, mod = (now.b * c + A[j].first) % n;
            if(step[len][mod] != (node) { -1, -1, -1}) continue;
            //printf("%d %d %d %d\n",len,now.a,now.b,mod);
            step[len][mod] = (node) {now.a, now.b, j};
            Q.push((node) {len, mod, j});
        }
    }
    //printf("%d\n",step[2][11]);
    //printf("now.a = %d\n",now.a);
    //printf("%d %d\n",now.a,now.b);
    if(now.a != 0 && now.b == 0) {
        dfs(now);
        printf("\n");
    } else printf("BOMB!!!\n");
}
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d", &n, &c, &m);
        for(int j = 1; j <= m; j++) {
            char s[2];
            scanf("%s", s);
            if(isdigit(s[0])) A[j].first = s[0] - '0';
            else A[j].first = s[0] - 'A' + 10;
            if(A[j].first == 14) A[j].first = 15;
            else if(A[j].first == 15) A[j].first = 14;
            if(A[j].first >= c) {
                j--; m--;
                continue;
            }
            A[j].second = s[0];
        }
        sort(A + 1, A + 1 + m);
        printf("m = %d\n",m);
        if(n) bfs();
        else {
            if(A[1].first == 0) printf("0\n");
            else printf("BOMB!!!\n");
        }
    }
    return 0;
}
