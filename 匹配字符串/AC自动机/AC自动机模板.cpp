struct AcAutoMaton
{
	const static int maxn=5e4+10;
    const static int maxv=200;
	int cnt,root;
	int ID_cnt;
	map<char,int> ID;
	int have[maxn],fail[maxn];
	int nxt[maxn][maxv];
	void init() {
		cnt=ID_cnt=0;
		ID.clear();
		root=newNode();
	}
	int newNode() {
		for (int i=0;i<128;i++) {
			nxt[cnt][i]=-1;
		}
		have[cnt++]=0;
		return cnt-1;
	}
	int getID(char c) {
		int ret=(int)c;
		// lookln(ret);
		return ret;
	}
	void insert(char buf[],int pos) {
		int len=strlen(buf);
		int now=root;
		for (int i=0;i<len;i++) {
			int id=getID(buf[i]);
			if (nxt[now][id]==-1) nxt[now][id]=newNode();
			now=nxt[now][id];
		}
		have[now]=pos;
	}
	void build() {
		fail[root]=root;
		queue<int> q;
		for (int i=0;i<128;i++) {
			if (nxt[root][i]==-1) {
				nxt[root][i]=root;
			}
			else {
				fail[nxt[root][i]]=root;
				q.push(nxt[root][i]);
			}
		}
		while (!q.empty()) {
			int u=q.front();q.pop();
			for (int i=0;i<128;i++) {
				int& v=nxt[u][i];
				if (v==-1) {
					v=nxt[fail[u]][i];
				}
				else {
					fail[v]=nxt[fail[u]][i];
					q.push(v);
				}
			}
		}
	}
	void find(char buf[]) {
		int len=strlen(buf);
		int now=root;
		for (int i=0;i<len;i++) {
			int id=getID(buf[i]);
			now=nxt[now][id];
			int tmp=now;
			while (tmp!=root) {
				if (have[tmp]) ans[have[tmp]]++;
				tmp=fail[tmp];
			}
		}
	}
}ac;