int work(int m)
{
    int i,j,l;
    i=0; j=1;
    while(i<m && j<m)
    {
        for(l=0;l<m;l++)
            if(a[(i+l)%m]!=a[(j+l)%m]) break;
        if(l>m) break;
        if(a[(i+l)%m] > a[(j+l)%m])
            i=i+l+1;
        else
            j=j+l+1;
        if(i==j) j=i+1;
    }
    if(i<j) return i;
    return j;
}

int work(int len,char pat[])  //最大表示法
{
   //int len = strlen(pat);
   int i=0,j=1,k=0;
   while(i<len && j<len && k<len)
   {
       int t = pat[(i+k)%len] - pat[(j+k)%len];
       if(!t) k++;
       else
       {
           if(t>0) j = j+k+1;
           else i = i+k+1;
           if(i == j) j++;
           k = 0 ;
       }
   }
   return i<j?i:j;
}
