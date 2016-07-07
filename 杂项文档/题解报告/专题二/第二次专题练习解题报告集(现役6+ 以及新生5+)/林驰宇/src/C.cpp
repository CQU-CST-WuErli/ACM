#include<cstdio>
#include<cstring>
#define M 41
using namespace std;
int dp[M][M][M][M];
int cnt[M];
int score[M*10];
int Max(int a,int b){
	return (a>b?a:b);
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
	int n,m,i,j,k,a,b;
	int T;
	scanf("%d",&T);
	//printf("1\n");
	while(T--){
        memset(dp,0,sizeof(dp));
        memset(cnt,0,sizeof(cnt));
        //printf("%d %d %d %d\n",cnt[1],cnt[2],cnt[3],cnt[4]);
        scanf("%d%d",&n,&m);
        //printf("%d %d\n",n,m);
		for(i=1;i<=n;i++){
            //printf("%d",score[i]);
			scanf("%d",&score[i]);
		}

		for(i=1;i<=m;i++){
			scanf("%d",&k);
			//printf("%d ",k);
			cnt[k]++;
		}
		dp[0][0][0][0]=score[1];
		//for(int j=1;j<=4;j++) printf("j = %d cnt = %d\n",j,cnt[j]);
		for(i=0;i<=cnt[1];i++)
			for(j=0;j<=cnt[2];j++)
				for(a=0;a<=cnt[3];a++)
					for(b=0;b<=cnt[4];b++){
						if(i+j+a+b==0)continue;
						int res=0;
						if(i>0)res=Max(res,dp[i-1][j][a][b]);
						if(j>0)res=Max(res,dp[i][j-1][a][b]);
						if(a>0)res=Max(res,dp[i][j][a-1][b]);
						if(b>0)res=Max(res,dp[i][j][a][b-1]);
						int now=1+i+2*j+3*a+4*b;//当前所在的位子
						dp[i][j][a][b]=score[now]+res;
					}
		printf("%d\n",dp[cnt[1]][cnt[2]][cnt[3]][cnt[4]]);

	}
	return 0;
}
