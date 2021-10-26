#include<bits/stdc++.h>
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int mod = 1e9+7;
using namespace std;
vector<int>g[300005];
int dep[300005];
int ans;
void dfs(int now, int pre) {
    dep[now] = 1;
    int mx = 0, sec_mx = 0;
    for (auto &i : g[now]) {
        if (i == pre) {
            continue;
        }
        dfs(i, now);
        dep[now] = max(dep[now], dep[i] + 1);
        if (dep[i] >= mx) {
            sec_mx = mx;
            mx = dep[i];
        }
        else if (dep[i] > sec_mx) {
            sec_mx = dep[i];
        }
    }
    ans = max(ans, mx + sec_mx);
}
void solve() {
    int n;
    cin >> n;
    for (int i = 0 ; i < n - 1 ; i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    } 
    dfs(1, 0);
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}