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
const int maxn = 5000100;
int len1,len2,len3;
int f[maxn];
bool leap[maxn];
char a[maxn],b[maxn],s[maxn];
void getfill(){
    memset(f,0,sizeof(f));
    for(int i = 1;i < len2;i++){
        int j = f[i];
        while(j && a[i] != a[j])
            j = f[j];
        f[i + 1] = (a[i] == a[j]) ? j + 1 : 0;
    }
}
void kmp(){
    int j = 0;
    for(int i = 0;i < len1;i++){
        while(j && s[i] != a[j])
            j = f[j];
        if(s[i] == a[j])
            j++;
        if(j == len2)
            leap[i - len2 + 1] = true;
    }
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
        scanf("%s%s%s",s,a,b);
        len1 = strlen(s);
        len2 = strlen(a);
        len3 = strlen(b);
        getfill();
        memset(leap,false,sizeof(leap));
        kmp();
        for(int i = 0;i < len1;i++){
            if(leap[i]){
                printf("%s",b);
                i = i + len2 - 1;
            }
            else
                printf("%c",s[i]);
        }
        printf("\n");
	}
	return 0;
}
