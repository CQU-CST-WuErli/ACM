#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

#define maxn 500010

inline int maxx(int a, int b)
{
	return a > b? a : b;
}
struct node
{
	int l,r,value;
};

int n,m;
int u,v;
int inpt[maxn];
int anslist[50010];
node segt[1000010];
int va[500010];


void initva(int,int);
void initst(int,int,int);
int stsearch(int,int,int);

int main()
{

	while(scanf("%d", &n) != EOF)
	{
		memset(va, 0, sizeof(va));
		memset(segt, 0, sizeof(segt));
		for(int i=1; i<=n; i++)
		{
			scanf("%d", &inpt[i]);
		}
		
		for(int i=n; i>0; i--)
		{
			if(!va[i])
			{
				initva(inpt[i], i);
			}
		}
		
		initst(1,n,1);

		/*
		for(int i=1 ;i<=2*n+1; i++)
		{
			printf("%d %d %d %d\n", i, segt[i].l, segt[i].r, segt[i].value);
		}
		*/

		scanf("%d", &m);

		for(int i=1; i<=m; i++)
		{
			scanf("%d%d", &u, &v);
			int point = stsearch(1,u,v);

			//printf("ansp:%d", point);
			anslist[i] = inpt[point];
		}

		for(int i=1; i<=m; i++)
		{
			if(anslist[i])
				printf("%d\n", anslist[i]);
			else
				printf("OK\n");
		}
	}
	
	return 0;
}

void initva(int now, int p)
{
	for(int i=p-1; i>0; i--)
	{
		if(inpt[i]==now)
		{
			va[i] = p;
			p = i;
		}
	}
	return;
}

void initst(int sl, int sr,int p)
{
	segt[p].l = sl;
	segt[p].r = sr;
	int mid = (sl+sr) /2;
	
	if(sl == sr)
	{
		segt[p].value = va[sl];
		return;
	}
	
	initst(sl,mid,p*2);
	initst(mid+1,sr,p*2+1);

	segt[p].value = maxx(segt[p*2].value, segt[p*2+1].value);
	
	return;
}

int stsearch(int p,int nl,int nr)
{
	int tl = segt[p].l;
	int tr = segt[p].r;
	int mid = (tl+tr)/2;
	int ansl,ansr;
	ansl = ansr = 0;
	
	//printf("top:%d %d %d %d %d\n", p, nl, nr, tl, tr);
	//system("pause");
	if(nl == tl && nr == tr)
	{
		if(segt[p].value <= v)
		{
			//printf("%d %d %d\n", nl, nr, segt[p].value);
			return segt[p].value;
		}

		else if(nl == nr)
		{
			//printf("%d %d 0\n", nl, nr);
			return 0;
		}
	}
	
	if(nr <= mid)
	{
		return stsearch(p*2,nl,nr);
	}
	
	if(nl >= mid + 1)
	{
  		return stsearch(p*2+1,nl,nr);
	}
	
	ansl = stsearch(p*2,nl,mid);
	ansr = stsearch(p*2+1,mid+1,nr);
	
	//printf("%d %d %d\n", p, ansl, ansr);
	
	//system("pause");
	return maxx(ansl, ansr);
 }
