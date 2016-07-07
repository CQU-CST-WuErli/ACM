#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
/*
*  �� ����ͼ�ĸ�����
*  �����ҳ������ţ���ɾ��ÿ��������ӵ���ͨ�顣
*  ��Ҫע���رߵĴ����������þ���棬��ת�ڽӱ����߽�������
*/
const int MAXN = 10010;
const int MAXM = 100010;
struct Edge
{
    int to,next;
    bool cut;//�Ƿ�Ϊ�ŵı��
}edge[MAXM];
int head[MAXN],tot;
int Low[MAXN],DFN[MAXN],Stack[MAXN];
int Index,top;
bool Instack[MAXN];
bool cut[MAXN];
int add_block[MAXN];//ɾ��һ��������ӵ���ͨ��
int bridge;

void addedge(int u,int v)
{
    edge[tot].to = v;edge[tot].next = head[u];edge[tot].cut = false;
    head[u] = tot++;
}

void Tarjan(int u,int pre)
{
    int v;
    Low[u] = DFN[u] = ++Index;
    Stack[top++] = u;
    Instack[u] = true;
    int son = 0;
    for(int i = head[u];i != -1;i = edge[i].next)
    {
        v = edge[i].to;
        if(v == pre)continue;
        if( !DFN[v] )
        {
            son++;
            Tarjan(v,u);
            if(Low[u] > Low[v])Low[u] = Low[v];
            //��
            //һ�������(u,v)���ţ����ҽ���(u,v)Ϊ��֦�ߣ�������DFS(u)<Low(v)��
            if(Low[v] > DFN[u])
            {
                bridge++;
                edge[i].cut = true;
                edge[i^1].cut = true;
            }
        }
        else if( Low[u] > DFN[v])
             Low[u] = DFN[v];
    }
    if(u == pre)add_block[u] = son - 1;
    Instack[u] = false;
    top--;
}

void solve(int N)
{
    memset(DFN,0,sizeof(DFN));
    memset(Instack,false,sizeof(Instack));
    memset(add_block,0,sizeof(add_block));
    memset(cut,false,sizeof(cut));
    Index = top = 0;
    bridge = 0;
    for(int i = 1;i <= N;i++)
        if( !DFN[i] )
            Tarjan(i,i);
    printf("%d critical links\n",bridge);
    vector<pair<int,int> >ans;
    for(int u = 1;u <= N;u++)
        for(int i = head[u];i != -1;i = edge[i].next)
            if(edge[i].cut && edge[i].to > u)
            {
                ans.push_back(make_pair(u,edge[i].to));
            }
    sort(ans.begin(),ans.end());
    for(int i = 0;i < ans.size();i++)
        printf("%d - %d\n",ans[i].first-1,ans[i].second-1);
    printf("\n");
}
void init()
{
    tot = 0;
    memset(head,-1,sizeof(head));
}

int main()
{
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int n;
    while(scanf("%d",&n) == 1)
    {
        init();
        int u;
        int k;
        int v;
        //mapit.clear();
        for(int i = 1;i <= n;i++)
        {
            scanf("%d (%d)",&u,&k);
            u++;
            while(k--)
            {
                scanf("%d",&v);
                v++;
                if(v <= u)continue;
                //if(isHash(u,v))continue;
                addedge(u,v);
                addedge(v,u);
            }
        }
        solve(n);
    }
    return 0;
}
