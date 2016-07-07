#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 501;
int n,m;
int edge[maxn][maxn];
int u[maxn*(maxn+1)/2],v[maxn],in[maxn],out[maxn];
int mp[maxn][maxn];
int vis[maxn];
int visit[maxn][maxn];

int check(){
	int flag = 0;
	if ((in[1]-out[1]==1 && in[n]-out[n]==-1)
		||(in[1]-out[1]==-1 && in[n]-out[n]==1)
		||(in[1]==out[1]&&in[n]==out[n]))
			flag = 1;
	for (int i=2 ; i<=n-1 ; i++) {
		if (in[i]!=out[i]) {
			flag = 0;
			break;
		}
	}
	return flag;
}
void dfs1(int x){
	for (int i=1 ; i<=n ; i++){
		if (vis[i]==-1 && mp[x][i]==1){
			vis[i] = 1;
			dfs1(i);
		}
		if (i==n) break;
		
	}
}
void dfs2(int x,int y){
	for (int i=1 ; i<=n ; i++){
		if (visit[y][i]==-1 && mp[y][i]==1){
			visit[y][i] = 1;
			dfs2(y,i);
		}
		if (i==n) break;
	}
}
int main(){
	int T; cin>>T;
	while (T--){
		cin>>n>>m;
		if (n==1 && m==0) {
			printf("Yes Yes\n");
			continue;
		}
		memset(edge,0,sizeof edge);
		for (int i=0 ; i<m ; i++){
			cin>>u[i]>>v[i];
			edge[u[i]][v[i]] = 1;
		}
		for(int i=1; i<=n; i++) {
    		in[i] = 0;
    		for(int j=1; j<=n; j++) in[i] += edge[i][j];
		}
		for(int i=1; i<=n; i++) {
    		out[i] = 0;
    		for(int j=1; j<=n; j++) out[i] += edge[j][i];
		}
		memset(mp,0,sizeof mp);
		for (int i=0 ; i<m ; i++) mp[u[i]][v[i]] = mp[v[i]][u[i]] = 1;
		memset(vis,-1,sizeof vis); memset(visit,-1,sizeof visit);
		int lalala=1,hahaha=1; 
		vis[u[0]]=1; dfs1(u[0]);
		visit[u[0]][v[0]]=1; dfs2(u[0],v[0]);
		for (int i=1 ; i<=n ; i++){
			if (vis[i]<0){
				lalala = 0;
				break;
			}
		}
		for (int i=0 ; i<m ; i++){
			if (visit[u[i]][v[i]]<0){
				hahaha = 0;
				break;
			}
		}
		int sum = 0;
		for (int i=1 ; i<=n ; i++)
			if ((in[i]+out[i])%2) sum++;
		if ((sum==0 || sum==2)&&(lalala==1)&&(hahaha==1)) cout<<"Yes ";
		else cout<<"No ";
		memset(mp,0,sizeof mp);
		for (int i=0 ; i<m ; i++) mp[u[i]][v[i]] = 1;
		memset(vis,-1,sizeof vis); memset(visit,-1,sizeof visit);
		lalala=1; hahaha=1;
		vis[u[0]]=1; dfs1(u[0]);
		visit[u[0]][v[0]]=1; dfs2(u[0],v[0]);
		for (int i=1 ; i<=n ; i++) if (vis[i]<0){
			lalala = 0;
			break;
		}
		for (int i=0 ; i<m ; i++){
			if (visit[u[i]][v[i]]<0){
				hahaha = 0;
				break;
			}
		}		
		if (check()==1 && lalala==1 && hahaha==1) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
