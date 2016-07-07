#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
#include<cctype>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<iomanip>
#include<sstream>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int N= 500000;
const int maxn = 1e4+10;
int mp[10][10];
int main(){
#ifdef LOCAL
	freopen("C:\\Users\\lanjiaming\\Desktop\\acm\\in.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
ios_base::sync_with_stdio(0);
    int T,n,m;
    cin>>T;
    while(T--)
    {
       for(int i = 1; i <= 4; i++)
        for(int j = 1; j <= 4; j++)
          cin>>mp[i][j];
       if (mp[1][1] != 1 || mp[1][4] != 3 || mp[4][1] != 7 || mp[4][4] != 9)
            { cout<<"BOOM!\n"; continue; }
       bool ok = true;
       int cnt = 0;
       for(int i = 1; i <= 3; i++)
       {
        for(int j = 2;j <= 3; j++)
        {
            cnt++;
          if (mp[i][j] == cnt && mp[i+1][j] == cnt+1 ||mp[i][j] == cnt+1 && mp[i+1][j] == cnt)
          {
              ok = false;
              break;
          }
        }
        cnt++;
       }
       cnt = 0;
       for(int i = 2;i <= 3; i++)
        for(int j = 2;j <= 4; j++)
        {
           cnt++;
          if (mp[i][j] == cnt && mp[i][j-1] == cnt+3 ||mp[i][j] == cnt+3 && mp[i][j-1] == cnt)
          {
              ok = false;
              break;
          }
        }

       if (!ok) cout<<"BOOM!\n";
       else cout<<"Lucky dog!\n";
    }
	return 0;
}
