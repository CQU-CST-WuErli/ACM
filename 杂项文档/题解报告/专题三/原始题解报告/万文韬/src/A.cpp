#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
const int maxn = 500 + 5;
int map[maxn][maxn];
int in[maxn],out[maxn],du[maxn],f[maxn],sum[maxn],n,m,u,v;

int find(int x){
        if(f[x] == x) return x;
        return f[x] = find(f[x]);
}

void unit(int a,int b){
        int fa = find(a),fb = find(b);
        if(fa != fb){
                f[fb] = fa;
                sum[fa]+=(sum[fb] + 1);
        }
}

int main(){
        int T;scanf("%d",&T);
        while(T--){
                memset(sum,0,sizeof sum);
                memset(in,0,sizeof in);
                memset(out,0,sizeof out);
                memset(du,0,sizeof du);
                memset(map,0,sizeof map);
                scanf("%d%d",&n,&m);
                for(int i = 1;i <= n;i++) f[i] = i;
                while(m--){
                        scanf("%d%d",&u,&v);
                        du[u]++;du[v]++;
                        in[u]++;out[v]++;
                        map[u][v] = 1;
                        map[v][u] = 1;
                        unit(u,v);
                }
                int flagto = 0;
                for(int i = 1;i <= n;i++){
                        if(sum[i] == n - 1) break;
                        else if(i == n){
                                puts("No No");
                                flagto = 1;
                        }
                }
                if(flagto) continue;
                //puts("ds");
                int jidu = 0;
                for(int i = 1;i <= n;i++){
                        if(du[i] % 2){
                                jidu++;
                        }
                }
                if(jidu == 2 || !jidu) printf("Yes ");
                else printf("No ");
                int shao = 0,duo = 0,flag = 0;
                for(int i = 1;i <= n;i++){
                        if(in[i] != out[i]){
                                if(abs(in[i] - out[i]) != 1){
                                        puts("No");
                                        flag = 1;
                                        break;
                                }
                                else{
                                        if((in[i] - out[i]) == 1) shao++;
                                        else duo++;
                                }
                        }
                }
                if(!flag){
                        if(!shao && !duo) puts("Yes");
                        else if(shao == 1 && duo == 1) puts("Yes");
                        else puts("No");
                }
        }
        return 0;
}
