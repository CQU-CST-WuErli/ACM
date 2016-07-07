// SOJ An Easy Problem.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cstdio>
#include<cmath>
#include<stack>
using namespace std;
int t;
int n, m;
const int MAXN = 1e3 + 10;
const int MAXM = 1e6 + 10;
vector<int>grap[MAXN]; //ϡ��ͼ�����ڽӱ��ʾͼ
stack<int>S;
vector<int>map[MAXN];//������ͼ
int low[MAXN]; //low[u] Ϊu��u�������ܹ�׷�ݵ��������ջ�нڵ�Ĵ�����
int num[MAXN]; //num[u] Ϊu�����Ĵ�����(ʱ���)
int visited[MAXN];  //����Ƿ��Ѿ���������
int instack[MAXN]; //����Ƿ���ջ��
int indexs; //�����ǰ����
int cnt_scc;   //��¼�ܹ���ͼ���ɶ��ٸ���
int belong[MAXN];  //belong[i] = j ��ʾԭͼ�ĵ�i�����Ϊ��j
//��ʼ��
void init(int n)
{
	for (int i = 0; i <= n; i++)
	{
		grap[i].clear();
		map[i].clear();
	}
	while (!S.empty())
	{
		S.pop();
	}
	memset(instack, 0, sizeof(instack));
	memset(visited, 0, sizeof(visited));
	memset(low, -1, sizeof(low));
	memset(num, -1, sizeof(num));
	memset(belong, -1, sizeof(belong));
	indexs = 0;
	cnt_scc = 0;
}
//�ҳ���ͨ��֧��������
void tarjan(int v)
{
	low[v] = num[v] = ++indexs;
	S.push(v);
	instack[v] = 1;
	visited[v] = 1;

	for (int i = 0; i<grap[v].size(); i++)
	{
		int w = grap[v][i];
		if (!visited[w])
		{
			tarjan(w);
			low[v] = min(low[v], low[w]);  //v��v�������ܹ�׷�ݵ��������ջ�нڵ�Ĵ�����
		}
		else if (instack[w])  //(v,w)Ϊ�����
		{
			low[v] = min(low[v], num[w]);
		}
	}
	int u;
	if (low[v] == num[v])  //����ǿ��ͨ��֧����,��������
	{
		++cnt_scc;
		do
		{
			u = S.top();
			belong[u] = cnt_scc;  //����
			S.pop();
			instack[u] = 0;    //��ջ������
		} while (u != v);
	}
}
/*
* �������㷨�ڽӱ���ʽ
* ʹ��ǰ��init()���г�ʼ������uN��ֵ
* �ӱ�ʹ�ú���addedge(u,v)
*
*/
struct Edge {
	int to, next;
}edge[MAXM];
int head[MAXN], tot;
void init2() {
	tot = 0;
	memset(head, -1, sizeof(head));
}
void addedge(int u, int v) {
	edge[tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot++;
}
int linker[MAXN];
bool used[MAXN];
int uN;
bool dfs(int u) {
	for (int i = head[u]; i != -1; i = edge[i].next){
		int v = edge[i].to;
		if (!used[v]){
			used[v] = true;
			if (linker[v] == -1 || dfs(linker[v])){
				linker[v] = u;
				return true;
			}
		}
	}
	return false;
}
int hungary(){
	int res = 0;
	memset(linker, -1, sizeof(linker));
	for (int u = 0; u < uN; u++){//��ı��0~uN-1
		memset(used, false, sizeof(used));
		if (dfs(u))res++;
	}
	return res;
}
int ans;
bool viss[MAXN];
int maps[MAXN][MAXN];
void dfs2(int u, int fa){
	viss[u] = 1;
	for (int i = head[u]; i != -1; i = edge[i].next){
		int v = edge[i].to;
		if (!viss[v]){
			if (!maps[fa][v]){
				addedge(fa, v);
				maps[fa][v] = 1;
			}
			dfs2(v, fa);
		}
	}
}
int main()
{
	scanf("%d", &t);
	int kase = 0;
	while (t--){
		scanf("%d%d", &n, &m);
		init(n);
		init2();
		while (m--)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			grap[a].push_back(b);
		}
		for (int i = 1; i <= n; i++)
		{
			if (!visited[i])
			{
				tarjan(i);
			}
		}
		//���¹�ͼ
		uN = cnt_scc;
		for (int i = 1; i <= n; ++i){
			for (int j = 0; j < grap[i].size(); ++j){
				int k = grap[i][j];
				if (belong[i] != belong[k]){
					addedge(belong[i] - 1, belong[k] - 1);
					maps[belong[i] - 1, belong[k] - 1];
				}
			}
		}
		memset(maps, 0, sizeof maps);
		for (int i = 0; i < cnt_scc; ++i){
			memset(viss, 0, sizeof viss);
			dfs2(i, i);
		}
		ans = cnt_scc - hungary();
		printf("Case %d: %d\n", ++kase, ans);
	}
	return 0;
}

