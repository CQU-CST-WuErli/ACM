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
typedef pair<int,int> Point;
const int maxn = 1e4;
const int maxm = 1e6+10;
struct TwoSAT
{
    int n;
    vector<int> G[maxn*2];
    bool mark[maxn*2];
    int S[maxn*2],c;

    bool dfs(int x){
        if(mark[x^1]) return 0;
        if(mark[x]) return 1;
        mark[x] = 1;
        S[c++] = x;
        for (int i = 0; i < G[x].size(); ++i)
            if(!dfs(G[x][i])) return 0;
        return 1;
    }

    void init(int n){
        this->n = n;
        for (int i = 0; i < n*2; ++i)
            G[i].clear();
        memset(mark,0,sizeof(mark));
    }

    void addedge(int x,int xval,int y,int yval){
        x = x * 2 + xval;
        y = y * 2 + yval;
        G[x^1].push_back(y);
        G[y^1].push_back(x);
    }

    bool solve(){
        for (int i = 0; i < n*2; i += 2)
            if(!mark[i] && !mark[i+1]){
                c = 0;
                if(!dfs(i)){
                    while(c > 0) mark[S[--c]] = 0;
                    if(!dfs(i+1))
                        return 0;
                }
            }
        return 1;
    }
};

TwoSAT TSAT;
Point p1,p2,P[maxn];
pair<int,int> hate[maxm],like[maxm];

int n,A,B,Dis;

int dis(Point P,Point Q){return abs(P.first-Q.first)+abs(P.second-Q.second);}

bool work(int mid){
    TSAT.init(n);
    for (int i = 0; i < A; ++i){
        TSAT.addedge(hate[i].first,0,hate[i].second,0);
        TSAT.addedge(hate[i].first,1,hate[i].second,1);
    }
    for (int i = 0; i < B; ++i){
        TSAT.addedge(like[i].first,0,like[i].second,1);
        TSAT.addedge(like[i].first,1,like[i].second,0);
    }
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j){
            int i0 = dis(P[i],p1),
                i1 = dis(P[i],p2),
                j0 = dis(P[j],p1),
                j1 = dis(P[j],p2);
            if(i0+j0>mid)
                TSAT.addedge(i,1,j,1);
            if(i1+j1>mid)
                TSAT.addedge(i,0,j,0);
            if(i0+Dis+j1>mid)
                TSAT.addedge(i,1,j,0);
            if(i1+Dis+j0>mid)
                TSAT.addedge(i,0,j,1);
        }
    return TSAT.solve();
}

int main(){
#ifdef LOCAL
	freopen("C:\\Users\\lanjiaming\\Desktop\\acm\\in.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
ios_base::sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>A>>B;
        cin>>p1.first>>p1.second>>p2.first>>p2.second;
        Dis=dis(p1,p2);
        for (int i = 0; i < n; ++i)
            cin>>P[i].first>>P[i].second;

        for (int i = 0; i < A; ++i)
        {
            cin>>hate[i].first>>hate[i].second;
            hate[i].first--;
            hate[i].second--;
        }
        for (int i = 0; i < B; ++i)
        {
            cin>>like[i].first>>like[i].second;
            like[i].first--;
            like[i].second--;
        }

        if(!work(maxm))
        {
            cout<<-1<<endl;
            continue;
        }

        int l = 0,r = maxm,ans;
        while(l < r)
        {
            int mid = (l+r)>>1;
            if (work(mid)) {r = mid ;ans = mid;}
            else l = mid+1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
