#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 200005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define S second
#define F first
int d[20][20];
int c[20];
int dp[1<<20][20];
int n;
int solve(int mask, int pos) {
    if (~dp[mask][pos]) {
        return dp[mask][pos];
    }
    if (__builtin_popcount(mask) == 1) {
        return dp[mask][pos] = 0;
    }
    int rm = mask;
    mask ^= (1<<c[pos]);
    int mi = 1e9;
    for (int i = 0 ; i < n ; i++) {
        if (mask & (1<<c[i])) {
            mi = min(mi, solve(mask, i) + d[i][pos]);
        }
    }
    return dp[rm][pos] = mi;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m, k;
    cin >> n >> m >> k;
    f(n) {
        cin >> c[i];
        c[i]--;
    }
    memset(d, 0x3f, sizeof(d));
    memset(dp, -1, sizeof(dp));
    f(n) {
        d[i][i] = 0;
    }
    f(m) {
        int a, b, x;
        cin >> a >> b >> x;
        a--, b--;
        d[a][b] = d[b][a] = x;
    }
    for (int k = 0 ; k < n ; k++) {
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    int ans = 1e9;
    f(n) {
        ans = min(ans, solve((1<<k) - 1, i));
    }
    cout << ans << '\n';
}