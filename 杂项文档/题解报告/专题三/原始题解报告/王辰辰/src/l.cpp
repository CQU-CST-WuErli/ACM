#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<utility>
#include<sstream>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f;
const int maxn = 1005;

int n, m, ans;
int u[2005], v[2005];
bool vis[1005];

void dfs(int num, int st) {
    if(num > 10) return ;
    for(int i = st; i <= m; i++) {
        if(vis[u[i]] || vis[v[i]]) continue;
        vis[u[i]] = true;
        dfs(num + 1, i + 1);
        vis[u[i]] = false;
        vis[v[i]] = true;
        dfs(num + 1, i + 1);
        vis[v[i]] = false;
        return ;
    }
    ans = min(ans, num);
}

/*
const int MAXN = 1005;
int N, M; //点的个数，点的编号从1到N
bool Graph[MAXN][MAXN];
bool vis[MAXN];
int Match[MAXN];
bool InQueue[MAXN],InPath[MAXN],InBlossom[MAXN];
int Head,Tail;
int Queue[MAXN];
int Start,Finish;
int NewBase;
int Father[MAXN],Base[MAXN];
int Count;//匹配数，匹配对数是Count/2
void CreateGraph() {
    int u, v;
    memset(Graph, false, sizeof(Graph));
    memset(vis, false, sizeof(vis));
    scanf("%d%d", &N, &M);
    for(int i = 1; i <= M; i++) {
        scanf("%d%d", &u, &v);
        vis[u] = vis[v] = true;
        Graph[u][v] = Graph[v][u] = true;
    }
}
void Push(int u) {
    Queue[Tail] = u;
    Tail++;
    InQueue[u] = true;
}
int Pop() {
    int res = Queue[Head];
    Head++;
    return res;
}
int FindCommonAncestor(int u, int v) {
    memset(InPath, false, sizeof(InPath));
    while(true) {
        u = Base[u];
        InPath[u] = true;
        if(u == Start) break;
        u = Father[Match[u]];
    }
    while(true) {
        v = Base[v];
        if(InPath[v])break;
        v = Father[Match[v]];
    }
    return v;
}
void ResetTrace(int u) {
    int v;
    while(Base[u] != NewBase) {
        v = Match[u];
        InBlossom[Base[u]] = InBlossom[Base[v]] = true;
        u = Father[v];
        if(Base[u] != NewBase) Father[u] = v;
    }
}
void BloosomContract(int u, int v) {
    NewBase = FindCommonAncestor(u,v);
    memset(InBlossom, false, sizeof(InBlossom));
    ResetTrace(u);
    ResetTrace(v);
    if(Base[u] != NewBase) Father[u] = v;
    if(Base[v] != NewBase) Father[v] = u;
    for(int tu = 1; tu <= N; tu++) {
        if(InBlossom[Base[tu]]) {
            Base[tu] = NewBase;
            if(!InQueue[tu]) Push(tu);
        }
    }
}

void FindAugmentingPath() {
    memset(InQueue, false, sizeof(InQueue));
    memset(Father, 0, sizeof(Father));
    for(int i = 1; i <= N; i++) Base[i] = i;
    Head = Tail = 1;
    Push(Start);
    Finish = 0;
    while(Head < Tail)  {
        int u = Pop();
        for(int v = 1; v <= N; v++) {
            if(Graph[u][v] && (Base[u] != Base[v]) && (Match[u] != v)) {
                if((v == Start) || ((Match[v] > 0) && Father[Match[v]] > 0))
                    BloosomContract(u,v);
                else if(Father[v] == 0) {
                    Father[v] = u;
                    if(Match[v] > 0)
                        Push(Match[v]);
                    else {
                        Finish = v; return;
                    }
                }
            }
        }
    }
}
void AugmentPath() {
    int u, v, w;
    u = Finish;
    while(u > 0) {
        v = Father[u];
        w = Match[v];
        Match[v] = u;
        Match[u] = v;
        u = w;
    }
}
void Edmonds() {
    memset(Match, 0, sizeof(Match));
    for(int u = 1; u <= N; u++) {
        if(Match[u] == 0) {
            Start = u;
            FindAugmentingPath();
            if(Finish > 0) AugmentPath();
        }
    }
}

void PrintMatch() {
    Count = 0;
    for(int u = 1; u <= N; u++)
        if(Match[u] > 0) Count++;
}
*/

int main()
{
    #ifdef LOCAL
    freopen("C:\\Users\\巍巍\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\巍巍\\Desktop\\out.txt","w",stdout);
    #endif // LOCAL
    /*int t; scanf("%d", &t);

    while(t--) {
        CreateGraph();
        Edmonds();
        PrintMatch();
        int ans = Count / 2;
        //for(int i = 1; i <= N; i++) {
        //    if(!vis[i]) ans++;
        //}
        if(ans > 10)
            printf("Poor lcy\n");
        else
            printf("%d\n", ans);
    }*/

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= m; i++)
            scanf("%d%d", &u[i], &v[i]);
        ans = inf;
        memset(vis, false, sizeof(vis));
        dfs(0, 1);
        if(ans == inf)
            printf("Poor lcy\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}
