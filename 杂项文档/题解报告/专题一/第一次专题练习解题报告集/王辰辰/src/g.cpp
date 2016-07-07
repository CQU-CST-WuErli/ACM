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
int n,t,c,m;
struct Node{
    char s[505];
    int len,mod;
};
vector<char>vt;
bool leap[5100];
int get(char c){
    if(c >= '0' && c <= '9')return c - '0';
    return c - 'A' + 10;
}
void bfs(){
    queue<Node>p;
    memset(leap,false,sizeof(leap));
    Node ini;
    if(vt.size() == 1 && vt[0] == '0'){
        printf("BOMB!!!\n");
        return;
    }
    for(int i = 0;i < vt.size();i++){
        if(vt[i] == '0')continue;
        ini.s[0] = vt[i];
        ini.len = 1;
        ini.mod = get(vt[i])%n;
        if(leap[ini.mod])continue;
        leap[ini.mod] = true;
        p.push(ini);
    }
    while(p.size()){
        Node temp = p.front();p.pop();
        if(temp.len == 500)continue;
        if(temp.mod == 0){
            for(int i = 0;i < temp.len;i++)
                printf("%c",temp.s[i]);
            printf("\n");
            return;
        }
        for(int i = 0;i < vt.size();i++){
            Node rtemp = temp;
            rtemp.s[rtemp.len] = vt[i];
            rtemp.len++;
            rtemp.mod = (rtemp.mod*c + get(vt[i]))%n;
            if(leap[rtemp.mod])continue;
            leap[rtemp.mod] = true;
            p.push(rtemp);
        }
    }
    printf("BOMB!!!\n");
}
int main()
{
	#ifdef LOCAL
	freopen("C:\\Users\\ΡΡ\\Desktop\\in.txt","r",stdin);
	//freopen("C:\\Users\\ΡΡ\\Desktop\\out.txt","w",stdout);
	#endif // LOCAL
	scanf("%d",&t);
	while(t--){
        vt.clear();
        scanf("%d%d",&n,&c);
        scanf("%d",&m);
        char s[10];
        for(int i = 1;i <= m;i++){
            scanf("%s",s);
            vt.push_back(s[0]);
        }
        sort(vt.begin(),vt.end());
        if(n == 0){
            if(vt[0] == '0')
                printf("0\n");
            else
                printf("BOMB!!!\n");
            continue;
        }
        bfs();
	}
	return 0;
}
