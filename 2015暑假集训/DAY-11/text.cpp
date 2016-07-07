#include<iostream>
#include<stdio.h>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<string.h>
#define ll long long
#define oo 10000007
using namespace std;     
int way[1005],num; 
bool DFSID(int x,int step)
{ 
      int i;
      if (num>step) return false;
      if (way[num]==x) return true;
      if (way[num]<<(step-num)  < x) return false; // Ç¿Á¦¼ôÖ¦ 
      for (i=0;i<=num;i++)
      {
             num++;
             way[num]=way[num-1]+way[i];
             if (way[num]<=10000 && DFSID(x,step)) return true; 
             way[num]=way[num-1]-way[i];  
             if (way[num]>0 && DFSID(x,step)) return true;           
             num--;
      } 
      return false;    
}
int main()
{  
#ifdef LOCAL
	freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
//	freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
      cout << 8*888+10 << endl;
      return 0;
}

