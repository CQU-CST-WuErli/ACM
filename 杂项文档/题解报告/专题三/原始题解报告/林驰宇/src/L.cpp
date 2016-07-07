#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
const int M =1005;
bool mark[M];
int deg[M];
vector<int>edge[M];
set<pair<int,int> >st;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        memset(mark,0,sizeof(mark));
        memset(deg,0,sizeof(deg));
        for(int j=1;j<=n;j++) edge[j].clear();
        int ans=0;
        for(int j=1;j<=m;j++){
            int a,b;
            scanf("%d%d",&a,&b);
            edge[a].push_back(b);
            edge[b].push_back(a);
            deg[a]++;
            deg[b]++;
        }
        st.clear();
        for(int j=1;j<=n;j++){
            st.insert(make_pair(deg[j],j));
        }
        if(m){
            for(int j=1;j<=10;j++){
                if(!st.size()) break;
                pair<int,int> now=*st.rbegin();
                st.erase((--st.end()));
                int id=now.second;
                mark[id]=1;
                ans+=now.first;
                if(ans==m){
                    printf("%d\n",j);
                    break;
                }
                for(int k=0;k<edge[j].size();k++){
                    int to=edge[j][k];
                    if(mark[to]) continue;
                    st.erase(st.find(make_pair(deg[to],to)));
                    deg[to]--;
                    st.insert(make_pair(deg[to],to));
                }

            }
            if(ans!=m) printf("Poor lcy\n");
        }
        else printf("0\n");
    }
    return 0;
}
