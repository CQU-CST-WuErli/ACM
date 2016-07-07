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
const int maxn = 5e5+10;
const int maxm = 2e6+10;
struct Node{
   int u,v,val;
   bool operator <(const Node A)const{return val < A.val;}
}mp[maxn];
int f[maxn];
int Find(int x)
{
	 if (f[x]!=x) return f[x]=Find(f[x]);
	 return f[x];
}
bool Unit(int x, int y)
{
	int t1=Find(x);
	int t2=Find(y);
	if (t1!=t2) f[t1]=t2;
	else return true;
	return false;
}

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
         cin>>n>>m;
         for (int i = 0; i < m; i++)
             cin>>mp[i].u>>mp[i].v>>mp[i].val;

       sort(mp,mp+m);
       int Max = -inf;
       bool ok = false;
       for(int i = 0; i <= n; i++) f[i] =i;
       for(int i = 0; i < m ; i++)
       {
           if(Max < mp[i].val) Max = mp[i].val;
           if (Unit(mp[i].u,mp[i].v)) {ok = true;break;}
       }
       if (ok) cout<<Max<<"\n";
       else cout<<"No solution!\n";
    }
	return 0;
}
