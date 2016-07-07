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
typedef long long ll;
typedef pair<int,int> P;
const int inf = 0x3f3f3f3f;
const int maxn = 1005;
int len,tot;
char s[200100];
int p[200100];
int ch[105536][2];
ll pow_mod(ll a,ll n,ll mod){
    if(n == 0)return 1;
    ll ans = pow_mod(a,n/2,mod);
    ans = ans*ans%mod;
    if(n%2)
        ans = ans*a%mod;
    return ans;
}
int work1(){
    int maxx = -1;
    for(int i = 1;i <= len;i++)
        maxx = max(maxx,p[i]);
    ll llen = len;
    llen = llen*llen*llen;
    return pow_mod(maxx,llen,maxx/3*5 + 1) + maxx*4/5;
}
int query(int x){
    int root = 0;
    int ans = 0;
    for(int i = 16;i >= 0;i--){
        int b = (x >> i) & 1;
        if(ch[root][b ^ 1] != -1){
            ans = ans + (1 << i);
            root = ch[root][b ^ 1];
        }
        else
            root = ch[root][b];
    }
    return ans;
}
void add(int x){
    int root = 0;
    for(int i = 16;i >= 0;i--){
        int b = (x >> i) & 1;
        if(ch[root][b] == -1)
            ch[root][b] = tot++;
        root = ch[root][b];
    }
}
int work2(){
    int idx = 0;
    int ans = -1;
    memset(ch,-1,sizeof(ch));
    tot = 1;
    add(0);
    for(int i = 1;i <= len;i++){
        idx = idx ^ p[i];
        ans = max(ans,query(idx));
        add(idx);
    }
    return ans;
}
int main()
{
	#ifdef LOCAL
	freopen("C:\\Users\\ΡΡ\\Desktop\\in.txt","r",stdin);
	//freopen("C:\\Users\\ΡΡ\\Desktop\\out.txt","w",stdout);
	#endif // LOCAL
	int t;
	scanf("%d",&t);
	while(t--){
        scanf("%s",s);
        len = strlen(s);
        for(int i = len;i >= 0;i--){
            s[i*2 + 2] = s[i];
            s[i*2 + 1] = '#';
        }
        s[0] = '*';
        int id = 0,maxlen = 0;
        for(int i = 2;i < 2*len + 1;i++){
            if(p[id] + id > i)p[i] = min(p[id*2 - i],p[id] + id - i);
            else
                p[i] = 1;
            while(s[i - p[i]] == s[i + p[i]])p[i]++;
            if(id + p[id] < i + p[i])id = i;
            maxlen = max(maxlen,p[i]);
        }
        for(int i = 1;i <= len;i++)
            p[i] = p[i*2] - 1;
        int ans1 = work1();
        int ans2 = work2();
        if(ans1 > ans2)
            printf("liujc\n");
        else
            printf("luoxinchen\n");
	}
	return 0;
}
