#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int maxn = 10001;
const int maxm = 20001;

int n,m;
vector<int> G[maxn];

struct Edge{
	int u,v;
	bool flag;
}e[maxm];

int pre[maxn],low[maxn];  
int dfs_clock;  
void tarjan(int u,int fa){  
    low[u] = pre[u] = ++dfs_clock;  
    for(int i=0 ; i<G[u].size() ; i++){  
        int v = G[u][i];  
        if(v == fa) continue;  
        if(!pre[v]){  
            tarjan(v,u);  
            low[u] = min(low[u],low[v]);  
        }  
        else low[u] = min(low[u],pre[v]);  
    }  
} 
int main(){
	int T; cin>>T;
	for (int cas=1 ; cas<=T ; cas++){
		printf("Case %d: ",cas);
		cin>>n>>m;
		dfs_clock = 0;
		memset(pre,0,sizeof pre);
		for (int i=1 ; i<=n ; i++) G[i].clear();
		for (int i=0 ; i<m ; i++){
			e[i].flag = false;
			cin>>e[i].u>>e[i].v;
			int x = e[i].u, y = e[i].v;
			G[x].push_back(y);
			G[y].push_back(x);
		}
		tarjan(1,-1);
		int ok = 1;
		for (int i=1 ; i<=n ; i++)
			if (!pre[i]){
			ok = 0;
			break;
		}
		if (ok==0) cout<<"0"<<endl;
		else {
			int ans = 0;
			for (int i=0 ; i<m ; i++){
				int u = e[i].u, v = e[i].v;
				if (low[u]>pre[v] || low[v]>pre[u])
					ans++;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
