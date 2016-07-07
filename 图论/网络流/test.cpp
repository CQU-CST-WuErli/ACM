#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

const int maxn =20005;
const int inf=0x3f3f3f3f;

struct Edge
{
    int v,cap,nxt;
};
int first[maxn],tot;
Edge edge[200*maxn];
int n,m;
int S,T;
void addedge(int u, int v, int cap)
{
    edge[tot]=Edge{v,cap,first[u]};
    first[u]=tot++;
    edge[tot]=Edge{u,0, first[v]};
    first[v]=tot++;
}

struct Val{
    int fir,sec;
    int emp;
};

Val mp[200][200];
int r[200][200],c[200][200],bel[200][200];
int row[10000],col[10000];
Val turn(char s[8])
{
    Val ret;
    if(s[0]=='X' || s[0]=='.') ret.fir=-1;
    else{
        int tmp=0;
        for(int i=0; i<3; i++){
            tmp=tmp*10+s[i]-'0';
        }
        ret.fir=tmp;
    }
    if(s[4]=='X'||s[4]=='.') ret.sec=-1;
    else{
        int tmp=0;
        for(int i=0; i<3; i++){
            tmp=tmp*10+s[i+4]-'0';
        }
        ret.sec=tmp;
    }
    ret.emp= (s[0]=='.'&&s[4]=='.');
    return ret;
}

void init()
{
    tot=0;
    memset(first, -1, sizeof(first));

    char s[8];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            scanf("%s", s);
            mp[i][j]=turn(s);
        }
    }

    S=0,T=n*m+1;
    int rowc=1,colc=1;
    int cnt=1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            Val cur=mp[i][j];
            if(cur.emp){
                continue;
            }
            if(cur.sec!=-1){
                int ed=j+1;
                while(ed<=m && mp[i][ed].emp) r[i][ed]=rowc,ed++;
                row[rowc]=cnt++;
                addedge(0, row[rowc++], cur.sec-(ed-j-1));
            }

            if(cur.fir!=-1){
                int ed=i+1;
                while(ed<=n && mp[ed][j].emp) c[ed][j]=colc,ed++;
                col[colc]=cnt++;
                addedge(col[colc++], T, cur.fir-(ed-i-1));
            }
        }
    }
    memset(bel, -1, sizeof(bel));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++)
        if(mp[i][j].emp){
            addedge(row[r[i][j]], col[c[i][j]], 8);
            bel[i][j]=tot-2;
        }
    }

}



int d[maxn];
int que[maxn*100], head,tail;
void bfs(int s)
{
    memset(d, inf, sizeof(d));
    d[s]=0;
    head=0;tail=-1;
    que[++tail]=s;

    while(tail+1!=head){
        int u=que[head++];

        for(int i=first[u]; i!=-1; i=edge[i].nxt){
            int v=edge[i].v, c=edge[i].cap;
            if(d[v]!=inf || !c) continue;
            d[v]=d[u]+1;
            que[++tail]=v;
        }
    }

}

int cur[maxn];
int dfs(int u, int T, int f)
{
    if(u==T) return f;

    for(int &i=cur[u]; i!=-1; i=edge[i].nxt){
        int v=edge[i].v, c=edge[i].cap, r=i^1;
        if(d[v]!=d[u]+1 || !c) continue;
        int tmp=dfs(v, T, min(c,f));
        if(tmp){
            edge[i].cap-=tmp;
            edge[r].cap+=tmp;
            return tmp;
        }
    }
    return 0;
}



int dinic(int S, int T)
{
    int ret=0;
    while(true){
        bfs(S);
        if(d[T]==inf) break;

        for(int i=0; i<=T; i++) cur[i]=first[i];
        int f=inf;
        while( (f=dfs(S,T,f))>0) ret+=f;
    }
    return ret;
}

int ans[maxn][maxn];

int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int cas=1;
    while(cin>>n>>m){
        init();
        int t=dinic(S, T);
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                int p=n+m+j+(i-1)*m;
                if(bel[i][j]==-1){
                    ans[i][j]=0;
                    continue;
                }
                ans[i][j]=9-edge[bel[i][j]].cap;
            }
        }
		cout << "t=" << t << endl;
//		for (int i=1;i<=n;i++) {
//			for (int j=1;j<=m;j++) cout << bel[i][j] << ' ';
//			cout << endl;
//		}
		cout << "tot=" << tot << endl;
//        for(int i=1; i<=n; i++){
//            for(int j=1; j<=m; j++){
//                if(!ans[i][j])
//                    putchar('_');
//                else printf("%d", ans[i][j]);
//                putchar(j==m?'\n':' ');
//            }
//        }

    }
    return 0;
}

