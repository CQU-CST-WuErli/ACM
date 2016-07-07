#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<utility>
#include<sstream>
using namespace std;
typedef unsigned long long ll;
typedef pair<int,int> P;
const int inf = 0x3f3f3f3f;
const int maxn = 1005;
bool leap[1005];
struct Node{
    ll a;
    int mod;
    Node(ll a = 0,int mod = 0) : a(a),mod(mod){}
};
int main()
{
	#ifdef LOCAL
	freopen("C:\\Users\\ΡΡ\\Desktop\\in.txt","r",stdin);
	//freopen("C:\\Users\\ΡΡ\\Desktop\\out.txt","w",stdout);
	#endif // LOCAL
	int t,n;
	scanf("%d",&t);
	while(t--){
        scanf("%d",&n);
        queue<Node>p;
        p.push(Node(1,1%n));
        memset(leap,false,sizeof(leap));
        leap[1%n] = true;
        while(p.size()){
            Node temp = p.front();p.pop();
            if(temp.mod == 0){
                printf("%llu\n",temp.a);break;
            }
            int mod = (temp.mod*10)%n;
            if(!leap[mod]){
                leap[mod] = true;
                p.push(Node(temp.a*10,mod));
            }
            mod = (temp.mod*10 + 1)%n;
            if(!leap[mod]){
                leap[mod] = true;
                p.push(Node(temp.a*10 + 1,mod));
            }
        }
	}
	return 0;
}
