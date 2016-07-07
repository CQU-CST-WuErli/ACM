#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;


#define INF 999999999
#define MAXN 14000
#define RE(x) (x)^1

int head[MAXN];
int map[120][120];
int st,ed;
struct Edge
{
    int v,next;
    int val;
    Edge(){}
    Edge( int V , int NEXT , int W = 0 ):v(V),next(NEXT),val(W){}
}edge[500000];

struct gg
{
    int x,y;
    int val;
}row[MAXN],col[MAXN];
int emp,row_num,col_num;
int lvl[MAXN], gap[MAXN];
int cnt_edge;
int n,m,T;
int empty[MAXN];

void Insert_Edge( int u , int v , int flow = 0 ) {

    edge[cnt_edge] = Edge(v,head[u],flow);
    head[u] = cnt_edge++;
    edge[cnt_edge] = Edge(u,head[v]);
    head[v] = cnt_edge++;

}

void Init(){
    cnt_edge = 0;
    memset(head,-1,sizeof(head));
     memset(lvl, 0, sizeof (lvl));
    memset(gap, 0, sizeof (gap));
}

int dfs(int u, int flow)
{
    if (u==ed) {
        return flow;
    }
    int tf = 0, sf, mlvl = ed-1;
    for (int i= head[u]; i != -1; i = edge[i].next) {
        if (edge[i].val > 0) { 
            if (lvl[u] ==lvl[edge[i].v]+1) {  
                sf = dfs(edge[i].v, min(flow-tf, edge[i].val));
                edge[i].val -= sf;
                edge[RE(i)].val += sf;
                tf += sf;
                if (lvl[st] >=ed) {
                    return tf;
                }
                if (tf == flow) {
                    break;
                }
            }
            mlvl = min(mlvl, lvl[edge[i].v]);
        }
    }
    if (tf == 0) {
        --gap[lvl[u]];
        if (!gap[lvl[u]]) {
            lvl[st] =ed;
        }
        else {
            lvl[u] = mlvl+1;
            ++gap[lvl[u]];
        }
    }
    return tf;
}

int sap()
{
    int ans = 0;
    gap[0]=ed;
    while (lvl[st] <ed) {
        ans += dfs(st, INF);
    }
    return ans;
}

int print( int tp ) {
    int ans = 0;
    int id = tp + row_num+1;
    for( int i = head[id] ; i != -1 ; i = edge[i].next ) {
        int v = edge[i].v;
        if( v <=row_num+1 )
        { 
          ans+= edge[i].val;
          break;
        }
    }
    return ans+1;
}

int main()

{
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int i,j;

    char s[15];

    while(scanf("%d%d",&n,&m)!=-1)
    {
        emp=row_num=col_num=0;
        for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        {
            scanf("%s",s);
            if(s[0]=='.')
            {
                map[i][j]=++emp;    
            }
            else
            {
                map[i][j]=-1;
                if(s[4]!='X')
                {
                        int tp=(s[4]-'0')*100+(s[5]-'0')*10+s[6]-'0';
                        row[++row_num].x=i;
                        row[row_num].y=j;
                        row[row_num].val=tp;
                        
    
                }
                if(s[0]!= 'X' ) {
                        int tp = (s[0]-'0')*100+(s[1]-'0')*10+s[2]-'0';
                        col[++col_num].x = i;
                        col[col_num].y = j;
                        col[col_num].val = tp;
                    }
    
            }
                
        }
        T=emp+col_num+row_num+2;
        st=1;
        ed=T;
        Init();
        for(i=1;i<=row_num;i++)
        {
            int pos = i;
            int x = row[i].x;
            int y = row[i].y;
            int cnt_len = 0;
            for( y=y+1; y <m ; y++ ) {
                if( map[x][y] != -1 ) {
                    cnt_len++;
            Insert_Edge(i+1, row_num+ map[x][y]+1,8);
                } else break;
            }
            Insert_Edge(st,pos+1,row[i].val-cnt_len);
        }
        
        for( i = 1 ; i <=col_num ; i++ ) {
            int pos =i+1+row_num+emp;
            int x = col[i].x;
            int y = col[i].y;
            int cnt_len = 0;
            for( x=x+1 ; x < n ; x++ ) {
                if( map[x][y] != -1 ) {
                    cnt_len++;
            Insert_Edge(row_num+ map[x][y]+1,pos,8);
                
                } else break;
            }
            Insert_Edge(pos,ed,col[i].val-cnt_len);
        }
        cout << "cnt_edge=" << cnt_edge << endl; 
        int tmp=sap();
        cout << "tmp=" << tmp << endl;
		for(i=0;i<n;i++)
        {
        for(j=0;j<m;j++)
        {
        
            if(map[i][j]==-1)
            printf("_ ");
            else
            printf("%d ",print(map[i][j]));    
        }
        printf("\n");
    }    
    }
    
    return 0;
}
