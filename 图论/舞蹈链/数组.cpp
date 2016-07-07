const int maxm = 324+10;
const int maxn = 729+10;
const int maxnode = maxn * maxm;
struct DLX {
    int n,m;
    int L[maxnode],R[maxnode],U[maxnode],D[maxnode];
    int Row[maxnode],Col[maxnode];
    int H[maxnode],S[maxnode];
    int vis[maxn];
    int ans;    //  need update
    int size;
    void init(int _n,int _m) {
        n=_n,m=_m;
        for (int i=0;i<=m;i++) {
            U[i]=D[i]=i;
            L[i]=i-1;R[i]=i+1;
            S[i]=0;
        }
        L[0]=m;R[m]=0;
        for (int i=1;i<=n;i++) H[i]=-1;
        size=m;
    }
    void link(int row,int col) {
        size++;
        Col[size]=col;Row[size]=row;
        S[col]++;
        U[size]=U[col];D[size]=col;
        D[U[col]]=size;
        U[col]=size;
        if (H[row]!=-1) {
            R[size]=H[row];
            L[size]=L[H[row]];
            R[L[size]]=size;
            L[R[size]]=size;
        }
        else
            H[row]=L[size]=R[size]=size;
    }
    // exact cover
    void remove(int c) {
        L[R[c]]=L[c];
        R[L[c]]=R[c];
        for (int i=D[c];i!=c;i=D[i]) {
            for (int j=R[i];j!=i;j=R[j]) {
                U[D[j]]=U[j];
                D[U[j]]=D[j];
                S[Col[j]]--;
            }
        }
    }
    void resume(int c) {
        for (int i=U[c];i!=c;i=U[i]) {
            for (int j=L[i];j!=i;j=L[j]) {
                U[D[j]]=j;
                D[U[j]]=j;
                S[Col[j]]++;
            }
        }
        R[L[c]]=c;
        L[R[c]]=c;
    }
    bool dfs(int cnt) {
        if (ans!=-1) return true;
        if (R[0]==0) {
            ans=cnt;
            return true;
        }
        int c=R[0];
        for (int i=R[0];i!=0;i=R[i]){
            if (S[c]>S[i]) c=i;
        }
        remove(c);
        for (int i=D[c];i!=c;i=D[i]) {
            for (int j=R[i];j!=i;j=R[j]) {
                remove(Col[j]);
            }
            if (dfs(cnt+1)) return true;
            for (int j=L[i];j!=i;j=L[j]) {
                resume(Col[j]);
            }
        }
        resume(c);
        return false;
    }
    // exact cover ends;
    // multiple cover
    void del(int c) {
        for (int i=D[c];i!=c;i=D[i]) {
            L[R[i]]=L[i];
            R[L[i]]=R[i];
        }
    }
    void rec(int c) {
        for (int i=U[c];i!=c;i=U[i]) {
            L[R[i]]=R[L[i]]=i;
        }
    }
    int h() {
        int ret=0;
        for (int i=0;i<=m;i++) vis[i]=0;
        for (int i=R[0];i!=0;i=R[i]) if (!vis[i]) {
            ret++;
            vis[i]=1;
            for (int j=D[i];j!=i;j=D[j])
                for (int k=R[j];k!=j;k=R[k])
                    vis[Col[k]]=1;
        }
        return ret;
    }
    void DFS(int cnt) {
        if (cnt+h()>=ans) return;
        if (R[0]==0) {
            ans=min(ans,cnt);
            return;
        }
        int c=R[0];
        for (int i=R[0];i!=0;i=R[i])
            if (S[c]>S[i]) c=i;
        for (int i=D[c];i!=c;i=D[i]) {
            del(i);
            for (int j=R[i];j!=i;j=R[j]) del(j);
            DFS(cnt+1);
            for (int j=L[i];j!=i;j=L[j]) rec(j);
            rec(i);
        }
        return;
    }
    // multiple cover ends;
}dlx;
