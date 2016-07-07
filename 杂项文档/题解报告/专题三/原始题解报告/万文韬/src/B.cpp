#include <cstdio>
#include <cstring>
int num[9][2] = {0,0,0,1,0,2,1,0,1,1,1,2,2,0,2,1,2,2};
int aim[9][9],sign[9],map[9][9];

bool check(){
        for(int i = 0;i < 4;i++){
                for(int j = 0;j < 4;j++) if(map[i][j] != aim[i][j]) return false;
        }
        return true;
}
int dfs(int cur){
        if(cur == 9) return 0;
        for(int i = 0;i < 9;i++){
                if(sign[i]) continue;
                for(int j = num[i][0];j < num[i][0] + 2;j++){
                        for(int k = num[i][1];k < num[i][1] + 2;k++){
                                map[j][k] = i + 1;
                        }
                }
               /* for(int i = 0;i < 4;i++){
                        for(int j = 0;j < 4;j++) printf("%d",map[i][j]);
                        puts("");
                }
                puts("");
                */
                if(check()) return 1;
                sign[i] = 1;
                if(dfs(cur + 1)) return 1;
                sign[i] = 0;
        }
        return 0;
}


int main(){
        int t;scanf("%d",&t);
        while(t--){
                memset(sign,0,sizeof sign);
                memset(map,0,sizeof map);
                for(int i = 0;i < 4;i++){
                        for(int j = 0;j < 4;j++) scanf("%d",&aim[i][j]);
                }
                if(dfs(0)) puts("Lucky dog!");
                else puts("BOOM!");
        }

        return 0;
}

