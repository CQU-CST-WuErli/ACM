// SOJ ���ţ��ü�(����ͼ����).cpp : �������̨Ӧ�ó������ڵ㡣
//

#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
const int MAXN = 1e4 + 10;
const int MAXM = 1e5 + 10;
struct Edge{
	int to, next;
	bool cut;//�Ƿ�Ϊ��
}edge[MAXM];
int head[MAXM];
int tot;
int low[MAXN];
int dfn[MAXN];
int Stack[MAXN];
int Index;
int top;
int Instack[MAXN];
int cut[MAXN];
int add_block[MAXN];//ɾ��һ��������ӵ���ͨ��
int bridge;
void addedge(int u, int v){
	edge[tot].to = v;
	edge[tot].next = head[u];
	edge[tot].cut = false;
	head[u] = tot++;
}
void tarjan(int u, int pre){
	int v;
	low[u] = dfn[u] = ++Index;
	Stack[top++] = u;
	Instack[u] = true;
	int son = 0;
	for (int i = head[u]; i != -1; i = edge[i].next){
		v = edge[i].to;
		if (i / 2 == pre / 2)continue;
		if (!dfn[v]){
			++son;
			tarjan(v, i);
			if (low[u] > low[v])low[u] = low[v];
			//��
			//һ�������(u,v)����,���ҽ���(u,v)Ϊ��֦��,������dfs(u)<low(v)
			if (low[v] > dfn[u]){
				++bridge;
				edge[i].cut = true;
				edge[i ^ 1].cut = true;
			}
		}
		else if (low[u] > dfn[v]){
			low[u] = dfn[v];
		}
	}
	//����,��֦������1
	if (u == pre&&son > 1)cut[u] = true;
	if (u == pre)add_block[u] = son - 1;
	Instack[u] = false;
	top--;
}
void init(){
	memset(dfn, 0, sizeof dfn);
	memset(Instack, 0, sizeof Instack);
	memset(add_block, 0, sizeof add_block);
	memset(cut, false, sizeof cut);
	memset(head, -1, sizeof head);
	tot = 0;
	Index = top = 0;
	bridge = 0;
}
int solve(int N){
	for (int i = 1; i <= N; ++i){
		if (!dfn[i])tarjan(i, -2);
	}
	//��
	return bridge;
}
int t;
int n, m;
int main()
{
	cin >> t;
	int kase = 0;
	while (t--){
		++kase;
		init();
		cin >> n >> m;
		while (m--){
			int u, v;
			cin >> u >> v;
			addedge(u, v);
			addedge(v, u);
		}
		int ans = solve(n);
		cout << "Case " << kase << ": " << ans << endl;
	}
	return 0;
}

