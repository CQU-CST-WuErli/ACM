#define Key_value ch[ch[root][1]][0]
const int MAXN = 500010;
const int INF = 0x3f3f3f3f;
int pre[MAXN],ch[MAXN][2],key[MAXN],size[MAXN];
int root,tot1;
int sum[MAXN],rev[MAXN],same[MAXN];
int lx[MAXN],rx[MAXN],mx[MAXN];
int s[MAXN],tot2;//内存池和容量
int a[MAXN];
int n,q;
//debug部分**********************************
void Treavel(int x)
{
if(x)
{
Treavel(ch[x][0]);
printf("结点：%2d: 左儿子 %2d 右儿子 %2d 父结点 %2d size = %2d\n",x,ch[x][0],ch[x][1],pre[x],size[x]);
Treavel(ch[x][1]);
}
}
void debug()
