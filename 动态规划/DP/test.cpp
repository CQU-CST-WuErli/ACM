#include <iostream>
#include <cstdio>
#include <cstring>
#define LMT 1000005
/****
KMP算法本质：在字符串中有一个字符，以这个字符为末尾的长度为N的子串(不包括末字符,N为所能取到的最大值)，
可以与字符串头字符构成的长度为N的字串匹配(不包括末字符，且保证末字符不等)。
***/
//第一次的next是最大的，之后就逐个减小
using namespace std;
int hsh[LMT],nxt[LMT],len;
char str[LMT];
void init()
{
    int i=0,j=-1;
    nxt[0]=-1;
    while(i<len)
    {
        if(j==-1||str[i]==str[j])
        {
            i++;j++;nxt[i]=j;
        }
        else j=nxt[j];
    }
    for(i=0;i<len;i++)
    hsh[nxt[i]]++;
}
int main(int argc, char const *argv[])
{
#ifdef LOCAL
    freopen("C:\\Users\\john\\Desktop\\in.txt","r",stdin);
    // freopen("C:\\Users\\john\\Desktop\\out.txt","w",stdout);
#endif
    int i;
    scanf("%s",str);
    len=strlen(str);
    init();
    i=len;
    cout << nxt[i] << endl;
    while(nxt[i]>0)
    {
       if(hsh[nxt[i]])
       {
        for(int j=0;j<nxt[i];j++)
        printf("%c",str[j]);
        printf("\n");
        return 0;
       }
       i=nxt[i];
    }
    printf("Just a legend\n");
    return 0;
}