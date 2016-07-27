struct Dinic
{
    const static int NV=500 * 500 + 501 * 501 + 10;
    const static int NE= NV * 7;
    int source,sink;
    int pnt[NE],nxt[NE],head[NV],cap[NE],cnt;
    int iter[NV],level[NV];
    void init(int s=0,int t=NE) {
        source=s,sink=t;
        cnt=0;
        OFF(head);
    }
    void add_edge(int u,int v,int c) {
        pnt[cnt]=v;nxt[cnt]=head[u];cap[cnt]=c;head[u]=cnt++;
    }
    bool bfs(int s,int t) {
        OFF(level);
        level[s]=0;
        queue<int> q;
        q.push(s);
        while(q.size()) {
            int x=q.front();q.pop();
            for (int i=head[x];~i;i=nxt[i]) {
                int v=pnt[i];
                if (level[v]==-1 && cap[i]) {
                    level[v]=level[x]+1;
                    q.push(v);
                }
            }
        }
        return level[t]!=-1;
    }
    int dfs(int u,int t,int f) {
        if (u==t || !f) return f;
        int left=f;
        for (int i=iter[u];~i;i=nxt[i]) {
            int v=pnt[i];
            if (level[v]==level[u]+1 && cap[i]) {
                int d=dfs(v,t,min(cap[i],left));
                iter[u]=i;
                cap[i]-=d;
                cap[i^1]+=d;
                left-=d;
                if (!left) return f;
            }
        }
        level[u]=-1;
        return f-left;
    }
    int solve(int s,int t) {
        int Max_flow=0;
        while (bfs(s,t)) {
            for (int i=s;i<=t;i++) iter[i]=head[i];
            Max_flow+=dfs(s,t,INF_INT);
        }
        return Max_flow;
    }
}dinic;