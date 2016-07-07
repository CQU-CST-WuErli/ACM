#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int a[5][5];
int G[10][10];
int n = 9;

struct node{
	int cas;
	int a[5];
};
node mp[5][5];
void sovle(){
	for (int i=1 ; i<=4 ; i++)
		for (int j=1 ; j<=4 ; j++)
			mp[i][j].cas = 0;
	int now = 1;
	for (int i=1 ; i<4 ; i++)
		for (int j=1 ; j<4 ; j++){
			mp[i][j].a[mp[i][j].cas++] = now;
			mp[i][j+1].a[mp[i][j+1].cas++] = now;
			mp[i+1][j].a[mp[i+1][j].cas++] = now;
			mp[i+1][j+1].a[mp[i+1][j+1].cas++] = now;
			now++;
		}
}

int c[10];
int topo[10],t;
bool dfs(int u){
	c[u] = -1;
	for (int v=1 ; v<=n ; v++) if (G[u][v]){
		if (c[v] < 0) return false;
		else if (!c[v] && !dfs(v)) return false;
	}
	c[u] = 1; topo[--t] = u;
	return true;
}
bool toposort(){
	t = n;
	memset(c,0,sizeof c);
	for (int u = 1; u<=n ; u++) if (!c[u])
		if (!dfs(u)) return false;
	return true;
}
	
int main(){
	int T; cin>>T;
	sovle();
	while (T--){
		memset(G,0,sizeof G);
		for (int i=1 ; i<=4 ; i++)
			for (int j=1 ; j<=4 ; j++){
				cin>>a[i][j];
				for (int now=0 ; now<mp[i][j].cas ; now++)
					if (mp[i][j].a[now] != a[i][j])
						G[a[i][j]][mp[i][j].a[now]]	= 1;
			}
		if (toposort()) printf("Lucky dog!\n");
		else printf("BOOM!\n");	
		
	}
	return 0;
}
