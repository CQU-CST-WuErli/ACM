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
const int maxn = 500100;
int wa[maxn],wb[maxn],wv[maxn],ww[maxn],ran[maxn];
int h[maxn],a[maxn],sa[maxn],ss[maxn];
int sum[maxn],ans[maxn],con[maxn],id[maxn];
char s[maxn];
int cmp(int *r,int a,int b,int l) {
    return r[a] == r[b] && r[a + l] == r[b + l];
}
void getsa(int *r,int *sa,int n,int m) {
    int i,j,p,*x = wa,*y = wb,*t;
    for(i = 0;i < m;i++) ww[i] = 0;
    for(i = 0;i < n;i++) ww[x[i] = r[i]]++;
    for(i = 1;i < m;i++) ww[i] += ww[i - 1];
    for(i = n - 1;i >= 0;i--) sa[--ww[x[i]]] = i;
    for(j = 1,p = 1;p < n;j *= 2,m = p){
        for(p = 0,i = n - j;i < n;i++) y[p++] = i;
        for(i = 0;i < n;i++) if(sa[i] >= j) y[p++] = sa[i] - j;
        for(i = 0;i < n;i++) wv[i] = x[y[i]];
        for(i = 0;i < m;i++) ww[i] = 0;
        for(i = 0;i < n;i++) ww[wv[i]]++;
        for(i = 1;i < m;i++) ww[i] += ww[i - 1];
        for(i = n - 1;i >= 0;i--) sa[--ww[wv[i]]] = y[i];
        for(t = x,x = y,y = t,p = 1,x[sa[0]] = 0,i = 1;i < n;i++)
            x[sa[i]] = cmp(y,sa[i - 1],sa[i],j) ? p - 1 : p++;
    }
    return;
}
void calheight(int *r,int *sa,int n) {
    int i,j,k = 0;
    for(i = 1;i <= n;i++) ran[sa[i]] = i;
    for(i = 0;i < n;h[ran[i++]] = k)
        for(k?k--:0,j = sa[ran[i] - 1];r[i + k] == r[j + k];k++);
    return;
}


int main()
{
	#ifdef LOCAL
	freopen("C:\\Users\\ΡΡ\\Desktop\\in.txt","r",stdin);
	//freopen("C:\\Users\\ΡΡ\\Desktop\\out.txt","w",stdout);
	#endif // LOCAL
	int t; scanf("%d",&t);
	while(t--) {
        scanf("%s",s);
        int len = strlen(s);
        for(int i = 0;i < len;i++)
            ss[i] = s[i];
        ss[len] = 0;
        getsa(ss,sa,len + 1,128);
        /*for(int i = 0;i <= len;i++)
            cout<<sa[i]<<" ";
        cout<<endl;*/
        calheight(ss,sa,len);
        /*for(int i = 0;i <= len;i++)
            cout<<h[i]<<" ";
        cout<<endl;*/
        for(int i = 0;i <= len;i++)
            ans[i] = inf;
        ans[0] = 0;
        con[0] = 0;
        id[0] = 0;
        sum[0] = 0;
        int pos = 0;
        for(int i = 1;i <= len;i++){
            int temp = lower_bound(ans,ans + pos + 1,h[i]) - ans;
            if(temp == pos + 1){
                sum[i] = sum[i - 1] + h[i];
                pos++;
                ans[pos] = h[i];
                con[pos] = con[pos - 1] + h[i];
                id[pos] = i;
            }
            else if(temp == 0){
                sum[i] = 0;
                pos = 0;
                ans[pos] = 0;
                con[pos] = 0;
                id[pos] = i;
            }
            else{
                pos = temp;
                sum[i] = sum[id[pos - 1]] + (i - id[pos - 1])*h[i];
                con[pos] = con[pos - 1] + h[i];
                ans[pos] = h[i];
                id[pos] = i;
            }
        }
        ll rans = 0;
        for(int i = 1;i <= len;i++)
            rans += sum[i];
        ll rrans = len;
        rrans = rrans*(rrans + 1)/2*(rrans - 1) - 2*rans;
        printf("%lld\n",rrans);
	}
	return 0;
}
