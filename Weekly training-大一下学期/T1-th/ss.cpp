#include <iostream>
#include <queue>
#include <vector>
typedef unsigned long long ll;
using namespace std;
ll my_max(ll a, ll b)
{
    return a > b? a : b;
}
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    int n, k;
    while (cin >> n >> k)
    {
        priority_queue<ll, vector<ll>, greater<ll> > pq;
        for (int i = 0; i < k; ++i)
            pq.push(0);
        int s, m;
        ll ans;
        for (int i = 0 ; i < n; ++i)
        {
            cin >> s >> m;
            ans = pq.top();
            pq.pop();
            ans = my_max(ans, s) + m;
            cout << ans << endl;
            pq.push(ans);
        }
    }
    return 0;
}
