//
//  Created by  CQU_CST_WuErli
//  Copyright (c) 2015 CQU_CST_WuErli. All rights reserved.
//
// #include<bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <sstream>
#define CLR(x) memset(x,0,sizeof(x))
#define OFF(x) memset(x,-1,sizeof(x))
#define MEM(x,a) memset((x),(a),sizeof(x))
#define ALL(x) x.begin(),x.end()
#define AT(i,v) for (auto &i:v)
#define For_UVa if (kase!=1) cout << endl
#define BUG cout << "I am here" << endl
#define lookln(x) cout << #x << "=" << x << endl
#define look(x) cout << #x << "=" << x
#define SI(a) scanf("%d",&a)
#define SII(a,b) scanf("%d%d",&a,&b)
#define SIII(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define root 1,n,1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define BigInteger bign
const int MAX_L=2005;// For BigInteger
const int INF_INT=0x3f3f3f3f;
const long long INF_LL=0x7fffffff;
const int MOD=1e9+7;
const double eps=1e-9;
const double pi=acos(-1);
typedef long long  ll;
using namespace std;

const int N=2e5+10;
const int M=10010;
int pnt[N],head[M],nxt[N],cap[N];
int cnt;
int iter[M],level[M];

struct P{
	int id;                 // 0-> black   1-> white
	int right,below;
}mp[110][110];
int ans[110][110];
int n,m;
int source,sink;

int ID(int i,int j){
	return (i-1)*n+j;
}

void read_data(){
	string tmp;
	CLR(mp);
	source=0;sink=m*n+1;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++){
			cin >> tmp;
			if (tmp[3]=='X') {
				mp[i][j].id=0;
				mp[i][j].below=mp[i][j].right=0;
			}				
			else if (tmp[3]=='\\') {
				mp[i][j].id=0;
				if (tmp[0]=='X') mp[i][j].below=0;
				else {
					int tt=0;
					for (int k=0;k<3;k++) tt=tt*10+tmp[k]-'0';
					mp[i][j].below=tt;
				}
				if (tmp[4]=='X') mp[i][j].right=0;
				else {
					int tt=0;
					for (int k=4;k<7;k++) tt=tt*10+tmp[k]-'0';
					mp[i][j].right=tt;
				}
			}
			else if (tmp[3]='.') {
				mp[i][j].id=1;
				mp[i][j].below=mp[i][j].right=0;
			}
		}
	}	
}

void add_edge(int u,int v,int c) {
	pnt[cnt]=v;nxt[cnt]=head[u];head[u]=cnt;
	cap[cnt++]=c;
}

// source -> kind A -> kind B -> kind C -> sink
// kind A : have a sum in a line -> right>0
// kind B : the white grid
// kind C : have a sum in a row -> below>0

void build_graph(){
	OFF(head);cnt=0;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			P tmp=mp[i][j];
			if (tmp.id==0) {
				ans[i][j]=-1;
				if (tmp.right){
					int kk=0;
					for (int k=j+1;k<=m;k++) {
						if (mp[i][k].id==1) kk++;
						else break;
					}
					add_edge(source,ID(i,j),tmp.right-kk);
					add_edge(ID(i,j),source,0);
					for (int k=j+1;k<=m;k++) {
						int u=ID(i,j),v=ID(i,k);
						if (mp[i][k].id==1) {
							add_edge(u,v,8);
							add_edge(v,u,0);
						}else break; 
					}
				}
				if (tmp.below) {
					int kk=0;
					for (int k=i+1;k<=n;k++) {
						if (mp[k][j].id==1) kk++;
						else break;
					}
					add_edge(ID(i,j),sink,tmp.below-kk);
					add_edge(sink,ID(i,j),0);
					for (int k=i+1;k<=n;k++) {
						if (mp[k][j].id==1) {
							int u=ID(k,j),v=ID(i,j);
							ans[k][j]=cnt;
							add_edge(u,v,8);
							add_edge(v,u,0);
						}else break;					
					}
				}
			}
		}
	}
}

bool bfs(int s,int t){
	OFF(level);
	queue<int> q;
	q.push(s);
	level[s]=0;
	while (!q.empty()){
		int x=q.front();q.pop();
		for (int i=head[x];~i;i=nxt[i]){
			int v=pnt[i];
			if (level[v]==-1 && cap[i]){
				level[v]=level[x]+1;
				q.push(v);
			}
		}
	}
	return level[t]!=-1;
}

int dfs(int u,int t,int Flow){
	if (u==t) return Flow;
	int left=Flow;
	for (int i=iter[u];~i;i=nxt[i]){
		int v=pnt[i];
		if (level[v]==level[u]+1 && cap[i]){
			int d=dfs(v,t,min(left,cap[i]));
			left-=d;
			iter[u]=i;
			cap[i]-=d;
			cap[i^1]+=d;
			if (!left) return Flow;
		}
	}
	level[u]=-1;
	return Flow-left;
}

int Dinic(int s,int t){
	int Max_flow=0;
	while (bfs(s,t)){
		for (int i=s;i<=t;i++) iter[i]=head[i];
		Max_flow+=dfs(s,t,INF_INT);
	}
	return Max_flow;
}

void print_ans(){
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			if (ans[i][j]==-1) cout << '_';
			else {
				cout << 9-cap[ans[i][j]] ;
			}
			putchar(j==m?'\n':' ');
		}
	}
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
	while (cin >> n >> m){
		getchar();
		read_data();
		build_graph();
		int tmp=Dinic(source,sink);
		lookln(tmp);
//		for (int i=1;i<=n;i++) {
//			for (int j=1;j<=m;j++) cout << ans[i][j] << ' ';
//			cout << endl;
//		}
		print_ans();
//		for (int i=head[ID(4,3)];~i;i=nxt[i]){
//			int v=pnt[i];
//			cout << cap[i] << endl;
//		}
	}
	return 0;
}

