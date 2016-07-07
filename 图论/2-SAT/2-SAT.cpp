struct TowSAT {
	const static int NE=5e6;  // edge
	const static int NV=2020;   // node
	int n;
	int pnt[NE],nxt[NE],head[NV];
	int cnt;
	void add_edge(int u,int v) {
		pnt[cnt]=v;nxt[cnt]=head[u];head[u]=cnt++;
	}

	int low[NV],pre[NV],dfs_clock;
	int sccno[NV],scc_cnt;
	stack<int> S;
	int inS[NV];

	void init(int _n) {
		n=_n;
		cnt=dfs_clock=scc_cnt=0;
		OFF(head);
		CLR(pre);
		CLR(sccno);
		while (S.size()) S.pop();
		CLR(inS);
	}

	int dfs(int u) {
		low[u]=pre[u]=++dfs_clock;
		S.push(u);inS[u]=1;
		for (int i=head[u];~i;i=nxt[i]) {
			int v=pnt[i];
			if (!pre[v]) {
				low[v]=dfs(v);
				low[u]=min(low[u],low[v]);
			}
			else if (inS[v])
				low[u]=min(low[u],pre[v]);
		}
		if (low[u]==pre[u]) {
			scc_cnt++;
			for (int v;v!=u;) {
				v=S.top();S.pop();
				inS[v]=0;
				sccno[v]=scc_cnt;
			}
		}
		return low[u];
	}
	int solve() {
		rep(i,0,2*n-1) if (!pre[i]) dfs(i);
	    rep(i,0,n-1) if (sccno[i<<1]==sccno[i<<1|1]) return 0;
	    return 1;
	}
}sat;

// get solution

int col[NV];
	int s[NV];
	int pos;
	bool DFS(int u) {
		if (col[u]==B) return false;
		if (col[u]==R) return true;
		col[u]=R;
		col[u^1]=B;
		s[pos++]=u;
		for (int i=head[u];~i;i=nxt[i]) {
			int v=pnt[i];
			if (!DFS(v)) return false;
		}
		return true;
	}
	bool getSolution() {
		memset(col,0,sizeof col);
		pos=0;
		rep(i,0,2*n-1) {
			if (col[i]) continue;
			pos=0;
			if (!DFS(i)){
				for (int j=0;j<pos;j++) col[s[j]]=col[s[j]^1]=0;
				if (!DFS(i^1)) return false;
			}
		}
		return true;
	}