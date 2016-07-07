/*  ^^ ====== ^^ 
ID: meixiuxiu
PROG: test
LANG: C++11
*/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <cctype>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int ,int> pii;
#define MEM(a,b) memset(a,b,sizeof a)
#define CLR(a) memset(a,0,sizeof a);
#define pi acos(-1.0)
#define maxn 40000
#define maxv 100005
const int inf = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
//#define LOCAL
bool yes[7][7][7][7][7][7];
int trans[7][7][7][7][7][7][7][8];
int dp[2][7][7][7][7][7][7][7];
//状态位置，状态结果，状态值
int a[10];
int b[10];
bool stop(){
    if(!a[a[7]])return 1;
    if(a[7]+1<=6 && a[7]-1>=1 && a[a[7]+1]==a[a[7]-1] && a[a[7]]==a[a[7]-1]){
            return 0;
    }
    else if(a[7]+1<=6 && a[a[7]+1]==a[a[7]]){
            return 0;
    }
    else if(a[7]-1>=1 && a[a[7]-1]==a[a[7]]){
            return 0;
    }
    return 1;
}
void init(){
    // 优化判断是否当前情况满足条件
    for(int i=0;i<=5;i++){
        a[1] = i;
        for(int j=0;j<=5;j++){
            a[2] = j;
            for(int k=0;k<=5;k++){
                a[3] = k;
                for(int t=0;t<=5;t++){
                    a[4] = t;
                    for(int s=0;s<=5;s++){
                        a[5] = s;
                        for(int r=0;r<=5;r++){
                            a[6] = r;
                            int ok = 1;
                            for(int p=2;p<=6;p++){ 
                                if(a[p]==a[p-1] && a[p]>=1 &&  a[p]<=4)ok = 0;
                            }
                            if(ok){
                                yes[a[1]][a[2]][a[3]][a[4]][a[5]][a[6]]=1;
                            }
                        }
                    }

                }
            }
        }
    }
   // 转移优化
    for(int i=0;i<=5;i++){
        a[1] = i,b[1] = i;
        for(int j=0;j<=5;j++){
            a[2] = j,b[2] = j;
            for(int k=0;k<=5;k++){
                a[3] = k,b[3] = k;
                for(int t=0;t<=5;t++){
                    a[4] = t,b[4] = t;
                    for(int s=0;s<=5;s++){
                        a[5] = s,b[5] = s;
                        for(int r=0;r<=5;r++){
                            a[6] = r,b[6] = r;
                            for(int p=1;p<=6;p++){
                                a[7] = p,b[7] = p;
                                int add = 0;
                                if(!a[a[7]])continue;
                                //if(b[1]==5 && b[2]==5 && b[3]==0 && b[4]==0 && b[5]==0 && b[6]==0 && b[7]==1)cout <<"yes\n";
                                int cnt = 0;
                                while(!stop()){  
                                    if(a[7]+1<=6 && a[7]-1>=1 && a[a[7]+1]==a[a[7]-1] && a[a[7]]==a[a[7]-1]){
                                        add += 3*pow(2,a[a[7]]);
                                        a[a[7]-1]=0;
                                        a[a[7]+1]=0;
                                        if(a[a[7]]<=4)a[a[7]]++;
                                        else a[a[7]]=0;
                                    }
                                    else if(a[7]+1<=6 && a[a[7]+1]==a[a[7]]){
                                        //if(b[1]==5 && b[2]==5 && b[3]==0 && b[4]==0 && b[5]==0 && b[6]==0 && b[7]==1)cout <<"yes\n";
                                        add += 2*pow(2,a[a[7]]);
                                        a[a[7]+1]=0;
                                        if(a[a[7]]<=4)a[a[7]]++;
                                         else a[a[7]]=0;
                                    }
                                    else if(a[7]-1>=1 && a[a[7]-1]==a[a[7]]){
                                        add+=2*pow(2,a[a[7]]);
                                        a[a[7]-1]=0;
                                        if(a[a[7]]<=4)a[a[7]]++;
                                        else a[a[7]]=0;
                                    }
                                    else break;
                                }
                                for(int q=1;q<=6;q++){
                                    trans[b[1]][b[2]][b[3]][b[4]][b[5]][b[6]][b[7]][q] = a[q];
                                    a[q] = b[q]; 
                                }
                                a[7]=b[7];
                                trans[b[1]][b[2]][b[3]][b[4]][b[5]][b[6]][b[7]][7] = add;
                            }
                        }
                    }
                }
            }
        }
    }
}
int x1,x2,x3,x4,x5,x6,x7,x8;
void solve(int p1,int p2,int p3,int p4,int p5,int p6,int p7,int p8){
    x1 = trans[p1][p2][p3][p4][p5][p6][p7][1];
    x2 = trans[p1][p2][p3][p4][p5][p6][p7][2];
    x3 = trans[p1][p2][p3][p4][p5][p6][p7][3];
    x4 = trans[p1][p2][p3][p4][p5][p6][p7][4];
    x5 = trans[p1][p2][p3][p4][p5][p6][p7][5];
    x6 = trans[p1][p2][p3][p4][p5][p6][p7][6];
    x7 = p8;
    x8 = trans[p1][p2][p3][p4][p5][p6][p7][7];
}
int main()
{
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
//	freopen("out.txt","w",stdout);
#endif
    int t;cin >>t;
    init();
    while(t--){
        int n,d;
        cin >> n >> d;
        string s;cin >> s;
        MEM(dp,-1);
        int nmax = 0;
        //cout << trans[5][5][0][0][0][0][1][7]<< endl;
        dp[0][0][0][0][0][0][0][0]=0;
        for(int i=1;i<=d;i++){
            int now = s[i-1]-'0';
            int p1,p2,p3,p4,p5,p6,p7;
            int max1,max2,max3,max4,max5,max6,max7;
            for(p1=0;p1<=5;p1++){
                a[1]=p1;
                for(p2=0;p2<=5;p2++){
                    a[2]=p2;
                    for(p3=0;p3<=5;p3++){
                        a[3]=p3;
                        if(n<4)max4 = 0;
                        else max4 = 5;
                        for(p4=0;p4<=max4;p4++){
                            a[4]=p4;
                            if(n<5)max5 =0;
                            else max5 =5;
                            for(p5=0;p5<=max5;p5++){
                                a[5]=p5;
                                if(n<6)max6 = 0;
                                else max6 = 5;
                                for(p6=0;p6<=max6;p6++){
                                    a[6]=p6;
                                    for(p7=0;p7<=5;p7++){
                                        a[7]=p7;
                                        if(dp[(i-1)%2][p1][p2][p3][p4][p5][p6][p7]==-1)continue;
                                        if(!yes[p1][p2][p3][p4][p5][p6])continue;
                                        //放当前的
                                        for(int p8=1;p8<=n;p8++){
                                            if(!a[p8]){
                                                if(p8==1){
                                                    solve(now,p2,p3,p4,p5,p6,1,p7);
                                                    dp[i%2][x1][x2][x3][x4][x5][x6][x7] = max(dp[(i-1)%2][p1][p2][p3][p4][p5][p6][p7]+x8,dp[i%2][x1][x2][x3][x4][x5][x6][x7]);
                                                    nmax = max(nmax,dp[i%2][x1][x2][x3][x4][x5][x6][x7]);
                                                }    
                                                if(p8==2){
                                                    solve(p1,now,p3,p4,p5,p6,2,p7);
                                                    dp[i%2][x1][x2][x3][x4][x5][x6][x7] = max(dp[(i-1)%2][p1][p2][p3][p4][p5][p6][p7]+x8,dp[i%2][x1][x2][x3][x4][x5][x6][x7]);
                                                    nmax = max(nmax,dp[i%2][x1][x2][x3][x4][x5][x6][x7]);
                                                }
                                                if(p8==3){
                                                    solve(p1,p2,now,p4,p5,p6,3,p7);
                                                    dp[i%2][x1][x2][x3][x4][x5][x6][x7] = max(dp[(i-1)%2][p1][p2][p3][p4][p5][p6][p7]+x8,dp[i%2][x1][x2][x3][x4][x5][x6][x7]);
                                                    nmax = max(nmax,dp[i%2][x1][x2][x3][x4][x5][x6][x7]);
                                                }
                                                if(p8==4){
                                                    solve(p1,p2,p3,now,p5,p6,4,p7);
                                                    dp[i%2][x1][x2][x3][x4][x5][x6][x7] = max(dp[(i-1)%2][p1][p2][p3][p4][p5][p6][p7]+x8,dp[i%2][x1][x2][x3][x4][x5][x6][x7]);
                                                    nmax = max(nmax,dp[i%2][x1][x2][x3][x4][x5][x6][x7]);
                                                }
                                                if(p8==5){
                                                    solve(p1,p2,p3,p4,now,p6,5,p7);
                                                    dp[i%2][x1][x2][x3][x4][x5][x6][x7] = max(dp[(i-1)%2][p1][p2][p3][p4][p5][p6][p7]+x8,dp[i%2][x1][x2][x3][x4][x5][x6][x7]);
                                                    nmax = max(nmax,dp[i%2][x1][x2][x3][x4][x5][x6][x7]);
                                                }
                                                if(p8==6){
                                                    solve(p1,p2,p3,p4,p5,now,6,p7);
                                                    dp[i%2][x1][x2][x3][x4][x5][x6][x7] = max(dp[(i-1)%2][p1][p2][p3][p4][p5][p6][p7]+x8,dp[i%2][x1][x2][x3][x4][x5][x6][x7]);
                                                    nmax = max(nmax,dp[i%2][x1][x2][x3][x4][x5][x6][x7]);
                                                }
                                            }
                                        }
                                        //放牛背
                                        if(!p7){
                                           // cout << i << endl;
                                            dp[i%2][p1][p2][p3][p4][p5][p6][now] = max(dp[(i-1)%2][p1][p2][p3][p4][p5][p6][p7],dp[i%2][p1][p2][p3][p4][p5][p6][now]);
                                            nmax = max(nmax,dp[i%2][p1][p2][p3][p4][p5][p6][now]);
                                        }
                                        //牛背和当前换
                                        if(p7){
                                            swap(now,p7);
                                            for(int p8=1;p8<=n;p8++){
                                                if(!a[p8]){
                                                    if(p8==1){
                                                        solve(now,p2,p3,p4,p5,p6,1,p7);
                                                        dp[i%2][x1][x2][x3][x4][x5][x6][x7] = max(dp[(i-1)%2][p1][p2][p3][p4][p5][p6][now]+x8,dp[i%2][x1][x2][x3][x4][x5][x6][x7]);
                                                        nmax = max(nmax,dp[i%2][x1][x2][x3][x4][x5][x6][x7]);
                                                    }    
                                                    if(p8==2){
                                                        solve(p1,now,p3,p4,p5,p6,2,p7);
                                                        dp[i%2][x1][x2][x3][x4][x5][x6][x7] = max(dp[(i-1)%2][p1][p2][p3][p4][p5][p6][now]+x8,dp[i%2][x1][x2][x3][x4][x5][x6][x7]);
                                                        nmax = max(nmax,dp[i%2][x1][x2][x3][x4][x5][x6][x7]);
                                                    }
                                                    if(p8==3){
                                                        solve(p1,p2,now,p4,p5,p6,3,p7);
                                                        dp[i%2][x1][x2][x3][x4][x5][x6][x7] = max(dp[(i-1)%2][p1][p2][p3][p4][p5][p6][now]+x8,dp[i%2][x1][x2][x3][x4][x5][x6][x7]);
                                                        nmax = max(nmax,dp[i%2][x1][x2][x3][x4][x5][x6][x7]);
                                                    }
                                                    if(p8==4){
                                                        solve(p1,p2,p3,now,p5,p6,4,p7);
                                                        dp[i%2][x1][x2][x3][x4][x5][x6][x7] = max(dp[(i-1)%2][p1][p2][p3][p4][p5][p6][now]+x8,dp[i%2][x1][x2][x3][x4][x5][x6][x7]);
                                                        nmax = max(nmax,dp[i%2][x1][x2][x3][x4][x5][x6][x7]);
                                                    }
                                                    if(p8==5){
                                                        solve(p1,p2,p3,p4,now,p6,5,p7);
                                                        dp[i%2][x1][x2][x3][x4][x5][x6][x7] = max(dp[(i-1)%2][p1][p2][p3][p4][p5][p6][now]+x8,dp[i%2][x1][x2][x3][x4][x5][x6][x7]);
                                                        nmax = max(nmax,dp[i%2][x1][x2][x3][x4][x5][x6][x7]);
                                                    }
                                                    if(p8==6){
                                                        solve(p1,p2,p3,p4,p5,now,6,p7);
                                                        dp[i%2][x1][x2][x3][x4][x5][x6][x7] = max(dp[(i-1)%2][p1][p2][p3][p4][p5][p6][now]+x8,dp[i%2][x1][x2][x3][x4][x5][x6][x7]);
                                                        nmax = max(nmax,dp[i%2][x1][x2][x3][x4][x5][x6][x7]);
                                                    }
                                                }
                                            }
                                            swap(now,p7);
                                        } 
                                    }
                                }
                            }
                        }
                    }
                }
            }
            MEM(dp[(i-1)%2],-1);
        }
       // cout << d%2 << endl;
        
        for(int p1=0;p1<=5;p1++){a[1] = p1;
            for(int p2=0;p2<=5;p2++){a[2] = p2;
                for(int p3=0;p3<=5;p3++){a[3] =p3;
                    for(int p4=0;p4<=5;p4++){a[4] = p4;
                        for(int p5=0;p5<=5;p5++){a[5] = p5;
                            for(int p6=0;p6<=5;p6++){a[6] = p6;
                               for(int p7=0;p7<=5;p7++){
                                    if(dp[d%2][p1][p2][p3][p4][p5][p6][p7]==-1)continue;
                                   // else cout << "ye"<< endl;
                                    if(!p7){
                                        nmax = max(nmax,dp[d%2][p1][p2][p3][p4][p5][p6][p7]);
                                    }
                                    else{
                                        int now = p7;
                                        for(int p8=1;p8<=n;p8++){
                                            if(!a[p8]){
                                                if(p8==1){
                                                    solve(now,p2,p3,p4,p5,p6,1,0);
                                                    nmax = max(dp[d%2][p1][p2][p3][p4][p5][p6][p7]+x8,nmax);
                                                }    
                                                if(p8==2){
                                                    solve(p1,now,p3,p4,p5,p6,2,0);
                                                    nmax = max(dp[d%2][p1][p2][p3][p4][p5][p6][p7]+x8,nmax);
                                                    
                                                }
                                                if(p8==3){
                                                    solve(p1,p2,now,p4,p5,p6,3,0);
                                                    nmax = max(dp[d%2][p1][p2][p3][p4][p5][p6][p7]+x8,nmax);
                                                    
                                                }
                                                if(p8==4){
                                                    solve(p1,p2,p3,now,p5,p6,4,0);
                                                    nmax = max(dp[d%2][p1][p2][p3][p4][p5][p6][p7]+x8,nmax);
                                                    
                                                }
                                                if(p8==5){
                                                    solve(p1,p2,p3,p4,now,p6,5,0);
                                                    nmax = max(dp[d%2][p1][p2][p3][p4][p5][p6][p7]+x8,nmax);
                                                    
                                                }
                                                if(p8==6){
                                                    solve(p1,p2,p3,p4,p5,now,6,0);
                                                    nmax = max(dp[d%2][p1][p2][p3][p4][p5][p6][p7]+x8,nmax);
                                                }
                                            }
                                        }
                                    } 
                                }
                            }
                        }
                    }
                }
            }
        } 
        cout << nmax << endl;
    }
	return 0;
}

















