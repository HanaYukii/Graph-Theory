#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;

vector<int>g[maxn];
long long c[maxn];
long long dp[maxn][2];
void solve(int now, int pre) {
    long long sum0 = 0, sum1 = c[now];
    for (auto &i : g[now]) {
        if (i == pre) {
            continue;
        }
        solve(i, now);
        sum0 += dp[i][1];
        sum1 += min(dp[i][0], dp[i][1]);
    }
    dp[now][0] = sum0;
    dp[now][1] = sum1;
}
void solve() {
    int n;
    cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        cin >> c[i];
    }
    for (int i = 0 ; i < n - 1 ; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    solve(1, 0);
    cout << min(dp[1][0], dp[1][1]) << ' ';
    for (int i = 1 ; i <= n ; i++) {
        c[i] = 1;
    }
    solve(1, 0);
    cout << min(dp[1][0], dp[1][1]) << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}