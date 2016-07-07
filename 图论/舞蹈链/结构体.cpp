struct Node {
	int right,left,down,up;
	int size;
	int x,y;
};

struct DLX {
	const static int maxn=10000;
	Node p[maxn];
	int size;
	int head[100];
	int vis[100];
	stack<int> Ans;
	int ans;
	void init(int m) {
		for (int i=0;i<=m;i++) {
			p[i].up=p[i].down=i;
			p[i].left=i-1;p[i].right=i+1;
			p[i].size=0;
		}
		p[0].left=m;p[m].right=0;
		OFF(head);
		size=m+1;
		ans=-1;
		while (Ans.size()) Ans.pop();
	}
	void link(int row,int col) {
		p[size].x=row;p[size].y=col;p[col].size++;
		p[size].up=p[col].up;p[size].down=col;
		p[p[col].up].down=size;p[col].up=size;
		if (head[row]<0) head[row]=p[size].left=p[size].right=size;
		else {
			p[size].right=head[row];p[size].left=p[head[row]].left;
			p[p[size].left].right=size;p[p[size].right].left=size;
		}
		size++;
	}
	// exact cover
	void remove(int c) {
		p[p[c].right].left=p[c].left;
		p[p[c].left].right=p[c].right;
		for (int i=p[c].down;i!=c;i=p[i].down) {
			for (int j=p[i].right;j!=i;j=p[j].right) {
				p[p[j].down].up=p[j].up;
				p[p[j].up].down=p[j].down;
				p[p[j].y].size--;
			}
		}
	}
	void resume(int c) {
		p[p[c].left].right=c;
		p[p[c].right].left=c;
		for (int i=p[c].up;i!=c;i=p[i].up) {
			for (int j=p[i].left;j!=i;j=p[j].left) {
				p[p[j].down].up=j;
				p[p[j].up].down=j;
				p[p[j].y].size++;
			}
		}

	}
	bool dfs(int cnt) {
		if (ans!=-1) return true;
		if (p[0].right==0) {
			ans=cnt;
			return true;
		}
		int c=0;
		int Min=INF_INT;
		for (int i=p[0].right;i!=0;i=p[i].right)
			if (Min>p[i].size) Min=p[i].size,c=i;
		remove(c);
		for (int i=p[c].down;i!=c;i=p[i].down) {
			Ans.push(p[i].x);
			for (int j=p[i].right;j!=i;j=p[j].right) {
				remove(p[j].y);
			}
			if (dfs(cnt+1)) return true;
			for (int j=p[i].left;j!=i;j=p[j].left) {
				resume(p[j].y);
			}
			Ans.pop();
		}
		resume(c);
		return false;
	}
	// exact cover ends;
	// multiple cover
	void del(int c) {
		for (int i=p[c].down;i!=c;i=p[i].down) {
			p[p[i].right].left=p[i].left;
			p[p[i].left].right=p[i].right;
		}
	}
	void rec(int c) {
		for (int i=p[c].up;i!=c;i=p[i].up) {
			p[p[i].right].left=i;
			p[p[i].left].right=i;
		}
	}
	int h() {
		int ret=0;
		CLR(vis);
		for (int i=p[0].right;i!=0;i=p[i].right) if (!vis[i]) {
			ret++;vis[i]=1;
			for (int j=p[i].down;j!=i;j=p[j].down)
				for (int k=p[j].right;k!=j;k=p[k].right)
					vis[p[k].y]=1;
		}
		return ret;
	}
	void DFS(int cnt) {
		if (p[0].right==0) ans=min(ans,cnt);
		else if (h()+cnt<ans) {
			int c=0;
			int Min=INF_INT;
			for (int i=p[0].right;i!=0;i=p[i].right){
				if (p[i].size<Min) Min=p[i].size,c=i;
			}
			// lookln(c);
			for (int i=p[c].down;i!=c;i=p[i].down) {
				del(i);
				for (int j=p[i].right;j!=i;j=p[j].right) del(j);
				DFS(cnt+1);
				// BUG;
				for (int j=p[i].left;j!=i;j=p[j].left) rec(j);
				rec(i);
			}
		}
		return;
	}
	// multiple cover ends;
}dlx;
