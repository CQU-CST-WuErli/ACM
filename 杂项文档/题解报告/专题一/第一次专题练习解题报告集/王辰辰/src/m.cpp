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
double ans[20];
char s[1000000];
int main()
{
	#ifdef LOCAL
	freopen("C:\\Users\\ΡΡ\\Desktop\\in.txt","r",stdin);
	//freopen("C:\\Users\\ΡΡ\\Desktop\\out.txt","w",stdout);
	#endif // LOCAL
	ans[0] = 1;
	double temp = (double)1000/(double)1024;
	ans[1] = temp;
	for(int i = 2;i <= 8;i++)
	    ans[i] = ans[i - 1]*temp;
    int t,kase = 1;
    scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        int len = strlen(s);
        int pos;
        for(int i = 0;i < len;i++){
            if(s[i] == 'B'){
                pos = 0;break;
            }
            else if(s[i] == 'K'){
                pos = 1;break;
            }
            else if(s[i] == 'M'){
                pos = 2;break;
            }
            else if(s[i] == 'G'){
                pos = 3;break;
            }
            else if(s[i] == 'T'){
                pos = 4;break;
            }
            else if(s[i] == 'P'){
                pos = 5;break;
            }
            else if(s[i] == 'E'){
                pos = 6;break;
            }
            else if(s[i] == 'Z'){
                pos = 7;break;
            }
            else if(s[i] == 'Y'){
                pos = 8;break;
            }
        }
        printf("Case #%d: %.2lf%%\n",kase++,100 - ans[pos]*100);
    }
	return 0;
}
