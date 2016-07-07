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
const int maxn = 610000;
int n;
int a[maxn];
int work(){
    int i,j,k;
    i = 0;j = 1;k = 0;
    while(i < n && j < n){
        k = 0;
        while(a[i + k] == a[j + k] && k < n)k++;
        if(k == n)return i;
        if(a[i + k] > a[j + k]){
            if(i + k + 1 > j)
                i = i + k + 1;
            else
                i = j + 1;
        }
        else if(j + k + 1 > i)
            j = j + k + 1;
        else
            j = i + 1;
    }
    if(i < n)return i;
    return j;
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
        scanf("%d",&n);
        for(int i = 0;i < n;i++)
            scanf("%d",&a[i]);
        for(int i = n;i < 2*n;i++)
            a[i] = a[i - n];
        int pos = work();
        for(int i = 0;i < n;i++){
            printf("%d",a[pos + i]);
            if(i != n - 1)
                printf(" ");
            else
                printf("\n");
        }
	}
	return 0;
}
